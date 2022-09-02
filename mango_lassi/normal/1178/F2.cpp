#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

const int N = 501;
ll dp[N][N];

ll solve(const vector<int>& col) {
	int n = col.size();
	if (n == 0) return 1;

	for (int i = 0; i < n; ++i) dp[i][i] = 1;
	for (int k = 2; k <= n; ++k) {
		for (int a = 0; a+k <= n; ++a) {
			int b = a+k-1;

			int j = a;
			for (int i = a; i <= b; ++i) {
				if (col[i] < col[j]) j = i;
			}
			ll lefts = 0;
			for (int x = a; x <= j; ++x) {
				ll add = 1;
				if (x < j) add = (add * dp[x][j-1]) % MOD;
				if (a < x) add = (add * dp[a][x-1]) % MOD;
				lefts = (lefts + add) % MOD;
			}
			ll rights = 0;
			for (int y = j; y <= b; ++y) {
				ll add = 1;
				if (j < y) add = (add * dp[j+1][y]) % MOD;
				if (y < b) add = (add * dp[y+1][b]) % MOD;
				rights = (rights + add) % MOD;
			}
			dp[a][b] = (lefts * rights) % MOD;
		}
	}
	return dp[0][n-1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// If some color appears multiple times, then the spaces between appearances contain
	// only larger numbers, and can be solved independently.
	// A color appearing multiple times in a row doesn't matter at all, and we can change it to just one occurrence.

	int n, m;
	cin >> n >> m;

	ll res = 1;
	vector<int> sta;
	vector<bool> app(n, false);
	for (int i = 0; i < m; ++i) {
		int c;
		cin >> c;
		--c;
		if (app[c]) {
			vector<int> sub;
			while(! sta.empty() && sta.back() != c) {
				sub.push_back(sta.back());
				sta.pop_back();
			}
			if (sta.empty()) {
				res = 0; // ABAB as subsequence
			} else {
				for (auto v : sub) {
					if (v < c) res = 0; // Smaller values in range
				}
				res = (res * solve(sub)) % MOD;
			}
		} else {
			sta.push_back(c);
			app[c] = true;
		}
	}
	res = (res * solve(sta)) % MOD;
	cout << res << '\n';
}