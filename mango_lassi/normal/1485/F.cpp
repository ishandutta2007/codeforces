#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7;

void solve() {
	int n;
	cin >> n;

	ll sum = 0, ans = 1;
	map<ll, ll> res;
	res[0] = 1;

	for (int i = 0; i < n; ++i) {
		ll b;
		cin >> b;
		
		ll tmp = res[-sum];
		res[-sum] = ans;
		ans = (2 * ans - tmp) % MOD;
		sum += b;
	}

	if (ans < 0) ans += MOD;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}