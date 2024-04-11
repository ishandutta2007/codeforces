#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 2005;
const int mod = 1000000007;

int n, h;
int a[Maxn];
int dp[Maxn][Maxn];

int main()
{
	scanf("%d %d", &n, &h);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		for (int j = 0; j <= i; j++) if (dp[i][j]) {
			if (a[i] + j + 1 == h) 
				dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
			if (a[i] + j == h)
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
			if (j && a[i] + j == h)
				dp[i + 1][j] = (dp[i + 1][j] + ll(dp[i][j]) * j % mod) % mod;
			if (j && a[i] + j - 1 == h)
				dp[i + 1][j - 1] = (dp[i + 1][j - 1] + ll(dp[i][j]) * j % mod) % mod;
		}
	}
	printf("%d\n", (dp[n][0] + dp[n][1]) % mod);
	return 0;
}