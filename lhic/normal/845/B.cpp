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

string s;

string get(int x) {
	string ans;
	for (int i = 0; i < 6; ++i) {
		ans += (char)('0' + x % 10);
		x /= 10;
	}
	return ans;
}

int diff(string a, string b) {
	int ans = 0;
	for (int i = 0; i < 6; ++i)
		ans += (a[i] != b[i]);
	return ans;
}

int gg(int x) {
	if (x == 0)
		return 0;
	return x % 10 + gg(x / 10);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> s;
	int ans = 6;
	for (int i = 0; i < 1000000; ++i) {
		if (gg(i % 1000) == gg(i / 1000))
			ans = min(ans, diff(s, get(i)));
	}
	cout << ans << "\n";
	return 0;
}