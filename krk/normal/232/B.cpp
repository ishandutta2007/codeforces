#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 105;

int C[Maxn][Maxn];
int n, k;
ll m;
int dp[Maxn][Maxn * Maxn];

int Power(int a, ll pw)
{
	int res = 1;
	while (pw) {
		if (pw & 1ll) res = ll(res) * ll(a) % ll(mod);
		pw >>= 1ll; a = ll(a) * ll(a) % ll(mod);
	}
	return res;
}

int main()
{
	for (int i = 0; i < Maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	scanf("%d %I64d %d", &n, &m, &k);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		ll pw = ll(m - i - 1) / ll(n) + 1ll;
		for (int j = 0; j <= n; j++) {
			int ways = Power(C[n][j], pw);
			for (int l = 0; l <= i * n; l++)
				dp[i + 1][l + j] = (dp[i + 1][l + j] + ll(dp[i][l]) * ll(ways) % ll(mod)) % mod;
		}
	}
	printf("%d\n", dp[n][k]);
	return 0;
}