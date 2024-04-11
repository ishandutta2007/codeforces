#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll x;
vector <ll> dvs, dvs2;
vector <ll> mult;
ll res;

ll Coprimes(ll x)
{
	ll num = x;
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) num -= num / i;
		while (x % i == 0) x /= i;
	}
	if (x > 1) num -= num / x;
	return num;
}

ll Mult(ll a, ll b)
{
	if (a == 0 || b == 0) return 0;
	ll res = 0;
	while (b) {
		if (b & 1) res = (res + a) % n;
		b >>= 1; a = (a + a) % n;
	}
	return res;
}

ll toPower(ll x, ll p)
{
	ll res = 1;
	while (p) {
		if (p & 1) res = Mult(res, x);
		p >>= 1; x = Mult(x, x);
	}
	return res;
}

int main()
{
	cin >> n >> x;
	for (ll i = 1; i * i <= n; i++) if (n % i == 0) {
		dvs.push_back(i);
		if (i * i < n) dvs.push_back(n / i);
	}
	ll p = Coprimes(n);
	for (ll i = 1; i * i <= p; i++) if (p % i == 0) {
		dvs2.push_back(i);
		if (i * i < p) dvs2.push_back(p / i);
	}
	sort(dvs2.begin(), dvs2.end());
	mult.resize(dvs2.size());
	for (int i = 0; i < dvs2.size(); i++)
		mult[i] = toPower(x, dvs2[i]);
	for (int i = 0; i < dvs.size(); i++) {
		ll nums = Coprimes(n / dvs[i]);
		for (int j = 0; j < mult.size(); j++)
			if (mult[j] % (n / dvs[i]) == 1) { res += nums / dvs2[j]; break; }
	}
	cout << res + 1 << endl;
	return 0;
}