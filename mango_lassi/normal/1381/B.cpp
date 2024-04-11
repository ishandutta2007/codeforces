#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int INF = (int)1e9 + 7;
const int N = 2000;
bool dp[2*N+1][N+1];

void solve() {
	int n;
	cin >> n;

	vector<int> perm(2*n);
	for (int& v : perm) cin >> v;
	perm.push_back(INF);

	// a[i] > a[i+1]: same
	// a[i] < a[i+1]: same or different, largest of other at least a[i+1] + 1
	// 	-> If we say "SAME" in the second case, continue forward until you find a number at least a[i+2].
	//		At that point, no history matters and you can again branch

	// DP on how much has been put into first, and where we are

	vector<int> nxt(2*n+1); // next larger than this
	vector<int> sta;
	for (int i = 0; i <= 2*n; ++i) {
		while(! sta.empty() && perm[sta.back()] < perm[i]) {
			nxt[sta.back()] = i;
			sta.pop_back();
		}
		sta.push_back(i);
	}

	for (int i = 0; i <= 2*n; ++i) {
		for (int a = 0; a <= n; ++a) dp[i][a] = 0;
	}
	dp[0][0] = 1;

	for (int i = 0; i < 2*n; ++i) {
		for (int a = 0; a <= min(i, n); ++a) {
			if (! dp[i][a]) continue;

			int j = nxt[i];
			int cou = j-i;

			if (a + cou <= n) dp[j][a + cou] = 1;
			dp[j][a] = 1;
		}
	}

	if (dp[2*n][n]) cout << "YES\n";
	else cout << "NO\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		solve();
	}


	
}