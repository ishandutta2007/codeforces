#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

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

int n;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	ll e1 = -1, e2 = -1;
	vector<pair<ll, ll>> vv;
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		vv.emplace_back(l, r);
	}
	sort(vv.begin(), vv.end());
	for (int i = 0; i < vv.size(); ++i) {
		if (vv[i].first > e1) {
			e1 = vv[i].second;
		}
		else if (vv[i].first > e2) {
			e2 = vv[i].second;
		}
		else {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}