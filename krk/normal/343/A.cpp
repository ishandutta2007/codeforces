#include <cstdio>
using namespace std;

typedef long long ll;

ll a, b;

ll Get(ll a, ll b)
{
	if (a == 0ll) return 0ll;
	if (a >= b) {
		ll tims = a / b; a %= b;
		return tims + Get(a, b);
	} else {
		ll tims = b / a; b %= a;
		if (b == 0) { tims--; b += a; }
		return tims + Get(a, b);
	}
}

int main()
{
	scanf("%I64d %I64d", &a, &b);
	printf("%I64d\n", Get(a, b));
	return 0;
}