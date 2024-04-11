#include <cstdio>
using namespace std;

const int mod = 1000000007;
const int Maxn = 2005;

int n, k;
int dp[Maxn][Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &k);
	for (int j = 1; j <= n; j++)
		dp[1][j] = 1;
	for (int i = 1; i < k; i++)
		for (int j = 1; j <= n; j++) if (dp[i][j])
			for (int k = j; k <= n; k += j)
				dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % mod;
	for (int j = 1; j <= n; j++)
		res = (res + dp[k][j]) % mod;
	printf("%d\n", res);
	return 0;
}