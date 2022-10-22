
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>
 
using namespace std;
 
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair 
#define vec vector
 
typedef long long LL;
typedef long double LD;
 
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

struct Node
{
    LL y, tl, tr, val, mx, ind, id, x;
    Node *l, *r;

    Node()
    {
        x = 0;
        l = r = 0;
        y = rand() % inf64;
        tl = tr = -1;
        val = 0;
        mx = -inf64;
        ind = id = -1;
    }

    Node(LL _tl, LL _tr, LL _x, LL _val, LL _id) 
    {
        y = rand() % inf64;
        tl = _tl;
        tr = _tr;
        val = _val;
        l = r = 0;
        mx = val;
        id = ind = _id;
        x = _x;
    }

    ~Node()
    {
        if(l) delete l;
        if(r) delete r;
    }
};

void update(Node *& v)
{
    LL mx, id;
    mx = v->val;
    id = v->id;

    if(v->l)
    {
        if(v->l->mx > mx)
        {
            mx = v->l->mx;
            id = v->l->ind;
        }
    }

    if(v->r)
    {
        if(v->r->mx > mx)
        {
            mx = v->r->mx;
            id = v->r->ind;
        }
    }

    v->ind = id;
    v->mx = mx;
}

void merge(Node *& v, Node *l, Node *r)
{
    if(!l || !r)
    {
        v = (l?l : r);
        return;
    }

    if(l->y >= r->y)
    {
        merge(l->r, l->r, r);
        v = l;
    }else
    {
        merge(r->l, l, r->l);
        v = r;
    }

    if(v) update(v);
}

void split(Node *v, Node *& l, Node *& r, LL x)
{
    if(!v)
    {
        l = r = 0;
        return;
    }

    if(v->tr <= x)
    {
        split(v->r, v->r, r, x);
        l = v;
    }else
    {
        split(v->l, l, v->l, x);
        r = v;
    }

    if(l) update(l);
    if(r) update(r);
}

bool solve()
{
    int n;
    scanf("%d", &n);
    
    Node *t, *nl, *nm, *nr;
    t = 0;

    vec< pair<LL, pair<pair<LL, LL>, LL> > > seg;

    for(int i(0);i < n;i++)
    {
        LL x, w, l, r;
        scanf("%I64d %I64d", &x, &w);

        l = x - w;
        r = x + w;

        seg.push_back(mp(x, mp(mp(l, r), i)));
    }

    vec<LL> dp(n, 0);

    sort(ALL(seg));

    for(int i(0);i < n;i++)
    {
        LL x, l, r, id;
        x = seg[i].first;
        l = seg[i].second.first.first;
        r = seg[i].second.first.second;
        id = seg[i].second.second;
        
        //cout << l << ' ' << x << ' ' << r << ' ' << id << '\n';

        nl = nm = nr = 0;

        split(t, nl, nr, l);

        if(nl)
        {
            LL mx = nl->mx;
            dp[id] = mx + 1;
        }else dp[id] = 1;

        merge(t, nl, nr);
        nl = nm = nr = 0;

        split(t, nl, nr, r);
        merge(nl, nl, new Node(l, r, x, dp[id], id));
        merge(t, nl, nr);
    }

    LL ans = *max_element(ALL(dp));

    printf("%I64d\n", ans);

    return true;
}
 
int main()
{
    //while(solve());
    solve();
 
    return 0;
}