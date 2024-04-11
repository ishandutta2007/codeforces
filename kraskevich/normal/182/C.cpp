#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
using namespace std;

#define ll long long
#define sqr(a) (a) * (a)
#define S second
#define F first
#define MP make_pair
#define PB push_back

int p[200 * 1000];
int call = 0;

void init()
{
     for(int i = 0; i < 200 * 1000; ++i)
             p[i] = i;
     random_shuffle(p, p + 200 * 1000);
}

struct node
{
       ll key, f, pr, cnt;
       node * l, * r;
};
 
typedef node * pnode;
 
ll cnt(pnode t)
{
             return t ? t->cnt : 0;
}
 
ll f(pnode t)
{
           return t ? t->f : 0;
}
 
void up(pnode t)
{
     if(t)
     {
          t->cnt = cnt(t->l) + cnt(t->r) + 1;
          t->f = t->key + f(t->l) + f(t->r);
     }
}
 
void splitC(pnode t, pnode & l, pnode & r, ll val)
{
     if(!t)
           l = r = NULL;
     else
        if(t->key >= val)
        {
                  splitC(t->l, l, t->l, val);
                  r = t;
        }
        else
        {
            splitC(t->r, t->r, r, val);
            l = t;
        }
     up(t);
}
 
void splitUC(pnode t, pnode & l, pnode & r, ll add, int pos)
{
     if(!t)
           l = r = NULL;
     else
     {
         int cur = add + cnt(t->l);
         if(cur >= pos)
         {
                splitUC(t->l, l, t->l, add, pos);
                r = t;
         }
         else
         {
             splitUC(t->r, t->r, r, add + 1 + cnt(t->l), pos);
             l = t;
         }
     }
     up(t);
}
 
void merge(pnode & t, pnode l, pnode r)
{
     if(!l || !r)
           t = l ? l : r;
     else
     {
         if(l->pr > r->pr)
         {
                  merge(l->r, l->r, r);
                  t = l;
         }
         else
         {
             merge(r->l, l, r->l);
             t = r;
         }
     }
     up(t);
}

void push(pnode & t, pnode p)
{
     if(!t)
           t = p;
     else
     {
         if(t->pr < p->pr)
         {
                  splitC(t, p->l, p->r, p->key);
                  t = p;
         }
         else
             push(t->key >= p->key ? t->l : t->r, p);
     }
     up(t);
}

void del(pnode & t, int val)
{
     if(t)
     {
          if(t->key == val)
                    merge(t, t->l, t->r);
           else
               del(t->key >= val ? t->l : t->r, val);
     }
     up(t);
} 

ll getS(pnode t)
{
              return f(t);
}

ll upM(pnode t, int k)
{
       if(!t)
             return 0;
       pnode t1, t2;
       splitUC(t, t1, t2, 0, k);
       ll ans = -1 * f(t1) + f(t2);
       merge(t, t1, t2);
       return ans;
}

ll upP(pnode t, int k)
{
             if(!t)
                   return 0;
             pnode t1, t2;
             int cur = cnt(t) - k;
             splitUC(t, t1, t2, 0, cur);
             ll ans = (-1) * f(t2) + f(t1);
             merge(t, t1, t2);
             return ans;
}

void add(pnode & t, int val)
{
     node * nn = (node*)malloc(sizeof(node));
     nn->pr = p[call++];
     nn->cnt = 1;
     nn->f = val;
     nn->key = val;
     nn->l = nn->r = NULL;
     push(t, nn);
}
     
             

int main()
{
    init();
    
    ios_base::sync_with_stdio(0);
    
    int n, len, k;
    
    cin >> n >> len;
    
    ll a[n];
    
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    
    cin >> k;
    
    node * minus = NULL, *plus = NULL;
    for(int i = 0; i < len; ++i)
    {
            if(a[i] < 0)
                    add(minus, a[i]);
            else
                add(plus, a[i]);
    }
    
    ll best = 0;
    
    for(int l = 1, r = len;  r < n; l++, r++)
    {
            best = max((ll)fabs(getS(minus) +  getS(plus)), best);
            best = max((ll)fabs(getS(minus) + upP(plus, k)), best);
            best = max((ll)fabs(getS(plus) + upM(minus, k)), best);
            if(a[l - 1] >= 0)
                   del(plus, a[l - 1]);
            else
                del(minus, a[l - 1]);
            if(a[r] >= 0)
                    add(plus, a[r]);
            else
                add(minus, a[r]);
    } 
    
    best = max((ll)fabs(getS(minus) +  getS(plus)), best);
    best = max((ll)fabs(getS(minus) + upP(plus, k)), best);
    best = max((ll)fabs(getS(plus) + upM(minus, k)), best);
       
    cout << best << endl;
    
    cin >> n;
         
    return 0;
}