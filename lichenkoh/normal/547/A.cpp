#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
#define UNDEF -1
int main() {
	ll m; cin >> m;
	ll pa[2],ca[2];
	ll ha[2],aa[2],xa[2],ya[2];
	for (ll i = 0; i <= 1; i++) {
		ll h,a,x,y;
		cin >> ha[i]; cin >> aa[i];
		cin >> xa[i]; cin >> ya[i];
		h = ha[i]; a = aa[i]; x = xa[i]; y = ya[i];
		bool *seen = new bool[m];
		for (ll k = 0; k < m; k++) {
			seen[k] = false;
		}
		ll id = 0;
		ll init = UNDEF; ll order = UNDEF;
		for (ll j = 0; j <= 5*m; j++) {
			if (h == a && seen[h] == true) {
				order = id - init;
				break;
			}
			if (h == a && seen[h] == false) {
				init = id;
			}
			seen[h] = true;
			h = (x*h+y) % m;
			id++;
		}
		pa[i] = order;
		ca[i] = init;
	}
	for (ll j = 0; j <= 5*m; j++) {
		if (ha[0] == aa[0] && ha[1] == aa[1]) {
			cout << j << endl;
			return 0;
		}
		for (ll i = 0; i <= 1; i++) {
			ha[i] = (xa[i]*ha[i]+ya[i]) % m;
		}
	}
	ll p = pa[0]; ll q = pa[1];
	ll c = ca[0]; ll d = ca[1];
	if (p == UNDEF || q == UNDEF || c == UNDEF || d == UNDEF) {
		cout << -1 << endl;
		return 0;
	}
	ll lim = 5*(q+c+d);
	for (ll x = 0; x <= lim; x++) {
		ll take = (p*x - d + c)%q;
		while (take < 0) {
			take += q;
		}
		if (take == 0) {
			ll ans = p*x+c;
			if (ans >= d) {
				cout << ans << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}