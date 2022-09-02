#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

const int N = 3000;
int dp0[2][N+1];
int dp1[2][N+1];

void modAdd(int& a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str, tar;
	cin >> str >> tar;
	int n = str.size(), m = tar.size();

	// Two ways to generate the same string are different
	// DP: ways to get into this interval
	// 	Works if the right side doesn't reach the end of the target string
	//	But if it does, we know where the right end is! In that case, instead store the amount of moves so far
	
	// Len 0
	dp1[0][m] = 2;
	for (int i = 0; i < m; ++i) {
		if (str[0] == tar[i]) dp0[0][i] = 2;
	}
	int res = 0;

	for (int len = 1; len <= n; ++len) {
		int c = (len & 1);
		int p = c ^ 1;
		for (int i = 0; i <= m; ++i) {
			dp0[c][i] = 0;
			dp1[c][i] = 0;
		}

		// Move from dp0 to dp1
		if (dp0[p][m-1] > 0 && m-len >= 0) {
			modAdd(dp1[p][m-len], dp0[p][m-1]);
			dp0[p][m-1] = 0;
		}
		
		// Update res
		modAdd(res, dp1[p][0]);
		if (len == n) break;

		// Update dp0
		for (int b = len; b < m; ++b) {
			int a = b - len;
			if (tar[a] == str[len]) modAdd(dp0[c][b], dp0[p][b]);
			if (tar[b] == str[len]) modAdd(dp0[c][b], dp0[p][b-1]);
		}

		// Update dp1
		modAdd(dp1[c][m], dp1[p][m]);
		modAdd(dp1[c][m], dp1[p][m]);
		for (int a = 0; a < m; ++a) {
			dp1[c][a] = dp1[p][a];
			if (str[len] == tar[a]) modAdd(dp1[c][a], dp1[p][a+1]);
		}
	}
	cout << res << '\n';
}