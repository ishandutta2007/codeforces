#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 105;

int n, m, k, mod;
int C[Maxn][Maxn];
int res;
int dp[Maxn][Maxn][Maxn];

int main()
{
    scanf("%d %d %d %d", &n, &m, &k, &mod);
    if (mod == 1) { printf("0\n"); return 0; }
    for (int i = 0; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    m--;
    for (int i = 0; i <= n; i++)
        dp[i][0][0] = 1;
    for (int lvl = n - 1; lvl >= 0; lvl--)
        for (int i = 1; i <= n - lvl; i++)
            for (int a = 0; a < i; a++) {
                int b = i - 1 - a;
                for (int c = 0; c <= a; c++) if (dp[lvl + 1][a][c])
                    for (int d = 0; d <= b; d++) if (dp[lvl + 1][b][d]) {
                        int my = c + d + (lvl == m);
                        dp[lvl][i][my] = (dp[lvl][i][my] + ll(C[i - 1][a]) * dp[lvl + 1][a][c] % mod * dp[lvl + 1][b][d]) % mod;
                    }
            }
    printf("%d\n", dp[0][n][k]);
    return 0;
}