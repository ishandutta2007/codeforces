#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, m;
ll k;
ll res;

ll Less(ll x)
{
	ll res = 0;
	for (int i = 1; i <= n; i++)
		res += min(ll(m), x / i);
	return res;
}

int main()
{
	scanf("%d %d %I64d", &n, &m, &k);
	ll l = 1, r = ll(n) * m;
	while (l <= r) {
		ll m = l + r >> 1ll;
		if (Less(m) >= k) { res = m; r = m - 1; }
		else l = m + 1;
	}
	printf("%I64d\n", res);
	return 0;
}