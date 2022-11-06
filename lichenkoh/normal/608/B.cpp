#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
int main() {
	ios_base::sync_with_stdio(false);
	string a,b;
	cin >> a; cin >> b;
	ll s = a.length();
	ll t = b.length();
	ll *d = new ll[t+1];
	d[0] = 0;
	for (ll i = 1; i <= t; i++) {
		d[i] = (b[i-1] == '1') ? 1 : 0;
	}
	for (ll i = 1; i <= t; i++) {
		d[i] = d[i-1] + d[i];
	}
	ll ans = 0;
	for (ll i = 1; i <= s; i++) {
		ll x = (a[i-1] == '1') ? 1 : 0;
		ll numone = d[t-s+i] - d[i-1];
		ll numzero = (t-s+1) - numone;
		if (x == 0) {
			ans += numone;
		}
		else {
			ans += numzero;
		}
	}
	cout << ans << "\n";
}