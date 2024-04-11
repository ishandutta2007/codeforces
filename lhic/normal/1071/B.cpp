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

string s[2100];
int go[2100][2100];
int n, k;
vector<pair<pair<char, int>, int> > vv;
int cl[2100][2100];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			go[i][j] = -1;
	go[0][0] = k;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (s[i][j] == 'a') {
				go[i + 1][j] = max(go[i + 1][j], go[i][j]);
				go[i][j + 1] = max(go[i][j + 1], go[i][j]);
			}
			else {
				go[i + 1][j] = max(go[i + 1][j], go[i][j] - 1);
				go[i][j + 1] = max(go[i][j + 1], go[i][j] - 1);
			}
		}
	int bst = -1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (go[i][j] >= 0)
				bst = max(bst, i + j);
	cl[n - 1][n - 1] = 0;
	for (int sum = 2 * n - 3; sum >= 0; --sum) {
		vv.clear();
		for (int i = 0; i < n; ++i) {
			int j = sum - i;
			if (j >= 0 && j < n) {
				int bst = n;
				if (i + 1 < n)
					bst = min(bst, cl[i + 1][j]);
				if (j + 1 < n)
					bst = min(bst, cl[i][j + 1]);
				vv.emplace_back(make_pair(s[i][j], bst), i);
			}
		}
		sort(ALL(vv));
		int now = 0;
		for (int i = 0; i < vv.size(); ++i) {
			int x = vv[i].second;
			int y = sum - x;
			cl[x][y] = now;
			if (i + 1 < vv.size() && vv[i + 1].first != vv[i].first)
				++now;
		}
	}
	string ans;
	for (int i = 0; i < bst; ++i)
		ans += 'a';
	int x = -1, y = -1;
	for (int i = 0; i < n; ++i) {
		int j = bst - i;
		if (j >= n || j < 0)
			continue;
		if (go[i][j] < 0)
			continue;
		if (x == -1 || cl[i][j] < cl[x][y])
			x = i, y = j;
	}
	while (x + y != 2 * (n - 1)) {
		ans += s[x][y];
		if (x + 1 == n)
			++y;
		else if (y + 1 == n)
			++x;
		else {
			if (cl[x + 1][y] < cl[x][y + 1])
				++x;
			else
				++y;
		}
	}
	if (go[x][y] > 0)
		ans += 'a';
	else
		ans += s[x][y];
	cout << ans << "\n";
	return 0;
}