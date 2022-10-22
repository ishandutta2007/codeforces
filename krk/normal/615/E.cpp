#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n;

int main() 
{
	cin >> n;
	ll lef = 1, rig = 1000000000;
	ll res = 0;
	while (lef <= rig) {
		ll mid = lef + rig >> 1ll;
		if (mid * (3ll * mid + 2ll) <= n) { res = mid; lef = mid + 1; }
		else rig = mid - 1;
	}
	ll x = res, y = -2ll * res;
	n -= res * (3ll * res + 2ll);

	ll mv = min(n, res + 1ll); n -= mv;
	x += mv; y += 2ll * mv;

	mv = min(n, res); n -= mv;
	x -= mv; y += 2ll * mv;

	mv = min(n, res + 1ll); n -= mv;
	x -= 2 * mv;

	mv = min(n, res + 1ll); n -= mv;
	x -= mv; y -= 2ll * mv;

	mv = min(n, res + 1ll); n -= mv;
	x += mv; y -= 2ll * mv;

	mv = min(n, res + 1ll); n -= mv;
	x += 2 * mv;

	printf("%I64d %I64d\n", x, y);
    return 0;
}