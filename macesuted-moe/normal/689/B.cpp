#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<vector<int> > graph;

bool vis[200005];
int dist[200005];
void spfa()
{
    for (register int i = 1; i <= n; i++)
        dist[i] = 0x7fffffff;
    dist[1] = 0;
    vis[1] = true;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (register int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    graph.resize(n + 1);
    for (register int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        graph[i].push_back(x);
        if (i != n)
        {
            graph[i].push_back(i + 1);
            graph[i + 1].push_back(i);
        }
    }
    spfa();
    for (register int i = 1; i <= n; i++)
        printf("%d ", dist[i]);
    puts("");
    return 0;
}