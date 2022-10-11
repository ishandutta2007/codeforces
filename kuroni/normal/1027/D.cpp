#include <iostream>
#include <cstdio>
using namespace std;

const int N = 200005, INF = 1E9 + 7;

int n, ans = 0, a[N], f[N], vis[N];

void DFS(int u)
{
    vis[u] = 1;
    if (vis[f[u]] == 0)
        DFS(f[u]);
    else if (vis[f[u]] == 1)
    {
        int add = INF, cur = u;
        do
        {
            add = min(add, a[cur]);
            cur = f[cur];
        }   while (cur != u);
        ans += add;
    }
    vis[u] = 2;

}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
        scanf("%d", f + i);
    for (int i = 1; i <= n; i++)
        if (vis[i] == 0)
            DFS(i);
    printf("%d\n", ans);
}