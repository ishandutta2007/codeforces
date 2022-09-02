#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void solve() {
	ll a, b;
	cin >> a >> b;
	if (a > b) {
		cout << a - b << '\n';
	} else {
		ll res = INF;
		for (ll y = 0; y < res; ++y) {
			ll v2 = b + y;
			for (ll v1 = v2; v1 >= a; v1 = (v1 - 1) & v2) {
				res = min(res, (v1 - a) + (v2 - b) + (v1 < v2));
			}
		}
		cout << res << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}