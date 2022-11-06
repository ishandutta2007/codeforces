#include <bits/stdc++.h>
#include <complex>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MOD 1000000007LL
#define PB push_back
#define UNDEF -1
ll g(ll x, ll y, ll d) {
	if (x % d != 0) {
		x += (d - x%d);
	}
	if (y % d != 0) {
		y -= y % d;
	}
	ll ret = (((y-x)/d) + 1)%MOD;
	if (ret < MOD) ret += MOD;
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	ll n,k;
	cin >> n; cin >> k;
	ll m = n/k;
	ll *a = new ll[m];
	ll *b = new ll[m];
	for (ll i = 0; i < m; i++) {
		cin >> a[i];
	}
	for (ll i = 0; i < m; i++) {
		cin >> b[i];
	}
	ll ans = 1;
	ll q = 1;
	for (ll i = 0; i < k-1; i++) {
		q *= 10;
	}
	ll lim = 1;
	for (ll i = 0; i < k; i++) {
		lim *= 10;
	}
	lim--;
	//cout << q << "," << lim << endl;
	for (ll i = 0; i < m; i++) {
		ll cand = (g(0, lim,a[i]) - g(b[i]*q, (b[i]+1)*q - 1, a[i]))%MOD;
		if (cand < 0) cand += MOD;
		ans = (ans * cand) % MOD;
		if (ans < 0) ans += MOD;
	}
	if (ans < 0) ans += MOD;
	cout << ans << endl;
}