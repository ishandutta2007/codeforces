#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int h, w;
	cin >> h >> w;

	int ty = -1, tx = -1;
	vector<string> arr(h);
	for (int y = 0; y < h; ++y) {
		cin >> arr[y];
		for (int x = 0; x < w; ++x) {
			if (arr[y][x] == 'L') {
				ty = y;
				tx = x;
			}
		}
	}

	vector<vector<int>> deg(h + 2, vector<int>(w + 2, 0));
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			if (arr[y][x] == '.' || arr[y][x] == 'L') deg[y + 1][x + 1] = 4;
		}
	}
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			if (deg[y + 1][x + 1] != 0) {
				for (int ind = 0; ind < 4; ++ind) {
					int y2 = y - (ind == 0) + (ind == 2);
					int x2 = x - (ind == 1) + (ind == 3);
					if (deg[y2 + 1][x2 + 1] == 0) --deg[y + 1][x + 1];
				}
			}
		}
	}

	vector<pair<int, int>> que;
	deg[ty + 1][tx + 1] = -1;
	que.emplace_back(ty + 1, tx + 1);
	for (int j = 0; j < que.size(); ++j) {
		int y = que[j].first, x = que[j].second;
		for (int ind = 0; ind < 4; ++ind) {
			int y2 = y - (ind == 0) + (ind == 2);
			int x2 = x - (ind == 1) + (ind == 3);
			int& d = deg[y2][x2];
			if (d > 0) {
				--d;
				if (d == 0 || d == 1) {
					d = -1;
					que.emplace_back(y2, x2);
				}
			}
		}
	}

	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			if (arr[y][x] == '.' && deg[y + 1][x + 1] == -1) arr[y][x] = '+';
		}
		cout << arr[y] << '\n';
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}