#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	string s;
	cin >> s;
	
	vector<int> dp(1 << 20);
	for (int i = 0; i < int(s.size()); ++i) {
		vector<bool> used(20);
		int mask = 0;
		for (int j = 0; i + j < int(s.size()); ++j) {
			if (used[s[i + j] - 'a']) break;
			used[s[i + j] - 'a'] = true;
			mask |= 1 << (s[i + j] - 'a');
			dp[mask] = __builtin_popcount(mask);
		}
	}
	
	for (int mask = 0; mask < (1 << 20); ++mask) {
		for (int pos = 0; pos < 20; ++pos) {
			if ((mask >> pos) & 1) {
				dp[mask] = max(dp[mask], dp[mask ^ (1 << pos)]);
			}
		}
	}
	
	int ans = 0;
	for (int mask = 0; mask < (1 << 20); ++mask) {
		if (dp[mask] == __builtin_popcount(mask)) {
			int comp = ~mask & ((1 << 20) - 1);
			ans = max(ans, dp[mask] + dp[comp]);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}