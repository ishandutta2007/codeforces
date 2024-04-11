#include <bits/stdc++.h>
using namespace std;

const int Maxn = 205;

int n, k;
int a[Maxn];
vector <int> neigh[Maxn];
int dp[Maxn][Maxn];

void Solve(int v, int p = 0)
{
    dp[v][0] = a[v];
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Solve(u, v);
        dp[u][k] = max(dp[u][k - 1], dp[u][k]);
        for (int j = k - 1; j > 0; j--)
            dp[u][j] = dp[u][j - 1];
        dp[u][0] = 0;
        for (int j = 0; j <= k; j++) {
            int val = dp[v][j]; dp[v][j] = 0;
            for (int z = 0; z <= k; z++) if (j + z >= k)
                dp[v][min(j, z)] = max(dp[v][min(j, z)], dp[u][z] + val);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &k); k++;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Solve(1);
    int res = 0;
    for (int j = 0; j <= k; j++)
        res = max(res, dp[1][j]);
    printf("%d\n", res);
    return 0;
}