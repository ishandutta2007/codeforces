#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	ll s = 0;
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		s += v;
	}
	if (s % n == 0) cout << 0 << '\n';
	else cout << 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}