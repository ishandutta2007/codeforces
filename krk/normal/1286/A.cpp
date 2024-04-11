#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
const int Inf = 1000000000;

int n;
int a[Maxn];
bool was[Maxn];
int has[2];
int dp[Maxn][2][Maxn][Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        was[a[i]] = true;
    }
    for (int i = 1; i <= n; i++) if (!was[i])
        has[i % 2]++;
    fill((int*)dp, (int*)dp + Maxn * 2 * Maxn * Maxn, Inf);
    dp[0][0][has[0]][has[1]] = dp[0][1][has[0]][has[1]] = 0;
    for (int i = 0; i < n; i++)
        for (int f = 0; f < 2; f++)
            for (int u = 0; u <= n; u++)
                for (int v = 0; v <= n; v++) if (dp[i][f][u][v] < Inf)
                    if (a[i] > 0)
                        dp[i + 1][a[i] % 2][u][v] = min(dp[i + 1][a[i] % 2][u][v], dp[i][f][u][v] + (f != a[i] % 2));
                    else {
                        has[0] = u; has[1] = v;
                        for (int k = 0; k < 2; k++) if (has[k] > 0) {
                            has[k]--;
                            dp[i + 1][k][has[0]][has[1]] = min(dp[i + 1][k][has[0]][has[1]], dp[i][f][u][v] + (f != k));
                            has[k]++;
                        }
                    }
    int res = min(dp[n][0][0][0], dp[n][1][0][0]);
    printf("%d\n", res);
    return 0;
}