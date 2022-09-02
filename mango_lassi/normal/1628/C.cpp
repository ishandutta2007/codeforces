#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void build(int n, int y0, int x0, vector<vector<int>>& res) {
	int y1 = y0 + n - 2;
	int x1 = x0 + n - 1;
	for (int i = 0; i < n; ++i) {
		res[y0][x0 + i] = 1;
		res[y1][x0 + i] = 1;
	}
	if (n > 1) {
		for (int i = 1; i + 1 < n; ++i) {
			res[y0 + 1][x0 + i] = 1;
			res[y1 - 1][x0 + i] = 1;
		}
		for (int j = 2; j < n/2; ++j) {
			res[y0 + j][x0 + (j & 1)] = 1;
			res[y0 + j][x0 + 1 + (j & 1)] = 1;
			res[y1 - j][x0 + (j & 1)] = 1;
			res[y1 - j][x0 + 1 + (j & 1)] = 1;
			
			res[y0 + j][x1 - (j & 1)] = 1;
			res[y0 + j][x1 - 1 - (j & 1)] = 1;
			res[y1 - j][x1 - (j & 1)] = 1;
			res[y1 - j][x1 - 1 - (j & 1)] = 1;
		}
		if (n >= 10) {
			build(n - 8, y0 + 4, x0 + 4, res);
		}
	}
}

void solve() {
	int n;
	cin >> n;

	vector<vector<int>> res(n, vector<int>(n, 0));
	build(n, 0, 0, res);

	/*
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) cout << res[y][x]; cout << '\n';
	}
	*/

	ll ans = 0;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			ll v;
			cin >> v;
			if (res[y][x]) ans ^= v;
		}
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