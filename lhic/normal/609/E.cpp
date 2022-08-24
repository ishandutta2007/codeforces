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

const int MAXN = 300000;
const int LOG = 20;

int p[MAXN];
int was[MAXN];
int rnk[MAXN];
int up[LOG][MAXN];
int upm[LOG][MAXN];
vector<pair<int, int> > eds[MAXN];
vector<tuple<int, int, int> > ed;
vector<tuple<int, int, int> > edd;
int n, m;
int tin[MAXN];
int tout[MAXN];
int tm;

int get(int a) {
	if (p[a] == a)
		return a;
	return p[a] = get(p[a]);
}

void un(int a, int b) {
	a = get(a);
	b = get(b);
	assert(a != b);
	if (rnk[a] > rnk[b]) {
		p[b] = a;
	}
	else {
		p[a] = b;
		if (rnk[a] == rnk[b])
			++rnk[b];
	}
}

void dfs(int v) {
	was[v] = 1;
	tin[v] = tm++;
	for (int i = 0; i < (int)eds[v].size(); ++i) {
		int u = eds[v][i].first;
		if (was[u])
			continue;
		up[0][u] = v;
		upm[0][u] = eds[v][i].second;
		dfs(u);
	}
	tout[v] = tm++;
}

int is_p(int a, int b) {
	if (tin[a] <= tin[b] && tout[b] <= tout[a])
		return 1;
	else
		return 0;
}

int lca(int a, int b) {
	if (is_p(a, b))
		return a;
	if (is_p(b, a))
		return b;
	for (int i = LOG - 1; i >= 0; --i) {
		if (!is_p(up[i][a], b))
			a = up[i][a];
	}
	return up[0][a];
}


ll gm(int a, int b) {
	if (is_p(a, b))
		return 0;
	ll mx = 0;
	for (int i = LOG - 1; i >= 0; --i) {
		if (!is_p(up[i][a], b))
			mx = max(mx, (ll)upm[i][a]), a = up[i][a];
	}
	return max(mx, (ll)upm[0][a]);
}



int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a;
		--b;
		ed.push_back(make_tuple(a, b, c));
		edd.push_back(make_tuple(c, a, b));
	}
	sort(edd.begin(), edd.end());
	for (int i = 0; i < n; ++i)
		p[i] = i, rnk[i] = 0;
	ll sum = 0;
	for (int i = 0; i < (int)edd.size(); ++i) {
		int a, b, c;
		tie(c, a, b) = edd[i];
		a = get(a);
		b = get(b);
		if (a != b) {
			eds[a].push_back(make_pair(b, c));
			eds[b].push_back(make_pair(a, c));
			un(a, b);
			sum += c;
		}
	}
	dfs(0);
	for (int i = 1; i < LOG; ++i)
		for (int j = 0; j < n; ++j)
			up[i][j] = up[i - 1][up[i - 1][j]], upm[i][j] = max(upm[i - 1][j], upm[i - 1][up[i - 1][j]]);

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		tie(a, b, c) = ed[i];
		int x = lca(a, b);
		printf("%lld\n", sum + c - max(gm(a, x), gm(b, x)));
	}

	return 0;
}