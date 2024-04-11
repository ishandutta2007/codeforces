#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void solve() {
	int n, m;
	cin >> n >> m;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	// Given x1 and x2, can toggle range of length |x1 - x2|
	// -> euclidean algorithm, can toggle range of length gcd_i b_i
	ll b = 0;
	for (int i = 0; i < m; ++i) {
		ll x;
		cin >> x;
		b = gcd(b, x);
	}

	ll even_sum = 0, odd_sum = 0;
	for (int i = 0; i < b; ++i) {
		ll val_even = 0, val_odd = -INF;
		for (int j = i; j < n; j += b) {
			ll nxt_even = max(val_even + as[j], val_odd - as[j]);
			ll nxt_odd = max(val_odd + as[j], val_even - as[j]);
			val_even = nxt_even;
			val_odd = nxt_odd;
		}
		even_sum += val_even;
		odd_sum += val_odd;
	}
	cout << max(even_sum, odd_sum) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}