#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
using pii = pair<int, int>;
const int N = 1e6 + 10, M = N, inf = 1e18, mod = 998244353;


void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), f(n + 1, 0), dp(n + 1, -inf);
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		int num = n, cnt = 0;
		for (int j = i - 1; j >= 0; j--) {
			int len = i - j - 1;
			if ((a[i] == a[j] or a[j] == 0) and len % 2 == 0 and f[num] * 2 <= len) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
			if (a[j] == num) cnt++;
			else cnt--;
			if (cnt < 0) num = a[j], cnt = 1;
			if (a[j]) f[a[j]]++;
		}
		for (int j = i - 1; j >= 0; j--) if (a[j]) f[a[j]]--;
	}

	int num = n, cnt = 0, ans(0);
	for (int i = n, now = 0; i >= 1; i--, now++) {
		if (now % 2 == 0 and f[num] * 2 <= now) ans = max(ans, dp[i]);
		if (a[i] == num) cnt++;
		else cnt--;
		if (cnt < 0) num = a[i], cnt = 1;
		f[a[i]]++;
	}
	cout << ans << endl;

}
signed main() {
	cin.tie(0) -> ios::sync_with_stdio(false);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}