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
ll l;

ll gg(ll x) {
	if (x < 0)
		return 0;
	return (x + 2) * (x + 1) / 2;
}


ll get(ll a, ll b, ll c) {
	ll x = c - a - b;
	ll ans = 0;
	for (ll i = 0; i <= l; ++i) {
		if (i + x < 0)
			continue;
		ll md = l - x - 2 * i;
		md = max(0ll, md);
		ans += gg(l - md - i);
	}
	return ans;
}


int main() {
	ll a, b, c;
	cin >> a >> b >> c;

	cin >> l;
	ll ans = (l + 3) * (l + 2) * (l + 1) / 6;
	ans -= get(a, b, c);
	ans -= get(c, a, b);
	ans -= get(c, b, a);
	cout << ans << "\n";

	return 0;
}