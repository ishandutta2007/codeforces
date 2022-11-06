#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long long
int main() {
	ll n;
	cin >> n;
	ll *a = new ll[n+1];
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll m;
	cin >> m;
	for (ll j = 0; j < m; j++) {
		ll x,y;
		cin >> x;
		cin >> y;
		ll left = y-1;
		ll right = a[x] - y;
		a[x] = 0;
		if (x-1 >= 1) {
			a[x-1] += left;
		}
		if (x+1 <= n) {
			a[x+1] += right;
		}
	}
	for (ll i = 1; i <= n; i++) {
		cout << a[i] << endl;
	}
	return 0;
}