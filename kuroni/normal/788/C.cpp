#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n, k, u, i, j, vis[2005];
bool chk[1005];
queue <int> q;
vector <int> adj[2005];

int main()
{
    scanf("%d%d", &n, &k);
    while (k--)
    {
        scanf("%d", &u);
        chk[u] = true;
    }
    for (i = 0; i <= 2000; i++)
        for (j = 0; j <= 1000; j++)
            if (chk[j] && i + j - n >= 0 && i + j - n <= 2000)
                adj[i].push_back(i + j - n);
    q.push(1000);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int v: adj[u])
            if (vis[v] == 0)
            {
                vis[v] = vis[u] + 1;
                q.push(v);
                if (v == 1000)
                {
                    printf("%d", vis[v]);
                    return 0;
                }
            }
    }
    printf("-1");
    return 0;
}