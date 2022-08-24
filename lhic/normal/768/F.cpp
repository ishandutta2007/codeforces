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
const int MX = 210000;
ll fc[MX];
ll bfc[MX];
const ll MOD = 1e9 + 7;

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

void init() {
	fc[0] = 1;
	for (int i = 1; i < MX; ++i)
		fc[i] = (fc[i - 1] * i) % MOD;
	for (int i = 0; i < MX; ++i)
		bfc[i] = pw(fc[i], MOD - 2);
}

ll cnk(int n, int k) {
	if (k > n)
		return 0;
	return fc[n] * bfc[k] % MOD * bfc[n - k] % MOD;
}


int f, w, h;

int main() {
	scanf("%d%d%d", &f, &w, &h);
	if (w == 0) {
		cout << 1 << "\n";
		return 0;
	}
	++h;
	init();
	ll ans = 0;
	for (int l = 1; l <= f + 1 && l * h <= w; ++l)
		ans = (ans + cnk(f + 1, l) * cnk(w - h * l + l - 1, l - 1)) % MOD;
	ans = (ans * pw(cnk(f + w, w), MOD - 2)) % MOD;
	cout << ans << "\n";
	return 0;
}