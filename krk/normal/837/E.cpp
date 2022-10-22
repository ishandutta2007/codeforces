#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

ll x, y;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

ll F(ll x, ll y)
{
	if (y == 0) return 0;
	ll g = gcd(x, y); x /= g; y /= g;
	ll res = 0;
	for (ll i = 1; i * i <= x; i++)
		if (x % i == 0) {
			if (i != 1) res = max(res, y / i * i);
			if (x / i != 1) res = max(res, y / (x / i) * (x / i));
		}
	return y - res + F(x, res);
}

int main()
{
	scanf("%I64d %I64d", &x, &y);
	printf("%I64d\n", F(x, y));
	return 0;
}