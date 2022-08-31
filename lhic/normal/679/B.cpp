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

ll m;

ll cb(ll a) {
	return a * a * a;
}

int main() {
	cin >> m;
	ll nsum = 0;
	vector<ll> vv;
	while (true) {
		int fl = 0;
		for (ll i = 1; ; ++i) {
			if (nsum + i * i * i > m) {
				fl = 1;
				break;
			}
			if ((i + 1) * (i + 1) * (i + 1) - i * i * i > nsum) {
				nsum += i * i * i;
				vv.push_back(i);
				break;
			}
		}
		if (fl)
			break;
	}
	cout << vv.size() << " ";
	ll up = m;
	reverse(vv.begin(), vv.end());
	for (int i = 0; i < (int)vv.size(); ++i) {
		while (nsum + cb(vv[i] + 1) - cb(vv[i]) <= up)
			nsum += cb(vv[i] + 1) - cb(vv[i]), ++vv[i];
		up -= cb(vv[i]);
		up = min(up, cb(vv[i] + 1) - cb(vv[i]) - 1);
		nsum -= cb(vv[i]);
	}
	ll ans = 0;
	for (int i = 0; i < (int)vv.size(); ++i)
		ans += cb(vv[i]);
	cout << ans << "\n";
	return 0;
}