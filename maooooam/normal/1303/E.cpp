#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		string s, t;
		cin >> s >> t;
		int n = t.size();
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, n + 1));
		for (int i = 0; i <= n; ++i) dp[0][i] = i;
		for (char c : s) for (int i = n; ~i; --i) for (int j = n; j >= i; --j) {
			if (i != 0 && t[i - 1] == c) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			if (i != j && t[j - 1] == c) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
		}
		bool ans = false;
		for (int i = 0; i <= n; ++i) ans |= dp[i][n] <= i;
		cout << (ans ? "YES" : "NO") << endl;
	}
}