#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m, i, u, v, out[100005], ans[100005], cur;
priority_queue <int> pq;
vector <int> adj[100005];

int main()
{
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        adj[v].push_back(u);
        ++out[u];
    }
    for (i = 1; i <= n; i++)
        if (out[i] == 0)
            pq.push(i);
    int cnt = n;
    while (!pq.empty())
    {
        cur = pq.top();
        pq.pop();
        ans[cur] = cnt--;
        for (i = 0; i < adj[cur].size(); i++)
        {
            --out[adj[cur][i]];
            if (out[adj[cur][i]] == 0)
                pq.push(adj[cur][i]);
        }
    }
    for (i = 1; i <= n; i++)
        printf("%d ", ans[i]);
}