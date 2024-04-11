#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int MOD = 1000000007;

typedef long long LL;
LL power(LL x, LL y) {
	LL ret = 1;
	for ( ; y; y >>= 1) {
		if (y & 1) ret = ret * x % MOD;
		x = x * x % MOD;
	}
	return ret;
}

LL fac[N], inv[N];

LL C(LL x, LL y) {
	if (x < y || y < 0) return 0;
	return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int n, K;
void work() {
	scanf("%d%d", &n, &K);
	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		int occ = (i - 1) * (K - 1);
		if (occ + i > n) break;
		ans += C(n - occ, i) * power(C(n, i), MOD - 2) % MOD;
		ans %= MOD;
	}
	printf("%lld\n", (ans % MOD + MOD + 1) % MOD);
}

int main() {
	fac[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = fac[i - 1] * i % MOD;
	}
	inv[N - 1] = power(fac[N - 1], MOD - 2);
	for (int i = N - 2; i >= 0; i--) {
		inv[i] = inv[i + 1] * (i + 1) % MOD;
	}
	int T;
	scanf("%d", &T);
	while (T--) work();
}