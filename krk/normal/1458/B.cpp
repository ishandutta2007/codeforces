#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int Maxn = 105;
const int Maxm = Maxn * Maxn;
const int Inf = 1000000000;

int n;
int dp[2][Maxn][Maxm];
int cur;

int main()
{
	fill((int*)dp, (int*)dp + 2 * Maxn * Maxm, -Inf);
	int H = 0;
	scanf("%d", &n);
	dp[cur][0][0] = 0;
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		H += b;
		for (int k = 0; k <= i; k++)
			for (int g = 0; g <= 100 * k; g++) if (dp[cur][k][g] >= -Inf) {
				int best = dp[cur][k][g]; dp[cur][k][g] = -Inf;
				dp[!cur][k][g] = max(dp[!cur][k][g], best);
				dp[!cur][k + 1][g + a] = max(dp[!cur][k + 1][g + a], best + b);
			}
		cur = !cur;
	}
	for (int k = 1; k <= n; k++) {
		int res = 0;
		for (int g = 0; g <= 100 * k; g++)
			res = max(res, min(dp[cur][k][g] + H, 2 * g));
		printf("%d.%c000000000%c", res / 2, res % 2? '5': '0', k + 1 <= n? ' ': '\n');
	}
    return 0;
}