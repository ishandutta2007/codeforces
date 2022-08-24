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
	int n;
	vector<int> vv;
	cin >> n;
	for (int i = 0; i < 2 * n; ++i) {
		int x;
		cin >> x;
		vv.push_back(x);
	}
	sort(vv.begin(), vv.end());
	if (vv[n] == vv[n - 1]) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}
	return 0;
}