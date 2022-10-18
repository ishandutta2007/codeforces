/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
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
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, dis[100005], pre[100005][25], size[100005], timer, rdp[100005];
pii t[100005];
ll dp[100005];
vector<int> edge[100005];

bool isanc(int a, int b)
{
    if (t[a].F <= t[b].F && t[b].S <= t[a].S)
        return true;
    return false;
}

int findchild(int a, int b) // find ancestor of a is child of b
{
    int lca = a;
    for (int i = __lg(dis[lca] + 1); i >= 0; i--)
        if (pre[lca][i] != 0 && !isanc(pre[lca][i], b))
            lca = pre[lca][i];
    return lca;
}

void dfs(int k)
{
    t[k].F = ++timer;
    for (int i = 1; i <= __lg(dis[k] + 1); i++)
        pre[k][i] = pre[pre[k][i - 1]][i - 1];
    for (int p : edge[k])
        if (p != pre[k][0])
        {
            pre[p][0] = k;
            dis[p] = dis[k] + 1;
            dfs(p);
            size[k] += size[p];
            dp[k] += dp[p];
        }
    dp[k] += dis[k];
    size[k]++;
    t[k].S = timer;
}

void dfs2(int k)
{
    for (int p : edge[k])
        if (p != pre[k][0])
        {
            rdp[p] = rdp[k] + (n - size[p]) - size[p];
            dfs2(p);
        }
}

signed main()
{
    fast;
    cout << fixed << setprecision(8);
    cin >> n >> m;
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    dfs(1);
    rdp[1] = dp[1];
    dfs2(1);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (isanc(x, y) || isanc(y, x))
        {
            if (dis[x] > dis[y])
                swap(x, y);
            int child = findchild(y, x);
            double ans = double(rdp[x] - (dp[child] - size[child] * dis[x])) / double(n - size[child]) +
                         double(1.0 * dp[y] / size[y]) - dis[x] + 1.0;
            cout << ans << '\n';
            continue;
        }
        int lca = findchild(x, y);
        if (!isanc(lca, y))
            lca = pre[lca][0];

        double ans = (dp[x] * 1.0 / size[x]) + (dp[y] * 1.0 / size[y]) - dis[lca] * 2.0 + 1.0;
        cout << ans << '\n';
    }
}