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
	ll x,y,n;
	cin >> x;
	cin >> y;
	cin >> n;
	ll g = gcd(x,y);
	x = x / g;
	y = y / g;
	if (n >= y) {
		cout << x << "/" << y << endl;
		return 0;
	}
	long double xdy = ((long double)x)/y;
	long double mind = INFINITY;
	ll mina;
	ll minb;
	for (ll b = 1; b <= n; b++) {
		ll a = floor(xdy*b);
		ll ar = round(xdy*b);
		long double adb = ((long double)a)/b;
		long double diff = fabs(xdy-adb);
		if (diff < mind) {
			mina = a;
			minb = b;
			mind = diff;
		}
		if (a != ar) {
			a = ar;
			adb = ((long double)a)/b;
			diff = fabs(xdy-adb);
			if (diff < mind) {
				mina = a;
				minb = b;
				mind = diff;
			}
		}

	}
	cout << mina << "/" << minb << endl;
}