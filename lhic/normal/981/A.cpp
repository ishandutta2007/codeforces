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

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int ans = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = i + 1; j <= s.size(); ++j) {
			string t = s.substr(i, j - i);
			string t2 = t;
			reverse(t2.begin(), t2.end());
			if (t != t2)
				ans = max(ans, (int)t.size());
		}
	}
	cout << ans << "\n";
	return 0;
}