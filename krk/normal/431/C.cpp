#include <cstdio>
#include <algorithm>
using namespace std;

const int mod = 1000000007;
const int Maxn = 105;

int n, d, k;
int dp[Maxn][Maxn];
int res;

int main()
{
	scanf("%d %d %d", &n, &k, &d);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= k; j++)
			for (int l = 1; i + l <= n; l++) {
				int ni = i + l, nj = max(j, l);
				dp[ni][nj] = (dp[ni][nj] + dp[i][j]) % mod;
			}
	for (int i = d; i <= k; i++)
		res = (res + dp[n][i]) % mod;
	printf("%d\n", res);
	return 0;
}