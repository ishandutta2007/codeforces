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
typedef double ld;

using namespace std;

const int LOG = 20;
const int MAXN = 120000;

int was[MAXN];
int en[MAXN];
int hr[MAXN];
int h[MAXN];
int tin[MAXN];
int tout[MAXN];
int up[LOG][MAXN];
set<pair<int, int> > ss1;
set<tuple<int, int, int> > ss2;
int n, m, q;
int tm;
vector<int> eds[MAXN];
int a[MAXN];

int is_p(int a, int b) {
	return (tin[a] <= tin[b]) && (tout[b] <= tout[a]);
}

int gans(int a, int b) {
	if (a == b)
		return a;
	if (tin[a] < tin[b])
		swap(a, b);
	for (int i = LOG - 1; i >= 0; --i)
		if (!is_p(up[i][a], b))
			a = up[i][a];
	if (up[0][a] == b)
		return a;
	else
		return up[0][a];
}

void del(int x) {
	auto st = ss1.lower_bound(make_pair(tin[x], x));
	while (st != ss1.end() && st->first <= tout[x]) {
		en[st->second] = 0;
		ss1.erase(st++);
	}
	if (st != ss1.end() && st != ss1.begin()) {
		int a = st->second;
		--st;
		int b = st->second;
		ss2.insert(make_tuple(h[gans(a, b)], a, b));
	}
}


void dfs(int v) {
	tin[v] = tm++;
	was[v] = 1;
	for (int i = 0; i < (int)eds[v].size(); ++i) {
		int u = eds[v][i];
		if (!was[u]) {
			up[0][u] = v;
			h[u] = h[v] + 1;
			dfs(u);
		}
	}
	tout[v] = tm++;
}

void build() {
	for (int i = 1; i < LOG; ++i)
		for (int j = 0; j < n; ++j)
			up[i][j] = up[i - 1][up[i - 1][j]];
}

bool cmp(int a, int b) {
	return tin[a] < tin[b];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs(0);
	build();
	scanf("%d", &q);
	for (int i = 0; i < n; ++i)
		hr[i] = q + 1;
	while (q--) {
		int m = 0;
		scanf("%d", &m);
		for (int i = 0; i < m; ++i)
			scanf("%d", &a[i]), --a[i];
		sort(a, a + m, cmp);
		for (int i = 0; i < m; ++i)
			en[a[i]] = 1;
		for (int i = 0; i < m; ++i)
			hr[a[i]] = q;
		ss1.clear();
		ss2.clear();
		for (int i = 0; i < m; ++i)
			ss1.insert(make_pair(tin[a[i]], a[i]));
		for (int i = 0; i < m - 1; ++i)
			ss2.insert(make_tuple(h[gans(a[i], a[i + 1])], a[i], a[i + 1]));
		int ans = 0;
		while (!ss2.empty()) {
			auto xx = *ss2.rbegin();
			ss2.erase(xx);
			int h, a, b;
			tie(h, a, b) = xx;
			int x = gans(a, b);
			if (!en[a] || !en[b])
				continue;
			if (hr[x] == q) {
				ans = -1;
				break;
			}
			++ans;
			del(x);
		}
		printf("%d\n",  ans);
	}
	return 0;
}