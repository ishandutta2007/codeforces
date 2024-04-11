#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct rmq {
       int l, r, val;
       rmq *left, *right;
};

rmq *build(int l, int r) {
    rmq* root = (rmq*)malloc(sizeof(rmq));
    root->l = l;
    root->r = r;
    if(l == r) {
         root->val = -1;
         root->left = root->right = NULL;
    }
    else {
         root->left = build(l, (l + r) / 2);
         root->right = build((l + r) / 2 + 1, r);
         root->val = -1;
    }
    return root;
}

int get(int l, int r, rmq* root) {
    if(l > r)
         return -1;
    if(root->l == l && root->r == r)
               return root->val;
    else {
         int resL = -1, resR = -1;
         if(root->left && root->left->r >= l)
                       resL = get(l, min(root->left->r, r), root->left);
         if(root->right && root->right->l <= r)
                        resR = get(max(l, root->right->l), r, root->right);
         return max(resL, resR);
    }
}

void modify(int l, int r, int val, rmq* root) {
     if(root->l == l && root->r == r)
                root->val = val;
     else {
          if(root->left && root->left->r >= l)
                        modify(l, min(r, root->left->r), val, root->left);
          if(root->right && root->right->l <= r)
                         modify(max(root->right->l, l), r, val, root->right);
          root->val = max(root->left->val, root->right->val);
     }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
     return a.first < b.first;
} 

int main() {
    int n;
    
    cin >> n;
    
    int a[n];
    
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    
    pair<int, int> p[n];
    int ans[n];
    
    for(int i = 0; i < n; ++i)
            p[i] = pair<int, int>(a[i], i);
    
    sort(p, p + n, cmp);
    
    rmq *root = build(0, n - 1);
    
    int pos = -1;
    
    for(int i = 0; i < n; ++i) {
            if(pos < 0 || p[i].first != p[pos].first)
                   pos = i;
            int j = p[i].second;
            ans[j] = get(0, pos - 1, root);
            if(ans[j] <= j)
                      ans[j] = -1;
            else
                ans[j] = ans[j] - j - 1;
            modify(i, i, j, root);
    }
    
    for(int i = 0; i < n; ++i)
            cout << ans[i] << " ";
             
    cin >> n;
    
    return 0;
}