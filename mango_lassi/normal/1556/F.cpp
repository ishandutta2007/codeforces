#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7;

ll mAdd(ll a, ll b) {
	if (a + b >= MOD) return a + b - MOD;
	else return a + b;
}
ll mSub(ll a, ll b) {
	if (a < b) return a + MOD - b;
	else return a - b;
}

ll modPow(ll a, ll b) {
	if (b & 1) return (a * modPow(a, b ^ 1)) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b >> 1);
}

const int N = 14;
ll winp[N][N];
ll mwinp[N][1 << N]; // Probability team i beats everyone in mask
ll sconp[1 << N];

ll winAll(ll mask, ll sub) {
	ll res = 1;
	for (int i = 0; (1 << i) <= sub; ++i) {
		if (sub & (1 << i)) res = (res * mwinp[i][mask ^ sub]) % MOD;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			winp[i][j] = (as[i] * modPow(mAdd(as[i], as[j]), MOD - 2)) % MOD;
		}
		for (int mask = 0; mask < (1 << n); ++mask) {
			ll res = 1;
			for (int j = 0; j < n; ++j) {
				if (mask & (1 << j)) res = (res * winp[i][j]) % MOD;
			}
			mwinp[i][mask] = res;
		}
	}

	// Inclusion-exclusion: for every bitmask, get probability that that bitmask is strongly connected
	//	P(S) = 1 - \sum_{S' subset S} P(S') P(everyone in S' beats everyone in S)
	// Then, answer is
	//	\sum_{S} |S| P(S) P(everyone in S beats everyone not in S)
	
	ll ans = 0;
	ll full = (1 << n) - 1;
	for (int mask = 1; mask < (1 << n); ++mask) {
		sconp[mask] = 1;
		for (int sub = (mask - 1) & mask; sub; sub = (sub - 1) & mask) {
			ll prob = (sconp[sub] * winAll(mask, sub)) % MOD;
			sconp[mask] = mSub(sconp[mask], prob);
		}
		ll mult = (sconp[mask] * winAll(full, mask)) % MOD;
		ans = (ans + __builtin_popcount(mask) * mult) % MOD;
	}
	cout << ans << '\n';
}