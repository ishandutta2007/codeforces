#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

int n, k, m;
int tt[120];

int main() {
	cin >> n >> k >> m;
	int sm = 0;
	for (int i = 0; i < k; ++i)
		cin >> tt[i], sm += tt[i];
	sort(tt, tt + k);
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		int t = m - i * sm;
		if (t < 0)
			continue;
		int now = k * i + i;
		for (int j = 0; j < k; ++j) {
			int go = min(n - i, t / tt[j]);
			t -= go * tt[j];
			now += go;
		}
		ans = max(ans, now);
	}
	cout << ans << "\n";
	return 0;
}