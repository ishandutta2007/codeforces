#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;

#define M 1000000007

int main() {
	ll n,k;
	cin >> n;
	cin >> k;
	ll **f = new ll*[k+1];
	for (ll i = 0; i <= k; i++) {
		f[i] = new ll[n+1];
		for (ll j = 0; j <= n; j++) {
			f[i][j] = 0;
		}
	}
	for (ll j = 0; j <= n; j++) {
		f[1][j] = 1;
	}
	for (ll i = 1; i < k; i++) {
		for (ll j = 1; j <= n; j++) {
			ll dlimit = n/j;
			for (ll d = 1; d <= dlimit; d++) {
				f[i+1][j*d] = (f[i][j] + f[i+1][j*d]) % M;
			}
		}
	}
	ll ans = 0;
	for (ll j = 1; j <= n; j++) {
		ans = (ans + f[k][j]) % M;
	}
	cout << ans % M << endl;
	return 0;
}