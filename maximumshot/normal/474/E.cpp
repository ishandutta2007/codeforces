// by maximumSHOT
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string>
#include <fstream>
#include <stdio.h>

#include <conio.h>
 
using namespace std;
 
#define ALL(x) (x).begin(), (x).end()
#define vec vector
#define mp make_pair
#define close() puts("Ok!\n"); return true;
 
typedef long long LL;
typedef long double LD;
 
const LL inf = 1000000000000000000ll;
//const LL inf64 = inf * inf;
const LL base = inf / 10ll;
 
LL Abs(LL x) {return (x >= 0?x : -x);}

int n, d;
vec<int> dp, from;
vec<LL> h;

struct treap
{
    int x, id;
    LL y;
    treap *l, *r;

    treap()
    {
        x = id = -1;
        y = rand() % inf;
        l = r = 0;
    }

    treap(int xx, int iid) : x(xx), id(iid), y(rand() % inf), l(0), r(0) {}

    void print()
    {
        if(l) l->print();
        if(r) r->print();
        cout << x << ' ' << h[x] << ' ' << id << ' ' << dp[id] << '\n';
    }
};

void update(treap*& v)
{
    int q = v->x;

    if(v->l) q = (dp[q] >= dp[v->l->id]?q : v->l->id);
    if(v->r) q = (dp[q] >= dp[v->r->id]?q : v->r->id);

    v->id = q;
}

void merge(treap*& v, treap *l, treap *r)
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

    update(v);
}

void split(treap* v, treap*& l, treap*& r, LL x)
{
    if(!v) 
    {
        l = r = 0;
        return;
    }

    if(h[v->x] <= x)
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

int get_from_lower(treap*& v, LL x) // x - 
{
    treap *l, *r;

    split(v, l, r, x - d);

    int ans = (l?l->id : -1);

    merge(v, l, r);

    return ans;
}

int get_from_upper(treap*& v, LL x)
{
    treap *l, *r;

    split(v, l, r, x + d - 1);

    int ans = (r?r->id : -1);

    merge(v, l, r);

    return ans;
}

void insert(treap*& v, treap* val)
{
    treap *l, *r;

    split(v, l, r, h[val->x]);

    merge(l, l, val);
    merge(v, l, r);
}

void pr(int x)
{
    if(x == -1) return;
    pr(from[x]);
    cout << x << ' ';
}

bool solve()
{
    ios_base::sync_with_stdio(0);

    cin >> n >> d;

    h.resize(n + 1);
    dp.resize(n + 1);
    from.resize(n + 1, -1);

    for(int i(1);i <= n;i++) cin >> h[i];

    dp[1] = 1;

    int u, d;

    treap *T = new treap(1, 1);

    //cout << "\n\n";

    for(int i(2);i <= n;i++)
    {
        //cout << h[i] << '\n';
        d = get_from_lower(T, h[i]);
        u = get_from_upper(T, h[i]);

        //cout << d << ' ' << u << '\n';

        if(d == -1 && u == -1) dp[i] = 1;
        else if(d == -1) dp[i] = dp[u] + 1, from[i] = u;
        else if(u == -1) dp[i] = dp[d] + 1, from[i] = d;
        else
        {
            if(dp[d] >= dp[u]) dp[i] = dp[d] + 1, from[i] = d;
            else dp[i] = dp[u] + 1, from[i] = u;
        }

        insert(T, new treap(i, i));

        //T->print();
        //cout << "---------\n";
    }

    int ans = -1;

    //for(int i(1);i <= n;i++) cout << dp[i] << ' ';
    //cout << '\n';

    for(int i(1);i <= n;i++) if(ans == -1 || dp[ans] < dp[i]) ans = i;

    cout << dp[ans] << '\n';

    pr(ans);

    return true;
}
 
int main()
{
    //while(solve());
    solve();
 
    return 0;
}