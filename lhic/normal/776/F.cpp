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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 320000;

vector<int> eds[MAXN];
vector<int> us[MAXN];
vector<int> gg[MAXN];
int n, m;
int cc;
pair<int, int> id[MAXN];
vector<pair<int, int> > vv;
map<pair<int, int>, vector<int> > mm;
vector<int> ls;
int sz[MAXN];
int was[MAXN];
int tm;
int cl[MAXN];

void dfs1(int v, int k) {
	if (us[v][k])
		return;
	us[v][k] = 1;
	gg[cc].push_back(v);
	int u = eds[v][k];
	int x = lower_bound(eds[u].begin(), eds[u].end(), v) - eds[u].begin();
	++x;
	if (x == eds[u].size())
		x = 0;
	dfs1(u, x);
}


void dfs2(int v) {
	ls.push_back(v);
	sz[v] = 1;
	was[v] = tm;
	for (int u: eds[v]) {
		if (was[u] < tm) {
			dfs2(u);
			sz[v] += sz[u];
		}
	}
}

void solve(int v, int k) {
	++tm;
	ls.clear();
	dfs2(v);
	int bst = -1;
	for (int i: ls) {
		if (sz[i] * 2 >= sz[v] && (bst == -1 || sz[i] < sz[bst]))
			bst = i;
	}
	v = bst;
	was[v] = MAXN;
	int x = lower_bound(vv.begin(), vv.end(), id[v]) - vv.begin();
	cl[x] = k;
	for (int u: eds[v]) {
		if (was[u] < MAXN)
			solve(u, k + 1);
	}
}


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int x = (i + 1) % n;
		eds[i].push_back(x);
		eds[x].push_back(i);
	}
	for (int i = 0; i < m; ++i) { 
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
		sort(eds[i].begin(), eds[i].end()), us[i].resize(eds[i].size());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < eds[i].size(); ++j)
			if (!us[i][j]) {
				dfs1(i, j);
				++cc;
			}
	}
	for (int i = 1; i < cc; ++i) {
		int mx1 = 0, mx2 = 0;
		gg[i].push_back(gg[i][0]);
		for (int j = 0; j < gg[i].size() - 1; ++j) {
			int a = gg[i][j];
			int b = gg[i][j + 1];
			if (mx2 < a)
				mx2 = a;
			if (mx2 > mx1)
				swap(mx2, mx1);
			if (a > b)
				swap(a, b);
			mm[make_pair(a, b)].push_back(i);
		}
		id[i] = make_pair(mx1, mx2);
		vv.push_back(make_pair(mx1, mx2));
	}
	sort(vv.begin(), vv.end());
	for (int i = 0; i < n; ++i)
		eds[i].clear();
	for (auto i: mm) {
		if (i.second.size() != 2)
			continue;
		eds[i.second[0]].push_back(i.second[1]);
		eds[i.second[1]].push_back(i.second[0]);
	}
	solve(1, 1);
	for (int i = 0; i < vv.size(); ++i)
		printf("%d ", cl[i]);
	printf("\n");
	return 0;
}