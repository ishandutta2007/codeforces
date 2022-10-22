#include <cstdio>
using namespace std;

const int mod = 1000000007;
const int Maxn = 2005;
const int Maxk = 11;

int n, k;
int a[Maxn];
int dp[Maxn][1 << Maxk];
int res;

int getMask(int mask, int add)
{
	if (add == 4 && mask & 1) return (mask & 1 << k - 1) | 1 << 1;
	int tims = add == 2? 0: 1;
	while (tims + 1 < k)
		if (!(mask & 1 << tims)) return mask | 1 << tims;
		else { mask ^= 1 << tims; tims++; }
	return mask | 1 << tims;
}

int main()
{
	scanf("%d %d", &n, &k);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		for (int j = 0; j < 1 << k; j++)
			if (dp[i][j]) {
				int nj;
				if (a[i] == 0 || a[i] == 2) {
					nj = getMask(j, 2);
					dp[i + 1][nj] = (dp[i + 1][nj] + dp[i][j]) % mod;
				}
				if (a[i] == 0 || a[i] == 4) {
					nj = getMask(j, 4);
					dp[i + 1][nj] = (dp[i + 1][nj] + dp[i][j]) % mod;
				}
			}
	}
	for (int j = 0; j < 1 << k; j++)
		if (j & 1 << k - 1) res = (res + dp[n][j]) % mod;
	printf("%d\n", res);
	return 0;
}