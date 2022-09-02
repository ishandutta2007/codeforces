#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll mAdd(ll a, ll b) { return (a + b >= MOD ? a + b - MOD : a + b); }
ll mSub(ll a, ll b) { return (a >= b ? a - b : a + MOD - b); }

void mobius(vector<ll>& f, bool rev = false) {
	for (int b = 1; b < f.size(); b *= 2) {
		for (int m = 0; m < f.size(); ++m) {
			if (m & b) {
				if (rev) f[m] = mSub(f[m], f[m^b]);
				else f[m] = mAdd(f[m], f[m^b]);
			}
		}
	}
}

const int N = 23;
const int C = 26;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<array<int, C>> cts(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < C; ++j) cts[i][j] = 1;
		string str;
		cin >> str;
		for (char c : str) ++cts[i][(c - 'a')];
	}

	vector<ll> fs((1 << n), 0);
	for (int mask = 1; mask < (1 << n); ++mask) {
		array<int, C> cur;
		for (int c = 0; c < C; ++c) cur[c] = MOD;
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) {
				for (int c = 0; c < C; ++c) cur[c] = min(cur[c], cts[i][c]);
			}
		}
		fs[mask] = 1;
		for (int c = 0; c < C; ++c) fs[mask] = (fs[mask] * cur[c]) % MOD;
		if (__builtin_popcount(mask) % 2 == 0) fs[mask] = (fs[mask] * (MOD - 1)) % MOD;
	}
	mobius(fs);
	
	ll res = 0;
	for (int mask = 0; mask < (1 << n); ++mask) {
		ll mult = 0;
		for (int i = 0; i < n; ++i) mult += ((mask & (1 << i)) ? i + 1 : 0);
		mult *= __builtin_popcount(mask);
		res = res ^ (mult * fs[mask]);
	}
	cout << res << '\n';
}