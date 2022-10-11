#include <iostream>
#include <cstdio>
using namespace std;

const int M = 1 << 22;

int n, m, ans = 0, tot, a[M];
bool chk[M], vis[M];

void DFS(int u)
{
    vis[u] = true;
    if (chk[u] && !vis[tot ^ u])
        DFS(tot ^ u);
    for (int i = 0; i < n; i++)
        if ((u >> i & 1) && !vis[u ^ (1 << i)])
            DFS(u ^ (1 << i));
}

int main()
{
    scanf("%d%d", &n, &m);
    tot = (1 << n) - 1;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", a + i);
        chk[a[i]] = true;
    }
    for (int i = 0; i < m; i++)
        if (!vis[a[i]])
        {
            ++ans;
            DFS(a[i]);
        }
    printf("%d", ans);
}