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

const int MAXN = 120000;

int n;
ll x[MAXN];
vector<ll> vv;

int fnd(ll x) {
	int k = lower_bound(vv.begin(), vv.end(), x) - vv.begin();
	if (vv[k] == x)
		return 1;
	return 0;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 1; i < n; i += 2)
		cin >> x[i];
	ll k = 0;
	for (ll i = 0; i < 200000; ++i)
		vv.push_back(i * i);
	for (int i = 0; i < n; i += 2) {
		ll lst = k * k;
		++k;
		while (2 * k + 1 <= x[i + 1] && !fnd(k * k + x[i + 1]))
			++k;
		if (2 * k + 1 > x[i + 1]) {
			cout << "No\n";
			return 0;
		}
		x[i] = k * k - lst;
		ll nw = k * k + x[i + 1];
		while (k * k < nw)
			++k;
	}
	cout << "Yes\n";
	for (int i = 0; i < n; ++i)
		cout << x[i] << " ";
	cout << "\n";
	return 0;
}