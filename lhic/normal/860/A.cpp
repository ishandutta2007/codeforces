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

string get(string s) {
	string ans;
	int fl = 0;
	string cur;
	for (char c: s) {
		if (cur.empty())
			cur += c;
		else if (!fl && cur[0] == c) {
			cur += c;
		}
		else if (cur.size() >= 2) {
			ans += cur;
			ans += " ";
			cur = c;
			fl = 0;
		}
		else {
			fl = 1;
			cur += c;
		}
	}
	if (cur.size())
		ans += cur;
	return ans;
}

int check(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return 0;
	return 1;
}

string s;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> s;
	string ans;
	string cur;
	for (char c: s) {
		if (check(c)) {
			cur += c;
		}
		else {
			if (cur.size())
				ans += get(cur);
			ans += c;
			cur = "";
		}
	}
	if (cur.size())
		ans += get(cur);
	cout << ans << "\n";
	return 0;
}