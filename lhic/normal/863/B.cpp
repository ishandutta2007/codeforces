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

int n;
int w[1200];

int main() {
	cin >> n;
	n *= 2;
	for (int i = 0; i < n; ++i)
		cin >> w[i];
	ll ans = 1e9;
	sort(w, w + n);
	for (int i = 0; i < n; i += 2) {
		for (int j = i + 1; j < n; j += 2) {
			ll cur = 0;
			for (int k = 0; k < i; k += 2)
				cur += w[k + 1] - w[k];
			for (int k = i + 1; k < j; k += 2)
				cur += w[k + 1] - w[k];
			for (int k = j + 1; k < n; k += 2)
				cur += w[k + 1] - w[k];
			ans = min(ans, cur);
		}
	}
	cout << ans << "\n";
	return 0;
}