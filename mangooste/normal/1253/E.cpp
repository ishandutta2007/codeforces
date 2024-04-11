#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <cstdio>
#include <ctime>

typedef long long ll;
typedef long double ld;

using namespace std;

const int INF = int(1e9);

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector <pair <int, int>> v(n);
	vector <int> x(n), s(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		x[i] = v[i].first, s[i] = v[i].second;
	}
	vector <int> dp(m + 1, INF);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		dp[x[i]] = dp[x[i] - 1];
		int Min = 0;
		for (int del = max(x[i] - 1, m - x[i]); del >= 0; del--) {
			int need = max(0, del - s[i]);
			if (x[i] - del > 0) {
				dp[x[i] - del] = min(dp[x[i] - del], min(dp[Min] + max(0, x[i] - s[i] - Min - 1) + max(0, need - max(0, x[i] - s[i] - Min - 1)), dp[max(0, x[i] - del - 1)] + need));
			}
			if (x[i] + del <= m) {
				dp[x[i] + del] = min(dp[x[i] + del], min(dp[Min] + max(0, x[i] - s[i] - Min - 1) + max(0, need - max(0, x[i] - s[i] - Min - 1)), dp[max(0, x[i] - del - 1)] + need));
			}
			if (dp[max(0, x[i] - del - 1)] + need < dp[Min] + max(0, x[i] - s[i] - Min - 1)) {
				Min = max(0, x[i] - del - 1);
			}
		}
	}
	cout << dp[m] << '\n';
	return 0;
}