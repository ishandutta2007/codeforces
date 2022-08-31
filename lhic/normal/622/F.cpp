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

const ll MOD = 1000000007;

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

ll bck(ll a) {
	if (a < 0)
		a += MOD;
	return pw(a, MOD - 2);
}

int n, k;

const int MAXN = 1200000;

ll ss[MAXN];
ll ff[MAXN];


int main() {
	cin >> n >> k;
	ss[0] = 0;
	for (int i = 1; i < k + 2; ++i)
		ss[i] = (ss[i - 1] + pw(i, k)) % MOD;
	ff[0] = 1;
	for (int i = 1; i < k + 2; ++i)
		ff[i] = (ff[i - 1] * i) % MOD;
	if (n < k + 2) {
		cout << ss[n] << "\n";
		return 0;
	}
	ll ans = 0;
	ll a = 1;
	for (int i = 0; i < k + 2; ++i)
		a = (a * (n - i)) % MOD;
	for (int i = 0; i < k + 2; ++i) {
		a = (a * bck(n - i)) % MOD;
		if ((k + 1 - i) & 1) {
			ll now = a * bck(-(ff[i] * ff[k + 1 - i]) % MOD);
			now %= MOD;
			ans = (ans + now * ss[i]) % MOD;
		}
		else {
			ll now = a * bck((ff[i] * ff[k + 1 - i]) % MOD);
			now %= MOD;
			ans = (ans + now * ss[i]) % MOD;
		}
		a = (a * (n - i)) % MOD;
	}
	cout << ans << "\n";
	
	return 0;
}