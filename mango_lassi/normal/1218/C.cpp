#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;
const ll INF = 1e18;

const int N = 500;
ll cost[N][N];
vector<pair<int, ll>> rowg[N][N];
vector<pair<int, ll>> colg[N][N];
ll dp[N][N];

void suffSum(vector<pair<int, ll>>& vec) {
	int n = vec.size();
	sort(vec.begin(), vec.end());
	for (int i = n-2; i >= 0; --i) vec[i].second += vec[i+1].second;
}
ll bins(const vector<pair<int, ll>>& vec, int v) {
	int low = 0;
	int high = (int)vec.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid].first < v) low = mid + 1;
		else high = mid;
	}
	if (low >= vec.size()) return 0;
	else return vec[low].second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int w, h, k;
	cin >> w >> h >> k;

	// 4 5 6
	// 0 2 2 2 3
	// 1 2 2 3 4
	// 0 3 1 2 1
	// 0 1 1 0 6
	// 0 2 1 0 6
	// 2 3 1 5 1

	// A: 3, B: 4
	// C: 1, D: 6
	// E: 6, F: 1

	// . . A  E .
	// D D BC C .
	// . . A  F .
	// . . B  . .

	for (int j = 0; j < k; ++j) {
		int x, y, d, t, e;
		cin >> x >> y >> d >> t >> e;

		vector<pair<int, int>> locs;
		if (t <= x+y && (x+y - t)%4 == 0) locs.push_back({x, y});
		if (t+1 <= x+y && (x+y - (t+1))%4 == 0) locs.push_back({x+d, y-d});
		if (t+2 <= x+y+d && (x+y+d - (t+2))%4 == 0) locs.push_back({x+d, y});
		if (t+3 <= x+y+d && (x+y+d - (t+3))%4 == 0) locs.push_back({x, y+d});
		for (auto pr : locs) {
			cost[pr.first][pr.second] += e;
		}

		if (locs.size() == 2) {
			int x0, y0, x1, y1;
			tie(x0, y0) = locs[0];
			tie(x1, y1) = locs[1];
			if (x0 == x1) {
				if (y0 > y1) swap(y0, y1);
				rowg[x1][y1].emplace_back(y0, -e);
			} else if (y0 == y1) {
				if (x0 > x1) swap(x0, x1);
				colg[x1][y1].emplace_back(x0, -e);
			}
		}
	}
	for (int x = 0; x < w; ++x) {
		for (int y = 0; y < h; ++y) {
			suffSum(rowg[x][y]);
			suffSum(colg[x][y]);
		}
	}

	dp[w-1][h-1] = cost[w-1][h-1];
	for (int s = w+h-3; s >= 0; --s) {
		for (int x0 = 0; x0 <= s; ++x0) {
			int y0 = s - x0;
			if (x0 >= w || y0 >= h) continue;

			dp[x0][y0] = INF;

			ll off = 0;
			for (int x = x0 + 1; x < w; ++x) {
				off += cost[x-1][y0];
				off += bins(colg[x][y0], x0);
				dp[x0][y0] = min(dp[x0][y0], off + dp[x][y0]);
			}
			off = 0;
			for (int y = y0 + 1; y < h; ++y) {
				off += cost[x0][y-1];
				off += bins(rowg[x0][y], y0);
				dp[x0][y0] = min(dp[x0][y0], off + dp[x0][y]);
			}
		}
	}

	cout << dp[0][0] << '\n';
}