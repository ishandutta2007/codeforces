#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
using namespace std;
/*
BE CAREFUL: ISN'T INT EQUAL TO LONG LONG?

REAL SOLUTION AFTER MAIN FUNCTION
*/
#define mp make_pair
#define pb push_back
typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
void solve();

int main ()
{
       
#ifdef _DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int t=1;
    while (t--)
                solve();
    return 0;
}

#define int li

struct treap
{
    typedef struct _node
    {
        int x, y;
        int val;
		int mincost;
        int add;
        _node *l, *r;
        _node () {  l=0; r=0; x=0; y=(rand()<<16)|rand(); add=0; mincost=(1LL<<55); }
        _node (int X, int Val):x(X), l(0), r(0), val(Val) { y=(rand()<<16)|rand(); add=0; mincost=Val; }
        void recalc()   
        {
			mincost=val;
            if (l)
                mincost=min(mincost, l->mincost + l->add);
            if (r)
                mincost=min(mincost, r->mincost + r->add);
        }
    }*node;

    node root;

    treap ():root(0){}

    node merge (node l, node r)
    {
            if (l==0)
                    return r;
            if (r==0)
                    return l;
            if (l->y < r->y)
            {
                    l->mincost += l->add;
					l->val += l->add;
                    if (l->l)
                        l->l->add += l->add;
                    if (l->r)
                        l->r->add += l->add;
                    l->add=0;
                    l->r=merge ( l->r, r );
                    l->recalc();
                    return l;
            }
            else
            {
                    r->mincost += r->add;
					r->val += r->add;
                    if (r->l)
                        r->l->add += r->add;
                    if (r->r)
                        r->r->add += r->add;
                    r->add=0;
                    r->l=merge ( l, r->l );
                    r->recalc();
                    return r;
            }
    }
    void split (node t, int key, node &l, node &r)
    {
            l=r=0;
            if (t==0)
                    return;
            node tmp;
            if ( t->x > key )
            {
                    r=t;
                    r->mincost += r->add;
					r->val += r->add;
                    if (r->l)
                        r->l->add += r->add;
                    if ( r->r )
                        r->r->add += r->add;
                    r->add=0;
                    split (r->l, key, l, tmp);
                    r->l=tmp;
                    r->recalc();
            }
            else
            {
                    l=t;
                    l->mincost += l->add;
					l->val += l->add;
                    if (l->l)
                        l->l->add += l->add;
                    if (l->r)
                        l->r->add += l->add;
                    l->add=0;
                    split (l->r, key, tmp, r);
                    l->r=tmp;
                    l->recalc();
            }
    }
    void insert (int key, int val)
    {
            node l=0, r=0;
            split (root, key, l, r);
            root=merge (merge(l, new _node(key, val)), r);
    }
    void modify (int ll, int rr, int val)
    {
            node l, r;
            split (root, ll-1, l, r);
            node l1, l2;
            split (r, rr, l1, l2);
            l1->add += val;
            root=merge ( merge (l, l1), l2 );
    }
    int rmq (int ll, int rr)
    {
            node l=0, r=0;
            split (root, ll-1, l, r);
            node l1=0, l2=0;
            split (r, rr, l1, l2);
            int ans=(l1->mincost + l1->add);
            root=merge( merge (l, l1), l2 );
            return ans;
    }
};

int n;

treap tree;


int m;
int q, w, r;
char c;

void solve ()
{
        cin>>n;
        
        for (int i=0; i<n; i++)
        {
                cin>>q;
                tree.insert(i, q);
        }

       
        cin>>m;
        for (int i=0; i<m; i++)
           {
                    cin>>q>>w;
                    c=getchar();
                    if (c==' ')
                    {
                            cin>>r;
                            if (q<=w)
                                    tree.modify ( q, w, r );
                            else
                                    tree.modify (q, n-1, r), tree.modify(0, w, r);
                    }
                    else
                    {
                            if (q<=w)
                                    cout<<tree.rmq(q, w)<<endl;
                            else
                                    cout<<min ( tree.rmq(q, n-1), tree.rmq(0, w) )<<endl;
                    }
            }
}