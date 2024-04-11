#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1000005;

int n, k, u, f[N], g[N], h[N];
vector<int> adj[N];

void DFS(int u)
{
    if (adj[u].empty())
    {
        f[u] = g[u] = 1;
        h[u] = k;
    }
    for (int &v : adj[u])
    {
        DFS(v);
        if (h[v] > 0)
        {
            g[u] += g[v];
            h[u] = max(h[u], h[v] - 1);
        }
    }
    for (int &v : adj[u])
        if (h[v] > 0)
            f[u] = max(f[u], g[u] - g[v] + f[v]);
        else
            f[u] = max(f[u], g[u] + f[v]);
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &u);
        adj[u].push_back(i);
    }
    DFS(1);
    printf("%d", max(f[1], g[1]));
}