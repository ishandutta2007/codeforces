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

string s;
int ans[1200];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> s;
	int cur = 0;
	for (int i = s.size() - 1; i >= 0; --i) {
		if (s[i] == 'a') {
			if (cur)
				continue;
			else
				ans[i] = 1, cur = 1;
		}
		else {
			if (cur) {
				ans[i] = 1;
				cur ^= 1;
			}
			else {
				continue;
			}
		}
	}
	for (int i = 0; i < s.size(); ++i)
		cout << ans[i] << " ";
	return 0;
}