#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void solve() {
	int h;
	cin >> h;
	int n = 2*h;

	vector<vector<ll>> cs(n, vector<ll>(n));
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) cin >> cs[y][x];
	}
	
	// 1. Remove all snow in topleft and bottom right quadrants
	ll base = 0;
	vector<vector<ll>> le_sum = cs, up_sum = cs;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if ((y < h) == (x < h)) {
				base += cs[y][x];
				cs[y][x] = 0;
			}
			if (y > 0) up_sum[y][x] += up_sum[y-1][x];
			if (x > 0) le_sum[y][x] += le_sum[y][x-1];
		}
	}

	ll res = INF;

	res = min(res, cs[h][0]);
	res = min(res, cs[h][h-1]);
	res = min(res, cs[0][h]);
	res = min(res, cs[h-1][h]);

	res = min(res, cs[n-1][0]);
	res = min(res, cs[n-1][h-1]);
	res = min(res, cs[0][n-1]);
	res = min(res, cs[h-1][n-1]);

	cout << res + base << '\n';
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}