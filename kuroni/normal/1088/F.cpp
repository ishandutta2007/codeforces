#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 500005, INF = 1E9 + 7;

pair<int, int> mi = make_pair(INF, 0);
int n, h[N] = {-1}, a[N], par[N][20];
long long ans = 0;
vector<int> adj[N];

long long get(int u, int v, int k)
{
    return 1LL * a[v] * (k + 1) + a[u];
}

void DFS(int u, int p = 0)
{
    h[u] = h[p] + 1;
    if (p != 0)
    {
        long long cur = get(u, par[u][0] = p, 0);
        for (int i = 1; (1 << i) <= h[u]; i++)
            cur = min(cur, get(u, par[u][i] = par[par[u][i - 1]][i - 1], i));
        cur = min(cur, get(u, mi.second, 32 - __builtin_clz(h[u] - 1)));
        ans += cur;
    }
    for (int &v : adj[u])
        if (v != p)
            DFS(v, u);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        mi = min(mi, make_pair(a[i], i));
    }
    for (int u, v, i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(mi.second);
    printf("%lld", ans);
}