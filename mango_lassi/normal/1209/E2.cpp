#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
	int h, w;
	cin >> h >> w;

	vector<vector<int>> mat(h, vector<int>(w));
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) cin >> mat[y][x];
	}
	vector<pair<int, int>> opt(w);
	for (int x = 0; x < w; ++x) {
		opt[x] = {0, x};
		for (int y = 0; y < h; ++y) {
			opt[x].first = max(opt[x].first, mat[y][x]);
		}
	}
	sort(opt.begin(), opt.end());
	reverse(opt.begin(), opt.end());
	if (w > h) w = h;

	vector<vector<int>> act(w, vector<int>(h));
	for (int j = 0; j < w; ++j) {
		int x = opt[j].second;
		for (int y = 0; y < h; ++y) act[j][y] = mat[y][x];
	}

	vector<vector<int>> dp(w+1, vector<int>(1<<h, 0));
	vector<vector<int>> base(w+1, vector<int>(1<<h, 0));
	for (int x = w-1; x >= 0; --x) {
		for (int m = 0; m < (1<<h); ++m) {
			for (int i = 0; i < h; ++i) {
				int off = 0;
				for (int j = 0; j < h; ++j) {
					if (m & (1<<j)) off += act[x][(i + j) % h];
				}
				base[x][m] = max(base[x][m], off);
			}
		}
	}
	for (int x = w-1; x >= 0; --x) {
		for (int m = 0; m < (1<<h); ++m) {
			dp[x][m] = base[x][m];
			for (int s = m; s; s = (s-1)&m) {
				dp[x][m] = max(dp[x][m], base[x][m ^ s] + dp[x+1][s]);
			}
		}
	}
	cout << dp[0][(1<<h)-1] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}