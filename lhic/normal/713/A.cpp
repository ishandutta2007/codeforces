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

map<ll, int> mm;

ll conv(ll x) {
	ll ans = 0;
	for (int i = 0; x != 0; ++i) {
		ll a = x % 10;
		if (a % 2 == 1)
			ans += (1ll << i);
		x /= 10;
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		char c;
		ll d;
		scanf(" %c%lld", &c, &d);
		if (c == '+') {
			d = conv(d);
			++mm[d];
		}
		else if (c == '-') {
			d = conv(d);
			--mm[d];
		}
		else {
			d = conv(d);
			printf("%d\n", mm[d]);
		}
	}
	return 0;
}