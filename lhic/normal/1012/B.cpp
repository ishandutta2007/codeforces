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

const int MAXN = 210000;

int p[MAXN];
int sz[MAXN];

int get(int a) {
	if (a == p[a])
		return a;
	return p[a] = get(p[a]);
}

void un(int a, int b) {
	a = get(a);
	b = get(b);
	if (a == b)
		return;
	if (sz[a] > sz[b])
		swap(a, b);
	p[a] = b;
	sz[b] += sz[a];
}

int n, m, q;

vector<int> go[MAXN];

set<int> gg[MAXN];
vector<pair<int, int> > vv;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m >> q;
	for (int i = 0; i < q; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		go[y].push_back(x);
		vv.emplace_back(x, y);
	}
	for (int i = 0; i < n; ++i) {
		p[i] = i, sz[i] = 1;
	}
	for (int i = 0; i < m; ++i) {
		if (go[i].empty())
			continue;
		for (int j: go[i])
			un(j, go[i][0]);
	}
	for (auto e: vv) {
		gg[get(e.first)].insert(e.second);
	}
	int cntx = 0;
	int cnty = m;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (p[i] != i)
			continue;
		if (gg[i].empty())
			++cntx;
		else {
			++cnt;
			cnty -= gg[i].size();
		}
	}
	int ans = 0;
	if (cnt == 0) {
		ans += cntx + cnty - 1;
	}
	else {
		ans += cnt - 1;
		ans += cntx + cnty;
	}
	cout << ans << "\n";
	return 0;
}