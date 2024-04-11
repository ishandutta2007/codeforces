#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll modPow(ll a, ll b) {
	if (b & 1) return a * modPow(a, b - 1) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b / 2);
}

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> cs(n);
	for (int i = 0; i < n; ++i) cin >> cs[i];

	// -> Answer: k! * (k + 1)^{# positions i with value i
	// -> Trivial to count
	ll ans = 1;
	for (int i = 1; i <= k; ++i) ans = (ans * i) % MOD;

	for (int i = 0; i < n - k; ++i) {
		if (cs[i] == -1) ans = ans * ((k + 1) + i) % MOD;
		else if (cs[i] == 0) ans = ans * (k + 1) % MOD;
	}
	for (int i = n - k; i < n; ++i) {
		if (cs[i] > 0) ans = 0;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}