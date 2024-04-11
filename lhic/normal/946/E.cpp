#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

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

string s;

void solve() {
	cin >> s;
	if (s[0] == '1') {
		int fl = 0;
		for (int j = 1; j < s.size() - 1; ++j)
			if (s[j] != '0')
				fl = 1;
		if (s[s.size() - 1] > '1')
			fl = 1;
		if (!fl) {
			for (int i = 0; i < s.size() - 2; ++i) {
				cout << 9;
			}
			cout << "\n";
			return;
		}
	}
	int cur = 0;
	for (int i = 0; i < s.size(); ++i)
		cur ^= (1 << (s[i] - '0'));
	for (int i = s.size() - 1; i >= 0; --i) {
		cur ^= (1 << (s[i] - '0'));
		int c = s[i] - '0';
		for (int j = c - 1; j >= 0; --j) {
			int now = cur ^ (1 << j);
			int cnt = __builtin_popcount(now);
			if (cnt > s.size() - 1 - i)
				continue;
			string ans = s.substr(0, i);
			ans += char('0' + j);
			int lf = s.size() - 1 - i;
			while (lf > cnt) {
				ans += "99";
				lf -= 2;
			}
			for (int j = 9; j >= 0; --j) {
				if ((now >> j) & 1)
					ans += char('0' + j);
			}
			cout << ans << "\n";
			return;
		}
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i)
		solve();
	return 0;
}