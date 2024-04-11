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


const int N = 1e6 + 100;
int n;
string s;
string t;
int go[N * 2];

void solve() {
	cin >> s;
	n = s.size();
	int br = 0;
	while (br <= (n - 1 - br) && s[br] == s[n - 1 - br]) {
		++br;
	}
	if (br >= (n - 1 - br)) {
		cout << s << "\n";
		return;
	}

	t = "#";
	for (int i = 0; i < s.size(); ++i) {
		t += s[i];
			t += "#";
	}

	int al = br;
	int ar = br;

	int sm = 0, r = 0;
	for (int i = 0; i < t.size(); ++i) {
		go[i] = 0;
		if (i < r) {
			go[i] = min(r - i,  go[sm - i]);
		}
		while (i + go[i] < t.size() && i - go[i] >= 0 && t[i + go[i]] == t[i - go[i]]) {
			++go[i];
		}

		if (i + go[i] > r) {
			r = i + go[i];
			sm = i * 2;
		}

		int cl = i - go[i] + 2;
		int cr = i + go[i] - 2;
		if (cl <= cr) {
			cl = (cl - 1) / 2;
			cr = (cr - 1) / 2;
			if (cl <= n - 1 - cr) {
				if (br >= cl) {
					int l = cr + 1;
					int r = cl;
					if (l + r > al + ar) {
						al = l, ar = r;
					}
				}
			} else {
				if (br >= n - 1 - cr) {
					int r = n - cl;
					int l = n - 1 - cr;
					if (l + r > al + ar) {
						al = l, ar = r;
					}
				}
			}
		}
	}
	cout << s.substr(0, al) + s.substr(n - ar, ar) << "\n";
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