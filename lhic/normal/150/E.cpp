#pragma GCC optimize "-Ofast"
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <ctime>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 110000;
#define tm tm_sakdfj

vector<pair<int, int> > eds[MAXN];
int n;
int l, r;

int was[MAXN];
vector<pair<int, int> > vv;
int sz[MAXN];
int rsz, glk;
pair<int, int> rmq[MAXN * 2];
int tm;
int mxh;
int vl[MAXN];
int vlc;

int sumtl = 0;
int ccc;

void dfs2(int v) {
	vl[vlc++] = v;
	was[v] = tm;
	sz[v] = 1;
	for (int i = 0; i < (int)eds[v].size(); ++i) {
		int u = eds[v][i].first;
		if (was[u] < tm) {
			dfs2(u);
			sz[v] += sz[u];
		}
	}
}

void dfs4(int v, int h, int sm) {
	was[v] = tm;
	if (h >= r)
		return;
	if ((int)vv.size() <= h)
		vv.push_back(make_pair(sm, v));
	else
		vv[h] = max(vv[h], make_pair(sm, v));
	for (pair<int, int> e: eds[v]) {
		int u = e.first;
		if (was[u] < tm)
			dfs4(u, h + 1, sm + (e.second >= glk ? 1 : -1));
	}
}

void upd(int x, int v, int c) {
	x += rsz - 1;
	for (; x >= 0 && rmq[x].first < c; x = (x - 1) >> 1)
		rmq[x] = make_pair(c, v);
}

pair<int, int> get(int l, int r) {
	l += rsz - 1;
	r += rsz - 1;
	pair<int, int> ans = make_pair(-MAXN * 100, -1);
	while (r > l) {
		if (l & 1)
			l = l >> 1;
		else
			ans = max(ans, rmq[l]), l = l >> 1;
		if (r & 1)
			r = r >> 1;
		else
			ans = max(ans, rmq[r - 1]), r = (r - 1) >> 1;
	}
	return ans;
}

void build(int h) {
	++h;
	rsz = h;
	for (int i = 0; i < rsz - 1 + rsz; ++i)
		rmq[i] = make_pair(-MAXN * 100, -1);
}

pair<int, int> dfs1(int v) {
	vlc = 0;
	++tm;
	dfs2(v);
	mxh = 0;
	mxh = sz[v];
	int nd = (sz[v] + 1) / 2;
	for (int i = 0; i < vlc; ++i)
		if (sz[vl[i]] >= nd && sz[vl[i]] < sz[v])
			v = vl[i];
	was[v] = MAXN * 100;
	++tm;
	mxh = min(mxh, r);
	build(mxh);
	upd(0, v, 0);
	for (pair<int, int> e: eds[v]) {
		int u = e.first;
		if (was[u] < tm) {
			vv.clear();
			dfs4(u, 0, (e.second >= glk ? 1 : -1));
			for (int i = 0; i < (int)vv.size(); ++i) {
				int lb = max(0, l - i - 1);
				int rb = min(mxh, r - i - 1);
				if (rb >= lb) {
					pair<int, int> g = get(lb, rb + 1);
					if (g.second != -1 && g.first + vv[i].first >= 0)
						return make_pair(vv[i].second, g.second);
				}
			}
			for (int i = 0; i < (int)vv.size(); ++i)
				upd(i + 1, vv[i].second, vv[i].first);
		}
	}
	++tm;
	for (pair<int, int> e: eds[v]) {
		int u = e.first;
		if (was[u] != MAXN * 100) {
			pair<int, int> ans = dfs1(u);
			if (ans.first != -1)
				return ans;
		}
	}
	return make_pair(-1, -1);
}

pair<int, int> check(int k) {
	memset(was, 0, sizeof(was));
	glk = k;
	tm = 0;
	return dfs1(0);
}

int main() {
	scanf("%d%d%d", &n, &l, &r);
	vector<int> ls;
	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a;
		--b;
		eds[a].push_back(make_pair(b, c));
		eds[b].push_back(make_pair(a, c));
		ls.push_back(c);
	}
	sort(ls.begin(), ls.end());
	ls.resize(unique(ls.begin(), ls.end()) - ls.begin());
	int lb = 0;
	int rb = ls.size();
	while (rb - lb > 1) {
		int mid = (lb + rb) >> 1;
		if (check(ls[mid]).first != -1)
			lb = mid;
		else
			rb = mid;
	}
	cerr << ls[lb] << "\n";
	pair<int, int> ans = check(ls[lb]);
	cout << ans.first + 1 << " " << ans.second + 1 << "\n";
	cerr << (ld)sumtl / CLOCKS_PER_SEC << "\n";
	return 0;
}