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
const ll MOD = 1e9 + 7;
const int MAXN = 5100;

ll dp[MAXN][30];
ll fc[MAXN];
ll bfc[MAXN];
int n;
char s[MAXN];
ll sum[MAXN];

ll pw(ll a, ll b) {
	ll ans = 1;
	while (b) {
		while (!(b & 1))
			b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD;
		--b;
	}
	return ans;
}
void init() {
	fc[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		fc[i] = (fc[i - 1] * i) % MOD;
	for (int i = 0; i < MAXN; ++i)
		bfc[i] = pw(fc[i], MOD - 2);
}

ll cnk(int n, int k) {
	return fc[n] * bfc[k] % MOD * bfc[n - k] % MOD;
}

int main() {
	init();
	scanf("%d", &n);
	scanf(" %s", s);
	for (int i = 0; i < n; ++i) {
		int x = s[i] - 'a';
		for (int j = i + 1; j > 1; --j) {
			sum[j] -= dp[j][x];
			if (sum[j] < 0)
				sum[j] += MOD;
			dp[j][x] = sum[j - 1] - dp[j - 1][x];
			if (dp[j][x] < 0)
				dp[j][x] += MOD;
			sum[j] += dp[j][x];
			if (sum[j] >= MOD)
				sum[j] -= MOD;
		}
		if (!dp[1][x])
			dp[1][x] = 1, ++sum[1];
	}
	ll ans = 0;
	for (int l = 1; l <= n; ++l) {
		ll c = sum[l];
		ans = (ans + c * cnk(n - 1, l - 1)) % MOD;
	}
	cout << ans << "\n";
	return 0;
}