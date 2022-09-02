#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;

const int H = 2 * (int)1e5;
vector<int> xs[H];

// Find last index with value <= val
int bins(const vector<int>& vec, int val) {
	int low = -1;
	int high = (int)vec.size() - 1;
	while(low != high) {
		int mid = (low + high + 1) >> 1;
		if (vec[mid] <= val) low = mid;
		else high = mid - 1;
	}
	return low;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w, t, c;
	cin >> h >> w >> t >> c;
	
	// At the previous level, we always end at either the leftmost or the rightmost treasure
	// store cost for both, use optimal continuation.

	for (int j = 0; j < t; ++j) {
		int y, x;
		cin >> y >> x;
		xs[y-1].push_back(x);
	}
	vector<int> cols(c);
	for (int j = 0; j < c; ++j) cin >> cols[j];
	sort(cols.begin(), cols.end());

	pair<int, ll> off1 = {1, 0};
	pair<int, ll> off2 = {1, 0};
	int max_y = 0;

	for (int y = 0; y < h; ++y) {
		if (xs[y].empty()) continue;
		max_y = y;

		sort(xs[y].begin(), xs[y].end());
		int x1 = xs[y][0];
		int x2 = xs[y].back();

		vector<pair<int, ll>> cans;
		if (y == 0) {
			cans.push_back({1, 0});
		} else {
			int j1 = bins(cols, off1.first);
			int j2 = bins(cols, off2.first);
			int j3 = j1 + 1;
			int j4 = j2 + 1;
			if (0 <= j1) cans.push_back({cols[j1], off1.second + abs(off1.first - cols[j1])});
			if (0 <= j2) cans.push_back({cols[j2], off2.second + abs(off2.first - cols[j2])});
			if (j3 < c) cans.push_back({cols[j3], off1.second + abs(off1.first - cols[j3])});
			if (j4 < c) cans.push_back({cols[j4], off2.second + abs(off2.first - cols[j4])});
		}

		off1 = {x1, INF};
		off2 = {x2, INF};
		for (auto pr : cans) {
			ll base = pr.second + x2 - x1;
			ll cost1 = base + abs(pr.first - x2);
			ll cost2 = base + abs(pr.first - x1);
			off1.second = min(off1.second, cost1);
			off2.second = min(off2.second, cost2);
		}
		// cerr << y << ' ' << x1 << ' ' << x2 << ": {" << off1.first << ' '<< off1.second << "}, {" << off2.first << ' ' << off2.second << "}\n";
	}

	ll res = min(off1.second, off2.second) + max_y;
	cout << res << '\n';
}