#include <cstdio>
using namespace std;

typedef long long ll;

ll a, b;

ll Get(ll x)
{
	ll res = 0ll;
	for (ll i = 1; i <= 62; i++) {
		ll has = (1ll << i) - 1ll;
		for (ll j = 0; j < i - 1; j++) {
			ll got = has ^ (1ll << j);
			if (got <= x) res++;
		}
	}
	return res;
}

int main()
{
	scanf("%I64d %I64d", &a, &b);
	printf("%I64d\n", Get(b) - Get(a - 1));
	return 0;
}