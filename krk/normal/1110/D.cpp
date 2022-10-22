#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
const int Inf = 1000000000;
const int Maxd = 3;

int n, m;
int a[Maxn];
int cnt[Maxn];
int dp[Maxn + 1][Maxd][Maxd];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    fill((int*)dp, (int*)dp + (Maxn + 1) * Maxd * Maxd, -Inf);
    dp[0][0][0] = 0;
    for (int i = 0; i < Maxn; i++)
        for (int a = 0; a < Maxd; a++)
            for (int b = 0; b < Maxd; b++) if (dp[i][a][b] >= 0)
                for (int c = 0; c < Maxd && a + b + c <= cnt[i]; c++) {
                    int cand = dp[i][a][b] + a + (cnt[i] - a - b - c) / 3;
                    dp[i + 1][b][c] = max(dp[i + 1][b][c], cand);
                }
    printf("%d\n", dp[Maxn][0][0]);
    return 0;
}