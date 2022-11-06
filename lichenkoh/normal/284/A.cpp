#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
ll gcd(ll a, ll b) {
	while (b != 0) {
		ll tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int main() {
	ll p;
	cin >> p;
	if (p == 2) {
		cout << 1 << endl;
		return 0;
	}
	ll ans = 0;
	for (ll i = 1; i < p-1; i++) {
		if (gcd(i,p-1) == 1) {
			ans++;
		}
	}
	cout << ans << endl;
}