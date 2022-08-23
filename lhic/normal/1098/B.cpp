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

const int MAXN = 310000;

int n, m;
string s[MAXN];

vector<char> ch = {'A', 'G', 'C', 'T'};


string ans[MAXN];
string curs[MAXN];

int cans = MAXN;


int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	for (int i = 0; i < n; ++i)
		ans[i] = s[i], curs[i] = s[i];
	for (int it = 0; it < (1 << 4); ++it) {
		vector<char> v[2];
		for (int j = 0; j < 4; ++j)
			if ((it >> j) & 1)
				v[0].push_back(ch[j]);
			else
				v[1].push_back(ch[j]);
		if (v[0].size() != 2)
			continue;
		int now = 0;
		for (int i = 0; i < n; ++i) {
			int c[2] = {0, 0};
			for (int j = 0; j < m; ++j) {
				for (int k = 0; k < 2; ++k)
					if (s[i][j] != v[i % 2][(k + j) % 2])
						++c[k];
			}
			if (c[0] < c[1]) {
				for (int j = 0; j < m; ++j)
					curs[i][j] = v[i % 2][j % 2];
				now += c[0];
			}
			else {
				for (int j = 0; j < m; ++j)
					curs[i][j] = v[i % 2][(j % 2) ^ 1];
				now += c[1];
			}
		}
		if (now < cans) {
			cans = now;
			for (int i = 0; i < n; ++i)
				ans[i] = curs[i];
		}
		now = 0;
		for (int i = 0; i < m; ++i) {
			int c[2] = {0, 0};
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < 2; ++k)
					if (s[j][i] != v[i % 2][(k + j) % 2])
						++c[k];
			}
			if (c[0] < c[1]) {
				for (int j = 0; j < n; ++j)
					curs[j][i] = v[i % 2][j % 2];
				now += c[0];
			}
			else {
				for (int j = 0; j < n; ++j)
					curs[j][i] = v[i % 2][(j % 2) ^ 1];
				now += c[1];
			}
		}
		if (now < cans) {
			cans = now;
			for (int i = 0; i < n; ++i)
				ans[i] = curs[i];
		}
	}
	cerr << cans << "\n";
	for (int i = 0; i < n; ++i)
		cout << ans[i] << "\n";
	return 0;
}