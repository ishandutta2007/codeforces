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

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair 
#define vec vector

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

const int LOG = 20;

vec<LL> mx[LOG], mn[LOG], a;
vec<int> _log, t, dp, pos;
int n;

void init()
{
    LL q = 0;
    while((1ll << q) <= n) q++;
    
    _log.resize(n + 1);

    for(int i(n);i >= 1;i--)
    {
        if((1ll << q) > i) q--;
        _log[i] = q;
    }

    mx[0].resize(n + 1);
    mn[0].resize(n + 1);

    for(int i(1);i <= n;i++) mx[0][i] = mn[0][i] = a[i];
    
    for(int i(1);i < LOG;i++)
    {
        mx[i].resize(n + 1);
        mn[i].resize(n + 1);
        for(int j(1);j <= n;j++)
        {
            if(j + (1ll << (i - 1)) > n) break;
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1ll << (i - 1))]);
            mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1ll << (i - 1))]);
        }
    }
}

LL get_diff(int l, int r)
{
    int len = r - l + 1;
    int lg = _log[len];

    LL A, B;

    A = max(mx[lg][l], mx[lg][r - (1ll << lg) + 1]);
    B = min(mn[lg][l], mn[lg][r - (1ll << lg) + 1]);

    return (A - B);
}

void up(int v, int tl, int tr, int ps, int val)
{
    if(tl == tr) t[v] = val, pos[v] = tl;
    else
    {
        int tm = (tl + tr) >> 1;

        if(ps <= tm) up(v << 1, tl, tm, ps, val);
        else up(v << 1 | 1, tm + 1, tr, ps, val);

        t[v] = min(t[v << 1], t[v << 1 | 1]);       
        pos[v] = (t[v << 1] == t[v]?pos[v << 1] : pos[v << 1 | 1]);
    }
}

pair<int, int> _get(int v, int tl, int tr, int l, int r)
{
    if(l <= tl && tr <= r) return mp(t[v], pos[v]);
    else
    {
        int tm = (tl + tr) >> 1;
        pair<int, int> L, R;
        L.first = R.first = inf;

        if(l <= tm) L = _get(v << 1, tl, tm, l, r);
        if(r > tm) R = _get(v << 1 | 1, tm + 1, tr, l, r);
    
        if(L.first <= R.first) return L;
        else return R;
    }
}

bool solve()
{
    LL s, l;

    cin >> n >> s >> l;

    if(l > n) 
    {
        puts("-1");
        return true;
    }

    a.resize(n + 1);

    for(int i(1);i <= n;i++) cin >> a[i];

    init();

    dp.resize(n + 1, inf);

    if(get_diff(1, l) > s)
    {
        puts("-1");
        return true;
    }

    t.resize(4 * n, inf);
    pos.resize(4 * n, -1);

    dp[l] = 1;
    dp[0] = 0;

    for(int i(1);i <= l;i++) up(1, 1, n, i, dp[i]);

    for(int i(l + 1);i <= n;i++)
    {
        int le, ri, mid, p;
        le = 1;
        ri = i;

        while(ri - le > 1)
        {
            mid = (le + ri) >> 1;

            if(get_diff(i - mid + 1, i) > s) ri = mid - 1;
            else le = mid;
        }
    
        p = (get_diff(i - ri + 1, i) <= s?ri : le);

        if(p == i)
        {
            dp[i] = 1;
            up(1, 1, n, i, dp[i]);
            continue;
        }else if(p >= l)
        {
            pair<int, int> _x = _get(1, 1, n, i - p, i - l);
            if(_x.first != inf)
            {
                dp[i] = _x.first + 1;
                up(1, 1, n, i, dp[i]);
                continue;
            }else
            {
                _x = _get(1, 1, n, i - p, i - 1);
                p = i - _x.second;
            }
        }

        // [i - p + 1 .. i - p + l]

        if(i - p + l > n || get_diff(i - p + 1, i - p + l) > s)
        {
            puts("-1");
            return true;
        }

        for(int C(l - p - 1), j(i);C >= 0;j++, C--) dp[j] = inf;
        dp[i - p + l] = dp[i - 1] + 1;

        for(int C(l - p), j(i);C >= 0;j++, C--) 
            up(1, 1, n, j, dp[j]);

        i = i - p + l;
        
    }

    cout << dp[n] << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}