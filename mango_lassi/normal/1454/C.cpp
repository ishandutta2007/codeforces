#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> locs(n);
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		locs[c-1].push_back(i);
	}

	int ans = n;
	for (int c = 0; c < n; ++c) {
		if (locs[c].empty()) continue;

		int pre = -1, off = 0;
		for (auto i : locs[c]) {
			if (i > pre + 1) ++off;
			pre = i;
		}
		if (pre + 1 != n) ++off;
		ans = min(ans, off);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}