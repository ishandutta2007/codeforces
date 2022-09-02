#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e9;

void solve() {
	ll a, b;
	cin >> a >> b;

	ll base = (b == 1);
	if (b == 1) b = 2;

	ll res = INF;
	for (int k = 0; k <= 40; ++k) {
		ll off = base + k;
		for (ll tmp = a; tmp; tmp /= (b + k)) ++off;
		res = min(res, off);
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