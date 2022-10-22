#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n;
ll a, b, c;
ll res;

ll Get1(ll n)
{
	ll x = n / a; n -= a * x;
	ll y = 0;
	if (n >= c) {
		y = (n - c) / (b - c);
	}
	return x + y;
}

ll Get2(ll n)
{
	ll y = 0;
	if (n >= c) { y = (n - c) / (b - c); n -= y * (b - c); }
	ll x = n / a;
	return x + y;
}

int main()
{
	scanf("%I64d", &n);
	scanf("%I64d %I64d %I64d", &a, &b, &c);
	printf("%I64d\n", max(Get1(n), Get2(n)));
	return 0;
}