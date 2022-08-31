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

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	string s;
	cin >> s;
	int cur = 0;
	for (int i = 0; i < s.size() && cur < 26; ++i) {
		if (s[i] - 'a' <= cur) {
			s[i] = 'a' + cur;
			++cur;
		}
	}
	if (cur != 26) {
		cout << -1 << "\n";
	}
	else
		cout << s << "\n";
	return 0;
}