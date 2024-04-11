#ifndef LOCAL
#pragma GCC optimize "-O3"
#endif
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

int a[123000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int mn = *min_element(a, a + n);
	vector<int> vv;
	for (int i = 0; i < n; ++i)
		if (a[i] == mn)
			vv.push_back(i);
	int ans = n;
	for (int i = 0; i < vv.size() - 1; ++i)
		ans = min(ans, vv[i + 1] - vv[i]);
	cout << ans << "\n";
	return 0;
}