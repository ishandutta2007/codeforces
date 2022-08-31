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

ll n;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	ll x = 2;
	for (ll k = 1; k <= n; ++k) {
		ll now = k * (k + 1) * (k + 1);
		ll a = 1;
		while (a * a * now < x)
			++a;
		cout << a * a * now - x << "\n";
		x = a * k;
	}
	return 0;
}