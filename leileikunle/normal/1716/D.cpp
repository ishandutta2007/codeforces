#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
//#define int long long
#define all(a) a.begin(),a.end()
using pii = pair<int, int>;
const int N = 2e5 + 10, M = N, inf = 1e18, mod = 998244353;


void solve() {

	int n, k;
	cin >> n >> k;

	vector<int> dp(n + 1), ans(n + 1);
	dp[0] = 1;
	for (int i = k, mx = 0; i <= n; i++) {
		mx += i;
		if (mx > n) break;
		vector<int> ndp(n + 1);
		for (int j = i; j <= n; j++) ndp[j] = (dp[j - i] + ndp[j - i]) % mod;
		for (int j = 0; j <= n; j++) (ans[j] += ndp[j] ) %= mod;
		dp = ndp;
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;

}


signed main() {
	cin.tie(0) -> ios::sync_with_stdio(false);
	int tt = 1;
//	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}