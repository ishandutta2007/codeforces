#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, vis[1000006], dis[1000006], sol[500005];
vector<int> E[1000006];

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        E[v << 1].emplace_back(u << 1 ^ c);
        E[v << 1 | 1].emplace_back(u << 1 ^ c);
    }
    for (int i = 2; i <= 2 * n + 1; i++)
        dis[i] = 1e9;
    queue<int> q;
    q.push(n << 1);
    q.push(n << 1 ^ 1);
    dis[n << 1] = 0;
    dis[n << 1 ^ 1] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        if (!vis[u ^ 1])
        {
            sol[u >> 1] = (u & 1) ^ 1;
            continue;
        }
        for (int i : E[u])
            if (dis[u] + 1 < dis[i])
            {
                dis[i] = dis[u] + 1;
                q.push(i);
            }
    }
    cout << (max(dis[2], dis[3]) >= 1e9 ? -1 : max(dis[2], dis[3])) << '\n';
    for (int i = 1; i <= n; i++)
        cout << sol[i];
}