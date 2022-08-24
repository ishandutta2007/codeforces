#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
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

int n, m;
string s[200];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (s[i][j] == 'B')
				++cnt;
	int k = 0;
	while (k * k < cnt)
		++k;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'B') {
				cout << i + 1 + (k - 1) / 2 << " " << j + 1 + (k - 1) / 2 << "\n";
				return 0;
			}
		}
	assert(false);
	return 0;
}