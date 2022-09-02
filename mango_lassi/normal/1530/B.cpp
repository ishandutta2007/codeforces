#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void addIfCan(int y, int x, vector<string>& res) {
	bool works = 1;
	for (int dy = -1; dy <= 1; ++dy) {
		for (int dx = -1; dx <= 1; ++dx) {
			int ty = y + dy;
			int tx = x + dx;
			if (ty >= 0 && ty < res.size() && tx >= 0 && tx < res[0].size()) {
				if (res[ty][tx] == '1') works = 0;
			}
		}
	}
	if (works) res[y][x] = '1';
}

void solve() {
	int h, w;
	cin >> h >> w;

	vector<string> res(h, string(w, '0'));
	for (int x = 0; x < w; ++x) {
		int y = 0;
		addIfCan(y, x, res);
	}
	for (int y = 1; y < h; ++y) {
		int x = w - 1;
		addIfCan(y, x, res);
	}
	for (int x = w - 2; x >= 0; --x) {
		int y = h - 1;
		addIfCan(y, x, res);
	}
	for (int y = h - 2; y >= 0; --y) {
		int x = 0;
		addIfCan(y, x, res);
	}

	for (int y = 0; y < h; ++y) cout << res[y] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}