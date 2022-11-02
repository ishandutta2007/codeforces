#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct rmq {
       int l, r, val;
       rmq* left, *right;
};

rmq* build(int l, int r) {
     rmq* root = (rmq*)malloc(sizeof(rmq));
     root->l = l;
     root->r = r;
     if(l == r)
          root->val = -1, root->left = root->right = NULL;
     else
         root->left = build(l, (l + r) / 2), root->right = build((l + r) / 2 + 1, r), root->val = -1;
     return root;
}

int get(int l, int r, rmq* root) {
    if(l > r)
         return -1;
    if(l == root->l && r == root->r)
         return root->val;
    int ml = -1, mr = -1;
    if(root->left && root->left->r >= l)
                  ml = get(l, min(r, root->left->r), root->left);
    if(root->right && root->right->l <= r)
                   mr = get(max(l, root->right->l), r, root->right);
    return max(ml, mr);
}

void up(int i, int val, rmq* root) {
     if(root->l == i && root->r == i)
                root->val = val;
     else {
         if(root->left && root->left->r >= i)
                       up(i, val, root->left);
         if(root->right && root->right->l <= i)
                        up(i, val, root->right);
         if(root->left)
                       root->val = max(root->right->val, root->left->val);
     }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
     return a.first < b.first;
}
          
int main() {
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
    }
    sort(a, a + n, cmp);
    vector<int> ans(n, -1);
    rmq* tree = build(0, n - 1);
    int prev = -1;
    for(int i = 0; i < n; ++i) {
            if(prev < 0 || a[prev].first != a[i].first)
                    prev = i;
            int num = a[i].second, x = a[i].first;
            int p = get(0, prev - 1, tree);
            if(p > num)
                 ans[num] = p - num - 1;
            up(i, num, tree);
    }
    for(int i = 0; i < n; ++i)
            cout << ans[i] << " ";
    cin >> n;
    return 0;
}