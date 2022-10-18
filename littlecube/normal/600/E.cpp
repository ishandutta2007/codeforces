/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
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
using namespace __gnu_pbds;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll N, pre[100005], bigsub[100005], Size[100005], dp[100005], mx[100005], color[100005];
map<int, int> g[100005];
vector<int> e[100005];

void dfs(int k)
{
    for (int i : e[k])
        if (pre[k] != i)
        {
            pre[i] = k;
            dfs(i);
            Size[k] += Size[i];
        }
    Size[k]++;
    for (int i : e[k])
        if (pre[k] != i)
            if (Size[i] > Size[bigsub[k]])
                bigsub[k] = i;
}

void dfs2(int k)
{
    for (int i : e[k])
        if (pre[k] != i)
            dfs2(i);

    if (bigsub[k] != 0)
    {
        g[k].swap(g[bigsub[k]]);
        mx[k] = mx[bigsub[k]];
        dp[k] = dp[bigsub[k]];
    }

    g[k][color[k]]++;
    if (g[k][color[k]] > mx[k])
        dp[k] = 0, mx[k] = g[k][color[k]];
    if (g[k][color[k]] == mx[k])
        dp[k] += color[k];
    
    for (int i : e[k])
        if (pre[k] != i && i != bigsub[k])
        {
            for (pii j : g[i])
            {
                g[k][j.F] += j.S;
                if (g[k][j.F] > mx[k])
                    dp[k] = 0, mx[k] = g[k][j.F];
                if (g[k][j.F] == mx[k])
                    dp[k] += j.F;
            }
            g[i].clear();
        }
}

void dfs3(int k)
{
    for (int i : e[k])
        if (pre[k] != i)
        {
            dfs3(i);
            dp[k] += dp[i];
        }
}

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> color[i];
    for (int i = 1; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1);
    dfs2(1);
    //dfs3(1);
    ll ans = 0;
    for (int i = 1; i <= N; i++)
        cout << dp[i] << ' ';
}