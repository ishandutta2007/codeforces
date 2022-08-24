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

const int MAXN = 12000;

vector<pair<int, int> > gg[MAXN * 4];
int p[MAXN];
int sz[MAXN];
vector<int> st;
int go[MAXN];
int n, m;

pair<int, int> get(int v) {
	if (p[v] == v)
		return make_pair(v, 0);
	pair<int, int> ans = get(p[v]);
	ans.second ^= go[v];
	return ans;
}

int un(int a, int b) {
	auto ga = get(a);
	auto gb = get(b);
	a = ga.first;
	b = gb.first;
	if (a == b) {
		if (ga.second == gb.second)
			return 1;
		st.push_back(-1);
		return 0;
	}
	if (sz[a] < sz[b])
		swap(a, b);
	st.push_back(b);
	p[b] = a;
	go[b] = 1 ^ ga.second ^ gb.second;
	sz[a] += sz[b];
	return 0;
}

void undo() {
	int x = st.back();
	st.pop_back();
	if (x == -1)
		return;
	sz[p[x]] -= sz[x];
	p[x] = x;
	go[x] = 0;
}

vector<int> ans;

void add(int v, int tl, int tr, int l, int r, pair<int, int> x) {
	if (tr <= l || r <= tl)
		return;
	if (l <= tl && tr <= r) {
		gg[v].push_back(x);
		return;
	}
	int m = (tl + tr) >> 1;
	add(v * 2 + 1, tl, m, l, r, x);
	add(v * 2 + 2, m, tr, l, r, x);
}


void run(int v, int tl, int tr) {
	int cnt = 0;
	for (int i = 0; i < (int)gg[v].size(); ++i) {
		if (un(gg[v][i].first, gg[v][i].second)) {
			while (cnt)
				--cnt, undo();
			return;
		}
		++cnt;
	}
	if (tl + 1 == tr) {
		ans.push_back(tl);
	}
	else {
		int m = (tl + tr) >> 1;
		run(v * 2 + 1, tl, m);
		run(v * 2 + 2, m, tr);
	}
	while (cnt)
		--cnt, undo();
}

int main() {
	scanf("%d%d", &n, &m);
	if (m == 0) {
		cout << 0 << "\n";
		return 0;
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		add(0, 0, m, 0, i, make_pair(a, b));
		add(0, 0, m, i + 1, m, make_pair(a, b));
	}
	for (int i = 0; i < n; ++i)
		p[i] = i, go[i] = 0, sz[i] = 1;
	run(0, 0, m);
	printf("%d\n", (int)ans.size());
	for (int i: ans)
		printf("%d ", i + 1);
	printf("\n");
	return 0;
}