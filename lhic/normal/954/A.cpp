#ifndef BZ
#ifndef __clang__
#pragma GCC optimize "-O3"
#endif
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

int n;
string s;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	cin >> s;
	vector<char> vv;
	for (char c: s) {
		if (vv.empty())
			vv.push_back(c);
		else if (vv.back() != 'D' && vv.back() != c)
			vv.pop_back(), vv.push_back('D');
		else
			vv.push_back(c);
	}
	cout << vv.size() << "\n";
	return 0;
}