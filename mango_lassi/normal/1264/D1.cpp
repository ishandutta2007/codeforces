#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

const int N = 2000;
int dp[N+2][N+1][2];

void ma(int& a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// To calculate depth:
	// Select center, count ( on left side, count ) on right side, answer minimum of those
	// Can always pick center so that these two are equal and maximal.
	// -> That position is unique!
	// Proof: If one to right is ')', moving right reduces right count. If one to right is '(',
	// moving to right increases left count. Similarly in other direction

	string str;
	cin >> str;
	int n = str.size();

	dp[0][0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (str[i-1] == '(' || str[i-1] == '?') {
			for (int c = 1; c <= i; ++c) ma(dp[i][c][0], dp[i-1][c-1][0]);
		}
		if (str[i-1] == ')' || str[i-1] == '?') {
			for (int c = 0; c <= i; ++c) ma(dp[i][c][0], dp[i-1][c][0]);
		}
	}
	dp[n+1][0][1] = 1;
	for (int i = n; i >= 1; --i) {
		if (str[i-1] == ')' || str[i-1] == '?') {
			for (int c = 1; c <= i; ++c) ma(dp[i][c][1], dp[i+1][c-1][1]);
		}
		if (str[i-1] == '(' || str[i-1] == '?') {
			for (int c = 0; c <= i; ++c) ma(dp[i][c][1], dp[i+1][c][1]);
		}
	}

	int res = 0;
	for (int i = 0; i <= n; ++i) {
		for (int c = 0; c <= n; ++c) {
			ll add = (ll)dp[i][c][0] * dp[i+1][c][1] % MOD;
			ma(res, add * c % MOD);
		}
	}
	cout << res << '\n';
}