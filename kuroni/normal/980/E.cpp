#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1000005;

int n, k, u, v, h[N];
vector<int> adj[N], par[N];
bool vis[N];

void DFS(int u, int p = 0)
{
    if (p != 0)
    {
        h[u] = h[p] + 1;
        par[u].push_back(p);
        for (int i = 1; (1 << i) <= h[u]; i++)
            par[u].push_back(par[par[u][i - 1]][i - 1]);
    }
    for (int &v : adj[u])
        if (v != p)
            DFS(v, u);
}

int find_ans(int u)
{
    if (vis[u])
        return 0;
    int ret = 1;
    for (int i = 20; i >= 0; i--)
        if ((1 << i) <= h[u] && !vis[par[u][i]])
        {
            u = par[u][i];
            ret += (1 << i);
        }
    return ret;
}

void del(int u)
{
    while (!vis[u])
    {
        vis[u] = true;
        --k;
        if (u == n)
            return;
        u = par[u][0];
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    k = n - k;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(n);
    for (int i = n; i >= 1; i--)
        if (find_ans(i) <= k)
            del(i);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            printf("%d ", i);
}