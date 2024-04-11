#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;
const int Inf = 1000000000;

int n, h, l, r;
int dp[Maxn][Maxn];

int main()
{
	scanf("%d %d %d %d", &n, &h, &l, &r);
	fill((int*)dp, (int*)dp + Maxn * Maxn, -Inf);
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		for (int j = 0; j < h; j++) if (dp[i][j] >= 0) {
			int nj = (j + a - 1) % h;
			dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j] + (l <= nj && nj <= r));
			nj = (j + a) % h;
			dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j] + (l <= nj && nj <= r));
		}
	}
	int res = 0;
	for (int j = 0; j < h; j++)
		res = max(res, dp[n][j]);
	printf("%d\n", res);
    return 0;
}