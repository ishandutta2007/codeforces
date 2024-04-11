#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 5005;
const int Maxm = 1 << 9;

int n, k;
int p[Maxn], inp[Maxn];
int my[Maxn][Maxn];
int dp[Maxn][Maxm];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        inp[p[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            my[i][j] = my[i][j - 1] + int(inp[j] > inp[i]);
    fill((int*)dp, (int*)dp + Maxn * Maxm, Inf);
    dp[1][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 1 << (k + 1); j++) if (dp[i][j] < Inf)
            if (j & 1) dp[i + 1][j >> 1] = min(dp[i + 1][j >> 1], dp[i][j]);
            else for (int z = 0; z <= k && i + z <= n; z++) if (!(j & 1 << z)) {
                int cand = dp[i][j] + my[i + z][i - 1];
                for (int c = 0; c <= k && i + c <= n; c++) if (j & 1 << c)
                    cand += inp[i + c] > inp[i + z];
                dp[i][j | 1 << z] = min(dp[i][j | 1 << z], cand);
            }
    printf("%d\n", dp[n + 1][0]);
    return 0;
}