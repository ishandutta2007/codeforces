#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	ll odd = 0, even = 0;
	vector<ll> as(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
		if (i & 1) odd += as[i];
		else even += as[i];
	}
	int s = (odd < even);
	for (int i = 0; i < n; ++i) {
		if ((i % 2) == s) cout << 1 << ' ';
		else cout << as[i] << ' ';
	}
	cout << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}