#include <cstdio>
using namespace std;

typedef long long ll;

int a, b, w, x, c;
ll res;

bool Enough(ll t)
{
	ll val = b - t * x;
	val = -val;
	ll got = val / w;
	if (got * w < val) got++;
	return c - t <= a - got;
}

int main()
{
	scanf("%d %d %d %d %d", &a, &b, &w, &x, &c);
	ll l = 0ll, r = 9000000000000000ll;
	while (l <= r) {
		ll m = l + r >> 1ll;
		if (Enough(m)) { res = m; r = m - 1; }
		else l = m + 1;
	}
	printf("%I64d\n", res);
	return 0;
}