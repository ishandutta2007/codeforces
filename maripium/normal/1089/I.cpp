#include <bits/stdc++.h>
using namespace std;

int mod;
int fac[405];
int f0[405], f1[405];
int g[405][405], sumg[405][405];
int ans[405];

void add(int& x,int y) {
	x += y; if (x >= mod) x -= mod;
}

void sub(int& x,int y) {
	x -= y; if (x < 0) x += mod;
}

int mul(int x,int y) {
	return (long long) x * y % mod;
}

int main() {
	int tt; scanf("%d %d", &tt, &mod);
	fac[0] = 1;
	for (int i = 1; i <= 400; ++i) fac[i] = mul(fac[i - 1], i);
	for (int n = 1; n <= 400; ++n) {
		f0[n] = fac[n];
		for (int i = 2; i <= n - 1; ++i) {
			sub(f0[n], mul(f0[i], mul(fac[n - i], n - i + 1)));
		}
	}
	for (int n = 1; n <= 400; ++n) {
		f1[n] = fac[n - 1];
		for (int i = 2; i <= n - 1; ++i) {
			sub(f1[n], mul(f1[i], fac[n - i]));
		}
	}
	for (int n = 1; n <= 400; ++n) {
		int tot = 0;
		for (int k = 0; k <= n - 1; ++k) {
			for (int len = 2; len <= min(n - 1, n - k); ++len) {
				if (k == 1 && len == n - 1) {
					add(g[n][k], f0[n - 1]);
					add(g[n][k], f0[n - 1]);
					sub(g[n][k], f1[n - 1]);
					sub(g[n][k], f1[n - 1]);
				}
				else {
					int now = fac[n - len + 1];
					if (k) sub(now, sumg[n - len + 1][k - 1]);
					add(g[n][k], mul(f0[len], now)); 
				}
			}
			add(tot, g[n][k]);
			sumg[n][k] = tot;
		}
	}
	for (int n = 1; n <= 400; ++n) {
		ans[n] = fac[n];
		for (int i = 0; i <= n - 2; ++i) sub(ans[n], g[n][i]);
	}
	while (tt--) {
		int n; scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
}