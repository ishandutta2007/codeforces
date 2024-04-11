#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

ll k;
const int X = 999999;


ll solve(vector<ll> a) {
	ll res = 0;
	ll cur = 0;
	int k = -1;
	for (int i = 0; i < a.size(); ++i) {
		cur += a[i];
		if (cur < 0) {
			cur = 0;
			k = i;
		}
		res = max(res, (i-k)*cur);
	}
	return res;
}

ll solve2(vector<ll> a) {
	ll ans = 0;
	for (int i = 0; i < a.size(); ++i) {
		for (int j = i; j < a.size(); ++j) {
			ll cur = 0;
			for (int k = i; k <= j; ++k)
				cur += a[k];
			ans = max(ans, cur * (j - i + 1));
		}
	}
	return ans;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> k;
	k += 2;
	ll x = (k + X - 1) / X;
	if ((x * X - k) % 2 == 1)
		x += 1;
	ll a = (x * X - k) / 2;
	vector<ll> vv;
	for (int i = 0; i < x; ++i)
		vv.push_back(0);
	vv.push_back(-1);
	vv.push_back(ll(1e6));
	vv.push_back(-ll(1e6));
	vv.push_back(-ll(1e6));
	vv.push_back(-ll(1e6));
	vv.push_back(ll(1e6));
	vv.push_back(a);
	cout << vv.size() << "\n";
	for (ll x: vv)
		cout << x << " ";
	cout << "\n";
	//cerr << solve2(vv) - solve(vv) << "\n";
	return 0;
}