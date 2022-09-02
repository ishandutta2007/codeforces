#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = (int)1e9 + 7;
const int C = 26;
const int M = (int)1e5 + 3;
int cou[C];
int dp[C+1][2*M + 1];
bool ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll t;
	cin >> n >> t;

	// Fact: last two are always -+, others can be arbitrarily chosen

	string str;
	cin >> str;
	for (int i = 0; i < n-2; ++i) ++cou[str[i] - 'a'];
	t += 1ll << (str[n-2] - 'a');
	t -= 1ll << (str[n-1] - 'a');
	if (t < 0) t = -t;

	/*
	cerr << t << '\n';
	for (int c = 0; c < C; ++c) {
		if (t & (1 << c)) cerr << c << ' ';
	}
	cerr << endl;
	*/

	int m = n + 3;

	ll x = (t >> C);
	if (x <= m) dp[C][x + m] = 1;

	for (int c = C-1; c >= 0; --c) {
		for (int j = 2*m; j >= 0; --j) {
			if (dp[c+1][j]) {
				int off = 2*(j - m) + m + (bool)(t & (1 << c));
				if (0 <= off && off <= 2*m) dp[c][off] = 1;
			}
		}

		// if (c == 18) cerr << dp[c][m + 18] << '\n';
		// if (c == 7) cerr << dp[c][m + 2] << '\n';

		vector<int> pre(2, INF);
		for (int j = 2*m; j >= 0; --j) {
			if (dp[c][j] & 1) pre[j & 1] = j;
			int p = pre[(j ^ cou[c]) & 1];
			if (p - j <= cou[c]) dp[c][j] |= 2;
		}

		pre = {-INF, -INF};
		for (int j = 0; j <= 2*m; ++j) {
			if (dp[c][j] & 1) pre[j & 1] = j;
			int p = pre[(j ^ cou[c]) & 1];
			if (j - p <= cou[c]) dp[c][j] |= 2;
		}

		for (int j = 0; j <= 2*m; ++j) {
			if (dp[c][j] & 1) dp[c][j] ^= 1;
		}

		// cerr << c << ": " << dp[c][m] << '\n';
	}
	cout << (dp[0][m] ? "Yes" : "No") << '\n';
}