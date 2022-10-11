#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, m, i, t = 0, s = 0, cnt = 0, c[300005], d[300005], f[300005];
vector <pair <int, int>> adj[300005];
vector <int> res[300005];
bool ans[300005];

void DFS_1(int u, int p)
{
    c[u] = p;
    for (int i = 0; i < adj[u].size(); i++)
    {
        pair <int, int> cur = adj[u][i]; int v = cur.first;
        if (c[v] == 0)
        {
            ++f[u]; f[u] %= 2;
            ++f[v]; f[v] %= 2;
            res[u].push_back(v);
            DFS_1(v, cur.second);
        }
    }
}

void DFS_2(int u, int p)
{
    for (int v: res[u])
        DFS_2(v, u);
    if (d[u] == f[u] && u > 1)
    {
        ans[c[u]] = true;
        ++cnt;
    }
    else
    {
        ++f[u]; f[u] %= 2;
        ++f[p]; f[p] %= 2;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", d + i);
        s += d[i] + 2; s %= 2;
        if (d[i] == -1)
        {
            t = i;
            d[i] = 1;
        }
    }
    for (i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(make_pair(v, i));
        adj[v].push_back(make_pair(u, i));
    }
    if (s == 1)
    {
        if (t == 0)
        {
            printf("-1");
            return 0;
        }
        else d[t] = 0;
    }
    DFS_1(1, -1);
    DFS_2(1, -1);
    printf("%d\n", cnt);
    for (i = 1; i <= m; i++)
        if (ans[i])
            printf("%d\n", i);
}