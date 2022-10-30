#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) { while (b) a %= b, swap(a,b); return a; }

ll calc(ll a, ll b) {
	b /= gcd(a,b);
	ll tb = b;
	// find totient(b)
	for (ll i = 2; i*i <= b; i++) {
		if (b % i == 0) {
			tb -= tb/i;
			while (b % i == 0) b /= i;
		}
	}
	if (b > 1) tb -= tb/b;
	return tb;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int ntc;
	cin >> ntc;
	while (ntc--) {
		ll x, y;
		cin >> x >> y;
		cout << calc(x, y) << endl;
	}
	return 0;
}