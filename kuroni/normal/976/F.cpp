#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N = 4005, M = 2005, INF = 1E9 + 7;

int u[M], v[M], mf[N][N], cf[N][N], cur[N][N], tr[N], s, t, n1, n2, m, mi = INF;
vector<int> adj[N], ans[M];

bool BFS()
{
    fill(tr, tr + t + 1, -1);
    queue<int> q;
    for (tr[s] = 0, q.push(s); !q.empty(); q.pop())
    {
        int u = q.front();
        for (int &v : adj[u])
            if (tr[v] == -1 && cf[u][v] < mf[u][v])
            {
                q.push(v);
                tr[v] = u;
                if (v == t)
                    return true;
            }
    }
    return false;
}

void trace()
{
    int p = INF, v = t;
    while (v != s)
    {
        int u = tr[v];
        p = min(p, mf[u][v] - cf[u][v]);
        v = u;
    }
    v = t;
    while (v != s)
    {
        int u = tr[v];
        cf[u][v] += p;
        cf[v][u] -= p;
        v = u;
    }
    return;
}

void init(int c)
{
    for (int i = 1; i <= n1; i++)
        mf[s][i]++;
    for (int i = n1 + 1; i <= n1 + n2; i++)
        mf[i][t]++;
    for (int i = 1; i <= m; i++)
        cur[u[i]][v[i]] = 0;
    while (BFS())
        trace();
    for (int i = 1; i <= m; i++)
    {
        cur[u[i]][v[i]]++;
        if (cur[u[i]][v[i]] > cf[u[i]][v[i]])
            ans[c].push_back(i);
    }
}

int main()
{
    scanf("%d%d%d", &n1, &n2, &m);
    s = 0;
    t = n1 + n2 + 1;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", u + i, v + i);
        v[i] += n1;
        if (mf[u[i]][v[i]] == 0)
        {
            adj[u[i]].push_back(v[i]);
            adj[v[i]].push_back(u[i]);
        }
        mf[s][u[i]]++;
        mf[v[i]][t]++;
        mf[u[i]][v[i]]++;
    }
    for (int i = 1; i <= n1; i++)
    {
        adj[s].push_back(i);
        adj[i].push_back(s);
        mi = min(mi, mf[s][i]);
    }
    for (int i = n1 + 1; i <= n1 + n2; i++)
    {
        adj[i].push_back(t);
        adj[t].push_back(s);
        mi = min(mi, mf[i][t]);
    }
    for (int i = 1; i <= n1; i++)
        mf[s][i] -= mi + 1;
    for (int i = n1 + 1; i <= n1 + n2; i++)
        mf[i][t] -= mi + 1;
    for (int i = mi; i >= 0; i--)
        init(i);
    for (int i = 0; i <= mi; i++)
    {
        printf("%u ", ans[i].size());
        for (int &v : ans[i])
            printf("%d ", v);
        printf("\n");
    }
}