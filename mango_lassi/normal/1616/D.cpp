#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;
	vector<ll> as(n);
	for (ll& a : as) cin >> a;
	ll x;
	cin >> x;

	int res = 1;
	ll minv = as[0] - x;
	for (int i = 1; i < n; ++i) {
		if (minv + as[i] < x) {
			minv = INF;
		} else {
			++res;
			minv = min(0ll, minv) + (as[i] - x);
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}