#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int n, m, u, v, i, cnt = 0, path = 0;
long long ans = 0;
vector <int> adj[1000005];
bool chk[1000005];

int DFS(int u)
{
    int rep = 1;
    chk[u] = true;
    for (int v: adj[u])
        if (!chk[v])
        rep += DFS(v);
    return rep;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        chk[u] = chk[v] = true;
        if (u == v)
            ++cnt;
        else
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    for (i = 1; i <= n; i++)
        path += chk[i];
    for (i = 1; i <= n; i++)
        if (chk[i])
        {
            memset(chk, 0, sizeof(chk));
            if (DFS(i) != path)
            {
                printf("0");
                return 0;
            }
            else break;
        }
    ans = 1LL * cnt * (m - 1) - 1LL * cnt * (cnt - 1) / 2;
    for (i = 1; i <= n; i++)
        ans += 1LL * adj[i].size() * (adj[i].size() - 1) / 2;
    printf("%I64d", ans);
}