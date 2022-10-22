#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353

int n;
ll ans, prv, prvv;
ll inv2;

int main() {
	scanf("%d", &n);
	prv = prvv = ans = 1;
	inv2 = 1;
	for (int i = 0; i < n; i++) inv2 = (inv2 * (MOD + 1) / 2) % MOD;
	for (int i = 3; i <= n; i++) {
		ans = prv + prvv;
		ans %= MOD;
		prvv = prv;
		prv = ans;
	}
	ans = ans * inv2 % MOD;
	printf("%lld\n", ans);
	return 0;
}