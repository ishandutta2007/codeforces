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
	ll b[6000];
	for (ll i = 0; i < 6000; i++) {
		b[i] = 0;
	}
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		b[x]++;
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		if (b[i] == 0) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}