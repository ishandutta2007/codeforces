#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 300005;

int n;
vector <int> neigh[Maxn];
int dp[Maxn][3];

void Solve(int v, int p)
{
    dp[v][0] = dp[v][1] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Solve(u, v);
        int nw[3] = {};
        // don't take
        for (int i = 0; i < 3; i++)
            nw[i] = (nw[i] + ll(dp[v][i]) * (dp[u][0] + dp[u][2])) % mod;
        // take
        nw[0] = (nw[0] + ll(dp[v][0]) * (ll(dp[u][0]) + ll(dp[u][1]) + ll(dp[u][2]))) % mod;
        nw[2] = (nw[2] + ll(dp[v][1] + dp[v][2]) * dp[u][0]) % mod;
        for (int i = 0; i < 3; i++)
            dp[v][i] = nw[i];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Solve(1, 0);
    int res = (dp[1][0] + dp[1][2]) % mod;
    res = (res - 1 + mod) % mod;
    printf("%d\n", res);
    return 0;
}