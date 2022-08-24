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


int main() {
	ll s, x;
	cin >> s >> x;
	ll a = (s - x);
	if (a % 2 != 0 || a < 0) {
		cout << 0 << "\n";
		return 0;
	}
	a /= 2;
	if ((a & x) != 0) {
		cout << 0 << "\n";
		return 0;
	}
	ll ans = 0;
	ll x2 = x;
	while (x)
		ans += (x & 1), x >>= 1;
	ans = 1ll << ans;
	if (s == x2)
		ans -= 2;
	cout << ans << "\n";

	return 0;
}