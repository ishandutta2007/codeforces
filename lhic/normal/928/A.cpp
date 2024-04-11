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

string get(string s) {
	for (int i = 0; i < s.size(); ++i) {
		if (isupper(s[i])) {
			s[i] = s[i] - 'A' + 'a';
		}
		if (s[i] == '1' || s[i] == 'l')
			s[i] = 'i';
		if (s[i] == '0')
			s[i] = 'o';
	}
	return s;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	string nw;
	cin >> nw;
	nw = get(nw);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		s = get(s);
		if (s == nw) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}