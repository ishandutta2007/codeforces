#include <stdio.h>
#define MAXN 1005

int dp[4][MAXN][MAXN], n, m, a[MAXN][MAXN];

inline int max(int a, int b){return a > b ? a : b;}
int init()
{
	int i, j;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; i ++)
		for(j = 1; j <= m; j ++)
			scanf("%d", &a[i][j]);
	return 0;
}
int solve()
{
	int i, j, ans = 0;
	for(i = 1; i <= n; i ++)
		for(j = 1; j <= m; j ++)
			dp[0][i][j] = a[i][j] + max(dp[0][i - 1][j], dp[0][i][j - 1]);
	for(i = n; i >= 1; i --)
		for(j = m; j >= 1; j --)
			dp[1][i][j] = a[i][j] + max(dp[1][i + 1][j], dp[1][i][j + 1]);
	for(i = n; i >= 1; i --)
		for(j = 1; j <= m; j ++)
			dp[2][i][j] = a[i][j] + max(dp[2][i + 1][j], dp[2][i][j - 1]);
	for(i = 1; i <= n; i ++)
		for(j = m; j >= 1; j --)
			dp[3][i][j] = a[i][j] + max(dp[3][i - 1][j], dp[3][i][j + 1]);
	for(i = 2; i < n; i ++)
		for(j = 2; j < m; j ++)
			ans = max(ans, max(dp[0][i - 1][j] + dp[1][i + 1][j] + dp[2][i][j - 1] + dp[3][i][j + 1], dp[0][i][j - 1] + dp[1][i][j + 1] + dp[2][i + 1][j] + dp[3][i - 1][j]));
	printf("%d\n", ans);
	return 0;
}
int main()
{
	init();
	solve();
	return 0;
}