#include <iostream>
#include <cstdio>
#include <vector>
#define fi first
#define se second
using namespace std;

const int N = 200005;

int n, u, v, w, f[N][2], g[N][2];
long long ans = 0;
vector<pair<int, int>> adj[N];

void DFS_1(int u, int p = 0)
{
    for (pair<int, int> &v : adj[u])
        if (v.fi != p)
        {
            DFS_1(v.fi, u);
            f[u][v.se] += f[v.fi][v.se] + 1;
        }
}

void DFS_2(int u, int p = 0)
{
    for (pair<int, int> &v : adj[u])
        if (v.fi != p)
        {
            g[v.fi][v.se] += g[u][v.se] + 1;
            g[v.fi][v.se] += f[u][v.se] - f[v.fi][v.se] - 1;
            DFS_2(v.fi, u);
        }
    ans += 1LL * (f[u][0] + g[u][0] + 1) * (f[u][1] + g[u][1] + 1) - 1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    DFS_1(1);
    DFS_2(1);
    printf("%lld", ans);
}