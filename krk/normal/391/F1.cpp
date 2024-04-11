#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 8000000000000000000ll;
const int Maxn = 3005;

int n, k;
ll dp[Maxn][Maxn][2];
ll res = -Inf;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k; j++)
			for (int l = 0; l < 2; l++)
				dp[i][j][l] = -Inf;
	dp[0][0][0] = 0ll;
	for (int i = 0; i < n; i++) {
		ll a; scanf("%I64d", &a);
		for (int j = 0; j <= k; j++)
			for (int l = 0; l < 2; l++) if (dp[i][j][l] != -Inf) {
				// do nothing
				dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l]);
				if (l == 0) dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][l] - a);
				else if (j < k) dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], dp[i][j][l] + a);
			}
	}
	for (int j = 0; j <= k; j++)
		res = max(res, dp[n][j][0]);
	printf("%I64d\n", res);
	return 0;
}