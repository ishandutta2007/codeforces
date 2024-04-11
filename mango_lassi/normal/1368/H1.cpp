#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
const int N = 1e5;
int col[4][N+1];
int dp[N+1][2]; // Min cost, so that current is red/blue

int solve(int h, int w, int m) {
	int le_tot = 0;
	for (int y = 1; y <= h; ++y) le_tot += col[0 ^ m][y];

	int ri_tot = 0;
	for (int y = 1; y <= h; ++y) ri_tot += col[1 ^ m][y];

	dp[0][0] = 0;
	dp[0][1] = 0;
	
	for (int x = 1; x <= w; ++x) {
		dp[x][0] = dp[x-1][0];
		dp[x][1] = dp[x-1][1];

		int rc = col[2 ^ m][x] + col[3 ^ m][x];
		int bc = 2 - rc;

		if (x == 1) {
			rc += le_tot;
			bc += h - le_tot;
		}
		if (x == w) {
			rc += ri_tot;
			bc += h - ri_tot;
		}

		dp[x][0] += bc;
		dp[x][1] += rc;
		dp[x][0] = min(dp[x][0], dp[x][1] + h);
		dp[x][1] = min(dp[x][1], dp[x][0] + h);
	}

	return min(dp[w][0], dp[w][1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// This is clearly a flow problem: red are sinks, blue sources, each edge has capacity 1
	// Problem: n, m = 1e5, flow is too slow
	// Max-flow min-cut!
	//	WLOG, single horizontal or single vertical cut?
	
	int h, w, q;
	cin >> h >> w >> q;

	for (int j = 0; j < 2; ++j) {
		string str;
		cin >> str;
		for (int i = 0; i < h; ++i) {
			if (str[i] == 'R') col[j][i+1] = 1;
		}
	}
	for (int j = 0; j < 2; ++j) {
		string str;
		cin >> str;
		for (int i = 0; i < w; ++i) {
			if (str[i] == 'R') col[j+2][i+1] = 1;
		}
	}

	int res = INF;
	res = min(res, solve(h, w, 0));
	res = min(res, solve(w, h, 2));
	cout << res << '\n';
}