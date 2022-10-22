#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Inf = 1000000000;

int T;
int n;
int a[Maxn];
int dp[Maxn][2];

int Get(int i, int j)
{
    int res = 0;
    for (int l = i; l <= j; l++)
        res += a[l];
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        fill((int*)dp, (int*)dp + (n + 1) * 2, Inf);
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 2; j++) if (dp[i][j] < Inf)
                for (int l = 1; l <= 2 && i + l <= n; l++) {
                    int cand = dp[i][j] + (j == 0? Get(i, i + l - 1): 0);
                    dp[i + l][1 - j] = min(dp[i + l][1 - j], cand);
                }
        int res = min(dp[n][0], dp[n][1]);
        printf("%d\n", res);
    }
    return 0;
}