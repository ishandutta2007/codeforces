#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Inf = 1000000009;
const int Maxn = 100005;
const int Maxm = 500;

int T;
int n;
int a[Maxn];
ll sum[Maxn];
int dp[Maxn][Maxm];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        for (int j = 1; j < Maxm; j++)
            dp[n + 1][j] = 0;
        dp[n + 1][0] = Inf;
        for (int i = n; i > 0; i--)
            for (int j = 0; j < Maxm; j++) {
                dp[i][j] = dp[i + 1][j];
                if (j > 0 && i + j <= n + 1 && sum[i + j - 1] - sum[i - 1] < dp[i + j][j - 1])
                    dp[i][j] = max(dp[i][j], int(sum[i + j - 1] - sum[i - 1]));
            }
        int j = Maxm - 1;
        while (!dp[1][j]) j--;
        printf("%d\n", j);
    }
    return 0;
}