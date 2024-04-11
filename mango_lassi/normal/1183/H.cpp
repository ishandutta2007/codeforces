#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

const int N = 101;
const int C = 26;
const int R = N;
ll dp[N][R][C];
int pre[C];

void solve() {
	int n;
	ll k;
	cin >> n >> k;
	string str;
	cin >> str;

	for (int c = 0; c < C; ++c) {
		pre[c] = 0;
		for (int i = 0; i <= n; ++i) {
			for (int r = 0; r <= n; ++r) {
				dp[i][r][c] = 0;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		int c = str[i-1] - 'a';
		int j = pre[c];
		pre[c] = i;

		for (int r = 0; r < i; ++r) {
			ll add = (r == 0);
			for (int pc = 0; pc < C; ++pc) {
				ll cou = dp[i-1][r][pc];
				add += cou;
				if (pc != c) dp[i][r][pc] = cou;
			}
			dp[i][r+1][c] = min(add, k);
		}
	}
	ll res = 0;
	for (int r = n; r >= 0; --r) {
		ll cou = 0;
		for (int c = 0; c < C; ++c) {
			cou += dp[n][r][c];
		}
		if (r == 0) cou = 1;
		ll mult = min(k, cou);
		res += mult * (n-r);
		k -= mult;
	}
	if (k == 0) cout << res << '\n';
	else cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}