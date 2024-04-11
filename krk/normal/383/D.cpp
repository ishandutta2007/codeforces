#include <cstdio>
using namespace std;

const int mod = 1000000007;
const int Maxn = 1005;
const int Maxm = 20015;
const int nil = 10005;

int n;
int dp[Maxn][Maxm];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		dp[i][nil]++;
		int a; scanf("%d", &a);
		for (int j = 0; j < Maxm; j++) if (dp[i][j]) {
			dp[i + 1][j - a] += dp[i][j];
			if (dp[i + 1][j - a] >= mod) dp[i + 1][j - a] -= mod;
			dp[i + 1][j + a] += dp[i][j];
			if (dp[i + 1][j + a] >= mod) dp[i + 1][j + a] -= mod;
		}
		res = (res + dp[i + 1][nil]) % mod;
	}
	printf("%d\n", res);
	return 0;
}