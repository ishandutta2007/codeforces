#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	if (2*k - 1 > n) cout << -1 << '\n';
	else {
		for (int y = 0; y < n; ++y) {
			string row(n, '.');
			if (y % 2 == 0 && y / 2 < k) row[y] = 'R';
			cout << row << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}