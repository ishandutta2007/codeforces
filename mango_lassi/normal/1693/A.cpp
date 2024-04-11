#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;
	for (int i = 1; i < n; ++i) as[i] += as[i - 1];
	
	bool works = 1, zero = 0;
	for (int i = 0; i < n; ++i) {
		if (as[i] < 0 || (as[i] > 0 && zero)) works = 0;
		if (as[i] == 0) zero = 1;
	}
	works &= zero;

	cout << (works ? "Yes" : "No") << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}