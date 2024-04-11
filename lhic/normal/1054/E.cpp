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

int n, m;

string s[310][310];
string t[310][310];

int cc1[310][310];
int cc2[310][310];

vector<tuple<int, int, int, int>> ans1, ans2;

void add1(int x1, int y1, int x2, int y2) {
	ans1.emplace_back(x1, y1, x2, y2);
}

void add2(int x1, int y1, int x2, int y2) {
	ans2.emplace_back(x2, y2, x1, y1);
}

void check() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			reverse(ALL(s[i][j]));
	for (auto p: ans1) {
		int x1, y1, x2, y2;
		tie(x1, y1, x2, y2) = p;
		assert(x1 == x2 || y1 == y2);
		assert(x1 != x2 || y1 != y2);
		assert(!s[x1][y1].empty());
		char c = s[x1][y1].back();
		s[x1][y1].pop_back();
		s[x2][y2] = c + s[x2][y2];
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> s[i][j];
			reverse(ALL(s[i][j]));
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> t[i][j];
		}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (char c: s[i][j]) {
				if (c == '0') {
					if (j == 0) {
						if (i == 0)
							++cc1[1][0], add1(i, j, 1, 0);
						else
							++cc1[0][0], add1(i, j, 0, 0);
					}
					else {
						++cc1[i][0], add1(i, j, i, 0);
					}
				}
				else {
					if (j == 1) {
						if (i == 0)
							++cc1[1][1], add1(i, j, 1, 1);
						else
							++cc1[0][1], add1(i, j, 0, 1);
					}
					else {
						++cc1[i][1], add1(i, j, i, 1);
					}
				}
			}
		}
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < cc1[i][j]; ++k)
				add1(i, j, 0, j), ++cc1[0][j];
			cc1[i][j] = 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (char c: t[i][j]) {
				if (c == '0') {
					if (j == 0) {
						if (i == 0)
							++cc2[1][0], add2(i, j, 1, 0);
						else
							++cc2[0][0], add2(i, j, 0, 0);
					}
					else {
						++cc2[i][0], add2(i, j, i, 0);
					}
				}
				else {
					if (j == 1) {
						if (i == 0)
							++cc2[1][1], add2(i, j, 1, 1);
						else
							++cc2[0][1], add2(i, j, 0, 1);
					}
					else {
						++cc2[i][1], add2(i, j, i, 1);
					}
				}
			}
		}
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < cc2[i][j]; ++k)
				add2(i, j, 0, j), ++cc2[0][j];
			cc2[i][j] = 0;
		}
	}
	reverse(ALL(ans2));
	for (auto p: ans2)
		ans1.push_back(p);
	cout << ans1.size() << "\n";
	for (auto p: ans1) {
		int x1, y1, x2, y2;
		tie(x1, y1, x2, y2) = p;
		cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << "\n";
	}
/*#ifdef BZ
	check();
#endif*/
	return 0;
}