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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

ll md(ll a, ll b) {
	a %= b;
	if (a < 0)
		return a + b;
	else
		return a;
}
ll a1, b1, a2, b2, l, r;

int main() {
	cin >> a1 >> b1 >> a2 >> b2 >> l >> r;
	l = max(l, b1);
	l = max(l, b2);
	if (a1 < a2)
		swap(a1, a2), swap(b1, b2);
	ll x = __gcd(a1, a2);
	if (md(b1, x) != md(b2, x) || l > r) {
		cout << 0 << "\n";
		return 0;
	}
	ll ans = 0;
	if (a1 > 1000) {
		while (b1 < l)
			b1 += a1;
		while (b1 <= r) {
			if ((b1 - b2) % a2 == 0)
				++ans;
			b1 += a1;
		}
	}
	else {
		if (b1 < l) {
			ll k = (l - b1 + a1 - 1) / a1;
			b1 += k * a1;
		}
		while (b1 <= r && (b1 - b2) % a2 != 0)
			b1 += a1;
		if (b1 <= r) {
			ll k = a1 * a2 / __gcd(a1, a2);
			ans = 1 + (r - b1) / k;
		}
	}
	cout << ans << "\n";
	return 0;
}