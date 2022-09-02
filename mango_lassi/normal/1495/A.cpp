#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
	int n;
	cin >> n;

	vector<ll> xs, ys;
	for (int i = 0; i < 2*n; ++i) {
		ll x, y;
		cin >> x >> y;
		if (x == 0) ys.push_back(abs(y));
		else xs.push_back(abs(x));
	}
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	
	ld res = 0;
	for (int i = 0; i < n; ++i) {
		res += sqrt(ld(xs[i] * xs[i] + ys[i] * ys[i]));
	}
	cout << fixed << setprecision(12) << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}