#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxm = 405;

int fac[Maxm], ifac[Maxm], inum[Maxm];
int n, k;
int dp[Maxm][Maxm];
int res[Maxm];

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

int main()
{
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < Maxm; i++) {
		fac[i] = ll(i) * fac[i - 1] % mod;
		ifac[i] = Inv(fac[i]);
		inum[i] = Inv(i);
	}
	scanf("%d %d", &n, &k);
	dp[0][0] = 1;
	for (int i = 0; i <= k; i++)
		for (int j = 0; j <= i; j++) if (dp[i][j]) {
			res[i] = (res[i] + ll(dp[i][j]) * ifac[j]) % mod;
			int cur = n - i - j;
			for (int s = 2; s + j + i <= n && i + s - 1 <= k; s++) {
				cur = ll(cur) * (n - i - j + 1 - s) % mod;
				dp[i + s - 1][j + 1] = (dp[i + s - 1][j + 1] + ll(cur) * inum[s] % mod * dp[i][j]) % mod;
			}
		}
	for (int i = 1; i <= k; i++) {
		if (i >= 2) res[i] = (res[i] + res[i - 2]) % mod;
		printf("%d%c", res[i], i + 1 <= k? ' ': '\n');
	}
    return 0;
}