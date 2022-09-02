#include <iostream>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const ll TWOINV = 499122177;

const int N = 18;
ll dp[1<<N];
int conns[1<<N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[1<<a] |= 1<<b;
		conns[1<<b] |= 1<<a;
	}

	dp[0] = 1;
	for (int mask = 1; mask < (1<<n); ++mask) {
		for (int v = 1; v <= mask; v <<= 1) {
			if (mask & v) conns[mask] |= conns[v];
		}
		for (int sub = mask; sub; sub = ((sub - 1) & mask)) {
			if (conns[sub] & sub) continue;
			bool even = __builtin_parity(sub);
			if (even) dp[mask] += dp[mask ^ sub];
			else dp[mask] -= dp[mask ^ sub];
		}
	}

	ll res = dp[(1<<n)-1];
	if (res < 0) res += MOD;

	res = (res * m) % MOD;
	res = (res * TWOINV) % MOD;
	cout << res << '\n';
}