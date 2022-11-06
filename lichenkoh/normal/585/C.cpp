#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
int main() {
	ll m,n;
	cin >> m; cin >> n;
	if (__gcd(m,n) != 1) {
		cout << "Impossible" << endl;
		return 0;
	}
	ll a = 1; ll b = 0;
	ll c = 0; ll d = 1;
	while(1) {
		if (a+b == m && c+d == n) break;
		/*cout << endl << a << "," << b << endl;
		cout << c << "," << d << endl;
		cout << endl;*/
		ll quo = a*d-b*c;
		assert(quo != 0);
		ll x = (d*m - b*n)/quo;
		ll y = (-c*m + a*n)/quo;
		assert(min(x,y) != 0);
		ll MAX = max(x,y);
		ll MIN = min(x,y);
		ll k = (MAX-1)/MIN;
		if (x < y) {
			cout << k << "B";
			a += k*b;
			c += k*d;
		}
		else if (x > y) {
			cout << k << "A";
			b += k*a;
			d += k*c;
		}
		else {
			assert(false);
		}
	}
	cout << endl;
}