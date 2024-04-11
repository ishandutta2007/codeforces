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


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 310000;

int n, m;
vector<tuple<int, int, int> > ed;
vector<pair<int, int> > eee[MAXN];
vector<pair<int, int> > eds[MAXN];
int was[MAXN];
int fl[MAXN];
int cl[MAXN];

set<pair<int, int> > ss;
int dp[MAXN];
int hh[MAXN];
int a, b;
int cnt;

void dfs1(int v, int h) {
	hh[v] = h;
	was[v] = 1;
	dp[v] = h;
	for (pair<int, int> u: eee[v]) {
		if (!was[u.first]) {
			dfs1(u.first, h + 1);
			dp[v] = min(dp[v], dp[u.first]);
			if (dp[u.first] > hh[v]) {
				ss.insert(make_pair(u.first, v));
				ss.insert(make_pair(v, u.first));
			}
		}
		else if (hh[u.first] != hh[v] - 1) {
			dp[v] = min(dp[v], hh[u.first]);
		}
	}
}

void dfs2(int v, int c) {
	cl[v] = c;
	was[v] = 1;
	for (pair<int, int> u: eee[v]) {
		if (was[u.first] || ss.count(make_pair(v, u.first)))
			continue;
		dfs2(u.first, c);
	}
}

int dfs3(int v, int st) {
	was[v] = 1;
	st |= fl[v];
	if (v == b)
		return st;
	for (pair<int, int> u: eds[v]) {
		if (was[u.first])
			continue;
		if (dfs3(u.first, st | u.second))
			return 1;
	}
	return 0;
}


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		--x;
		--y;
		eee[x].push_back(make_pair(y, z));
		eee[y].push_back(make_pair(x, z));
		ed.push_back(make_tuple(x, y, z));
	}
	scanf("%d%d", &a, &b);
	--a;
	--b;
	dfs1(0, 0);
	memset(was, 0, sizeof(was));
	for (int i = 0; i < n; ++i) {
		if (!was[i])
			dfs2(i, cnt++);
	}
	for (int i = 0; i < m; ++i) {
		int x, y, z;
		tie(x, y, z) = ed[i];
		if (cl[x] == cl[y])
			fl[cl[x]] |= z;
		else {
			eds[cl[x]].push_back(make_pair(cl[y], z));
			eds[cl[y]].push_back(make_pair(cl[x], z));
		}
	}
	a = cl[a];
	b = cl[b];
	memset(was, 0, sizeof(was));
	if (dfs3(a, 0))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}