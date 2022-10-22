#include<bits/stdc++.h>
#define int long long
#define ll long long
#define maxn 100005
#define M 10005
#define LEFT 1
#define RIGHT 1
using namespace std;

typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
}BTNode;
 
int max(int a, int b);
 
 
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
int max(int a, int b)
{
    return (a > b) ? a : b;
}
 
BTNode* newNode(int key)
{
    struct Node* node = (BTNode*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}
 
BTNode* ll_rotate(BTNode* y)
{
    BTNode *x = y->left;
    y->left = x->right;
    x->right = y;
 
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
 
    return x;
}
 
BTNode* rr_rotate(BTNode* y)
{
    BTNode *x = y->right;
    y->right = x->left;
    x->left = y;
 
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
 
    return x;
}
 
int getBalance(BTNode* N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
BTNode* insert(BTNode* node, int key)
{
 
    if (node == NULL)
        return newNode(key);
 
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
 
    node->height = 1 + max(height(node->left), height(node->right));
 
 
    int balance = getBalance(node);
 
 
 
    if (balance > 1 && key < node->left->key) //LL
        return ll_rotate(node);
 
 
    if (balance < -1 && key > node->right->key)     //RR
        return rr_rotate(node);
 
 
    if (balance > 1 && key > node->left->key)     //LR
    {
        node->left = rr_rotate(node->left);
        return ll_rotate(node);
    }
 
    if (balance < -1 && key < node->right->key)     //RL
    {
        node->right = ll_rotate(node->right);
        return rr_rotate(node);
    }
 
    return node;
}
 
 
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
int work()
{
    BTNode *root = NULL;
 
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 0);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 9);
    root = insert(root, 8);
    root = insert(root, 7);
 
    printf("");
    preOrder(root);
    return 0;
}
int n;
int a[1145141],kkk,nmsl,tp,s,s1;
signed main() {
	cin>>n>>kkk;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,greater<long long>() );
	for (int i=1;i<=n;i++) nmsl+=(n-i)*a[i];
	tp=nmsl;
	for (int i=1;i<=n;i++) s+=a[i];
	for (int i=n;i>=1;i--)
	{
		s1+=a[i+1];
		if ((n-i)%(kkk+1)) tp-=(s-s1);
		nmsl=max(nmsl,tp);
	}
	cout<<nmsl<<endl;
}