#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 400;
int dp[N+1][N+1];

bool solve(string str, string t1, string t2) {
	int n = str.size();
	int m = t1.size();
	for (int j = 1; j <= m; ++j) dp[0][j] = -1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			dp[i][j] = -1;
			if (dp[i-1][j] != -1) {
				dp[i][j] = dp[i-1][j];
				if (dp[i][j] < t2.size() && str[i-1] == t2[dp[i][j]]) ++dp[i][j];
			}
			if (j > 0 && str[i-1] == t1[j-1]) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
			}
		}
	}
	return dp[n][m] >= (int)t2.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int ti = 0; ti < tc; ++ti) {
		string src, tar;
		cin >> src >> tar;

		bool works = false;
		for (int a = 1; a <= tar.size(); ++a) {
			string le, ri;
			for (int i = 0; i < a; ++i) le.push_back(tar[i]);
			for (int i = a; i < tar.size(); ++i) ri.push_back(tar[i]);
			if (solve(src, le, ri)) works = true;
		}
		if (works) cout << "YES\n";
		else cout << "NO\n";
	}
}