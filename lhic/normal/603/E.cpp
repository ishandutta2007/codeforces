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

const int MAXN = 400000;

int sz[MAXN];
int p[MAXN];
int ans[MAXN];
int co;
vector<pair<int, int> > st;

int get(int v) {
	while (p[v] != v)
		v = p[v];
	return v;
}

void unite(int a, int b) {
	a = get(a);
	b = get(b);
	if (a == b)
		return;
	if ((sz[a] & 1) == 1 && (sz[b] & 1) == 1)
		co -= 2;
	if (sz[a] >= sz[b]) {
		sz[a] += sz[b];
		p[b] = a;
		st.push_back(make_pair(a, b));
	}
	else {
		sz[b] += sz[a];
		p[a] = b;
		st.push_back(make_pair(b, a));
	}
}

void undo() {
	int a, b;
	tie(a, b) = st.back();
	st.pop_back();
	sz[a] -= sz[b];
	p[b] = b;
	if ((sz[a] & 1) == 1 && (sz[b] & 1) == 1)
		co += 2;
}

void run(int l, int r, int al, int ar, const vector<tuple<int, int, int, int> > &vv) {
	if (r <= l)
		return;
	if (al >= ar) {
		for (int i = l; i < r; ++i)
			ans[i] = ar;
		return;
	}

	int m = (l + r) >> 1;
	int uop = 0;

	int lst = al;
	for (int i = 0; i < (int)vv.size(); ++i) {
		int x, l2, a, b;
		tie(l2, x, a, b) = vv[i];
		if (x > m)
			continue;
		if (co == 0)
			break;
		a = get(a);
		b = get(b);
		lst = max(l2, lst);
		if (a != b)
			++uop, unite(a, b);
	}
	if (co != 0)
		lst = ar;
	while (uop)
		--uop, undo();
	ans[m] = lst;
	vector<tuple<int, int, int, int> > vv2;
	for (int i = 0; i < (int)vv.size(); ++i) {
		int x, l2, a, b;
		tie(l2, x, a, b) = vv[i];
		if (x < l && l2 <= lst) {
			a = get(a);
			b = get(b);
			if (a != b)
				++uop, unite(a, b);
		}
		else if (x < m)
			vv2.push_back(vv[i]);
	}
	run(l, m, lst, ar, vv2);
	vv2.clear();
	while (uop)
		--uop, undo();

	for (int i = 0; i < (int)vv.size(); ++i) {
		int x, l2, a, b;
		tie(l2, x, a, b) = vv[i];
		if (x <= m && l2 <= al) {
			a = get(a);
			b = get(b);
			if (a != b)
				++uop, unite(a, b);
		}
		else if (l2 <= lst)
			vv2.push_back(vv[i]);
	}
	run(m + 1, r, al, lst + 1, vv2);
	while (uop)
		--uop, undo();
}


int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	if (n % 2 != 0) {
		for (int i = 0; i < m; ++i)
			printf("-1\n");
		return 0;
	}
	vector<tuple<int, int, int, int> > vv;
	for (int i = 0; i < m; ++i) {
		int a, b, l;
		scanf("%d%d%d", &a, &b, &l);
		--a;
		--b;
		vv.push_back(make_tuple(l, i, a, b));
	}
	sort(vv.begin(), vv.end());

	for (int i = 0; i < n; ++i)
		sz[i] = 1, p[i] = i;
	co = n;
	run(0, m, 1, 1e9 + 10, vv);
	for (int i = 0; i < m; ++i)
		if (ans[i] <= 1000000000)
			printf("%d\n", ans[i]);
		else
			printf("-1\n");
	return 0;
}