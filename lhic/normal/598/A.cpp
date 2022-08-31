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
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		ll n;
		cin >> n;
		ll ans = n * (n + 1) / 2;
		for (ll now = 1; now <= n; now *= 2)
			ans -= 2 * now;
		cout << ans << "\n";
	}
	return 0;
}