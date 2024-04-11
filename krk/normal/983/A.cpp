#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

int main()
{
	scanf("%d", &n);
	while (n--) {
		ll p, q, b; scanf("%I64d %I64d %I64d", &p, &q, &b);
		ll g = gcd(p, q); p /= g; q /= g;
		while (q > 1) {
			b = gcd(q, b);
			if (b == 1) break;
			q /= b;
		}
		printf("%s\n", q > 1? "Infinite": "Finite");
	}
	return 0;
}