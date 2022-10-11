#include <iostream>
#include <cstdio>
#include <stack>
#include <deque>
using namespace std;

stack<pair<int, int>> adj[100005];
int n, m, i, u, v, pre = 0;
bool chk[500005], rev = 0;

void DFS(int u, int p)
{
    while (true)
    {
        while (!adj[u].empty() && chk[adj[u].top().second])
            adj[u].pop();
        if (adj[u].empty())
            break;
        else
        {
            chk[adj[u].top().second] = true;
            DFS(adj[u].top().first, u);
        }
    }
    if (p != 0)
    {
        if (rev)
            printf("%d %d\n", p, u);
        else printf("%d %d\n", u, p);
        rev ^= 1;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push(make_pair(v, i));
        adj[v].push(make_pair(u, i));
    }
    for (i = 1; i <= n; i++)
        if (adj[i].size() & 1)
            if (pre == 0)
                pre = i;
            else
            {
                ++m;
                adj[pre].push(make_pair(i, m));
                adj[i].push(make_pair(pre, m));
                pre = 0;
            }
    if (m & 1)
    {
        ++m;
        adj[1].push(make_pair(1, m));
        adj[1].push(make_pair(1, m));
    }
    printf("%d\n", m);
    DFS(1, 0);
}