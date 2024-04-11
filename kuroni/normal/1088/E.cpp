#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 300005;
const long long INF = 1E18 + 7;

int n, k = 0, a[N];
long long mx = -INF, dp[N];
bool chk[N];
vector<int> adj[N];
vector<pair<long long, int>> ve[N];

long long DFS(int u, int p = 0)
{
    dp[u] = a[u];
    for (int &v : adj[u])
        if (v != p)
            ve[u].push_back(make_pair(DFS(v, u), v));
    for (pair<long long, int> &v : ve[u])
        if (v.first > 0)
            dp[u] += v.first;
    mx = max(mx, dp[u]);
    return dp[u];
}

long long trace(int u)
{
    chk[u] = true;
    long long ret = a[u];
    for (pair<long long, int> &v : ve[u])
        if (v.first > 0 && !chk[v.second])
            ret += trace(v.second);
    return ret;
}

void DFS_2(int u, int p = 0)
{
    for (int &v : adj[u])
        if (v != p)
            DFS_2(v, u);
    if (dp[u] == mx && trace(u) == mx)
        ++k;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    DFS_2(1);
    printf("%lld %d\n", mx * k, k);
}