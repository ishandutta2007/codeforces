#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 2005;
const int mod = 1000000007;

int n, m;
int dp[Maxn][Maxn][2], sum[Maxn][Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int j = 2; j <= m; j++) {
		dp[1][j][0] = dp[1][j][1] = 1;
		sum[1][j] = (sum[1][j - 1] + dp[1][j][0]) % mod;
	}
	for (int i = 2; i <= n; i++) {
		int acc = 0;
		for (int j = 2; j <= m; j++) {
			dp[i][j][0] = (acc + sum[i - 1][j]) % mod;
			dp[i][j][1] = (acc + sum[i - 1][j - 1]) % mod;
			sum[i][j] = (sum[i][j - 1] + dp[i][j][0]) % mod;
			acc = (acc + sum[i - 1][j]) % mod;
		}
	}
	for (int j = 2; j <= m; j++)
		for (int i = 0; i < n; i++)
			for (int k = 0; k < 2; k++)
				dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k]) % mod;
	for (int i = 1; i <= n; i++)
		for (int j = 2; j <= m; j++)
			res = (res + ll(m - j + 1) * ll(dp[i][j][1]) % ll(mod) * ll(dp[n - i + 1][j][0]) % ll(mod)) % mod;
	printf("%d\n", res);
	return 0;
}