#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;

	ll res = -(ll)k * (k - 1) / 2;
	vector<ll> vals(n);
	for (int i = 0; i < n; ++i) {
		cin >> vals[i];
		res += vals[i];
		vals[i] -= n - 1 - i;
	}
	sort(vals.rbegin(), vals.rend());
	for (int i = 0; i < k; ++i) res -= vals[i];
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}