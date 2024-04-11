/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC comment(linker,"/stack:200000000")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N, M, dp[200005], dis[200005];
bool vis[200005];
vector<int> e[200005];

void init()
{
    for (int i = 1; i <= N; i++)
    {
        dp[i] = 0;
        vis[i] = 0;
        dis[i] = 0;
    }
    for (int i = 1; i <= N; i++)
        e[i].clear();
}

void dfs(int k)
{
    vis[k] = 0;
    for (int i : e[k])
    {
        if (vis[i] && dis[i] > dis[k])
            dfs(i);
        if (dis[i] > dis[k])
            dp[k] = min(dp[k], dp[i]);
        if (dis[i] <= dis[k])
            dp[k] = min(dp[k], dis[i]);
    }
}

void solve()
{

    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].pb(y);
    }
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    vis[1] = 1;
    while (!q.empty())
    {
        for (int i : e[q.front()])
            if (!vis[i])
            {
                dis[i] = dis[q.front()] + 1;
                vis[i] = 1;
                q.push(i);
            }
        q.pop();
    }
    for (int i = 1; i <= N; i++)
        dp[i] = dis[i];
    dfs(1);
    for (int i = 1; i <= N; i++)
        cout << dp[i] << " \n"[i == N];
}

signed main()
{
    fast;
    int T;
    cin >> T;
    while (T--)
    {
        init();
        solve();
    }
}