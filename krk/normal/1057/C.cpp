#include <bits/stdc++.h>
using namespace std;

const string cols = "RGB";
const int Maxa = 2052;
const int Maxb = 53;
const int Maxc = 53;
const int Maxd = 3;
const int Inf = 1000000000;

int n, s, K;
int r[Maxb];
int c[Maxb];
int dp[Maxa][Maxb][Maxc][Maxd];
int res = Inf;

int main()
{
    scanf("%d %d %d", &n, &s, &K);
    for (int i = 1; i <= n; i++)
        scanf("%d", &r[i]);
    for (int i = 1; i <= n; i++) {
        char ch; scanf(" %c", &ch);
        c[i] = cols.find(ch);
    }
    fill((int*)dp, (int*)dp + Maxa * Maxb * Maxc * Maxd, Inf);
    dp[0][s][0][0] = dp[0][s][0][1] = dp[0][s][0][2] = 0;
    for (int i = 0; i < Maxa; i++) {
        for (int j = 1; j <= n; j++)
            for (int k = 0; k < Maxc; k++)
                for (int d = 0; d < Maxd; d++)
                    dp[i][j][k][d] = min(dp[i][j][k][d], dp[i][j - 1][k][d] + 1);
        for (int j = n; j >= 1; j--)
            for (int k = 0; k < Maxc; k++)
                for (int d = 0; d < Maxd; d++) {
                    dp[i][j][k][d] = min(dp[i][j][k][d], dp[i][j + 1][k][d] + 1);
                    if (i >= K) res = min(res, dp[i][j][k][d]);
                    if (k < r[j] && d != c[j] && i + r[j] < Maxa)
                        dp[i + r[j]][j][r[j]][c[j]] = min(dp[i + r[j]][j][r[j]][c[j]], dp[i][j][k][d]);
                }
    }
    printf("%d\n", res >= Inf? -1: res);
    return 0;
}