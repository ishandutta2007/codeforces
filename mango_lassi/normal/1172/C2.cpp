#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll modPow(ll a, ll b) {
	if (a >= MOD) a %= MOD;
	if (a == 0) return 0;
	if (b == 0) return 1;
	if (b & 1) return (a * modPow(a, b-1)) % MOD;
	else return modPow((a*a) % MOD, b / 2);
}

const int M = 3010;
ll dp[M+1][M+1];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= m; ++i) {
		for (int k = 0; k <= i; ++k) dp[i][k] = 0;
	}

	vector<int> is_good(n);
	for (int i = 0; i < n; ++i) {
		cin >> is_good[i];
	}

	ll good_sum = 0;
	ll bad_sum = 0;

	vector<ll> weights(n);
	for (int i = 0; i < n; ++i) {
		cin >> weights[i];
		if (is_good[i]) good_sum += weights[i];
		else bad_sum += weights[i];
	}

	dp[0][0] = 1;
	for (int i = 0; i < m; ++i) {
		for (int k = 0; k <= i; ++k) {
			ll cur_good = good_sum + k;
			ll cur_bad = bad_sum - (i-k);
			if (cur_bad < 0) continue;

			ll mult = (dp[i][k] * modPow((cur_good + cur_bad) % MOD, MOD-2)) % MOD;

			ll good_val = (cur_good * mult) % MOD;
			ll bad_val = (cur_bad * mult) % MOD;
			dp[i+1][k+1] = (dp[i+1][k+1] + good_val) % MOD;
			dp[i+1][k] = (dp[i+1][k] + bad_val) % MOD;
		}
	}
	ll good_val = 0;
	ll bad_val = 0;
	for (int k = 0; k <= m; ++k) {
		ll cur_good = good_sum + k;
		ll cur_bad = bad_sum - (m-k);
		if (cur_bad < 0) continue;

		good_val = (good_val + cur_good * dp[m][k]) % MOD;
		bad_val = (bad_val + cur_bad * dp[m][k]) % MOD;

		// cout << dp[m][k] << ' ' << cur_good << ' ' << cur_bad << '\n';
	}

	for (int i = 0; i < n; ++i) {
		if (is_good[i]) {
			ll rat = (weights[i] * modPow(good_sum, MOD-2)) % MOD;
			cout << (good_val * rat) % MOD << '\n';
		} else {
			ll rat = (weights[i] * modPow(bad_sum, MOD-2)) % MOD;
			cout << (bad_val * rat) % MOD << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// int t;
	// cin >> t;
	// for (int ti = 0; ti < t; ++ti) solve();
	solve();
}