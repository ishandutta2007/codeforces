#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long long
int main() {
	ll a,b;
	cin >> a;
	cin >> b;
	ll ans = 0;
	while (a != 0 && b != 0 && a!=b) {
		if (a < b) {
			ll n = b/a;
			ll anew = b - n*a;
			ll bnew = a;
			a = anew;
			b = bnew;
			ans += n;
		}
		else {
			ll k = a/b;
			ll anew = a - k*b;
			ll bnew = b;
			a = anew;
			b = bnew;
			ans += k;
		}
	}
	if (a == b && a != 0) {
		ans += 1;
	}
	cout << ans << endl;
	return 0;
}