#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;

bool solve() {
	int n;
	cin >> n;

	vector<ll> as(n), bs(n);
	for (ll& v : as) cin >> v;
	for (ll& v : bs) cin >> v;

	// x: How much of bs[n-1] goes to as[n-1]
	ll low_x = 0;
	ll high_x = bs[n-1];
	ll cur = bs[n-1];
	for (int i = 0; i+1 < n; ++i) {
		ll need = as[i] - cur;
		if (need < 0) {
			low_x -= need;
			need = 0;
		}

		cur = bs[i] - need;
		high_x = min(high_x, cur + low_x);
	}
	if (high_x < 0) return false;
	
	cur = bs[n-1] - high_x;
	for (int i = 0; i < n; ++i) {
		cur += (i == n-1 ? high_x : bs[i]) - as[i];
		cur = min(cur, bs[i]);
		if (cur < 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		bool can = solve();
		if (can) cout << "YES\n";
		else cout << "NO\n";
	}
}