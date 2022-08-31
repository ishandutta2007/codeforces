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
const int MAXN = 310000;

struct st {
	ll lb, rb;
	int fl;
	int l1, r1;
	int l2, r2;
	int ans;
};

st merge(st l, st r) {
	st ans;
	if (l.rb == r.lb) {
		ans.lb = l.lb;
		ans.rb = r.rb;
		ans.fl = 0;
		ans.l1 = l.l1;
		ans.r1 = l.r1;
		ans.l2 = r.l2;
		ans.r2 = r.r2;
		ans.ans = max(l.ans, r.ans);
		return ans;
	}
	int fl = 0;
	if (l.rb > r.lb) {
		fl = 1;
		swap(l, r);
		swap(l.l1, l.r2);
		swap(l.l2, l.r1);
		swap(l.lb, l.rb);
		swap(r.l1, r.r2);
		swap(r.l2, r.r1);
		swap(r.lb, r.rb);
	}
	ans.lb = l.lb;
	ans.rb = r.rb;
	ans.ans = max(l.ans, r.ans);
	ans.fl = 0;
	if (!l.fl && !r.fl) {
		ans.l1 = l.l1;
		ans.r1 = l.r1;
		ans.l2 = r.l2;
		ans.r2 = r.r2;
		ans.fl = 0;
		if (l.r2 == 0)
			ans.ans = max(ans.ans, r.r1 + r.l1 + 1 + l.l2 + 1);
		else
			ans.ans = max(ans.ans, r.r1 + r.l1 + 1 + 1);
	}
	else if (!l.fl && r.fl) {
		ans.fl = 0;
		ans.l1 = l.l1;
		ans.r1 = l.r1;
		ans.l2 = r.l2 + 1;
		ans.r2 = r.r2;
		if (l.r2 == 0)
			ans.l2 += l.l2;
		ans.ans = max(ans.ans, ans.r2 + ans.l2 + 1);
	}
	else if (l.fl && !r.fl) {
		ans.l1 = l.l1;
		ans.r1 = l.r1;
		ans.l2 = r.l2;
		ans.r2 = r.r2;
		ans.fl = 0;
		if (l.r2 == 0) {
			ans.ans = max(ans.ans, r.r1 + r.l1 + 1 + l.l2 + 1);
			ans.r1 = r.r1;
			ans.l1 = l.l1 + 1 + r.l1;
		}
		else {
			ans.ans = max(ans.ans, r.r1 + r.l1 + 1 + 1);
		}
	}
	else {
		if (l.r2 == 0) {
			ans.fl = 1;
			ans.l1 = ans.l2 = l.l1 + 1 + r.l1;
			ans.r1 = ans.r2 = r.r2;
			ans.ans = max(ans.ans, ans.l1 + ans.r1 + 1);
		}
		else {
			ans.fl = 0;
			ans.l1 = l.l1;
			ans.r1 = l.r1;
			ans.r2 = r.r2;
			ans.l2 = r.l2 + 1;
			ans.ans = max(ans.ans, r.r2 + r.l2 + 1 + 1);
		}
	}
	if (fl) {
		swap(ans.l1, ans.r2);
		swap(ans.l2, ans.r1);
		swap(ans.lb, ans.rb);
	}
	return ans;
}

st rmq[MAXN * 4];
ll dd[MAXN * 4];
int a[MAXN];

void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		rmq[v].fl = 1;
		rmq[v].l1 = rmq[v].r1 = rmq[v].l2 = rmq[v].r2 = 0;
		rmq[v].lb = rmq[v].rb = a[tl];
		rmq[v].ans = 1;
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	rmq[v] = merge(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

void add(int v, int tl, int tr, int l, int r, ll d) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		rmq[v].lb += d;
		rmq[v].rb += d;
		dd[v] += d;
		return;
	}
	int m = (tl + tr) >> 1;
	add(v * 2 + 1, tl, m, l, r, d);
	add(v * 2 + 2, m, tr, l, r, d);
	rmq[v] = merge(rmq[v * 2 + 1], rmq[v * 2 + 2]);
	rmq[v].lb += dd[v];
	rmq[v].rb += dd[v];
}

int n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	build(0, 0, n);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int l, r, d;
		scanf("%d%d%d", &l, &r, &d);
		--l;
		add(0, 0, n, l, r, d);
		printf("%d\n", rmq[0].ans);
	}
	return 0;
}