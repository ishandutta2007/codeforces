#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
 
int a[2000 * 100];
const long long inf = 1e18;
vector<long long> ans;

long long num(string s, int l, int r) {
     long long t = 1, res = 0;
     for(int i = r; i >= l; --i) {
             if(s[i] == '-')
                  res *= -1;
             else {
                 res += (s[i] - '0') * t;
                 t *= 10;
             }
     }
     return res;
}

struct rmq {
       long long l, r, add, val;
       rmq* left, *right;
};

vector<rmq> RMQ(2 * 1000 * 1000);
int last = 0;

rmq* build(int l, int r) {
     rmq* root = &(RMQ[last++]);
     root->l = l;
     root->r = r;
     root->add = 0;
     if(l == r) {
          root->left = root->right = NULL;
          root->val = a[l];
     }
     else {
          root->left = build(l, (l + r) / 2);
          root->right = build((l + r) / 2 + 1, r);
          root->val = min(root->right->val, root->left->val);
     }
     return root;
}

long long get(int l, int r, long long add, rmq* root) {
     if(root->l == l && root->r == r) 
                return root->val + root->add + add;
     else {
          long long minL = inf, minR = inf;
          if(root->left && root->left->r >= l)
                        minL = get(l, min((long long)r, root->left->r), add + root->add, root->left);
          if(root->right && root->right->l <= r)
                         minR = get(max(root->right->l, (long long)l), r, add + root->add, root->right);
          return min(minL, minR);
     }
}

void update(int l, int r, long long Sadd, rmq* root) {
     if(root->l == l && root->r == r)
                root->add = root->add + Sadd;
      else {
           if(root->left && root->left->r >= l)
                         update(l, min((long long)r, root->left->r), Sadd, root->left);
           if(root->right && root->right->l <= r)
                          update(max((long long)l, root->right->l), r, Sadd, root->right);
           if(root->left)
                         root->val = min(root->left->val + root->left->add, root->right->val + root->right->add);
      }
}       

int main() {
    int n;
    
    cin >> n;
    
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    
    rmq* root = build(0, n - 1);
    
    int k;
    
    scanf("%d\n", &k);
    
    for(int t = 0; t < k; ++t) {
            string s;
            getline(cin, s);
            int cnt = 0;
            for(int i = 0; i < s.length(); ++i)
                    if(s[i] == ' ')
                            ++cnt;
            if(cnt == 1) {
                   int l = 0, r = 0;
                   while(s[r] != ' ')
                              ++r;
                   int L = num(s, l, r - 1);
                   l = r + 1;
                   ++r;
                   while(r < s.length())
                           ++r;
                   int R = num(s, l, r - 1);
                   if(L <= R)
                        ans.push_back(get(L, R, 0, root));
                   else
                       ans.push_back(min(get(0, R, 0, root), get(L, n - 1, 0, root)));
            } 
            else {
                   int l = 0, r = 0;
                   while(s[r] != ' ')
                              ++r;
                   int L = num(s, l, r - 1);
                   l = r + 1;
                   ++r;
                   while(s[r] != ' ')
                           ++r;
                   int R = num(s, l, r - 1);
                   l = r + 1;
                   int v = num(s, l, s.length() - 1);
                   if(L <= R)
                        update(L, R, v, root);
                   else
                       update(0, R, v, root), update(L, n - 1, v, root);
            }
    }
    for(int i = 0; i < ans.size(); ++i)
            cout << ans[i] << endl;
    
    cin >> n;
    
    return 0;
}