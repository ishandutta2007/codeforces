#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 1e+9;

ll pow(ll x, ll power, ll mod) {
	if (!power)
		return 1;
	ll res = pow(x, power >> 1, mod);
	res = res * res % mod;
	if (power & 1)
		res = res * x % mod;
	return res;
}

pair<ll, ll> subfib(ll n, ll mod) {
	if (n <= 1)
		return make_pair(0, 1);
	if (n <= 3)
		return make_pair(1, 2);
	pair<ll, ll> prev = subfib(n >> 1, mod);
	if (n & 2)
		return make_pair((pow(prev.first + prev.second, 2, mod) - pow(prev.first, 2, mod) + mod) % mod,
		(pow(prev.first + prev.second, 2, mod) + pow(prev.second, 2, mod)) % mod);
	else
		return make_pair((pow(prev.second, 2, mod) - pow(prev.second - prev.first, 2, mod) + mod) % mod,
		(pow(prev.second, 2, mod) + pow(prev.first, 2, mod)) % mod);
}

ll fib(ll n, ll mod) {
	pair<ll, ll> res = subfib(n, mod);
	return (n & 1 ? res.second : res.first);
}

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll n, k, l, m, cnt0 = 0, cnt1 = 0;
	cin >> n >> k >> l >> m;

	for (; l; k >>= 1, l--)
		if (k & 1)
			cnt1++;
		else
			cnt0++;
	if (k) {
		cout << 0;
		return 0;
	}

	ll f = fib(n + 2, m);
	ll pow2 = pow(2, n, m);
	cout << (pow(f, cnt0, m) * pow((pow2 - f + m) % m, cnt1, m)) % m;

	return 0;
}