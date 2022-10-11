#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 200005, MOD = 998244353;

int n, u;
long long f[N][2];
vector<int> adj[N];

void DFS(int u)
{
    if (adj[u].empty())
    {
        f[u][0] = f[u][1] = 1;
        return;
    }
    long long to = 1, ze = 1, on = 0;
    for (int &v : adj[u])
    {
        DFS(v);
        (to *= f[v][0] + f[v][1]) %= MOD;
        (on *= f[v][0]) %= MOD;
        (on += ze * f[v][1]) %= MOD;
        (ze *= f[v][0]) %= MOD;
    }
    f[u][0] = (to - on) % MOD;
    f[u][1] = (to - ze) % MOD;
}

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &u);
        adj[u].push_back(i);
    }
    DFS(1);
    printf("%lld", (f[1][0] + MOD) % MOD);
    return 0;
}