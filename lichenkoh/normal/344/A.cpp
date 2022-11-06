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
	ll prev = 0;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (x != prev) {
			prev = x;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}