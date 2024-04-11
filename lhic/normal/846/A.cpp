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


int a[120];
int main() {
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i <= n; ++i) {
		int now = 0;
		for (int j = 0; j < i; ++j)
			if (!a[j])
				++now;
		for (int j = i; j < n; ++j)
			if (a[j])
				++now;
		ans = max(ans, now);
	}
	cout << ans << "\n";
	return 0;
}