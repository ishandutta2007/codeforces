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

string a, b;
string s[3100], t[3100];

string gl, gr;

void no() {
	cout << "NO\n";
	exit(0);
}

int n;
int st[3100];
string tmp;
int z[6100];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	for (int i = 0; i < n; ++i)
		cin >> t[i];
	for (int i = 0; i < n; ++i) {
		if (s[i] == t[i]) {
			st[i] = s[i].size();
			continue;
		}
		int l = s[i].size(), r = -1;
		for (int j = 0; j < s[i].size(); ++j)
			if (s[i][j] != t[i][j])
				l = min(l, j), r = max(r, j);
		st[i] = l;
		if (a.empty()) {
			a = s[i].substr(l, r - l + 1);
			b = t[i].substr(l, r - l + 1);
			string tmp = s[i].substr(0, l);
			reverse(ALL(tmp));
			gl = tmp;
			tmp = s[i].substr(r + 1);
			gr = tmp;
		}
		else {
			if (a != s[i].substr(l, r - l + 1))
				no();
			if (b != t[i].substr(l, r - l + 1))
				no();
			string tmp = s[i].substr(0, l);
			reverse(ALL(tmp));
			int now = 0;
			while (now < tmp.size() && now < gl.size() && tmp[now] == gl[now])
				++now;
			gl.resize(now);
			tmp = s[i].substr(r + 1);
			now = 0;
			while (now < tmp.size() && now < gr.size() && tmp[now] == gr[now])
				++now;
			gr.resize(now);
		}
	}
	int sh = gl.size();
	reverse(ALL(gl));
	a = gl + a + gr;
	b = gl + b + gr;
	for (int i = 0; i < n; ++i) {
		tmp = a + "#" + s[i];
		z[0] = 0;
		int l = 0, r = 0;
		for (int j = 1; j < tmp.size(); ++j) {
			if (r > j)
				z[j] = min(r - j, z[j - l]);
			else
				z[j] = 0;
			while (j + z[j] < tmp.size() && tmp[z[j]] == tmp[j + z[j]])
				++z[j];
			if (j + z[j] > r)
				r = j + z[j], l = j;
		}
		for (int j = 0; j < st[i] - sh; ++j)
			if (z[a.size() + 1 + j] >= a.size())
				no();
	}
	cout << "YES\n";
	cout << a << "\n" << b << "\n";
	return 0;
}