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

int n, k;
ll fv[1200000];

void fl(int x) {
	for (; x < n; x |= (x + 1))
		fv[x] += 1;
}

ll get(int x) {
	ll ans = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1)
		ans += fv[x];
	return ans;
}

ll get(int l, int r) {
	ll ans = 0;
	if (r > 0)
		ans += get(r - 1);
	if (l > 0)
		ans -= get(l - 1);
	return ans;
}

int main() {
	cin >> n >> k;
	k = min(k, n - k);
	int x = 0;
	ll ans = 1;
	for (int i = 0; i < n; ++i) {
		fl(x);
		int nx = x + k;
		ans += 1;
		if (nx < n) {
			ans += 2 * get(x + 1, nx);
			x = nx;
		}
		else {
			nx -= n;
			ans += 2 * get(x + 1, n);
			ans += 2 * get(0, nx);
			if (nx != 0)
				ans -= 1;
			x = nx;
		}
		printf("%lld ", ans);
	}
	return 0;
}