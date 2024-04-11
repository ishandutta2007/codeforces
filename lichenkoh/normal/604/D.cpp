#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
int main() {
	ios_base::sync_with_stdio(false);
	ll p,k; cin >> p; cin >> k;
	if (k == 0) {
		ll final = 1;
		for (ll i = 1; i < p; i++) {
			final = (final * p) % MOD;
		}
		final = final % MOD;
		cout << final << endl;
		return 0;
	}
	ll *h = new ll[p];
	bool *seen = new bool[p];
	for (ll i = 0; i < p; i++) {
		h[i] = 0;
		seen[i] = false;
	}
	set<ll> s;
	for (ll x = 0; x < p; x++) {
		if (seen[x]) continue;
		ll y = x;
		ll c = 0;
		while(1) {
			if (seen[y]) break;
			seen[y] = true;
			c++;
			y = (k * y)% p;
		}
		h[c]++;
		s.insert(c);
	}
	vector<ll> v;
	for (auto& y: s) {
		v.PB(y);
	}
	ll m = v.size();
	ll ans = 1;
	for (ll i = 0; i < m; i++) {
		ll c = v[i];
		ll cand = 0;
		for (ll j = 0; j < m; j++) {
			ll d = v[j];
			if (c % d == 0) {
				cand = (cand + (h[d] * d)%MOD)%MOD;
			}
		}
		for (ll i = 0; i < h[c]; i++) {
			ans = (ans * cand) % MOD;
		}
	}
	ans = ans % MOD;
	while (ans < 0) ans += MOD;
	ans = ans % MOD;
	cout << ans << endl;
}