/* Heroes Never Die. */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <class T> inline void read(T &_a) {
	bool _f = 0; int _c = 0; _a = 0;
	while (_c < '0' || _c > '9') _f |= _c == '-', _c = getchar();
	while (_c >= '0' && _c <= '9') _a = _a * 10 + _c - '0', _c = getchar();
	if (_f) _a = -_a;
}
#define MAXk 5005
#define MOD 1000000007


LL power(LL a, LL b) {
	LL ret = 1;
	for (a %= MOD; b; b >>= 1) {
		if (b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
	}
	return ret;
}

LL f[MAXk][MAXk], fac[MAXk], n, k, ans;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		f[i][1] = 1;
		for (int j = 2; j <= i; j++) {
			f[i][j] = f[i - 1][j] * j + f[i - 1][j - 1];
			f[i][j] %= MOD;
		}
	}
	fac[0] = 1; for (int i = 1; i <= k; i++) fac[i] = fac[i - 1] * i % MOD;
	LL j = n;
	for (int i = 1; i <= k; i++) {
		if (i > n) break;
		ans = ans + (fac[i] * f[k][i] % MOD * power(2, n - i) % MOD * j);
		ans %= MOD;
		j = j * (n - i) % MOD;
		j = j * power(i + 1, MOD - 2) % MOD;
	}
	printf("%d\n", (int)ans);
	return 0;
}