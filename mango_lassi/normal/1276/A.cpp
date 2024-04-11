#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = (int)1e9 + 7;

const int N = 2 * (int)1e5;
int dp[N][4][4];
pair<int, pair<int, int>> pre[N][4][4];

void solve() {
	string str;
	cin >> str;
	int n = str.size();

	string x = "one";
	string y = "two";

	for (int i = 0; i < n; ++i) {
		for (int a = 0; a < 3; ++a) {
			for (int b = 0; b < 3; ++b) {
				dp[i+1][a][b] = dp[i][a][b] + 1;
				pre[i+1][a][b] = pre[i][a][b];
			}
		}
		for (int a = 0; a < 3; ++a) {
			int ta = (str[i] == x[a] ? a+1 : (str[i] == x[0]));
			for (int b = 0; b < 3; ++b) {
				int tb = (str[i] == y[b] ? b+1 : (str[i] == y[0]));
				if (dp[i+1][ta][tb] > dp[i][a][b]) {
					dp[i+1][ta][tb] = dp[i][a][b];
					pre[i+1][ta][tb] = {i, {a, b}};
				}
			}
		}
		/*
		for (int a = 0; a < 3; ++a) {
			for (int b = 0; b < 3; ++b) {
				if (dp[i+1][a][b] <= 1) cerr << i << ' ' << a << ' ' << b << ' ' << dp[i+1][a][b] << '\n';
			}
		}
		*/
	}

	int ca = 0;
	int cb = 0;
	for (int a = 0; a < 3; ++a) {
		for (int b = 0; b < 3; ++b) {
			if (dp[n][a][b] < dp[n][ca][cb]) {
				ca = a;
				cb = b;
			}
		}
	}

	cout << dp[n][ca][cb] << '\n';
	for (int i = n; i > 0;) {
		int ni = pre[i][ca][cb].first;
		int na = pre[i][ca][cb].second.first;
		int nb = pre[i][ca][cb].second.second;
		for (int j = ni+2; j <= i; ++j) cout << j << ' ';

		i = ni;
		ca = na;
		cb = nb;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int a = 0; a < 3; ++a) {
		for (int b = 0; b < 3; ++b) {
			if (a != 0 || b != 0) dp[0][a][b] = INF;
			pre[0][a][b] = {-1, {-1, -1}};
		}
	}

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}