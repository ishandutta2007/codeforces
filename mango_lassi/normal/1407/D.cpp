#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> hs(n);
	for (int& h : hs) cin >> h;

	vector<int> lows, highs;
	vector<int> dp(n, n);
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		// Jump over taller buildings
		while (! lows.empty() && hs[lows.back()] > hs[i]) {
			dp[i] = min(dp[i], dp[lows.back()] + 1);
			lows.pop_back();
		}
		if (! lows.empty()) {
			dp[i] = min(dp[i], dp[lows.back()] + 1);
			if (hs[lows.back()] == hs[i]) lows.pop_back();
		}
		lows.push_back(i);

		// Jump over lower buildings
		while (! highs.empty() && hs[highs.back()] < hs[i]) {
			dp[i] = min(dp[i], dp[highs.back()] + 1);
			highs.pop_back();
		}
		if (! highs.empty()) {
			dp[i] = min(dp[i], dp[highs.back()] + 1);
			if (hs[highs.back()] == hs[i]) highs.pop_back();
		}
		highs.push_back(i);
	}
	cout << dp[n-1] << '\n';
}