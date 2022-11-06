#include <iostream>
using namespace std;
#define ll unsigned long long
int main() {
	ll n;
	cin >> n;
	ll a[30][30];
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	ll r[30];
	ll c[30];
	for (ll i = 0; i < 30; i++) {
		r[i] = 0;
		c[i] = 0;
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			c[i] += a[j][i];
		}
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			r[i] += a[i][j];
		}
		//cout << r[i] << endl;
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			if (c[i] > r[j]) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}