#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int findNext(const vector<int>& vec, int v) {
	int low = 0;
	int high = (int)vec.size() - 1;
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] <= v) low = mid + 1;
		else high = mid;
	}
	return vec[low];
}
int findPrev(const vector<int>& vec, int v) {
	int low = 0;
	int high = (int)vec.size() - 1;
	while(low != high) {
		int mid = (low + high + 1) >> 1;
		if (vec[mid] >= v) high = mid - 1;
		else low = mid;
	}
	return vec[low];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w, m;
	cin >> h >> w >> m;

	vector<vector<int>> row(h), col(w);
	for (int i = 0; i < m; ++i) {
		int y, x;
		cin >> y >> x;
		--y; --x;
		row[y].push_back(x);
		col[x].push_back(y);
	}
	for (int i = 0; i < w; ++i) {
		col[i].push_back(-1);
		col[i].push_back(h);
		sort(col[i].begin(), col[i].end());
	}
	for (int i = 0; i < h; ++i) {
		row[i].push_back(-1);
		row[i].push_back(w);
		sort(row[i].begin(), row[i].end());
	}

	// Exactly once!
	// -> If there is ever an empty space to our left, we immediately lose. Getting there will be impossible
	// -> Our path must be a spiral
	// -> Simulate walking the spiral, then see that we visited all squares once

	int x = 0, y = 0, d = 0;
	ll v = 1;
	int minx = -1, miny = -1;
	int maxx = w, maxy = h;
	while(true) {
		if (d == 0) {
			int nx = min(maxx, findNext(row[y], x)) - 1;
			if (nx == x && v != 1) break;
			v += nx - x;
			x = nx;
			miny = y;
		} else if (d == 1) {
			int ny = min(maxy, findNext(col[x], y)) - 1;
			if (ny == y) break;
			v += ny - y;
			y = ny;
			maxx = x;
		} else if (d == 2) {
			int nx = max(minx, findPrev(row[y], x)) + 1;
			if (nx == x) break;
			v += x - nx;
			x = nx;
			maxy = y;
		} else if (d == 3) {
			int ny = max(miny, findPrev(col[x], y)) + 1;
			if (ny == y) break;
			v += y - ny;
			y = ny;
			minx = x;
		}
		d = (d + 1) % 4;
	}
	if (v == (ll)w*h - m) cout << "Yes\n";
	else cout << "No\n";
}