#include <cstdio>
#include <set>
using namespace std;

typedef long long ll;

ll n;
set <ll> res;

void Test(ll k2)
{
	ll lef = 0ll, rig = 5000000000ll;
	while (lef <= rig) {
		ll mid = lef + rig >> 1ll;
		ll x = 2ll * mid + 1ll;
		if (x + 2ll * k2 - 3ll <= 2ll * n / x)
			if (x * (x + 2ll * k2 - 3ll) == 2ll * n) { res.insert(x * k2); return; }
			else lef = mid + 1ll;
		else rig = mid - 1ll;
	}
}

int main()
{
	scanf("%I64d", &n);
	ll cur = 1;
	while (2ll * cur - 2ll <= 2ll * n) { Test(cur); cur *= 2ll; }
	if (res.empty()) printf("-1\n");
	else for (set <ll>::iterator it = res.begin(); it != res.end(); it++)
			printf("%I64d\n", *it);
	return 0;
}