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

const int MX = 1200000;
const ll MOD = 1e9 + 7;

ll fc[MX];
ll bfc[MX];
vector<int> pr;
int bb[MX];

ll pw(ll a, ll b) {
	ll ans = 1;
	while (b) {
		while (!(b & 1))
			b >>= 1, a = (a * a) % MOD;
		--b;
		ans = (ans * a) % MOD;
	}
	return ans;
}

ll cnk(int n, int k) {
	if (k > n)
		return 0;
	return fc[n] * bfc[k] % MOD * bfc[n - k] % MOD;
}


int main() {
	for (int i = 0; i < MX; ++i)
		bb[i] = i;
	for (int i = 2; i < MX; ++i) {
		if (bb[i] == i)
			pr.push_back(i);
		for (int j: pr) {
			if (j * i >= MX || j > bb[i])
				break;
			bb[j * i] = j;
		}
	}
	fc[0] = 1;
	for (int i = 1; i < MX; ++i)
		fc[i] = (fc[i - 1] * i) % MOD;
	bfc[MX - 1] = pw(fc[MX - 1], MOD - 2);
	for (int i = MX - 2; i >= 0; --i)
		bfc[i] = (bfc[i + 1] * (i + 1)) % MOD;
	int q;
	scanf("%d", &q);
	for (int it = 0; it < q; ++it) {
		int r, n;
		scanf("%d%d", &r, &n);
		ll ans = 1;
		while (n != 1) {
			int k = bb[n];
			int cnt = 0;
			while (n % k == 0)
				n /= k, ++cnt;
			ll dsh = cnk(r + cnt - 1, cnt);
			ll ndsh = 0;
			for (int i = 0; i < cnt; ++i)
				ndsh = (ndsh + cnk(r + i - 1, i)) % MOD;
			if (r == 0)
				dsh = 0, ndsh = 1;
			ans = (ans * (dsh + 2 * ndsh)) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}