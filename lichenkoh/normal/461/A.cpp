#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
	ll n;
	cin >> n;
	ll *a = new ll[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a,a+n);
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ans += a[i] * min(n, i+2);
	}
	cout << ans << endl;
}