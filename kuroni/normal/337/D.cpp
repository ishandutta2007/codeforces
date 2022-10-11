#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

queue <int> q;
vector <int> adj[100005], nodes;
int par[100005], n, m, d, f[100005], g[100005], pre[100005], suf[100005], ans = 0;
bool boom[100005];
const int INF = 1000000000;

void BFS(int x)
{
    q.push(x);
    par[x] = -1;
    while (!q.empty())
    {
        int u = q.front();
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if (par[u] == v) continue;
            q.push(v);
            par[v] = u;
        }
        nodes.push_back(u);
        q.pop();
    }
}

int main()
{
	scanf("%d%d%d", &n, &m, &d);
	int x, y;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &x);
        boom[x] = true;
    }
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    BFS(1);
    for (int i = nodes.size() - 1; i >= 0; i--)
    {
        int u = nodes[i];
        f[u] = -INF;
        if (boom[u])
            f[u] = 0;
        for (int j = 0; j < adj[u].size(); j++)
        {
            int v = adj[u][j];
            if (par[u] == v) continue;
            if (f[v] >= 0) f[u] = max(f[u], f[v] + 1);
        }
    }
    for (int i = 0; i < nodes.size(); i++)
    {
        int u = nodes[i];
        //cout << u << " " << f[u] << '\n';
        for (int j = 0; j < adj[u].size(); j++)
        {
            int v = adj[u][j];
            if (par[u] == v) pre[j + 1] = g[u] + 1;
            else pre[j + 1] = f[v] + 1;
            suf[j + 1] = pre[j + 1];
        }
        pre[0] = suf[adj[u].size() + 1] = -INF;
        for (int j = 1; j <= adj[u].size(); j++) pre[j] = max(pre[j], pre[j - 1]);
        for (int j = adj[u].size(); j > 0; j--) suf[j] = max(suf[j], suf[j + 1]);
        f[u] = max(f[u], suf[1]);
        for (int j = 0; j < adj[u].size(); j++)
        {
            int v = adj[u][j];
            if (par[u] == v) continue;
            g[v] = max(pre[j], suf[j + 2]);
            if (boom[u]) g[v] = max(g[v], 0);
        }
        //cout << u << " " << f[u] << '\n';
        if (f[u] <= d) ans++;
    }
    printf("%d", ans);
	return 0;
}