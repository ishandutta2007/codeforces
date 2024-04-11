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

char ret(char d) {
	if (d == 'u')
		return 'd';
	if (d == 'd')
		return 'u';
	if (d == 'r')
		return 'l';
	return 'r';
}

string mv(char d) {
	string ans;
	ans += d;
	ans += "10";
	ans += ret(d);
	ans += 't';
	ans += ret(d);
	ans += 'e';
	ans += d;
	return ans;
}

const int C60 = 40;
const int C40 = 32;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	string ans;
	ans += 'd';
	for (int i = 0; i < C60; ++i)
		ans += "0l";
	for (int i = 0; i < C60; ++i)
		ans += 'r';
	ans += 'd';
	for (int i = 0; i < C60; ++i)
		ans += "1l";
	for (int i = 0; i < C60; ++i)
		ans += 'r';
	ans += "uu";
	for (int i = 0; i < C40; ++i) {
		ans += 'd';
		ans += "su";
		ans += "t";
		ans += "0dlt";
		ans += "u";
		ans += "l";
	}
	for (int i = 0; i < C40; ++i)
		ans += "r";
	ans += "u";
	ans += 'u';
	for (int i = 0; i < C60; ++i)
		ans += "0l";
	for (int i = 0; i < C60; ++i)
		ans += 'r';
	ans += 'u';
	for (int i = 0; i < C60; ++i)
		ans += "1l";
	for (int i = 0; i < C60; ++i)
		ans += 'r';
	ans += "dd";
	for (int i = 0; i < C40; ++i) {
		ans += 'u';
		ans += "sd";
		ans += "t";
		ans += "0ult";
		ans += "d";
		ans += "l";
	}
	for (int i = 0; i < C40; ++i)
		ans += "r";
	for (int i = 0; i < C40; ++i) {
		ans += mv('u');
		ans += 'd';
		ans += 'l';
	}
	for (int i = 0; i < C40; ++i)
		ans += 'r';
	ans += "r0l";
	for (int i = 0; i < C40; ++i) {
		ans += "1100utrtdt";
		ans += mv('l');
		ans += 'r';
		ans += "01010utrtdt";
		ans += mv('r');
		ans += "ll";
		ans += mv('r');
		ans += "l";
	}
	ans += "rr";
	for (int i = 0; i < 50; ++i)
		ans += "rlt";
	cout << ans << "\n";
	cerr << ans.size() << "\n";
	return 0;
}