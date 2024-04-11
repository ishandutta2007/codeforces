#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int h, w;
	cin >> h >> w;

	vector<string> arr(h);
	for (int y = h-1; y >= 0; --y) cin >> arr[y];

	vector<int> needs(w);
	for (int& a : needs) cin >> a;
	
	// If all blocks below y drop on previous column, what is the highest block that drops in the previous column?
	// (assuming columns past it don't exist)
	vector<int> prev_cascade(h);
	for (int y = 0; y < h; ++y) prev_cascade[y] = y;
	
	int res = 0; // Answer
	int prev_max_y = -1; // Highest block in previous column
	int prev_min_y = -1; // y of lowest block we have to drop on previous column
	int prev_drop = -1; // y of highest block dropping for free in previous column

	for (int x = 0; x < w; ++x) {
		// Get highest block
		int max_y = -1;
		for (int y = 0; y < h; ++y) {
			if (arr[y][x] == '#') max_y = y;
		}

		// Get cascade
		vector<int> cascade(h, -1);
		for (int y = 0; y < h; ++y) {
			if (arr[y][x] == '#') cascade[y] = y;
			else if (y > 0) cascade[y] = cascade[y-1];
		}
		for (int y = h-1; y >= 0; --y) {
			if (arr[y][x] != '#') continue;
			if (y+1 < h && arr[y+1][x] == '#') cascade[y] = cascade[y+1];
			else if (prev_cascade[y] != -1) cascade[y] = max(cascade[y], cascade[prev_cascade[y]]);
		}
		for (int y = 1; y < h; ++y) cascade[y] = max(cascade[y-1], cascade[y]);

		// Check if we can drop previous column
		// If we cannot, drop its highest block (guaranteed to drop this column as well)
		if (max_y < prev_min_y) {
			++res;
			prev_min_y = -1;
			prev_drop = max_y;
		} else {
			// Compute min y that needs to drop to satisfy counter of this column
			int min_y = -1;
			for (int y = 0; needs[x] > 0; ++y) {
				if (arr[y][x] == '#') {
					--needs[x];
					min_y = y;
				}
			}

			// Force min_y to drop prev_min_y
			if (prev_min_y >= 0) {
				while((min_y < prev_min_y) || (arr[min_y][x] != '#')) ++min_y;
			}

			// Update min_y with cascade
			if (min_y >= 0) {
				for (int y = 0; y < h; ++y) {
					if (cascade[y] >= min_y) {
						min_y = y;
						break;
					}
				}
			}


			// Get dropping y
			int drop = (prev_drop >= 0 ? cascade[prev_drop] : -1);
			if (min_y <= drop) min_y = -1;

			// Change to new values
			prev_min_y = min_y;
			prev_drop = drop;
		}
		prev_max_y = max_y;
		prev_cascade = cascade;

		// cerr << x << ' ' << res << ": " << prev_max_y << ' ' << prev_min_y << ' ' << prev_drop << ": ";
		// for (int y = 0; y < h; ++y) cerr << prev_cascade[y] << ' '; cerr << '\n';
	}

	if (prev_min_y >= 0) ++res;
	cout << res << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	// cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}