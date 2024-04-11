#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<ll> mxs(k, 0);
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		mxs[i % k] = max(mxs[i % k], v);
	}

	ll res = 0;
	for (ll v : mxs) res += v;
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}