#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll count(int x0, int x1, int y0, int y1, const vector<string>& grid) {
	ll res = 0;
	for (int y = y0; y <= y1; ++y) {
		for (int x = x0; x <= x1; ++x) {
			res += (grid[y][x] == 'A');
		}
	}
	return res;
}

int solve() {
	int h, w;
	cin >> h >> w;

	vector<string> grid(h);
	for (int y = 0; y < h; ++y) cin >> grid[y];

	// If we have none, impossible or already done
	ll tot = count(0, w-1, 0, h-1, grid);
	if (tot == 0) return -1;
	if (tot == (ll)h*w) return 0;

	// If we have one of the four sides: Possible in one
	ll cs0 = count(0, w-1, 0, 0, grid);
	ll cs1 = count(0, w-1, h-1, h-1, grid);
	ll cs2 = count(0, 0, 0, h-1, grid);
	ll cs3 = count(w-1, w-1, 0, h-1, grid);
	if (cs0 == w || cs1 == w || cs2 == h || cs3 == h) return 1;

	// If we have any corner or any vertical or horizontal row: Possible in two
	if (grid[0][0] == 'A' || grid[0][w-1] == 'A' || grid[h-1][0] == 'A' || grid[h-1][w-1] == 'A') return 2;
	for (int x = 0; x < w; ++x) {
		if (count(x, x, 0, h-1, grid) == h) return 2;
	}
	for (int y = 0; y < h; ++y) {
		if (count(0, w-1, y, y, grid) == w) return 2;
	}

	// If we have none at sides: Need four
	if (cs0 + cs1 + cs2 + cs3 == 0) return 4;

	// Otherwise, answer 3
	return 3;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int res = solve();
		if (res == -1) cout << "MORTAL\n";
		else cout << res << '\n';
	}
}