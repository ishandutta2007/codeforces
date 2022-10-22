#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

ll Get(ll x)
{
	ll res = 0;
	for (ll k = 2; ; k++) {
		ll val = k * k * k;
		if (val > x) break;
		res += x / val;
	}
	return res;
}

int main()
{
	ll m; scanf("%I64d", &m);
	ll lef = 1, rig = 100000000000000000ll;
	ll res;
	while (lef <= rig) {
		ll mid = lef + rig >> 1ll;
		ll got = Get(mid);
		if (got >= m) { res = mid; rig = mid - 1; }
		else lef = mid + 1;
	}
	printf("%I64d\n", Get(res) == m? res: -1ll);
	return 0;
}