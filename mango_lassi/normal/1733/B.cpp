#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	if (x > y) swap(x, y);

	if (x != 0 || y == 0 || ((n-1) % y != 0)) {
		cout << -1 << '\n';
	} else {
		for (int i = 1; i <= n-1; i += y) {
			for (int j = 0; j < y; ++j) cout << i + 1 << ' ';
		}
		cout << '\n';
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}