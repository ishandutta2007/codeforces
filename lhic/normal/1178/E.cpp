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

string s;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> s;
	int l = 0;
	int r = s.size();
	string al, ar;
	while (r - l >= 4) {
		if (s[l] == s[r - 1] || s[l] == s[r - 2])
			al += s[l], ar += s[l];
		else
			al += s[l + 1], ar += s[l + 1];
		l += 2, r -= 2;
	}
	if (l < r)
		al += s[l];
	reverse(ALL(ar));
	cout << al + ar << "\n";
	return 0;
}