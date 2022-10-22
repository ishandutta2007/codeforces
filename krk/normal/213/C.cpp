#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 305;

int n;
int a[Maxn][Maxn];
int dp[Maxn][Maxn][Maxn][2];

int main()
{
	fill((int*)dp, (int*)dp + Maxn * Maxn * Maxn * 2, -Inf);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	dp[0][0][0][0] = a[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) {
				if (dp[i][j][k][0] != -Inf) {
					dp[i][j][k][1] = max(dp[i][j][k][1], dp[i][j][k][0] + (j < k? a[i][k]: 0));
					if (j + 1 < n) dp[i][j + 1][k][0] = max(dp[i][j + 1][k][0], dp[i][j][k][0] + a[i][j + 1]);
				}
				if (dp[i][j][k][1] != -Inf) {
					int mn = min(j, k), mx = max(j, k);
					if (i + 1 < n) dp[i + 1][mn][mx][0] = max(dp[i + 1][mn][mx][0], dp[i][j][k][1] + a[i + 1][mn]);
					if (k + 1 < n) dp[i][j][k + 1][1] = max(dp[i][j][k + 1][1], dp[i][j][k][1] + (j < k + 1? a[i][k + 1]: 0));
				}
			}
	printf("%d\n", dp[n - 1][n - 1][n - 1][1]);
	return 0;
}