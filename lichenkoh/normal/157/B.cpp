#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <array>
#include <iomanip>
#define ll unsigned long long
#define PI atan(1)*4
using namespace std;
int main() {
	ll n;
	cin >> n;
	ll *a = new ll[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a,a+n);
	ll s = 0;
	if (n % 2 == 0) {
		for (ll i = 1; i < n; i+=2 ) {
			s += a[i]*a[i] - a[i-1]*a[i-1];
		}
	}
	else {
		for (ll i = 0; i < n; i+=2) {
			if (i == 0) {
				s += a[i]*a[i];
			}
			else {
				s += a[i]*a[i] - a[i-1]*a[i-1];
			}
		}
	}
	cout << std::fixed;
    cout << std::setprecision(20);
	cout << PI * s << endl;
}