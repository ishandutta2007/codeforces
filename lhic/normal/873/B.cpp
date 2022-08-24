#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()

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

const int MX = 120000;

int lst[MX * 2];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	for (int i = 0; i < 2 * MX; ++i)
		lst[i] = -1;
	lst[MX] = 0;
	int cur = MX;
	string s;
	int n;
	cin >> n;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '1')
			++cur;
		else
			--cur;
		if (lst[cur] != -1)
			ans = max(ans, i + 1 - lst[cur]);
		else
			lst[cur] = i + 1;
	}
	cout << ans << "\n";
	return 0;
}