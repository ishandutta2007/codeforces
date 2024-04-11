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
	map<int, int> mm;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, x;
		cin >> a >> x;
		mm[a] = max(mm[a], x);
	}
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, x;
		cin >> a >> x;
		mm[a] = max(mm[a], x);
	}
	ll ans = 0;
	for (auto x: mm) {
		ans += x.second;
	}
	cout << ans << "\n";
	return 0;
}