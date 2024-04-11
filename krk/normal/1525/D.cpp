#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;
const int Inf = 1000000000;

int n;
int a[Maxn];
int dp[Maxn][Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	fill((int*)dp, (int*)dp + Maxn * Maxn, Inf);
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) if (dp[i][j] < Inf)
			if (i < n && a[i] == 0) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			else if (j < n && a[j] == 1) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
			else {
				if (j < n) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
				if (i < n && j < n) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], abs(i - j) + dp[i][j]);
			}
	printf("%d\n", dp[n][n]);
    return 0;
}