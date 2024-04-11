/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
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
// using namespace __gnu_pbds;

int n, m, dis[200005], vis[200005], pre[200005];
pii ans[200005];
vector<pii> E[200005];
vector<int> sol[200005];

void dfs(int u)
{
    int cnt = 0, preid = 0;
    vis[u] = 1;
    for (auto [v, id] : E[u])
        if (!vis[v])
        {
            pre[v] = u;
            dis[u] = dis[v] + 1;
            dfs(v);
        }
    for (auto [v, id] : E[u])
        if (v == pre[u])
            preid = id;
        else if (ans[id] == pii{0, 0})
            ans[id] = {u, v}, cnt ^= 1;
    if (cnt && preid)
        ans[preid] = {u, pre[u]};
}

signed main()
{
    fast;
    int n;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(pii{v, i});
        E[v].emplace_back(pii{u, i});
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);
    for (int i = 1; i <= m; i++)
        sol[ans[i].F].emplace_back(ans[i].S);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += sol[i].size() / 2;
    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
        for (int j = 0; j + 1 < sol[i].size(); j += 2)
            cout << sol[i][j] << " " << i << " " << sol[i][j + 1] << '\n';
}