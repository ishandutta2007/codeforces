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

ll dp1[2][2];
ll dp2[2][2];

ll get(ll x) {
	if (x < 0)
		return 0;
	ll ans = 0;
	for (int i = 0; i < 16; ++i) {
		dp1[0][0] = dp1[0][1] = dp1[1][0] = dp1[1][1] = 0;
		dp1[0][0] = 1;
		for (int j = 14; j >= 0; --j) {
			int l = j * 4;
			int r = j * 4 + 4;
			dp2[0][0] = dp2[0][1] = dp2[1][0] = dp2[1][1] = 0;
			int now = ((x >> l) & 15);
			for (int k = 0; k <= i; ++k) {
				if (l <= i && i < r && !((k >> (i - l)) & 1))
					continue;
				dp2[1][1] += dp1[1][1];
				if (k != i)
					dp2[1][0] += dp1[1][0];
				else
					dp2[1][1] += dp1[1][0];
				if (k == now)
					dp2[0][1] += dp1[0][1];
				else if (k < now)
					dp2[1][1] += dp1[0][1];
				if (k != i && k == now)
					dp2[0][0] += dp1[0][0];
				else if (k == i && k == now)
					dp2[0][1] += dp1[0][0];
				else if (k != i && k < now)
					dp2[1][0] += dp1[0][0];
				else if (k == i && k < now)
					dp2[1][1] += dp1[0][0];
			}
			dp1[0][0] = dp2[0][0];
			dp1[0][1] = dp2[0][1];
			dp1[1][0] = dp2[1][0];
			dp1[1][1] = dp2[1][1];
		}
		ans += dp1[0][1] + dp1[1][1];
	}
	return ans;
}


int main() {
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		ll l, r;
		scanf("%llx%llx", &l, &r);
		printf("%lld\n", get(r) - get(l - 1));
	}
	return 0;
}