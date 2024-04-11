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
	ll *a = new ll[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll inv =0;
	for (ll i = 0; i < n; i++) {
		for (ll j = i+1; j < n; j++) {
			if (a[i] > a[j]) inv++;
		}
	}
	ll ans = 0;
	ll invdiv2 = inv/2;
	if (inv % 2 == 1) {
		ans = (invdiv2)*4 + 1;
	}
	else {
		ans = (invdiv2)*4;
	}
	cout << ans << endl;
}