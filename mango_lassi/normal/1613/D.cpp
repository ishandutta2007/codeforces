#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> as(n);
	for (int& a : as) cin >> a;

	vector<ll> dp0(n + 2, 0), dp1(n + 2, 0); // dp1: sequences where mex + 1 already exists
	dp0[0] = 1;
	for (int i = 0; i < n; ++i) {
		dp0[as[i] + 1] = (2*dp0[as[i] + 1] + dp0[as[i]]) % MOD;
		if (as[i] > 0) dp1[as[i] - 1] = (2*dp1[as[i] - 1] + dp0[as[i] - 1]) % MOD;
		dp1[as[i] + 1] = (2 * dp1[as[i] + 1]) % MOD;
	}
	
	ll res = MOD - 1;
	for (ll& r : dp0) res = (res + r) % MOD;
	for (ll& r : dp1) res = (res + r) % MOD;
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}