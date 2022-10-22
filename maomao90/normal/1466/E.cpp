#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int t;
int n;
ll x[500005];
int maxBit, cnt1[70];
ll lft[500005], rht[500005];
ll ans;

#define getchar_unlocked getchar
inline void read(ll& x) {
    x = 0;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9') ch = getchar_unlocked();
    while (ch >= '0' && ch <= '9' ) {
        x = (x << 3) + (x << 1) + (ch & 15);
        ch = getchar_unlocked();
    }
}

int main() {
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		scanf("%d", &n);
		memset(lft, 0, sizeof lft);
		memset(cnt1, 0, sizeof cnt1);
		maxBit = 0;
		for (int i = 0; i < n; ++i) {
			read(x[i]);
			ll temp = x[i];
			while (temp > 0) {
				ll val = temp & -temp;
				int j = 63 - __builtin_clzll(val);
				cnt1[j]++;
				temp -= val;
				maxBit = max(maxBit, j);
			}
		}
		for (int k = 0; k < n; ++k) {
			ll temp = x[k];
			while (temp > 0) {
				ll val = temp & -temp;
				int j = 63 - __builtin_clzll(val);
				lft[k] += cnt1[j] * ((1ll << j) % MOD) % MOD;
				lft[k] %= MOD;
				temp -= val;
			}
		}
		ll temp = 0;
		for (int i = 0; i <= maxBit; ++i) {
			temp += cnt1[i] * ((1ll << i) % MOD) % MOD;
			temp %= MOD;
		}
		for (int i = 0; i < n; ++i) rht[i] = temp;
		for (int k = 0; k < n; ++k) {
			ll temp = x[k];
			while (temp > 0) {
				ll val = temp & -temp;
				int j = 63 - __builtin_clzll(val);
				if (x[k] & (1ll << j)) rht[k] += (n - cnt1[j]) * ((1ll << j) % MOD) % MOD;
				rht[k] %= MOD;
				temp -= val;
			}
		}
		for (int k = 0; k < n; ++k) {
			ans += lft[k] * rht[k] % MOD;
			ans %= MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}