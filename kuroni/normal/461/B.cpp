#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 100005, MOD = 1E9 + 7;

vector<int> adj[N];
int n, u, a[N];
long long f[N][2];

long long pw(int u, int p)
{
    long long ret = 1;
    for (int i = 31 - __builtin_clz(p); i >= 0; i--)
    {
        (ret *= ret) %= MOD;
        if (p >> i & 1)
            (ret *= u) %= MOD;
    }
    return ret;
}

void DFS(int u)
{
    long long mul = 1;
    for (int &v : adj[u])
    {
        DFS(v);
        (mul *= (f[v][0] + f[v][1])) %= MOD;
    }
    if (a[u] == 0)
    {
        f[u][0] = mul;
        for (int &v : adj[u])
            (f[u][1] += mul * pw(f[v][0] + f[v][1], MOD - 2) % MOD * f[v][1]) %= MOD;
    }
    else
    {
        f[u][0] = 0;
        f[u][1] = mul;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &u);
        adj[u].push_back(i);
    }
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    DFS(0);
    printf("%lld", f[0][1]);
}