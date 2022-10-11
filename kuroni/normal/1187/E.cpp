#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, u, v, sub[N];
long long ans = 0, f[N], g[N];
vector<int> adj[N];

int DFS_1(int u, int p = 0)
{
    sub[u] = 1;
    for (int &v : adj[u])
        if (v != p)
        {
            sub[u] += DFS_1(v, u);
            f[u] += f[v] + sub[v];
        }
    return sub[u];
}

void DFS_2(int u, int p = 0)
{
    for (int &v : adj[u])
        if (v != p)
        {
            g[v] = g[u];
            g[v] += n - sub[v];
            g[v] += f[u] - (f[v] + sub[v]);
            DFS_2(v, u);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS_1(1);
    DFS_2(1);
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i] + g[i]);
    cout << ans + n;
}