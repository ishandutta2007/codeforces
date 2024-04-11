#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

const int Maxn = 205;
const int Maxp = 5;
const int lft[Maxp] = {4, 3, 2, 1, 2};
const int inter[Maxp] = {4, 2, 1, 0, 0};
const int Maxm = 2 * Maxp;

int C[Maxm][Maxm];
int dp[Maxn][Maxn][Maxp][3];
int n, k;
int res;

int Get(int v, int k, int tk, int opt)
{
	if (dp[v][k][tk][opt] == -1) {
		int res = 0;
		if (opt == 0) {
			res = Get(v, k, tk, 1);
			if (tk == 0) {
				if (k >= 1) {
					res = (res + ll(Get(v, k - 1, 1, 1)) * 4ll % ll(mod)) % mod;
					res = (res + ll(Get(v, k - 1, 2, 1)) * 4ll % ll(mod)) % mod;
				}
				if (k >= 2) {
					res = (res + ll(Get(v, k - 2, 2, 1)) * 4ll % ll(mod)) % mod;
					res = (res + ll(Get(v, k - 2, 4, 1)) * 2ll % ll(mod)) % mod;
					res = (res + ll(Get(v, k - 2, 3, 1)) * 8ll % ll(mod)) % mod;
				}
				if (k == 2) res = (res + 2) % mod;
				if (k >= 3) res = (res + ll(Get(v, k - 3, 3, 1)) * 4ll % ll(mod)) % mod;
				if (k == 3) res = (res + 4) % mod;
				if (k == 4) res = (res + 1) % mod;
			} else if (tk == 1) {
				if (k >= 1) {
					res = (res + ll(Get(v, k - 1, 2, 1)) * 2ll % ll(mod)) % mod;
					res = (res + Get(v, k - 1, 4, 1)) % mod;
					res = (res + ll(Get(v, k - 1, 3, 1)) * 2ll % ll(mod)) % mod;
				}
				if (k >= 2) res = (res + ll(Get(v, k - 2, 3, 1)) * 3ll % ll(mod)) % mod;
				if (k == 2) res = (res + 2) % mod;
				if (k == 3) res = (res + 1) % mod;
			} else if (tk == 2) {
				if (k >= 1) res = (res + ll(Get(v, k - 1, 3, 1)) * 2ll % ll(mod)) % mod;
				if (k == 1) res = (res + 1) % mod;
				if (k == 2) res = (res + 1) % mod;
			} else if (tk == 3) {
				if (k == 1) res = (res + 1) % mod;
			} else if (tk == 4) {
				if (k >= 1) res = (res + ll(Get(v, k - 1, 3, 1)) * 2ll % ll(mod)) % mod;
				if (k == 2) res = (res + 1) % mod;
			}
		} else if (opt == 1)
			if (v == 0) res = k == 0;
			else {
				int parts = 2 * lft[tk], in = inter[tk];
				for (int i = 0; i <= in && i <= k; i++)
					for (int j = 0; 2 * i + j <= parts && i + j <= k; j++)
						res = (res + ll(C[in][i]) * ll(C[parts - 2 * i][j]) % ll(mod) * ll(Get(v, k - i - j, tk, 2)) % ll(mod)) % mod;
			}
		else if (opt == 2) {
			int parts = lft[tk];
			for (int i = 0; i <= parts && i <= k; i++)
				res = (res + ll(C[parts][i]) * ll(Get(v - 1, k - i, tk, 0)) % ll(mod)) % mod;
		}
		dp[v][k][tk][opt] = res;
	}
	return dp[v][k][tk][opt];
}

int main()
{
	for (int i = 0; i < Maxm; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	fill((int*)dp, (int*)dp + Maxn * Maxn * Maxp * 3, -1);
	scanf("%d %d", &n, &k);
	res = Get(n, k, 0, 0);
	for (int i = 2; i <= k; i++) res = ll(res) * ll(i) % ll(mod);
	printf("%d\n", res);
	return 0;
}