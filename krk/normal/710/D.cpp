#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a1, b1, a2, b2, L, R;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

void Solve(ll a, ll &x, ll b, ll &y)
{
	if (a == 0) { x = 0; y = 1; }
	else {
		ll xx, yy;
		Solve(b % a, xx, a, yy);
		x = yy - b / a * xx; y = xx;
	}
}

ll Reach(ll a, ll b)
{
	if (a < 0) return 0;
	return a / b + 1 - (a % b == 0);
}

int main()
{
	cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
	ll g = gcd(a1, a2);
	ll dif = b2 - b1;
	if (dif % g != 0) { printf("0\n"); return 0; }
	a1 /= g; a2 /= g; dif /= g;
	ll x, y; Solve(a1, x, a2, y); x *= dif; y *= dif;
	if (x >= 0) {
		int tk = x / a2;
		x -= a2 * tk; y += a1 * tk;
	}
	ll r = max(Reach(-x, a2), Reach(y, a1));
	x += a2 * r; y -= a1 * r;
	L -= (g * a1 * x + b1); R -= (g * a1 * x + b1);
	L = max(L, 0ll); 
	ll x1 = L / (g * a1 * a2);
	while (L <= a1 * a2 * g * x1) x1--;
	x1++;
	ll x2 = R / (g * a1 * a2);
	while (a1 * a2 * g * x2 <= R) x2++;
	x2--;
	printf("%I64d\n", max(0ll, x2 - x1 + 1));
	return 0;
}