#include <bits/stdc++.h>
using namespace std;

const int Maxn = 205;
const int Maxm = 505;
const int Inf = 1000000000;

int q;
int n;
int t[Maxn];
int dp[Maxn][Maxm];

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &t[i]);
        sort(t, t + n);
        fill((int*)dp, (int*)dp + (n + 1) * Maxm, Inf);
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < Maxm; j++) if (dp[i][j] < Inf)
                for (int k = j + 1; k < Maxm; k++)
                    dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + abs(k - t[i]));
        int res = Inf;
        for (int j = 0; j < Maxm; j++)
            res = min(res, dp[n][j]);
        printf("%d\n", res);
    }
    return 0;
}