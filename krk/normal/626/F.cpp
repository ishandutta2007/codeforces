#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 205;
const int Maxk = 1005;

int n, k;
int a[Maxn];
int dp[Maxn][Maxn][Maxk];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		if (i && a[i] > a[i - 1])
			for (int j = 0; j <= i; j++) {
				int dist = (a[i] - a[i - 1]) * j;
				for (int z = k; z >= dist; z--)
					dp[i][j][z] = dp[i][j][z - dist];
				for (int z = dist - 1; z >= 0; z--)
					dp[i][j][z] = 0;
			}
		for (int j = 0; j <= i; j++)
			for (int z = 0; z <= k; z++) {
				// open
				dp[i + 1][j + 1][z] = (dp[i + 1][j + 1][z] + dp[i][j][z]) % mod;
				// add
				dp[i + 1][j][z] = (dp[i + 1][j][z] + ll(j) * dp[i][j][z]) % mod;
				// close
				if (j) dp[i + 1][j - 1][z] = (dp[i + 1][j - 1][z] + ll(j) * dp[i][j][z]) % mod;
				// open/close
				dp[i + 1][j][z] = (dp[i + 1][j][z] + dp[i][j][z]) % mod;
			}
	}
	int res = 0;
	for (int z = 0; z <= k; z++)
		res = (res + dp[n][0][z]) % mod;
	printf("%d\n", res);
	return 0;
}