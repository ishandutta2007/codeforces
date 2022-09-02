#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9 + 7;

void solve() {
	string str, tar;
	cin >> str >> tar;
	int n = str.size();
	int m = tar.size();

	int pre_dp0 = -INF, pre_dp1 = -INF;
	int dp0 = 0, dp1 = -INF;
	for (auto c : str) {
		int nxt0 = max(dp1 - 1, pre_dp0), nxt1 = max(dp0 - 1, pre_dp1);
		if (0 <= dp0 && dp0 < m && tar[dp0] == c) nxt1 = max(nxt1, dp0 + 1);
		if (0 <= dp1 && dp1 < m && tar[dp1] == c) nxt0 = max(nxt0, dp1 + 1);
		if (nxt0 < 0) nxt0 = 0;
		if (nxt1 < 0) nxt1 = -INF;
		pre_dp0 = dp0; pre_dp1 = dp1;
		dp0 = nxt0; dp1 = nxt1;
	}
	if (dp0 == m || dp1 == m) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}