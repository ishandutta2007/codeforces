#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, q, i, u, v, t, x, l = 0, ans[1000005];
vector <int> adj[1000005];

void DFS(int u, int val)
{
    ans[u] = val;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (ans[v] == 0)
        DFS(v, min(v, val));
    }
}

int main()
{
    scanf("%d%d", &n, &q);
    for (i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v); adj[v].push_back(u);
    }
    scanf("%d%d", &t, &x);
    x = (x + l) % n + 1;
    DFS(x, x);
    int cur = x;
    while (--q)
    {
        scanf("%d%d", &t, &x);
        x = (x + l) % n + 1;
        if (t == 1)
            cur = min(cur, ans[x]);
        else
        {
            l = min(cur, ans[x]);
            printf("%d\n", l);
        }
    }
}