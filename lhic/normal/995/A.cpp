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

vector<tuple<int, int, int>> ans;

void add(int a, int b, int c) {
	ans.emplace_back(a, b, c);
}

int n, k;

int a[4][120];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> k;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j], --a[i][j];
	for (int i = 0; i < n; ++i) {
		if (a[0][i] == a[1][i]) {
			int x = a[0][i];
			if (x != -1) {
				add(x, 0, i);
				a[0][i] = a[1][i] = -1;
				--k;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (a[2][i] == a[3][i]) {
			int x = a[2][i];
			if (x != -1) {
				add(x, 3, i);
				a[2][i] = a[3][i] = -1;
				--k;
			}
		}
	}
	int fll = 0;
	for (int i = 0; i < n; ++i) {
		if (a[1][i] == -1 || a[2][i] == -1) {
			fll = 1;
			break;
		}
	}
	if (fll == 0) {
		cout << -1 << "\n";
		return 0;
	}
	vector<pair<int, int> > vv;
	for (int i = 0; i < n; ++i)
		vv.emplace_back(1, i);
	for (int i = n - 1; i >= 0; --i)
		vv.emplace_back(2, i);
	vv.push_back(vv[0]);
	while (k) {
		for (int i = 1; i < vv.size(); ++i) {
			int x = vv[i].first;
			int y = vv[i].second;
			if (a[x][y] == -1)
				continue;
			if (a[x][y] == a[x ^ 1][y]) {
				--k;
				add(a[x][y], x ^ 1, y);
				a[x][y] = a[x ^ 1][y] = -1;
			}
			else {
				int x1 = vv[i - 1].first;
				int y1 = vv[i - 1].second;
				if (a[x1][y1] == -1) {
					add(a[x][y], x1, y1);
					a[x1][y1] = a[x][y];
					a[x][y] = -1;
				}
			}
		}
	}
	cout << ans.size() << "\n";
	for (auto x: ans) {
		int a, b, c;
		tie(a, b, c) = x;
		cout << a + 1 << " " << b + 1 << " " << c + 1 << "\n";
	}
	return 0;
}