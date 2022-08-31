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

ll c, h1, h2, w1, w2;

int main() {
	cin >> c >> h1 >> h2 >> w1 >> w2;
	if (w1 < w2)
		swap(h1, h2), swap(w1, w2);

	ll ans = 0;
	if (w1 > 100) {
		for (ll i = 0; i * w1 <= c; ++i)
			ans = max(ans, i * h1 + ((c - i * w1) / w2) * h2);
	}
	else {
		if (h1 * w2 < h2 * w1)
			swap(h1, h2), swap(w1, w2);
		ll k = c / w1;
		for (ll i = k; i >= k - 200 && i >= 0; --i)
			ans = max(ans, i * h1 + ((c - i * w1) / w2) * h2);
	}
	cout << ans;
	return 0;
}