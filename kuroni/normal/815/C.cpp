#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const long long INF = 1e15;

int n, b, i, j, c[5005], d[5005], x, ans = 0, child[5005];
long long f[5005][5005], g[5005][5005];
vector <int> adj[5005];

void DFS(int u)
{
    child[u] = 1;
    fill(f[u], f[u] + n + 1, INF); fill(g[u], g[u] + n + 1, INF);
    int i, j;
    f[u][0] = 0; f[u][1] = c[u];
    g[u][1] = c[u] - d[u];
    for (int v: adj[u])
    {
        DFS(v);
        for (i = child[u] + child[v]; i >= 1; i--)
            for (j = max(0, i - child[v]); j <= min(i, child[u]); j++)
            {
                f[u][i] = min(f[u][i], f[u][j] + f[v][i - j]);
                g[u][i] = min(g[u][i], g[u][j] + g[v][i - j]);
            }
        child[u] += child[v];
    }
    for (i = 0; i <= child[u]; i++)
        g[u][i] = min(g[u][i], f[u][i]);
}

int main()
{
    scanf("%d%d", &n, &b);
    scanf("%d%d", c + 1, d + 1);
    for (i = 2; i <= n; i++)
    {
        scanf("%d%d%d", c + i, d + i, &x);
        adj[x].push_back(i);
    }
    DFS(1);
    for (i = 0; i <= n; i++)
    {
        if (f[1][i] <= b)
            ans = max(ans, i);
        if (g[1][i] <= b)
            ans = max(ans, i);
    }
    printf("%d", ans);
}