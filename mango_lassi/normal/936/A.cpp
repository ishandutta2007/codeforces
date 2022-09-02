#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
	ll k, d, t;
	cin >> k >> d >> t;
	t *= 2;
	// j: smallest ll such that k <= jd
	ll j = (k+d-1)/d;
	// k <= jd
	ll rem = (2 * k) + (j*d - k);
	ll steps = t / rem;
	t -= steps * rem;
	ld res = steps * (j*d);
	if (t > 2 * k) {
		t -= 2 * k;
		res += k;
		res += t;
	} else {
		res += t / (ld)2;
	}
	cout << setprecision(20) << res << '\n';
}