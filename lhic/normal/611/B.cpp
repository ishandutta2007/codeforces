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


set<ll> ss;
int main() {
	for (ll now = 3; now < 2e18; now = (now * 2 + 1)) {
		for (int i = 0; i < 62; ++i) {
			if (now & (1ll << i) && now & (1ll << (i + 1)))
				ss.insert(now ^ (1ll << i));
		}
	}
	ll a, b;
	cin >> a >> b;
	int ans = 0;
	for (auto i: ss) {
		if (a <= i && i <= b)
			++ans;
	}
	cout << ans << "\n";
	return 0;

}