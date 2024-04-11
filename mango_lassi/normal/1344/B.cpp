#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1000;
string arr[N];

int dfs(int y, int x, int h, int w) {
	if (arr[y][x] != '#') return 0;
	arr[y][x] = '.';
	if (y > 0) dfs(y-1, x, h, w);
	if (x > 0) dfs(y, x-1, h, w);
	if (y+1 < h) dfs(y+1, x, h, w);
	if (x+1 < w) dfs(y, x+1, h, w);
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;
	
	// "ON" positions must form a interval on every row and column
	// There must be no row or column of "OFF" positions, or there must be both such a row and such a column
	// These are the only requirements. As long as they are met, the answer is number of components.
	// Place one "NORTH" magnet in every component, and a "SOUTH" magnet in every position in the component.
	//	Place a "SOUTH" magnet in every intersection of empty rows and columns
	// Proof: after every operation, every "NORTH" magnet is on some "SOUTH" magnet.

	for (int y = 0; y < h; ++y) cin >> arr[y];

	bool fail = false;
	bool empty_row = 0;
	bool empty_col = 0;

	for (int y = 0; y < h; ++y) {
		int state = 0;
		for (int x = 0; x < w; ++x) {
			if (arr[y][x] == '#') {
				if (state % 2 == 0) ++state;
			} else {
				if (state % 2 == 1) ++state;
			}
		}
		if (state == 0) empty_row = 1;
		if (state > 2) fail = true;
	}
	for (int x = 0; x < w; ++x) {
		int state = 0;
		for (int y = 0; y < h; ++y) {
			if (arr[y][x] == '#') {
				if (state % 2 == 0) ++state;
			} else {
				if (state % 2 == 1) ++state;
			}
		}
		if (state == 0) empty_col = 1;
		if (state > 2) fail = true;
	}

	if (empty_row != empty_col) fail = true;

	if (fail) cout << -1 << '\n';
	else {
		int res = 0;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) res += dfs(y, x, h, w);
		}
		cout << res << '\n';
	}
}