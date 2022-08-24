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

ll n, k;

ll phi(ll n) {
	ll ans = 1;
	for (ll i = 2; i * i <= n; ++i) {
		if (n % i != 0)
			continue;
		ll p = i - 1;
		n /= i;
		while (n % i == 0)
			n /= i, p *= i;
		ans *= p;
	}
	if (n != 1)
		ans *= (n - 1);
	return ans;
}
const ll MOD = 1e9 + 7;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= k && n != 1; ++i) {
		if (i % 2 == 1) {
			n = phi(n);
		}
	}
	cout << n % MOD << "\n";
	return 0;
}