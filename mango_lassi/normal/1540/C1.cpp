#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7;

ll mAdd(ll a, ll b) {
	return (a + b >= MOD ? a + b - MOD : a + b);
}
ll mSub(ll a, ll b) {
	return (a >= b ? a - b : a + MOD - b);
}
ll modPow(ll a, ll b) {
	if (b & 1) return (a * modPow(a, b ^ 1)) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b >> 1);
}

const int N = 100;
const int H = 2000000;
ll dp[H + 100];
ll pre[H + 100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> cs(n);
	for (ll& c : cs) cin >> c;

	vector<ll> suff_ways(n + 1);
	suff_ways[n] = 1;
	for (int i = n-1; i >= 0; --i) suff_ways[i] = suff_ways[i + 1] * (cs[i] + 1) % MOD;

	vector<ll> bs(n, 0);
	for (int i = 1; i < n; ++i) {
		cin >> bs[i];
		bs[i] += bs[i-1];
	}

	// Operation is:
	//	Increment a_{i+1} and decrement a_{i} equally much such that a_{i+1} is at least b_i larger
	// -> Final result has same sum of all a_i and a_{i+1} >= a_{i} + b_{i}
	// 	If we had equality, answer would be easy to compute
	
	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		// DP[i][total slack]
		// total slack: \sum_{j = 1}^{i} a_{j} - (x + \sum_{t = 1}^{j - 1} b_t)
		// total slack >= 0: possible for that prefix
		// We only care that every prefix has total slack >= 0

		ll x;
		cin >> x;
		if (x + bs[n-1] <= 0) {
			// In this case, even if all values are 0, we are done
			cout << suff_ways[0] << '\n';
		} else {
			vector<ll> needs(n);
			for (int i = 0; i < n; ++i) needs[i] = (x + bs[i]);

			for (int j = 0; j < H; ++j) dp[j] = 0;
			dp[0] = 1;

			ll res = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < H; ++j) pre[j] = dp[j];
				ll low = -needs[i];
				ll high = cs[i] - needs[i];
				
				ll cur = 0;
				for (int j = -H; j < H; ++j) {
					if (j >= 0) dp[j] = cur;
					if (0 <= j + 1 - low && j + 1 - low < H) cur = mAdd(cur, pre[j + 1 - low]);
					if (0 <= j - high && j - high < H) cur = mSub(cur, pre[j - high]);
				}

				/*
				cerr << low << ' ' << high << ": ";
				for (int j = 0; j < H; ++j) {
					if (dp[j] > 0) cerr << j << '\n';
				}
				*/
			}
			for (int j = 0; j < H; ++j) res = mAdd(res, dp[j]);
			cout << res << '\n';
		}

	}
}