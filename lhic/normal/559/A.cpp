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

ll a[10];

ll get(ll x) {
	ll aa = 0;
	ll n = 1;
	for (int i = 0; i < x; ++i, n += 2) {
		aa += n;
	}
	return aa;
}

int main() {
	for (int i = 0; i < 6; ++i)
		cin >> a[i];
	ll ans = get(a[0] + a[1] + a[2]);
	ans -= get(a[0]);
	ans -= get(a[2]);
	ans -= get(a[4]);
	cout << ans << "\n";
	return 0;
}