#include <bits/stdc++.h>

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

bool was[1234];
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (char c : s) was[c] = true;
	int m;
	cin >> m;
	int mask = 0;
	for (int i = 0; i < 26; i++) if (!was['a' + i]) mask |= (1 << i);
	for (int i = 0; i < m; i++) {
		string t;
		cin >> t;
		bool ok = true;
		for (int j = 0; j < n; j++) {
			if (s[j] == '*' && was[t[j]]) ok = false;
		}
		for (int j = 0; j < n; j++) {
			if (s[j] != '*' && t[j] != s[j]) ok = false;
		}
		if (!ok) continue;
		int cmask = 0;
		for (int j = 0; j < n; j++) {
			if (s[j] == '*') {
				cmask |= (1 << (t[j] - 'a'));
			}
		}
		mask &= cmask;
	}
	int res = 0;
	while (mask) {
		res += mask % 2;
		mask /= 2;
	}
	cout << res << endl;

	return 0;
}