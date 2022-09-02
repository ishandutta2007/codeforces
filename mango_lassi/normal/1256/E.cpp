#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = (int)1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> as(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i].first;
		as[i].second = i;
	}
	sort(as.begin(), as.end());

	vector<int> dp(n+1, INF);
	vector<int> pre(n+1, -1);
	dp[0] = 0;
	for (int i = 3; i <= n; ++i) {
		for (int p = i-3; p >= max(0, i-5); --p) {
			int off = dp[p] + (as[i-1].first - as[p].first);
			if (off < dp[i]) {
				pre[i] = p;
				dp[i] = off;
			}
		}
	}

	int cc = 0;
	vector<int> team(n, -1);
	for (int i = n; i > 0; i = pre[i]) {
		++cc;
		for (int j = pre[i]; j < i; ++j) team[as[j].second] = cc;
	}

	cout << dp[n] << ' ' << cc << '\n';
	for (auto t : team) cout << t << ' '; cout << '\n';
}