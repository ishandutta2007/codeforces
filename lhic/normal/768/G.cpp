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
const int MAXN = 120000;
vector<int> vv;

int sz[MAXN];
int tin[MAXN];
int tout[MAXN];
int pl[MAXN];
vector<int> eds[MAXN];
int n;
vector<int> rmq[MAXN * 4];
int ans[MAXN];

void build(int v, int tl, int tr) {
	rmq[v].clear();
	if (tl + 1 == tr) {
		rmq[v].push_back(sz[vv[tl]]);
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	merge(rmq[v * 2 + 1].begin(), rmq[v * 2 + 1].end(), rmq[v * 2 + 2].begin(), rmq[v * 2 + 2].end(), back_inserter(rmq[v]));
}

pair<int, int> get(int v, int tl, int tr, int l, int r, int k) {
	if (tr <= l || r <= tl)
		return make_pair(0, n);
	if (l <= tl && tr <= r) {
		int x = lower_bound(rmq[v].begin(), rmq[v].end(), k) - rmq[v].begin();
		pair<int, int> ans;
		if (x == rmq[v].size())
			ans.second = n;
		else
			ans.second = rmq[v][x];
		if (x == 0)
			ans.first = 0;
		else
			ans.first = rmq[v][x - 1];
		return ans;
	}
	int m = (tl + tr) >> 1;
	pair<int, int> a = get(v * 2 + 1, tl, m, l, r, k);
	pair<int, int> b = get(v * 2 + 2, m, tr, l, r, k);
	return make_pair(max(a.first, b.first), min(a.second, b.second));
}



void dfs1(int v) {
	sz[v] = 1;
	vv.push_back(v);
	pl[v] = vv.size() - 1;
	for (int u: eds[v]) {
		dfs1(u);
		sz[v] += sz[u];
	}
	tout[v] = vv.size();
}

set<int> ss;

void dfs2(int v) {
	vector<pair<int, int> > vv;
	int k = n - sz[v];
	ss.insert(sz[v]);
	for (int u: eds[v]) {
		dfs2(u);
		vv.push_back(make_pair(sz[u], u));
	}
	if (vv.empty())
		return;
	sort(vv.begin(), vv.end());
	if (k >= vv.back().first) {
		int b = k - vv.front().first;
		b /= 2;
		pair<int, int> xx = get(0, 0, n, tout[v], n, b);
		ans[v] = min(ans[v], max(vv.front().first + xx.first, k - xx.first));
		ans[v] = min(ans[v], max(vv.front().first + xx.second, k - xx.second));
		b += sz[v];
		auto it = ss.lower_bound(b);
		if (it != ss.end())
			ans[v] = min(ans[v], max(vv.front().first + *it - sz[v], k - *it + sz[v]));
		if (it != ss.begin()) {
			--it;
			ans[v] = min(ans[v], max(vv.front().first + *it - sz[v], k - *it + sz[v]));
		}
		ans[v] = max(ans[v], vv.back().first);
	}
	else {
		int mn = min(vv.front().first, k);
		if (k == 0)
			mn = vv.front().first;
		int b = vv.back().first - mn;
		b /= 2;
		pair<int, int> xx = get(0, 0, n, pl[vv.back().second], tout[vv.back().second], b);
		ans[v] = min(ans[v], max(mn + xx.first, vv.back().first - xx.first));
		ans[v] = min(ans[v], max(mn + xx.second, vv.back().first - xx.second));
		if (vv.size() >= 2)
			ans[v] = max(ans[v], vv[vv.size() - 2].first);
		if (mn != k)
			ans[v] = max(ans[v], k);
	}
	ss.erase(sz[v]);
}

void dfs3(int v) {
	tin[v] = vv.size();
	for (int u: eds[v])
		dfs3(u);
	vv.push_back(v);
}

void dfs4(int v) {
	vector<pair<int, int> > vv;
	int k = n - sz[v];
	for (int u: eds[v]) {
		dfs4(u);
		vv.push_back(make_pair(sz[u], u));
	}
	if (vv.empty())
		return;
	sort(vv.begin(), vv.end());
	if (k >= vv.back().first) {
		int b = k - vv.front().first;
		b /= 2;
		pair<int, int> xx = get(0, 0, n, 0, tin[v], b);
		ans[v] = min(ans[v], max(vv.front().first + xx.first, k - xx.first));
		ans[v] = min(ans[v], max(vv.front().first + xx.second, k - xx.second));
		ans[v] = max(ans[v], vv.back().first);
	}
}

int main() {
	int st = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		if (a == -1) {
			st = b;
		}
		else {
			eds[a].push_back(b);
		}
	}
	for (int i = 0; i < n; ++i)
		ans[i] = n - 1;
	dfs1(st);
	build(0, 0, n);
	dfs2(st);
	vv.clear();
	dfs3(st);
	build(0, 0, n);
	dfs4(st);
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}