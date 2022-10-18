/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
//using namespace __gnu_pbds;

int N, a[100005], b[100005], pre[100005], sz[100005];
ll dp[100005];
vector<int> E[100005];

struct Lseg
{
    vector<pll> seg, line;
    vector<int> l, r;
    int newnode()
    {
        seg.emplace_back(pll{0, 1e18});
        l.emplace_back(-1);
        r.emplace_back(-1);
        return seg.size() - 1;
    }
    void init()
    {
        newnode();
    }
    void modify(pll p, int i = 0, ll L = -1e5, ll R = +1e5)
    {
        if (p == pll{0, 1e18})
            return;
        if (i == 0)
            line.emplace_back(p);
        ll mid = (L + R) / 2;
        if (p.F * mid + p.S < seg[i].F * mid + seg[i].S)
            std::swap(p, seg[i]);
        if (L != R)
        {
            if (p.F >= seg[i].F)
            {
                if (l[i] == -1)
                    l[i] = newnode();
                modify(p, l[i], L, mid);
            }
            else
            {
                if (r[i] == -1)
                    r[i] = newnode();
                modify(p, r[i], mid + 1, R);
            }
        }
    }
    ll query(ll x, int i = 0, ll L = -1e5, ll R = 1e5)
    {
        if(i == -1)
            return 1e18;
        if (L == R)
            return seg[i].F * x + seg[i].S;
        ll mid = (L + R) / 2;
        if (x <= mid)
            return min(seg[i].F * x + seg[i].S, query(x, l[i], L, mid));
        else
            return min(seg[i].F * x + seg[i].S, query(x, r[i], mid + 1, R));
    }
    void swap(Lseg &T)
    {
        seg.swap(T.seg);
        line.swap(T.line);
        l.swap(T.l);
        r.swap(T.r);
    }
    void clear()
    {
        seg.clear();
        line.clear();
        l.clear();
        r.clear();
    }
} lct[100005];

void dfs(int k)
{
    sz[k] = 1;
    int mx = 0;
    for (int i : E[k])
        if (pre[k] != i)
        {
            pre[i] = k;
            dfs(i);
            sz[k] += sz[i];
            if (sz[i] > sz[mx])
                mx = i;
        }
    if (mx == 0)
    {
        dp[k] = 0;
        lct[k].init();
    }
    else
    {
        lct[k].swap(lct[mx]);
        for (int i : E[k])
            if (pre[k] != i && i != mx)
            {
                for(pll p : lct[i].line)
                    lct[k].modify(p);
                lct[i].clear();
            }
        dp[k] = lct[k].query(a[k]);
    }
    lct[k].modify(pll{b[k], dp[k]});
}

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i <= N; i++)
        cin >> b[i];
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    dfs(1);
    for (int i = 1; i <= N; i++)
        cout << dp[i] << " \n"[i == N];
}