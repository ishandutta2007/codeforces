#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 105;
const int mod = 1000000007;

int C[Maxn][Maxn];
int T;
int n, k;
vector <int> neigh[Maxn];
int dp[Maxn][Maxn];
int dist[Maxn];

void Traverse(int v, int p, int d)
{
    dist[d]++;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v, d + 1);
    }
}

int main()
{
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        int res = 0;
        if (k == 2) res = ll(n) * (n - 1) / 2 % mod;
        else for (int i = 1; i <= n; i++) {
            fill((int*)dp, (int*)dp + Maxn * Maxn, 0);
            for (int d = 1; d < n; d++)
                dp[d][0] = 1;
            for (int j = 0; j < neigh[i].size(); j++) {
                fill(dist, dist + n, 0);
                int v = neigh[i][j];
                Traverse(v, i, 1);
                for (int d = 1; d < n; d++)
                    for (int t = k - 1; t >= 0; t--)
                        dp[d][t + 1] = (dp[d][t + 1] + ll(dp[d][t]) * dist[d]) % mod;
            }
            for (int d = 1; d < n; d++)
                res = (res + dp[d][k]) % mod;
        }
        printf("%d\n", res);
    }
    return 0;
}