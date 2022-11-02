#include <iostream>
#include <stdlib.h>
using namespace std;

int a[100 * 1000];

struct rmq {
       int l, r, val;
       rmq *left, *right;
};

rmq* build(int l, int r) {
     rmq* root = (rmq*)malloc(sizeof(rmq));
     root->l = l;
     root->r = r;
     if(l == r) {
          root->val = a[l];
          root->left = root->right = NULL;
     }
     else {
          root->left = build(l, (l + r)  /2);
          root->right = build((l + r) / 2 + 1, r);
          root->val = min(root->left->val, root->right->val);
     }
     return root;
}

int get(int l, int r, rmq* root) {
    if(root->l == l && root->r == r)
               return root->val;
    int minL = 1000 * 1000 + 1, minR = 1000 * 1000 + 1;
    if(root->left && root->left->r >= l) 
                  minL = get(l, min(root->left->r, r), root->left);
    if(root->right && root->right->l <= r)
                   minR = get(max(root->right->l, l), r, root->right);
    return min(minR, minL);
}

rmq* buildMax(int l, int r) {
     rmq* root = (rmq*)malloc(sizeof(rmq));
     root->l = l;
     root->r = r;
     if(l == r) {
          root->val = a[l];
          root->left = root->right = NULL;
     }
     else {
          root->left = buildMax(l, (l + r)  / 2);
          root->right = buildMax((l + r) / 2 + 1, r);
          root->val = max(root->left->val, root->right->val);
     }
     return root;
}

int getMax(int l, int r, rmq* root) {
    if(root->l == l && root->r == r)
               return root->val;
    int minL = -(1000 * 1000 + 1), minR = -(1000 * 1000 + 1);
    if(root->left && root->left->r >= l) 
                  minL = getMax(l, min(root->left->r, r), root->left);
    if(root->right && root->right->l <= r)
                   minR = getMax(max(root->right->l, l), r, root->right);
    return max(minR, minL);
}

int main() {
    int n;
    
    cin >> n;
    for(int i = 0; i < n; ++i)
            cin >> a[i];
            
    rmq* rootMin = build(0, n - 1), *rootMax = buildMax(0, n - 1);
    
    for(int i = 1; i < n - 1; ++i) {
            int l = get(0, i - 1, rootMin), r = get(i + 1, n - 1, rootMin);
            if(r < a[i] && l < a[i]) {
                 cout << 3 << endl;
                 for(int j = 0; j < i; ++j)
                         if(a[j] == l) {
                                 cout << j + 1 << " ";
                                 break;
                         }                    
                  cout << i + 1 << " ";
                  for(int j = i + 1; j < n; ++j)
                         if(a[j] == r) {
                                 cout << j + 1 << " ";
                                 break;
                         }     
                 cin >> n;
                 
                 return 0;
            }
            l = getMax(0, i - 1, rootMax), r = getMax(i + 1, n - 1, rootMax);
            if(r > a[i] && l > a[i]) {
                 cout << 3 << endl;
                 for(int j = 0; j < i; ++j)
                         if(a[j] == l) {
                                 cout << j + 1 << " ";
                                 break;
                         }                    
                  cout << i + 1 << " ";
                  for(int j = i + 1; j < n; ++j)
                         if(a[j] == r) {
                                 cout << j + 1 << " ";
                                 break;
                         }     
                 cin >> n;
                 
                 return 0;
            }
    }
    
    cout << 0;
    
    cin >> n;
    
    return 0;
}