#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int getWays(int t) {
	int res = 0;
	for (int a = 0; a <= 9; ++a) {
		int b = t-a;
		if (0 <= b && b <= 9) ++res;
	}
	return res;
}

void solve() {
	array<int, 4> dp, nxt;
	for (int j = 0; j < 4; ++j) {
		dp[j] = 0;
		nxt[j] = 0;
	}
	dp[0] = 1;
	
	string str;
	cin >> str;
	reverse(str.begin(), str.end());
	for (char c : str) {
		int t0 = (c - '0');
		int t1 = t0 + 10;
		for (int j = 0; j < 4; ++j) {
			int add = (j & 1);
			nxt[j >> 1] += dp[j] * getWays(t0 - add);
			nxt[(j >> 1) | 2] += dp[j] * getWays(t1 - add);
			dp[j] = 0;
		}
		swap(dp, nxt);
	}
	cout << dp[0] - 2 << '\n'; // Subtract 0 n, n 0
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}