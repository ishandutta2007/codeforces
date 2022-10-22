#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;

int n, k;
int a[Maxn];
int dp[Maxn][Maxn];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int l = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++)
            dp[i][j] = dp[i - 1][j];
        while (a[i] - a[l] > 5) l++;
        for (int j = 1; j <= k; j++)
            dp[i][j] = max(dp[i][j], dp[l - 1][j - 1] + (i - l + 1));
    }
    printf("%d\n", dp[n][k]);
    return 0;
}