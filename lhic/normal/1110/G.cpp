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

const int MAXN = 510000;

vector<int> eds[MAXN];


int n;
string s;

void draw() {
	cout << "Draw\n";
}

void white() {
	cout << "White\n";
}

pair<int, int> dfs1(int v, int p) {
	pair<int, int> ans = {0, v};
	for (int u: eds[v]) {
		if (u == p)
			continue;
		auto tmp = dfs1(u, v);
		++tmp.first;
		ans = max(ans, tmp);
	}
	return ans;
}

vector<int> vv;

int dfs2(int v, int p, int d) {
	vv.push_back(v);
	if (d == v)
		return 1;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		if (dfs2(u, v, d))
			return 1;
	}
	vv.pop_back();
	return 0;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		eds[i].clear();
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	cin >> s;
	if (n <= 2) {
		draw();
		return;
	}
	if (n == 3) {
		int cc = 0;
		for (int i = 0; i < 3; ++i)
			if (s[i] == 'W')
				++cc;
		if (cc >= 2)
			white();
		else
			draw();
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (eds[i].size() >= 4) {
			white();
			return;
		}
		if (s[i] == 'W' && eds[i].size() >= 2) {
			white();
			return;
		}
	}
	int a = dfs1(0, -1).second;
	int b = dfs1(a, -1).second;
	vv.clear();
	dfs2(a, -1, b);
	for (int i = 2; i + 2 < vv.size(); ++i)
		if (eds[vv[i]].size() > 2) {
			white();
			return;
		}
	int all = vv.size();
	if (eds[vv[1]].size() > 2)
		++all;
	if (eds[vv[vv.size() - 2]].size() > 2 && vv.size() - 2 > 1)
		++all;
	if (all != n) {
		white();
		return;
	}
	if (all == vv.size()) {
		int cc = 0;
		for (int i = 0; i < n; ++i)
			if (s[i] == 'W')
				++cc;
		if (cc == 2 && vv.size() % 2 == 1)
			white();
		else
			draw();
		return;
	}
	else if (all == vv.size() + 1) {
		if (eds[vv[1]].size() == 2)
			reverse(ALL(vv));
		int cc = 0;
		for (int i = 0; i < n; ++i)
			if (s[i] == 'W')
				++cc;
		if (cc >= 2) {
			white();
		}
		else if (cc == 0) {
			draw();
		}
		else {
			if (s[vv.back()] == 'W') {
				if (vv.size() % 2 == 1)
					white();
				else
					draw();
			}
			else {
				white();
			}
		}
	}
	else {
		int cc = 0;
		for (int i = 0; i < n; ++i)
			if (s[i] == 'W')
				++cc;
		if (cc)
			white();
		else if (vv.size() % 2 == 0) {
			draw();
		}
		else {
			white();
		}
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i)
		solve();
	return 0;
}