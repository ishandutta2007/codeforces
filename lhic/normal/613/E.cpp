#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

using namespace std;

const int MAXN = 2100;
const ull P = 23917;

const int MOD = 1000000007;
ull pw[MAXN];
char s[2][MAXN];
char t[MAXN];
ull hss[2][MAXN];
ull bhss[2][MAXN];
ull hst[MAXN];
int n, m;
int ans = 0;
int dp[2][MAXN][MAXN];

void ad(int &a, int b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
}

void initHash() {
	pw[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		pw[i] = pw[i - 1] * P;
	for (int i = 0; i < 2; ++i) {
		hss[i][0] = 0;
		for (int j = 0; j < n; ++j)
			hss[i][j + 1] = hss[i][j] * P + s[i][j];
		bhss[i][n] = 0;
		for (int j = n - 1; j >= 0; --j)
			bhss[i][j] = bhss[i][j + 1] * P + s[i][j];
	}
	hst[0] = 0;
	for (int j = 0; j < m; ++j)
		hst[j + 1] = hst[j] * P + t[j];
}

ull getHs(int x, int l, int r) {
	if (x == 0 || x == 1) {
		return hss[x][r] - hss[x][l] * pw[r - l];
	}
	return hst[r] - hst[l] * pw[r - l];
}

ull getBHs(int x, int l, int r) {
	return bhss[x][l] - bhss[x][r] * pw[r - l];
}

void solve() {
	initHash();
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k <= m; ++k)
				dp[i][j][k] = 0;
	dp[0][n][0] = 1;
	dp[1][n][0] = 1;
	for (int i = n - 1; i >= 0; --i) {
		dp[0][i][0] = 1;
		dp[1][i][0] = 1;
		if (s[0][i] == t[m - 1])
			dp[0][i][1] = 1;
		if (s[1][i] == t[m - 1])
			dp[1][i][1] = 1;
		for (int k = 2; k <= m; ++k) {
			if ((n - i) * 2 < k)
				break;
			if (s[0][i] == t[m - k]) {
				if (s[1][i] == t[m - k + 1])
					ad(dp[0][i][k], dp[1][i + 1][k - 2]);
				ad(dp[0][i][k], dp[0][i + 1][k - 1]);
				if (k > 2 && k % 2 == 0) {
					if (getHs(0, i, i + k / 2) == getHs(2, m - k, m - k + k / 2) && getBHs(1, i, i + k / 2) == getHs(2, m - k + k / 2, m))
						ad(dp[0][i][k], 1);
				}
			}
			if (s[1][i] == t[m - k]) {
				if (s[0][i] == t[m - k + 1])
					ad(dp[1][i][k], dp[0][i + 1][k - 2]);
				ad(dp[1][i][k], dp[1][i + 1][k - 1]);
				if (k > 2 && k % 2 == 0) {
					if (getHs(1, i, i + k / 2) == getHs(2, m - k, m - k + k / 2) && getBHs(0, i, i + k / 2) == getHs(2, m - k + k / 2, m))
						ad(dp[1][i][k], 1);
				}
			}
		}
		for (int k = 1; k <= m; ++k) {
			if (k == m) {
				ad(ans, dp[0][i][k]);
				ad(ans, dp[1][i][k]);
			}
			if (2 * i >= m - k && m - k > 2 && (m - k) % 2 == 0) {
				int x = (m - k);
				if (getHs(0, i - x / 2, i) == getHs(2, x / 2, x) && getBHs(1, i - x / 2, i) == getHs(2, 0, x / 2))
					ad(ans, dp[0][i][k]);
				if (getHs(1, i - x / 2, i) == getHs(2, x / 2, x) && getBHs(0, i - x / 2, i) == getHs(2, 0, x / 2))
					ad(ans, dp[1][i][k]);
			}
		}
	}
}


int main() {
	scanf(" %s %s %s", s[0], s[1], t);
	n = strlen(s[0]);
	m = strlen(t);
	solve();
	if (m != 1) {
	//	reverse(t, t + m);
		reverse(s[0], s[0] + n);
		reverse(s[1], s[1] + n);
		solve();
	}
	if (m == 2) {
		for (int i = 0; i < n; ++i) {
			if (s[0][i] == t[0] && s[1][i] == t[1])
				--ans;
			if (s[1][i] == t[0] && s[0][i] == t[1])
				--ans;
		}
	}
	ad(ans, MOD);
	cout << ans << "\n";
	return 0;
}