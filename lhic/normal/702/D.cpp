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

void out(ll a) {
	cout << a << "\n";
	exit(0);
}

ll d, k, a, b, t;

int main() {
	cin >> d >> k >> a >> b >> t;
	ll rans = b * d;
	ll ans = a * d;
	b -= a;

	if (k >= d)
		out(ans);

	if (b * k <= t) {
		out(ans + (d - k) * b);
	}
	else {
		ll x = d / k;
		x -= 2;
		x = max(x, 0ll);
		d -= x * k;
		ans += t * x;
		while (d > 0) {
			if (d <= k) {
				rans = min(rans, ans);
				break;
			}
			d -= k;
			rans = min(rans, ans + d * b);
			ans += t;
		}
		out(rans);
	}

	return 0;
}