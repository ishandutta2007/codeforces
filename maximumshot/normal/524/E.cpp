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
const LL base = inf + 7;
  
vec<int> t;
int n, m, k, q;

void up(int v, int tl, int tr, int pos, int val)
{
    if(tl == tr) t[v] = val;
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm) up(v << 1, tl, tm, pos, val);
        else up(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
}

int get(int v, int tl, int tr, int l, int r)
{
    if(l <= tl && tr <= r) return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        LL L, R;
        L = R = inf;
        if(l <= tm) L = get(v << 1, tl, tm, l, r);
        if(r > tm) R = get(v << 1 | 1, tm + 1, tr, l, r);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
        return min(L, R);
    }
}

bool solve()
{
    scanf("%d%d%d%d", &n, &m, &k, &q);

    vec< vec<int> > x(n + 1), y(m + 1);
    vec< vec<int> > l, r;
    vec< pair< pair<int, int>, pair<int, int> > > crd(q);
    vec<int> ans(q, 0);

    for(int i(0);i < k;i++)
    {
        int tx, ty;
        scanf("%d %d", &tx, &ty);
        x[tx].push_back(ty);
        y[ty].push_back(tx);
    }

    l.resize(n + 1);
    r.resize(m + 1);

    for(int i(0);i < q;i++)
    {
        int tx1, tx2, ty1, ty2;
        scanf("%d%d%d%d", &tx1, &ty1, &tx2, &ty2);
        crd[i] = mp(mp(tx1, ty1), mp(tx2, ty2));
        l[tx2].push_back(i);
        r[ty2].push_back(i);
    }

    t.clear();
    t.resize(4 * (m + 1), -inf);

    for(int i(1);i <= n;i++)
    {
        for(int j(0);j < (int)x[i].size();j++)
        {
            int pos = x[i][j], val = i;
            up(1, 1, m, pos, val);
        }

        for(int j(0);j < (int)l[i].size();j++)
        {
            int id = l[i][j], le, ri;
            le = crd[id].first.second;
            ri = crd[id].second.second;
            int val = get(1, 1, m, le, ri);
            if(val >= crd[id].first.first) ans[id] = 1;
        }
    }

    t.clear();
    t.resize(4 * (n + 1), -inf);

    for(int i(1);i <= m;i++)
    {
        for(int j(0);j < (int)y[i].size();j++)
        {
            int pos = y[i][j], val = i;
            up(1, 1, n, pos, val);
        }

        for(int j(0);j < (int)r[i].size();j++)
        {
            int id = r[i][j], le, ri;
            le = crd[id].first.first;
            ri = crd[id].second.first;
            int val = get(1, 1, n, le, ri);
            if(val >= crd[id].first.second) ans[id] = 1;
        }
    }

    for(int i(0);i < q;i++) puts(ans[i]?"YES":"NO");

    return true;
}
   
int main()
{
    //while(solve());
    solve();
   
    return 0;
}