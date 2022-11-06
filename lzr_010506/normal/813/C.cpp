#include <bits/stdc++.h>
using namespace std;
vector<int> g[200010];
int Dep[200010], h[200010], Dis[200010];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void dfs(int v, int p, int x)
{
    h[v] = x;
    Dep[v] = 0;
    for(int i = 0; i < g[v].size(); i ++)
    {
        int to = g[v][i];
        if (to == p) continue;
        dfs(to, v, x + 1);
        Dep[v] = max(Dep[v], Dep[to] + 1);
    }
}


void dfs2(int v, int p, int x)
{
    Dis[v] = x;
    for(int i = 0; i < g[v].size(); i ++)
    {
        int to = g[v][i];
        if (to == p) continue;
        dfs2(to, v, x + 1);
    }
}

int main()
{
    int n, x;
    n = read();
    x = read();
    x --;
    for (int i = 0; i < n - 1; i ++)
    {
        int u, v;
        u = read();
        v = read();
        u --;
        v --;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 0, 0);
    dfs2(x, x, 0);
    int ans = 0;
    for (int v = 0; v < n; v ++)
        if (Dis[v] < h[v])
            ans = max(ans, 2 * h[v]);
    cout << ans;
    return 0;
}