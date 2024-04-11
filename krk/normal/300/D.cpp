#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 32;
const int Maxm = 1001;
const int mod = 7340033;

int dp[Maxn][Maxm];
int q;

int main()
{
	dp[0][0] = 1;
	for (int i = 1; i < Maxn; i++) {
		dp[i][0] = dp[i][1] = 1;
		for (int j = 0; j < 4; j++)
			for (int l = Maxm - 1; l >= 1; l--) if (dp[i][l])
				for (int k = 1; l + k < Maxm && dp[i - 1][k]; k++)
					dp[i][l + k] = (dp[i][l + k] + ll(dp[i][l]) * ll(dp[i - 1][k]) % ll(mod)) % mod;
	}
	scanf("%d", &q);
	while (q--) {
		int n, k; scanf("%d %d", &n, &k);
		int lvl = 0;
		while (n % 2 && n > 1) { lvl++; n /= 2; }
		printf("%d\n", dp[lvl][k]);
	}
	return 0;
}