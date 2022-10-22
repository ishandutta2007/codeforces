#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

int t;
ll x, y, p, q;

int main()
{
	cin >> t;
	while (t--) {
		cin >> x >> y >> p >> q;
		ll b = (q - y % q) % q;
		ll a = p * (y + b) / q - x;
		if (a < 0)
			if (p == 0) { printf("-1\n"); continue; }
			else {
				ll tk = (-a / p) + ll(-a % p != 0);
				a += p * tk; b += q * tk;
			}
		if (a <= b) printf("%I64d\n", b);
		else if (q - p == 0) printf("-1\n");
		else {
			ll add = (a - b) / (q - p) + ll((a- b) % (q - p) != 0);
			a += add * p; b += add * q;
			printf("%I64d\n", b);
		}
	}
	return 0;
}