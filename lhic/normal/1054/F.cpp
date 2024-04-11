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

const int MAXN = 2200;

int n;
int x[MAXN];
int y[MAXN];

vector<int> vx, vy;

int fnd(const vector<int> &v, int x) {
	return lower_bound(ALL(v), x) - v.begin();
}

vector<int> gx[MAXN];
vector<int> gy[MAXN];
vector<int> eds[MAXN];
int p[MAXN];
int q[MAXN];
int was[MAXN];
int was1[MAXN];

int dfs1(int v) {
	was[v] = 1;
	for (int u: eds[v]) {
		if (q[u] == -1) {
			p[v] = u;
			q[u] = v;
			return 1;
		}
	}
	for (int u: eds[v]) {
		int x = q[u];
		if (!was[x] && dfs1(x)) {
			q[u] = v;
			p[v] = u;
			return 1;
		}
	}
	return 0;
}

void dfs2(int v) {
	was[v] = 1;
	for (int u: eds[v]) {
		if (!was1[u]) {
			was1[u] = 1;
			int x = q[u];
			if (x != -1 && !was[x])
				dfs2(x);
		}
	}
}

vector<pair<int, int>> ax[MAXN], ay[MAXN];


int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		swap(x[i], y[i]);
		vx.push_back(x[i]);
		vy.push_back(y[i]);
	}
	sort(ALL(vx));
	vx.resize(unique(ALL(vx)) - vx.begin());
	sort(ALL(vy));
	vy.resize(unique(ALL(vy)) - vy.begin());
	for (int i = 0; i < n; ++i)
		x[i] = fnd(vx, x[i]);
	for (int i = 0; i < n; ++i)
		y[i] = fnd(vy, y[i]);
	for (int i = 0; i < n; ++i) {
		gx[x[i]].push_back(y[i]);
		gy[y[i]].push_back(x[i]);
	}
	for (int i = 0; i < n; ++i)
		sort(ALL(gx[i])), sort(ALL(gy[i]));
	vector<tuple<int, int, int>> ex, ey;
	for (int i = 0; i < vx.size(); ++i) {
		for (int j = 0; j + 1 < gx[i].size(); ++j) {
			ex.emplace_back(i, gx[i][j], gx[i][j + 1]);
		}
	}
	for (int i = 0; i < vy.size(); ++i) {
		for (int j = 0; j + 1 < gy[i].size(); ++j) {
			ey.emplace_back(i, gy[i][j], gy[i][j + 1]);
		}
	}
	for (int i = 0; i < ex.size(); ++i)
		for (int j = 0; j < ey.size(); ++j) {
			int a1, b1, c1;
			int a2, b2, c2;
			tie(a1, b1, c1) = ex[i];
			tie(a2, b2, c2) = ey[j];
			if (b2 < a1 && a1 < c2 && b1 < a2 && a2 < c1) {
				eds[i].push_back(j);
			}
		}
	memset(p, -1, sizeof(p));
	memset(q, -1, sizeof(q));
	int fl = 1;
	while (fl) {
		fl = 0;
		memset(was, 0, sizeof(was));
		for (int i = 0; i < ex.size(); ++i) {
			if (p[i] == -1 && !was[i] && dfs1(i))
				fl = 1;
		}
	}
	memset(was, 0, sizeof(was));
	memset(was1, 0, sizeof(was1));
	for (int i = 0; i < ex.size(); ++i) {
		if (p[i] == -1) {
			dfs2(i);
		}
	}
	for (int i = 0; i < ex.size(); ++i) {
		if (was[i]) {
			int a, b, c;
			tie(a, b, c) = ex[i];
			ax[a].emplace_back(b, c);
		}
	}
	for (int i = 0; i < ey.size(); ++i) {
		if (!was1[i]) {
			int a, b, c;
			tie(a, b, c) = ey[i];
			ay[a].emplace_back(b, c);
		}
	}
	vector<tuple<int, int, int>> ansx;
	for (int i = 0; i < vx.size(); ++i) {
		for (int j: gx[i])
			ax[i].emplace_back(j, j);
		sort(ALL(ax[i]));
		int l = -1;
		int r = -1;
		for (auto p: ax[i]) {
			if (l == -1)
				l = p.first, r = p.second;
			else if (r >= p.first) {
				r = max(r, p.second);
			}
			else {
				ansx.emplace_back(i, l, r);
				l = p.first, r = p.second;
			}
		}
		if (l != -1)
			ansx.emplace_back(i, l, r);
	}
	vector<tuple<int, int, int>> ansy;
	for (int i = 0; i < vy.size(); ++i) {
		for (int j: gy[i])
			ay[i].emplace_back(j, j);
		sort(ALL(ay[i]));
		int l = -1;
		int r = -1;
		for (auto p: ay[i]) {
			if (l == -1)
				l = p.first, r = p.second;
			else if (r >= p.first) {
				r = max(r, p.second);
			}
			else {
				ansy.emplace_back(i, l, r);
				l = p.first, r = p.second;
			}
		}
		if (l != -1)
			ansy.emplace_back(i, l, r);
	}
	cout << ansx.size() << "\n";
	for (auto t: ansx) {
		int a, b, c;
		tie(a, b, c) = t;
		cout << vy[b] << " " << vx[a] << " " << vy[c] << " " << vx[a] << "\n";
	}
	cout << ansy.size() << "\n";
	for (auto t: ansy) {
		int a, b, c;
		tie(a, b, c) = t;
		cout << vy[a] << " " << vx[b] << " " << vy[a] << " " << vx[c] << "\n";
	}
	return 0;
}