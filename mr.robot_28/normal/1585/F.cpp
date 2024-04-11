#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
#define sz(a) (int)a.size()
const int N = 2e5 + 100;
const int mod = 998244353;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n + 1);
	vector <int> dp(n + 1), sum(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector <int> vec;
	dp[0] = 1;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int t = 0;
		while (sz(vec) && a[vec.back()] > a[i]) {
			t += sum[sz(vec)], t %= mod;
			ans -= 1LL * sum[sz(vec)] % mod * a[vec.back()] % mod;
			ans %= mod;
			if (ans < 0) {
				ans += mod;
			}
			vec.pop_back();
		}
		t += dp[i - 1], t %= mod;
		vec.push_back(i);
		sum[sz(vec)] = t;
		ans += sum[sz(vec)] * a[i] % mod;
		ans %= mod;
		dp[i] = mod - ans;
	}
	dp[n] = (dp[n] + mod) % mod;
	if (n % 2 == 1) {
		dp[n] = (mod - dp[n]) % mod;
	}
	cout << dp[n];
	return 0;
}