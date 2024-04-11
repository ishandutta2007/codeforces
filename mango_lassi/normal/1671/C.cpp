#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	ll x;
	cin >> n >> x;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;
	sort(as.begin(), as.end());

	ll res = 0, d = 0, sum = 0;
	for (ll a : as) sum += a;
	for (int i = n-1; i >= 0; --i) {
		int c = i + 1;
		ll base = sum + d * c;

		if (base <= x) {
			ll diff = (x - base) / c + 1;
			res += c * diff;
			d += diff;
		}
		sum -= as[i];
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