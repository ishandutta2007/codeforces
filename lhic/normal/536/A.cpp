#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;


ll a, b;
int n;

bool check(ll l, ll r, ll m, ll t) {
	ll xl = a + (l - 1) * b;
	ll xr = a + (r - 1) * b;
	ll sum = (xl + xr) * (r - l + 1) / 2;
	if (xr <= t && m * t >= sum)
		return true;
	else
		return false;
}



int main() {
	scanf("%lld%lld%d", &a, &b, &n);
	for (int i = 0; i < n; ++i) {
		ll lx, m, t;
		scanf("%lld%lld%lld", &lx, &t, &m);
		ll l = lx - 1;
		ll r = lx + 4000000;
		while (r - l > 1) {
			ll x = (l + r) / 2;
			if (check(lx, x, m, t))
				l = x;
			else
				r = x;
		}
		if (l == lx - 1)
			printf("-1\n");
		else
			printf("%lld\n", l);
	}
	return 0;
}