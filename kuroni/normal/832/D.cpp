#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int n, q, a, b, c, i, x, y, z, u, h[100005], cur, ans;
vector <int> adj[100005], par[100005];
bool visit[100005];

void DFS(int a, int p)
{
    visit[a] = true;
    int i;
    if (a != 1)
    {
        h[a] = h[p] + 1;
        par[a].push_back(p);
        for (i = 1; (1 << i) <= h[a]; i++)
            par[a].push_back(par[par[a][i - 1]][i - 1]);
    }
    for (i = 0; i < adj[a].size(); i++)
        if (!visit[adj[a][i]])
            DFS(adj[a][i], a);
}

int LCA(int x, int y)
{
    int i, j;
    if (h[x] < h[y])
        swap(x, y);
    for (i = 0; (1 << i) <= h[x] - h[y]; i++)
    {
        if (((h[x] - h[y]) >> i) & 1)
            x = par[x][i];
    }
    if (x == y)
        return x;
    for (i = 0; (1 << i) <= h[x]; i++)
        j = i;
    for (i = j; i >= 0; i--)
        if ((1 << i) <= h[x])
            if (par[x][i] != par[y][i])
            {
                x = par[x][i];
                y = par[y][i];
            }
    return par[x][0];
}

int abs(int a)
{
    return (a < 0) ? -a : a;
}

int main()
{
    memset(visit, 0, sizeof(visit));
    h[1] = 0;
    scanf("%d%d", &n, &q);
    for (i = 2; i <= n; i++)
    {
        scanf("%d", &u);
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    DFS(1, 0);
    while (q--)
    {
        scanf("%d%d%d", &a, &b, &c);
        x = LCA(a, b);
        y = LCA(b, c);
        z = LCA(a, c);
        if (h[x] >= h[y] && h[x] >= h[z])
            cur = x;
        else if (h[y] >= h[x] && h[y] >= h[z])
            cur = y;
        else cur = z;
        ans = 0;
        x = LCA(a, cur);
        ans = max(ans, h[a] + h[cur] - 2 * h[x]);
        x = LCA(b, cur);
        ans = max(ans, h[b] + h[cur] - 2 * h[x]);
        x = LCA(c, cur);
        ans = max(ans, h[c] + h[cur] - 2 * h[x]);
        printf("%d\n", ans + 1);
    }
    return 0;
}