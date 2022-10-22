#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 30005;
const int Maxk = 205;
const int Maxd = 6;

int n, k;
int a[Maxn];
int dp[Maxn][Maxk][2][Maxd];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	fill((int*)dp, (int*)dp + Maxn * Maxk * 2 * Maxd, -Inf);
	for (int i = 0; i < n; i++) {
		dp[i][1][1][0] = dp[i][1][0][0] = -a[i];
		dp[i][1][1][1] = dp[i][1][0][1] = a[i];
	}
	for (int i = n - 1; i >= 0; i--)
		for (int j = 1; j <= k; j++) {
			// 0
			dp[i][j][1][0] = max(dp[i][j][1][0], dp[i + 1][j][1][0] - a[i]);
			// 1
			dp[i][j][1][1] = max(dp[i][j][1][1], dp[i + 1][j][1][1] + a[i]);
			// 2
			dp[i][j][1][2] = max(dp[i][j][1][2], dp[i + 1][j][1][2] - 2 * a[i]);
			if (j) {
				dp[i][j][1][2] = max(dp[i][j][1][2], dp[i + 1][j - 1][0][1] - 2 * a[i]);
				dp[i][j][1][2] = max(dp[i][j][1][2], dp[i + 1][j - 1][0][3] - 2 * a[i]);
			}
			// 3
			dp[i][j][1][3] = max(dp[i][j][1][3], dp[i + 1][j][1][3] + 2 * a[i]);
			if (j) {
				dp[i][j][1][3] = max(dp[i][j][1][3], dp[i + 1][j - 1][0][0] + 2 * a[i]);
				dp[i][j][1][3] = max(dp[i][j][1][3], dp[i + 1][j - 1][0][2] + 2 * a[i]);
			}
			// 4
			dp[i][j][1][4] = max(dp[i][j][1][4], dp[i + 1][j][1][4] - a[i]);
			if (j) {
				dp[i][j][1][4] = max(dp[i][j][1][4], dp[i + 1][j - 1][0][1] - a[i]);
				dp[i][j][1][4] = max(dp[i][j][1][4], dp[i + 1][j - 1][0][3] - a[i]);
			}
			// 5
			dp[i][j][1][5] = max(dp[i][j][1][5], dp[i + 1][j][1][5] + a[i]);
			if (j) {
				dp[i][j][1][5] = max(dp[i][j][1][5], dp[i + 1][j - 1][0][0] + a[i]);
				dp[i][j][1][5] = max(dp[i][j][1][5], dp[i + 1][j - 1][0][2] + a[i]);
			}
			for (int z = 0; z < Maxd; z++) {
				dp[i][j][0][z] = max(dp[i][j][1][z], dp[i + 1][j][0][z]);
				if (j) dp[i][j][0][z] = max(dp[i][j][0][z], dp[i + 1][j - 1][0][z]);
			}
		}
	printf("%d\n", max(dp[0][k][0][4], dp[0][k][0][5]));
	return 0;
}