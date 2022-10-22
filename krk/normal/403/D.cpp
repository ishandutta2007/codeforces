#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 1005;
const int Maxm = 2005;
const int mod = 1000000007;

int C[Maxn][Maxn];
int dp[Maxn][Maxm];
int fac[Maxn];
int t;
int n, k;

int C_(int pl, int k) { return pl < k - 1? 0: C[pl + 1][pl - k + 1]; }

int main()
{
	for (int i = 0; i < Maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	dp[0][0] = 1;
	for (int i = 1; i < Maxn; i++)
		for (int j = 0; j < Maxm; j++)
			for (int k = i; j - k >= 0; k += i) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
			}
	fac[0] = 1;
	for (int i = 1; i < Maxn; i++)
		fac[i] = ll(i) * fac[i - 1] % mod;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		int res = 0;
		for (int i = 0; i <= n - 1; i++)
			res = (res + ll(dp[k][i + k]) * C_(n - 1 - i, k) % mod) % mod;
		res = ll(res) * fac[k] % mod;
		printf("%d\n", res);
	}
	return 0;
}