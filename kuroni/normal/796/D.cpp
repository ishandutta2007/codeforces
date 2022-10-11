#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, k, d, i, u, v, par;
bool chk[300005], mark[300005];
vector < pair <int, int> > adj[300005];
queue < pair <int, int> > q;

int main()
{
    scanf("%d%d%d", &n, &k, &d);
    for (i = 1; i <= k; i++)
    {
        scanf("%d", &v);
        q.push({v, 0});
    }
    for (i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    while (!q.empty())
    {
        u = q.front().first;
        par = q.front().second;
        q.pop();
        if (chk[u])
            continue;
        chk[u] = true;
        for (i = 0; i < adj[u].size(); i++)
        {
            v = adj[u][i].first;
            if (v == par)
                continue;
            if (!chk[v])
                q.push({v, u});
            else mark[adj[u][i].second] = true;
        }
    }
    int ans = 0;
    for (i = 1; i < n; i++)
        if (mark[i])
            ++ans;
    printf("%d\n", ans);
    for (i = 1; i < n; i++)
        if (mark[i])
            printf("%d ", i);
}