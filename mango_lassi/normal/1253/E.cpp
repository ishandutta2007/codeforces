#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int M = 1e5;
int dp[M+1]; // Min cost to cover up to i

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int j = 1; j <= m; ++j) dp[j] = m;

	vector<pair<int, int>> ats(n);
	for (int i = 0; i < n; ++i) cin >> ats[i].first >> ats[i].second;
	sort(ats.begin(), ats.end());

	for (int i = 0; i < n; ++i) {
		int x = ats[i].first - 1;
		int s = ats[i].second;
		for (int j = 0; j <= m; ++j) {
			int add = max(0, (x - s) - j);
			int t = min(m, x+s+add + 1);
			dp[t] = min(dp[t], dp[j] + add);
		}

		// Case where this covers end
		int add = max(0, (m-1) - (x + s));
		int t = max(0, x - s - add);
		dp[m] = min(dp[m], dp[t] + add);

		for (int j = m; j > 0; --j) dp[j-1] = min(dp[j], dp[j-1]);
	}
	cout << dp[m] << '\n';
}