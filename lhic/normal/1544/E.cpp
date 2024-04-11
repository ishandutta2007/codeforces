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

int cc[26];

void solve() {
	string s;
	cin >> s;
	fill(cc, cc + 26, 0);
	for (char c : s) {
		++cc[c - 'a'];
	}
	for (int i = 0; i < 26; ++i) {
		if (cc[i] == 1) {
			string t;
			t += char('a' + i);
			--cc[i];
			for (int j = 0; j < 26; ++j) {
				while (cc[j]) {
					t += char('a' + j);
					--cc[j];
				}
			}
			cout << t << "\n";
			return;
		} else if (cc[i] == s.size()) {
			cout << s << "\n";
			return;
		}
	}

	int n = s.size();

	int a = 0;
	while (cc[a] == 0) {
		++a;
	}

	if (2 + (n - cc[a]) >= cc[a]) {
		string t;
		t += char('a' + a);
		t += char('a' + a);
		cc[a] -= 2;
		int b = a + 1;
		while (cc[a]) {
			while (b < 26 && cc[b] == 0) {
				++b;
			}
			assert(b < 26);
			t += char('a' + b);
			--cc[b];
			t += char('a' + a);
			--cc[a];
		}
		for (int i = 0; i < 26; ++i) {
			while (cc[i]) {
				t += char('a' + i);
				--cc[i];
			}
		}
		cout << t << "\n";
		return;
	}

	int b = a + 1;
	while (b < 26 && cc[b] == 0) {
		++b;
	}
	assert(b < 26);

	string t;

	t += char('a' + a);
	t += char('a' + b);
	if (cc[a] + cc[b] == s.size()) {
		--cc[a];
		--cc[b];
		while (cc[b]) {
			t += char('a' + b);
			--cc[b];
		}
		while (cc[a]) {
			t += char('a' + a);
			--cc[a];
		}
		cout << t << "\n";
		return;
	} else {
		--cc[a];
		--cc[b];
		while (cc[a]) {
			t += char('a' + a);
			--cc[a];
		}
		int c = b + 1;
		while (c < 26 && cc[c] == 0) {
			++c;
		}
		assert(c < 26);
		t += char('a' + c);
		--cc[c];
		for (int i = 0; i < 26; ++i) {
			while (cc[i]) {
				t += char('a' + i);
				--cc[i];
			}
		}
		cout << t << "\n";
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		solve();
	}
	return 0;
}