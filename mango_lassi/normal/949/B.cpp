#include <iostream>
using namespace std;

typedef long long ll;

ll ask(ll n, ll x) {
	ll res = 0;
	if (x & 1) {
		res = (x+1)>>1;
	} else {
		if (n & 1) {
			if (x == 2) {
				res = (n+1)/2 + ask(n/2, n/2);
			} else {
				res = (n+1)/2 + ask(n/2, (x-2)/2);
			}
		} else {
			res = (n+1)/2 + ask(n/2, x/2);
		}
	}
	// cout << n << ' ' << x << ' ' << res << '\n';
	return res;
}

int main() {
	ll n; int q;
	cin >> n >> q;
	while(q--) {
		ll x;
		cin >> x;
		cout << ask(n, x) << '\n';
	}
}