#include <iostream>
#define ll long long
using namespace std;
int main() {
	ll n,k;
	cin >> n;
	cin >> k;
	ll *p = new ll[n];
	ll x = 0;
	for (ll i = 0; i < n; i++) {
		cin >> p[i];
		if (p[i] + k <= 5) {
			x++;
		}
	}
	ll ans = x/3;
	cout << ans << endl;
	return 0;
}