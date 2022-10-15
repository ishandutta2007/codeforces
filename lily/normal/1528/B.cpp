#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 5;
const int MOD = 998244353;

int n;
LL g[N], f[N], sf[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			(++g[j]) %= MOD;
		}
	}
	// g : full
	for (int i = 1; i <= n; i++) {
		f[i] += sf[i - 1];
		f[i] += g[i];
		f[i] %= MOD;
		sf[i] = sf[i - 1] + f[i];
		sf[i] %= MOD;
	}
	printf("%lld\n", (f[n] + MOD) % MOD);
}