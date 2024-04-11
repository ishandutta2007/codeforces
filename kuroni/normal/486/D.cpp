#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

long long f[2005], ans = 0;
int d, n, a[2005], u, v, i;
bool chk[2005];
vector<int> adj[2005];

void DFS(int u, int s)
{
    chk[u] = true;
    f[u] = 1;
    for (int v : adj[u])
        if (!chk[v] && (a[v] > a[s] || (a[v] == a[s] && v > s)) && a[v] <= a[s] + d)
        {
            DFS(v, s);
            f[u] *= (f[v] + 1);
            f[u] %= mod;
        }
}

int main()
{
    scanf("%d%d", &d, &n);
    for (i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (i = 1; i <= n; i++)
    {
        memset(f, 0, sizeof(f));
        memset(chk, 0, sizeof(chk));
        DFS(i, i);
        ans += f[i];
        ans %= mod;
    }
    printf("%I64d", ans);
}