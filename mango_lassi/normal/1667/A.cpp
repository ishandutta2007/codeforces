#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	ll res = INF;
	// Loop where we have a 0
	for (int i = 0; i < n; ++i) {
		ll pre = 0, off = 0;
		for (int j = i + 1; j < n; ++j) {
			ll c = pre / as[j] + 1;
			off += c;
			pre = c * as[j];
		}
		pre = 0;
		for (int j = i - 1; j >= 0; --j) {
			ll c = pre / as[j] + 1;
			off += c;
			pre = c * as[j];
		}
		res = min(res, off);
	}
	cout << res << '\n';
}