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
const int MAXN = 2100;
int a[MAXN];

vector<int> ans;
string s, t;

vector<int> go[30];
int n;

void shift(int x) {
	if (x == 0)
		return;
	ans.push_back(x);
	rotate(a, a + (n - x), a + n);
	reverse(a, a + x);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	cin >> s >> t;
	for (int i = 0; i < t.size(); ++i) {
		go[t[i] - 'a'].push_back(i);
	}
	for (int i = 0; i < s.size(); ++i) {
		int c = s[i] - 'a';
		if (go[c].empty()) {
			cout << -1 << "\n";
			return 0;
		}
		a[i] = go[c].back();
		go[c].pop_back();
	}
	int l, r;
	l = r = n / 2;
	int len = 1;
	for (int i = 0; i < n; ++i) {
		if (a[i] == l) {
			shift(n - i - 1);
			shift(1);
			break;
		}
	}
	while (len < n) {
		if (a[0] == l) {
			for (int i = len; i < n; ++i) {
				if (a[i] == l - 1) {
					shift(n - i);
					--l;
					++len;
					int st = n - 1 - i;
					shift(n - st - len);
					shift(len);
					break;
				}
			}
		}
		else {
			for (int i = len; i < n; ++i) {
				if (a[i] == r + 1) {
					shift(n - i);
					++r;
					++len;
					int st = n - 1 - i;
					shift(n - st - len);
					shift(len);
					break;
				}
			}
		}
	}
	if (a[0] != 0) {
		shift(n);
	}
	cout << ans.size() << "\n";
	for (int x: ans) {
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}