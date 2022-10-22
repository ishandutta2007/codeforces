#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll n;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

ll sum(ll n)
{
	ll res = 0;
	while (n) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%I64d", &n);
		while (gcd(n, sum(n)) == 1) n++;
		printf("%I64d\n", n);
	}
    return 0;
}