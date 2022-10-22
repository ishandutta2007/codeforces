#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;
const int Inf = 1000000007;

int n, k;
int a[Maxn];
int dp[2][Maxn][3], cur;

int main()
{
	scanf("%d", &n); k = (n + 1) / 2;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	fill((int*)dp, (int*)dp + 2 * Maxn * 3, Inf);
	dp[cur][0][2] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (dp[cur][j][0] < Inf) {
				// no
				int cand = max(0, a[i] - (a[i - 1] - 1));
				dp[!cur][j][1] = min(dp[!cur][j][1], dp[cur][j][0] + cand);
				dp[cur][j][0] = Inf;
			}
			if (dp[cur][j][1] < Inf) {
				// no
				dp[!cur][j][2] = min(dp[!cur][j][2], dp[cur][j][1]);
				// yes
				int lft = min(a[i - 1], a[i - 2] - 1);
				int cand = max(0, lft - (a[i] - 1));
				dp[!cur][j + 1][0] = min(dp[!cur][j + 1][0], dp[cur][j][1] + cand);
				dp[cur][j][1] = Inf;
			}
			if (dp[cur][j][2] < Inf) {
				// no
				dp[!cur][j][2] = min(dp[!cur][j][2], dp[cur][j][2]);
				// yes
				int cand = max(0, a[i - 1] - (a[i] - 1));
				dp[!cur][j + 1][0] = min(dp[!cur][j + 1][0], dp[cur][j][2] + cand);
				dp[cur][j][2] = Inf;
			}
		}
		cur = !cur;
	}
	for (int i = 1; i <= k; i++) {
		int res = min(dp[cur][i][0], min(dp[cur][i][1], dp[cur][i][2]));
		printf("%d%c", res, i + 1 <= k? ' ': '\n');
	}
	return 0;
}