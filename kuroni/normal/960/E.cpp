#include <bits/stdc++.h>
using namespace std;

const int N = 200005, MOD = 1E9 + 7;

vector<int> adj[N];
int n, u, v, a[N];
long long ans, f[N][2], g[N][2];

void DFS(int u, int p = 0)
{
    f[u][1] = a[u]; g[u][1] = 1;
    for (int &v : adj[u])
        if (v != p)
        {
            DFS(v, u);
            (ans += f[u][0] * g[v][1] + f[v][1] * g[u][0]) %= MOD;
            (ans += f[u][1] * g[v][0] + f[v][0] * g[u][1]) %= MOD;
            (f[u][0] += f[v][1] - a[u] * g[v][1]) %= MOD;
            (f[u][1] += f[v][0] + a[u] * g[v][0]) %= MOD;
            (g[u][0] += g[v][1]) %= MOD;
            (g[u][1] += g[v][0]) %= MOD;
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    (ans *= 2) %= MOD;
    for (int i = 1; i <= n; i++)
        (ans += a[i]) %= MOD;
    cout << (ans + MOD) % MOD;
}