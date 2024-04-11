#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 505;

int n, m, k;
char B[Maxn][Maxn];
int tot[Maxn];
int cost[Maxn][Maxn];
int dp[Maxn][Maxn];

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s", B[i]);
		for (int j = 0; j < m; j++)
			tot[i] += B[i][j] == '1';
		fill(cost[i], cost[i] + Maxn, Inf);
		cost[i][0] = 0;
		for (int j = 0; j < m; j++) {
			int cur = 0;
			for (int j2 = j; j2 < m; j2++) {
				cur += B[i][j2] == '1';
				cost[i][cur] = min(cost[i][cur], j2 - j + 1);
			}
		}
	}
	fill((int*)dp, (int*)dp + Maxn * Maxn, Inf);
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= k; j++) if (dp[i][j] < Inf)
			for (int l = 0; l <= tot[i] && j + l <= k; l++)
				dp[i + 1][j + l] = min(dp[i + 1][j + l], dp[i][j] + cost[i][tot[i] - l]);
	int res = Inf;
	for (int j = 0; j <= k; j++)
		res = min(res, dp[n][j]);
	printf("%d\n", res);
	return 0;
}