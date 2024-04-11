#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 1005;

int C[Maxn][Maxn];
int n, k;
int dp[Maxn][Maxn][2];
int res[Maxn];

int main()
{
	for (int i = 0; i < Maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	scanf("%d %d", &n, &k);
	dp[0][0][0] = 1;
	for (int i = 1; i <= n / 2; i++) {
		int ind = 2 * i;
		for (int j = 0; j <= i; j++) {
			dp[i][j][0] = (dp[i][j][0] + (dp[i - 1][j][0] + dp[i - 1][j][1]) % mod) % mod;
			if (j >= 1) { 
				dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j - 1][0]) % mod;
				if (ind + 1 <= n) dp[i][j][1] = (dp[i][j][1] + (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1]) % mod) % mod;
			}
		}
	}
	for (int i = n / 2 + 1; i <= n; i++) {
		int ind = 1 + (i - n / 2 - 1) * 2;
		for (int j = 0; j <= i; j++) {
			dp[i][j][0] = (dp[i][j][0] + (dp[i - 1][j][0] + dp[i - 1][j][1]) % mod) % mod;
			if (j >= 1) {
				if (ind > 1) dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j - 1][0]) % mod;
				if (ind + 1 <= n) dp[i][j][1] = (dp[i][j][1] + (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1]) % mod) % mod;
			}
		}
	}
	for (int i = n; i >= k; i--) {
		res[i] = (dp[n][i][0] + dp[n][i][1]) % mod;
		for (int j = 2; j <= n - i; j++) res[i] = ll(res[i]) * ll(j) % ll(mod);
		for (int j = i + 1; j <= n; j++) {
			res[i] -= ll(res[j]) * ll(C[j][i]) % ll(mod);
			if (res[i] < 0) res[i] += mod;
		}
	}
	printf("%d\n", res[k]);
	return 0;
}