#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll INF = 1e9;
const int N = 1500;
const int S = 1500;
int val[N];
int dp[S+1][N+1];
int cou[N+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Size of the set should be maximized (if we can get S and U, and S \subset U, U is better)
	// If no two segments intersect:
	// 	Binary search the answer, and select greedily the sets that contain the most numbers <= ans
	// what about when some segments intersect?
	// do DP: what is the maximum amount you can get such that
	// 	1. You have selected A segments
	// 	2. The first number we can get is at i
	
	int n, s, m, k;
	cin >> n >> s >> m >> k;
	for (int i = 0; i < n; ++i) cin >> val[i];

	vector<pair<int, int>> segs(s);
	for (int i = 0; i < s; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		segs[i].first = a;
		segs[i].second = b;
	}

	ll low = 0;
	ll high = INF + 1;
	while(low != high) {
		ll mid = (low + high) >> 1;

		cou[0] = 0;
		for (int i = 1; i <= n; ++i) {
			cou[i] = cou[i-1];
			if (val[i-1] <= mid) ++cou[i];
		}

		for (int i = 0; i <= n; ++i) {
			dp[0][i] = 0;
		}
		for (int sel = 1; sel <= m; ++sel) {
			for (int i = 0; i <= n; ++i) {
				dp[sel][i] = 0;
			}
			for (auto pr : segs) {
				int a = pr.first;
				int b = pr.second;
				dp[sel][b+1] = max(dp[sel][b+1], dp[sel-1][a] + cou[b+1] - cou[a]);
			}
			for (int i = 1; i <= n; ++i) {
				dp[sel][i] = max(dp[sel][i], dp[sel][i-1]);
			}

			// To allow overlapping intervals
			int bst = -cou[n];
			for (int i = n; i >= 0; --i) {
				dp[sel][i] = max(dp[sel][i], bst + cou[i]);
				bst = dp[sel][i] - cou[i];
			}
		}

		if (dp[m][n] >= k) high = mid;
		else low = mid + 1;
	}

	if (low == INF + 1) low = -1;
	cout << low << '\n';
}