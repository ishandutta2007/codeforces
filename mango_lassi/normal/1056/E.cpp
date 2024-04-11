#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <assert.h>
using namespace std;
typedef long long ll;

const int N = 2 * (int)1e6;
const ll MOD = 1e9 + 7;
ll mult = 2;

ll hsh[N+1];
ll mup[N+1];

bool comp(ll a, ll b, ll len) {
	assert(a >= 0 && b >= 0 && a+len <= 2*N && b+len <= 2*N);

	ll a_hash = (hsh[a + len] - hsh[a] * mup[len]) % MOD;
	ll b_hash = (hsh[b + len] - hsh[b] * mup[len]) % MOD;
	if (a_hash < 0) a_hash += MOD;
	if (b_hash < 0) b_hash += MOD;
	return a_hash == b_hash;
}

int main() {
	/*
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	*/

	// pls no hacks :(
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	mult = uniform_int_distribution<ll>(2, MOD-1)(rng);

	string pat;
	string str;
	cin >> pat >> str;
	ll n = str.size();
	ll m = pat.size();

	hsh[0] = 0;
	for (int i = 0; i < n; ++i) {
		hsh[i+1] = ((ll)str[i] + hsh[i] * mult) % MOD;
	}

	mup[0] = 1;
	for (int i = 1; i <= n; ++i) mup[i] = (mult * mup[i-1]) % MOD;
	
	ll zc = 0;
	ll oc = 0;
	for (auto c : pat) {
		if (c == '0') ++zc;
		if (c == '1') ++oc;
	}

	ll res = 0;

	// Length of first string
	for (ll la = 1; la < n; ++la) {
		// Length of second string
		ll lb = 0;
		if (oc == 0) {
			if (la * zc != n) continue;
		} else {
			lb = (n - zc * la) / oc;
			if (la * zc + lb * oc != n) continue;
			if (lb <= 0) continue;
		}

		bool fail = false;
		ll zf = -1;
		ll of = -1;
		ll j = 0;
		for (int i = 0; i < m; ++i) {
			if (pat[i] == '0') {
				if (zf == -1) zf = j;
				if (! comp(zf, j, la)) fail = true;
				j += la;
			} else if (pat[i] == '1') {
				if (of == -1) of = j;
				if (! comp(of, j, lb)) fail = true;
				j += lb;
			}
		}
		if (! fail) ++res;
	}
	// subtract case where both strings are equal
	for (ll la = 1; la < n; ++la) {
		if (la * m != n) continue;
		bool fail = false;
		ll j = 0;
		for (int i = 0; i < m; ++i) {
			if (! comp(0, j, la)) fail = true;
			j += la;
		}
		if (! fail) --res;
	}

	cout << res << '\n';
}