#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> as(n), bs(n);
	for (int& a : as) cin >> a;
	for (int& b : bs) cin >> b;
	
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		if (as[i] > bs[i]) swap(as[i], bs[i]);
		if (i > 0) res += abs(as[i] - as[i-1]) + abs(bs[i] - bs[i-1]);
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