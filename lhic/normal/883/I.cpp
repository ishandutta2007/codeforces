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

int n, k;
int v[320000];
int sm[320000];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", v + i);
	sort(v + 1, v + n + 1);
	ll l = -1;
	ll r = 1e9 + 100;
	while (r - l > 1) {
		ll mid = (l + r) >> 1;
		sm[0] = 0;
		sm[1] = 1;
		for (int i = 1; i <= n; ++i) {
			int rb = i - k + 1;
			int lb = lower_bound(v + 1, v + n + 1, v[i] - mid) - v - 1;
			if (rb <= lb || sm[rb] == sm[lb]) {
				sm[i + 1] = sm[i];
			}
			else
				sm[i + 1] = sm[i] + 1;
		}
		if (sm[n + 1] == sm[n])
			l = mid;
		else
			r = mid;
	}
	cout << r << "\n";
	return 0;
}