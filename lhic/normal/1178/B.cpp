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

const int N = 1e6 + 100;

string s;

ll dl[N];
ll dr[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> s;
	for (int i = 2; i < s.size(); ++i) {
		dl[i] = dl[i - 1];
		if (s[i - 1] == 'v' && s[i - 2] == 'v')
			++dl[i];
	}
	for (int i = (int)s.size() - 3; i >= 0; --i) {
		dr[i] = dr[i + 1];
		if (s[i + 1] == 'v' && s[i + 2] == 'v')
			++dr[i];
	}
	ll ans = 0;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == 'o')
			ans += dl[i] * dr[i];
	cout << ans << "\n";
	return 0;
}