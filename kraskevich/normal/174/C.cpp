#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

#define pii pair<int, int>
const int inf = 1000 * 1000 * 1000;

struct rmq 
{
       int l, r, add;
       pair<int, int> val; 
       rmq * ll, * rr;
};

rmq* build(int l, int r, int a[])
{
     rmq* t = (rmq*)malloc(sizeof(rmq));
     t->l = l;
     t->r = r;
     t->add = 0;
     if(l == r)
     {
          t->ll = t->rr = NULL;
          t->val = pii(a[l], l);
     }
     else
     {
         t->ll = build(l, (l + r) / 2, a);
         t->rr = build((l + r) / 2 + 1, r, a);
         t->val = min(t->ll->val, t->rr->val);
     }
     return t;
}

pii get(int l, int r, int add, rmq * t)
{
    pii res = pii(inf, inf);
    add += t->add;
    if(t->l == l && t->r == r)
            return pii(add + t->val.first, t->val.second);
    if(t->ll && t->ll->r >= l)
             res = get(l, min(r, t->ll->r), add, t->ll);
    if(t->rr && t->rr->l <= r)
             res = min(res, get(max(l, t->rr->l), r, add, t->rr));
    return res;
}

void up(int l, int r, int val, rmq * t)
{
     if(t->l == l && t->r == r)
             t->add += val;
     else
     {
         if(t->ll && t->ll->r >= l)
                  up(l, min(r, t->ll->r), val, t->ll);
         if(t->rr && t->rr->l <= r)
                  up(max(l, t->rr->l), r, val, t->rr);
         if(t->ll)
                  t->val = min(pii(t->ll->val.first + t->ll->add, t->ll->val.second), 
                               pii(t->rr->val.first + t->rr->add, t->rr->val.second));
     }
}

vector<int> L, R;
rmq* root;

void solve(int l, int r)
{
     if(l > r)
          return; 
     pii cur = get(l, r, 0, root);
     if(cur.first != 0)
     {
            L.push_back(l + 1);
            R.push_back(r + 1);
            up(l, r, -1, root);
            solve(l, r);
     }
     else
     {
         int m = cur.second;
         solve(l, m - 1);
         solve(m + 1, r);
     }
}

int main()
{
    int n;
    
    cin >> n;
    
    int a[n];
    
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    
    root = build(0, n - 1, a);
    
    solve(0, n - 1);
    
    cout << L.size() << endl;
    for(int i = 0; i < L.size(); ++i)
            cout << L[i] << " " << R[i] << endl;
    
    cin >> n;
    
    return 0;
}