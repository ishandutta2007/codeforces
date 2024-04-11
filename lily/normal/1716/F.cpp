#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

const int N = 2e5 + 5;
const int MOD = 998244353;

int n, m, K;

LL power (LL x, LL y) {
	LL ret = 1;
	for ( ; y; y >>= 1) {
		if (y & 1) ret = ret * x % MOD;
		x = x * x % MOD;
	}
	return ret;
}

LL S[2005][2005], inv[2005];

void work() {
	read(n); read(m); read(K);
	if (m == 1) {
		printf("%d\n", int(power(n, K)));
		return;
	}
	LL base = (m + 1) / 2, ww = base * power (m, MOD - 2) % MOD;
	LL ans = 0, w = 1, fac = 1, mm = power (m, n);
	for (int j = 0; j <= K; j++) {
		if (j >= 1) fac = fac * j % MOD;
		ans = (ans + w * S[K][j] % MOD * fac % MOD * mm) % MOD;
		w = w * (n - j) % MOD;
		w = w * inv[j + 1] % MOD;
		mm = mm * ww % MOD;
		if (w == 0) break;
	}
	ans = ans % MOD;
	printf("%d\n", (int)ans);
}

int main() {
	S[0][0] = 1;
	for (int n = 1; n <= 2000; n++) {
		for (int k = 1; k <= n; k++) {
			S[n][k] = (k * S[n - 1][k] + S[n - 1][k - 1]) % MOD;
		}
	}
	for (int i = 1; i <= 2000; i++) inv[i] = power(i, MOD - 2);
	int T; read(T);
	while (T--) work();
}