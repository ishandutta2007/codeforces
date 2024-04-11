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
const int MAXN = 53;

int n;
vector<int> eds[MAXN];
int sz[MAXN];

vector<pair<int, int>> ed;
vector<tuple<int, int, int>> ev;

void dfs1(int v, int p) {
	sz[v] = 1;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		dfs1(u, v);
		sz[v] += sz[u];
	}
}

int getsz(int v, int p) {
	if (sz[v] < sz[p])
		return sz[v];
	return n - sz[p];
}

ld d[MAXN][MAXN];
ld d2[MAXN][MAXN];
ld d3[MAXN][MAXN];
ld dp[MAXN * 4][MAXN][MAXN];
int cc;
map<pair<int, int>, int> mm;
ll cnk[52][52];
ld ans[52];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(20);
	for (int i = 0; i < 52; ++i)
		for (int j = 0; j < 52; ++j) {
			if (i == j || j == 0)
				cnk[i][j] = 1;
			else if (j > i)
				cnk[i][j] = 0;
			else
				cnk[i][j] = cnk[i - 1][j] + cnk[i - 1][j - 1];
		}
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		ed.emplace_back(a, b);
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs1(0, -1);
	for (int i = 0; i < n; ++i)
		ev.emplace_back(n, -1, i);
	for (auto e: ed) {
		int a = e.first;
		int b = e.second;
		if (sz[a] < sz[b])
			swap(a, b);
		ev.emplace_back(sz[b], a, b);
		ev.emplace_back(n - sz[b], b, a);
	}
	sort(ALL(ev));
	for (auto tmp: ev) {
		int stmp, p, v;
		tie(stmp, p, v) = tmp;
		mm[make_pair(v, p)] = cc++;
		vector<int> ed;
		for (int u: eds[v]) {
			if (u == p)
				continue;
			ed.push_back(u);
		}
		int cur = 0;
		d[0][0] = 1;
		for (int u: ed) {
			int nw = getsz(u, v);
			int go = mm[make_pair(u, v)];
			for (int t = 0; t <= nw; ++t) {
				for (int cnt = 0; cnt <= t; ++cnt) {
					d2[t][cnt] = 0;
					if (cnt) {
						for (int i = 0; i < t; ++i)
							d2[t][cnt] += (dp[go][i][cnt - 1]) / nw;
					}
					d2[t][cnt] += dp[go][t][cnt] * (nw - t) / nw;
				}
			}
			for (int i = 0; i <= cur + nw; ++i)
				for (int j = 0; j <= i; ++j)
					d3[i][j] = 0;
			for (int t1 = 0; t1 <= cur; ++t1)
				for (int c1 = 0; c1 <= t1; ++c1)
					for (int t2 = 0; t2 <= nw; ++t2)
						for (int c2 = 0; c2 <= t2; ++c2) {
							d3[t1 + t2][c1 + c2] += d[t1][c1] * d2[t2][c2] * ((cnk[t1 + t2][t1] * cnk[nw + cur - t1 - t2][cur - t1]) / (ld)cnk[nw + cur][cur]);
						}
			cur += nw;
			for (int i = 0; i <= cur; ++i)
				for (int j = 0; j <= i; ++j)
					d[i][j] = d3[i][j];
		}
		for (int i = 0; i <= cur; ++i)
			for (int j = 0; j <= i; ++j)
				dp[cc - 1][i][j] = d[i][j];
		if (p == -1) {
			ld mul = 1;
			for (int i = 0; i <= cur; ++i, mul /= 2)
				ans[v] += mul * dp[cc - 1][cur][i];
		}
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i] << "\n";
	cout << "\n";
	return 0;
}