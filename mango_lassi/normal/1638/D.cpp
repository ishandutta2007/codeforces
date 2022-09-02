#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int H = 1000;
const int W = 1000;
int arr[H][W];

int works(int y, int x, int h, int w) {
	if (y < 0 || y + 1 >= h || x < 0 || x + 1 >= w) return 0;

	int c0 = arr[y][x];
	int c1 = arr[y+1][x];
	int c2 = arr[y][x+1];
	int c3 = arr[y+1][x+1];

	int col = max(max(c0, c1), max(c2, c3));
	if (col == 0) return 0;
	if (c0 != col && c0 != 0) return 0;
	if (c1 != col && c1 != 0) return 0;
	if (c2 != col && c2 != 0) return 0;
	if (c3 != col && c3 != 0) return 0;
	return col;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) cin >> arr[y][x];
	}

	vector<pair<int, int>> que;
	for (int y = 0; y + 1 < h; ++y) {
		for (int x = 0; x + 1 < w; ++x) {
			if (works(y, x, h, w)) que.emplace_back(y, x);
		}
	}

	vector<pair<int, pair<int, int>>> res;
	for (int ind = 0; ind < que.size(); ++ind) {
		int y0, x0;
		tie(y0, x0) = que[ind];
		
		int col = works(y0, x0, h, w);
		if (col == 0) continue;
		res.emplace_back(col, make_pair(y0, x0));

		for (int y = y0; y <= y0 + 1; ++y) {
			for (int x = x0; x <= x0 + 1; ++x) arr[y][x] = 0;
		}
		for (int y = y0 - 1; y <= y0 + 1; ++y) {
			for (int x = x0 - 1; x <= x0 + 1; ++x) {
				if (works(y, x, h, w)) que.emplace_back(y, x);
			}
		}
	}
	
	bool ac = 1;
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) ac &= (arr[y][x] == 0);
	}

	if (ac) {
		reverse(res.begin(), res.end());

		cout << res.size() << '\n';
		for (auto pr : res) {
			cout << pr.second.first + 1 << ' ' << pr.second.second + 1 << ' ' << pr.first << '\n';
		}
	} else {
		cout << -1 << '\n';
	}
}