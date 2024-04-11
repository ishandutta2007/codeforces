#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1e9 + 7;

const int K = 60;

void solve() {
	int n;
	cin >> n;

	// sum_j (sum_i x_i BITWISE_AND x_j) (sum_i x_i BITWISE_OR x_j)
	// Consider these sums bitwise. How many times do we add bit 2^k in (sum_i x_i BITWISE_AND x_j)?
	//	If it appears in x_j, exactly f(k) - 1 times, where f(k) is the number of times it appears in total
	//	Consider the or bitwise as well

	vector<ll> cou(K, 0);
	vector<ll> vals(n);
	for (ll& x : vals) {
		cin >> x;
		for (ll b = 0; b < K; ++b) {
			if (x & (1ll << b)) ++cou[b];
		}
	}

	ll res = 0;
	for (ll& x : vals) {
		ll v1 = 0, v2 = 0;
		for (ll b = 0; b < K; ++b) {
			ll bit = (1ll << b);
			if (x & bit) {
				v1 = (v1 + (bit % MOD) * cou[b]) % MOD;
				v2 = (v2 + (bit % MOD) * n) % MOD;
			} else {
				v2 = (v2 + (bit % MOD) * cou[b]) % MOD;
			}
		}
		res = (res + v1 * v2) % MOD;
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}