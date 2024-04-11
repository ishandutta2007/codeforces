#include <bits/stdc++.h>
#define sz(a) int((a).size())

using namespace std;
const int N = 3e3 + 10;
int n, c[N], b[N], dp[N][N][2];
vector<int> p[N];

int DP(int l, int r, int t) {
	if(l > r) return 0;
	if(dp[l][r][t] != -1) return dp[l][r][t];
	int &res = dp[l][r][t];
	res = INT_MAX / 4;
	for(int i = sz(p[b[r]]) - 1; i >= 0; i--) {
		int x = p[b[r]][i];
		if(l <= x && x < r) {
			res = min(res, DP(l, x, 1) + DP(x + 1, r - 1, 0));
		}
	}
	if(t == 1) {
		res = min(res, DP(l, r - 1, 0));
	} else {
		res = min(res + 1, DP(l, r - 1, 0) + 1);
	}
	return res;
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> c[i];
	int tot = 1;
	b[1] = c[1];
	for(int i = 2; i <= n; i++) {
		if(c[i] != c[i - 1]) {
			b[++tot] = c[i];
		}
	}
	for(int i = 1; i <= n; i++) p[i].clear();
	for(int i = 1; i <= tot; i++) p[b[i]].push_back(i);
	for(int i = 1; i <= tot; i++) {
		for(int j = 1; j <= tot; j++) {
			dp[i][j][0] = dp[i][j][1] = -1;
		}
	}
	cout << DP(1, tot, 0) - 1 << endl;
	return;
}

int main() {
	int T;
	for(cin >> T; T--; solve());
	return 0;
}