#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)
#define MOD 998244353

int n;
LL fac[1000055], fuck[1000055];

int main() {
	cin >> n;
	fac[0] =1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i % MOD;
	}
	fuck[n + 1] = 1;
	for (int i = n; ~i; i--) {
		fuck[i] = fuck[i + 1] * i % MOD;
	}
	LL ans = fac[n];
	for (int i = 1; i <= n - 1; i++) {
		ans += fuck[n - i + 1] * (fac[n - i] - 1);
		ans %= MOD;
	}
	printf("%lld\n", (ans + MOD) % MOD);
	return 0;
}