#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define INF 200000000
using namespace std;

int n, m, i, j, u, v, c, s = 0, t, cf[300][300], mf[300][300], sum = 0, ans = 0, trace[300];
bool chk[300];
vector <int> adj[300];

bool BFS()
{
    memset(chk, 0, sizeof(chk));
    memset(trace, -1, sizeof(trace));
    queue <int> q;
    chk[s] = 1; q.push(s);
    int u, v, i;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (i = 0; i < adj[u].size(); i++)
        {
            v = adj[u][i];
            if (!chk[v] && cf[u][v] < mf[u][v])
            {
                q.push(v);
                chk[v] = 1;
                trace[v] = u;
                if (v == t)
                    return 1;
            }
        }
    }
    return 0;
}

int solve()
{
    int p = 1000005, v = t, u, i;
    while (v != s)
    {
        u = trace[v];
        p = min(p, mf[u][v] - cf[u][v]);
        v = u;
    }
    v = t;
    while (v != s)
    {
        u = trace[v];
        cf[u][v] += p;
        cf[v][u] -= p;
        v = u;
    }
    return p;
}

int main()
{
    memset(mf, 0, sizeof(mf));
    memset(cf, 0, sizeof(cf));
    scanf("%d%d", &n, &m);
    t = 2 * n + 1;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &u);
        mf[0][i] = u;
        sum += u;
        adj[0].push_back(i); adj[i].push_back(0);
        mf[i][i + n] = INF;
        adj[i].push_back(i + n); adj[i + n].push_back(i);
    }
    for (i = n + 1; i <= 2 * n; i++)
    {
        scanf("%d", &u);
        ans += u;
        mf[i][t] = u;
        adj[i].push_back(t); adj[t].push_back(i);
    }
    if (ans != sum)
    {
        printf("NO\n");
        return 0;
    }
    ans = 0;
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        mf[u][v + n] = mf[v][u + n] = INF;
        adj[u].push_back(v + n); adj[v + n].push_back(u);
        adj[v].push_back(u + n); adj[u + n].push_back(v);
    }
    while (BFS())
        ans += solve();
    if (ans != sum)
        printf("NO\n");
    else
    {
        printf("YES\n");
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
                printf("%d ", cf[i][j + n]);
            printf("\n");
        }
    }
}