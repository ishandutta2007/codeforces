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

const int T = 10000;

const int N = 120;

int n;
string s;
int a[N];
int b[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i];
	int ans = 0;
	for (int t = 0; t < T; ++t) {
		for (int j = 0; j < n; ++j) {
			if (t >= b[j] && (t - b[j]) % a[j] == 0) {
				if (s[j] == '0')
					s[j] = '1';
				else
					s[j] = '0';
			}
		}
		int cur = 0;
		for (char c: s)
			if (c == '1')
				++cur;
		ans = max(ans, cur);
	}
	cout << ans << "\n";
	return 0;
}