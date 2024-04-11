#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, a, b, p, q;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

int main()
{
	scanf("%d %d %d %d %d", &n, &a, &b, &p, &q);
	ll lcm = ll(a) / gcd(a, b) * b;
	ll redblue = ll(n) / lcm;
	ll red = n / a - redblue;
	ll blue = n / b - redblue;
	printf("%I64d\n", red * p + blue * q + redblue * max(p, q));
	return 0;
}