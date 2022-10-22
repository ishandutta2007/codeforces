#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n;
ll res;

ll gcd(ll x, ll y)
{
	if (!x) return y;
	return gcd(y % x, x);
}

int main()
{
	cin >> n;
	if (n <= 2ll) res = n;
	else if (n % 2ll) res = n * (n - 1ll) * (n - 2ll);
	else {
		res = (n - 1ll) * (n - 2ll) * (n - 3ll);
		ll a = n, b = n - 1ll;
		ll c = n - 2ll;
		while (gcd(a, c) != 1ll || gcd(b, c) != 1ll) c--;
		res = max(res, a * b * c);
	}
	cout << res << endl;
	return 0;
}