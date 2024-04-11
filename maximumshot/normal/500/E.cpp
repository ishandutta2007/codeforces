#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define what(x) cerr << #x << " = " << x << '\n';

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const int LOG = 20;

int n;
vec<LL> p, l, len, t;
vec<LL> par[LOG], cost[LOG];

void up(int v, int tl, int tr, int pos, LL x)
{
    if(tl == tr) t[v] = x;
    else
    {
        int tm = (tl + tr) >> 1;

        if(pos <= tm) up(v << 1, tl, tm, pos, x);
        else up(v << 1 | 1, tm + 1, tr, pos, x);

        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
}

LL get_mx(int v, int tl, int tr, int l, int r)
{
    if(l <= tl && tr <= r) return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        LL L, R;
        L = R = -inf64;

        if(l <= tm) L = get_mx(v << 1, tl, tm, l, r);
        if(r > tm) R = get_mx(v << 1 | 1, tm + 1, tr, l, r);

        return max(L, R);
    }
}
bool solve()
{
    cin >> n;

    p.resize(n + 2, inf64);
    l.resize(n + 2);
    len.resize(n + 2);
    p[0] = -inf64;
    t.resize(4 * n, -inf64);
    for(int i(1);i <= n;i++) cin >> p[i] >> l[i], len[i] = p[i] + l[i];
    for(int i(0);i < LOG;i++)
    {
        par[i].resize(n + 2, n + 1);
        cost[i].resize(n + 2, 0);
    }
 
    up(1, 1, n, n, len[n]);

    //puts("ok");

    for(int i(n - 1);i >= 1;i--)
    {
        int x = lower_bound(ALL(p), len[i] + 1) - p.begin() - 1;
        // [i .. x]

        LL cur = get_mx(1, 1, n, i, x);
        cur = max(cur, len[i]);

        up(1, 1, n, i, cur);

        int y = lower_bound(ALL(p), cur + 1) - p.begin();

        par[0][i] = y;
        cost[0][i] = (y == n + 1?0 : p[y] - cur);

        for(int j(1);j < LOG;j++)
        {
            par[j][i] = par[j - 1][par[j - 1][i]];
            cost[j][i] = cost[j - 1][par[j - 1][i]] + cost[j - 1][i];
        }
    }

    int q;

    cin >> q;

    while(q--)
    {
        int ql, qr, pos;

        cin >> ql >> qr;

        LL ans = 0;
        pos = ql;

        for(int i(LOG - 1);i >= 0;i--)
        {
            if(par[i][pos] <= qr)
            {
                ans += cost[i][pos];
                pos = par[i][pos];
            }
        }

        cout << ans << '\n';
    }

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}