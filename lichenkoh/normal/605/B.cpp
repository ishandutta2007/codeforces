#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define SZ 100008
pair<ll,ll> ans[SZ];
ll a[SZ], b[SZ], p[SZ];
pair<pair<ll,ll>, ll> e[SZ];
vector<pair<ll,ll> > v;
int main() {
	ios_base::sync_with_stdio(false);
	ll n,m; cin >> n; cin >> m;
	for (ll i = 0; i < m; i++) {
		ll ai,bi; cin >> ai; cin >> bi;
		e[i] = MP(MP(ai,1-bi),i);
	}
	sort(e, e+m);
	for (ll i = 0; i < m; i++) {
		a[i] = e[i].first.first;
		b[i] = 1-e[i].first.second;
		p[i] = e[i].second;
	}
	ll mste = 0;
	for (ll i = 0; i < m; i++) {
		if (b[i] == 1) mste++;
	}
	ll inc = 0;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j < (i-1); j++) {
			v.PB(MP(j,i));
			inc++;
			if (inc > m) break;
		}
		if (inc > m) break;
	}
	ll vlim = v.size();
	ll t = 1;
	ll s = 0;
	bool good = true;
	for (ll i = 0; i < m; i++) {
		if (b[i] == 1) {
			ll x = t;
			ll y = t+1;
			if (x > n || y > n) {
				good = false; break;
			}
			ans[p[i]] = MP(x,y);
			t++;
		}
		else {
			if (!(s < vlim)) {
				good = false; break;
			}
			ll x = v[s].first; ll y = v[s].second;
			if (x > t || y > t) {
				good = false; break;
			}
			ans[p[i]] = MP(x,y);
			s++;
		}
	}
	if (mste != (n-1)) {
		good = false;
	}
	if(good) {
		for (ll i = 0; i < m; i++) {
			printf("%I64d %I64d\n", ans[i].first, ans[i].second);
		}
	}
	else {
		printf("%d\n", -1);
	}
}