#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

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
int a[120];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; ++i)
		cin >> a[i], sum += a[i];
	vector<int> ans = {0};
	int cur = a[0];
	for (int i = 1; i < n; ++i)
		if (a[i] * 2 <= a[0])
			ans.push_back(i), cur += a[i];
	if (cur * 2 > sum) {
		cout << ans.size() << "\n";
		for (int i: ans)
			cout << i + 1 << " ";
		cout << "\n";
	}
	else {
		cout << 0 << "\n";
	}
	return 0;
}