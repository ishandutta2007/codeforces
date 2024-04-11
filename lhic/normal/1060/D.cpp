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

int n;

ll ans = 0;
vector<int> sl, sr;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll l, r;
		cin >> l >> r;
		ans += l + r + 1;
		sl.push_back(l);
		sr.push_back(r);
	}
	sort(ALL(sl));
	sort(ALL(sr));
	for (int i = 0; i < sl.size(); ++i)
		ans -= min(sl[i], sr[i]);
	cout << ans << "\n";
	return 0;
}