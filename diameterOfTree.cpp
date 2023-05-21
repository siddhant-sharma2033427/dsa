#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

void inorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
 }
int height(node *root){
    if(root == NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
int findNode(node * root){
    if(root == NULL){
        return 0;
    }
    int leftcount = findNode(root->left);
    int rightcount = findNode(root->right);
    
    return leftcount+rightcount+1;
    
}
int DiameterOfTree(node * root){
    if(root == NULL){
        return 0;
    }
    int op1 = height(root->left) + height(root->right);
    int op2 = DiameterOfTree(root->left);
    int op3 = DiameterOfTree(root->right);
    return max(op1,max(op2, op3));
    //tc = n*h
}
pair<int,int> fastDiameter(node * root){
    if(root == NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int,int> leftans = fastDiameter(root->left);
    pair<int,int> rightans = fastDiameter(root->right);
    int ld = leftans.second;
    int lh = leftans.first;
    int rd = rightans.second;
    int rh = rightans.first;

    int height = 1 + max(lh,rh);
    int diameter = max(lh+rh,max(ld,rd));
    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;
}
int main() {

    node* root = NULL;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    cout<<findNode(root)<<endl;
    cout<<fastDiameter(root).second<<endl;
    /*
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //level order
    cout << "Printing the level order tracersal output " << endl;
    levelOrderTraversal(root);

    cout << "inorder traversal is:  ";
    inorder(root); 

    cout << endl << "preorder traversal is:  ";
    preorder(root); 

    cout << endl << "postorder traversal is:  ";
    postorder(root); 
    */


    return 0;
}