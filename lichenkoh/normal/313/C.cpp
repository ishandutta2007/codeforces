#include <iostream>
#include <assert.h>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll unsigned long long

int main() {
	ll n;
	cin >> n;
	ll *a = new ll[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a,a+n,std::greater<ll>());
	ll e = round(log2(n))/2;
	ll ans = 0;
	ll x = 0;
	ll lim = 1<<(2*x);
	for (ll i=0; i<n; i++) {
		ll j = i+1;
		if (j > lim) {
			x++;
			lim = 1<<(2*x);
		}
		ll times = e-x+1;
		//cout << j << ":" << times << endl;
		ans += a[i]*times;
	}
	cout << ans << endl;
	return 0;
}