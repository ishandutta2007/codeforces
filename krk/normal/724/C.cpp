#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;

int n, m, k;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

void Euclid(ll a, ll &x, ll b, ll &y)
{
	if (a == 0) { x = 0; y = 1; }
	else {
		ll xx, yy; Euclid(b % a, xx, a, yy);
		x = yy - b / a * xx; y = xx;
	}
}

ll Solve(ll a, ll n, ll b, ll m)
{
	ll dif = b - a;
	ll g = gcd(n, m);
	if (dif % g != 0) return Inf;
	n /= g; m /= g; dif /= g;
	ll x, y; Euclid(n, x, m, y);
	x *= dif;
	x %= m;
	if (x < 0) x += m;
	return g * n * x + a;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	while (k--) {
		int x, y; scanf("%d %d", &x, &y);
		ll res1 = min(Solve(x, 2 * n, y, 2 * m), Solve(x, 2 * n, 2 * m - y, 2 * m));
		ll res2 = min(Solve(2 * n - x, 2 * n, y, 2 * m), Solve(2 * n - x, 2 * n, 2 * m - y, 2 * m));
		ll res = min(res1, res2);
		if (res >= Inf) printf("-1\n");
		else printf("%I64d\n", res);
	}
	return 0;
}