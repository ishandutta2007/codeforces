/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;
int _c = 0;
template <class _T> inline void read(_T &_a) {
	_a = 0; bool _f = 0;
	while (_c < '0' || _c > '9') _f |= _c == '-', _c = getchar();
	while (_c >= '0' && _c <= '9') _a = _a * 10 + _c - '0', _c = getchar();
	if (_f) _a = -_a;
}
typedef long long LL;
typedef long double LD;

struct Node {
	int l, r;
	int del, add, top;
} t[262144];

int n, tcnt = 0;

int build(int l, int r) {
	int x = ++tcnt;
	t[x].top = -1;
	if (l != r) {
		int mid = (l + r) >> 1;
		t[x].l = build(l, mid);
		t[x].r = build(mid + 1, r);
	}
	return x;
}
#define lch t[x].l
#define rch t[x].r

int find(int x, int l, int r, int k) {
	if (l == r) return t[x].top;
	else {
		int mid = (l + r) >> 1;
		int delta = t[lch].add - t[rch].del;
		if (delta <= 0) return find(rch, mid + 1, r, k);
		else {
			if (k <= delta) return find(lch, l, mid, k);
			else return find(rch, mid + 1, r, k - delta);
		}
	}
}

void pushup(int x, int l, int r) {
	if (t[rch].del >= t[lch].add) t[x].del = t[lch].del + t[rch].del - t[lch].add, t[x].add = t[rch].add;
	else t[x].del = t[lch].del, t[x].add = t[lch].add - t[rch].del + t[rch].add;
	if (t[rch].add) t[x].top = t[rch].top;
	else if (t[x].add) t[x].top = find(lch, l, (l + r) >> 1, t[x].add);
	else t[x].top = -1;
}

void update(int x, int l, int r, int p, int v) {
	if (l == r) {
		if (v == -1) t[x].del = 1, t[x].add = 0, t[x].top = -1;
		else t[x].del = 0, t[x].add = 1, t[x].top = v;
	}
	else {
		int mid = (l + r) >> 1;
		if (p <= mid) update(t[x].l, l, mid, p, v);
		else update(t[x].r, mid + 1, r, p, v);
		pushup(x, l, r);
	}
}

int main() {
	read(n);
	build(1, n);
	for (int i = 1, p, op, x; i <= n; i++) {
		read(p); read(op);
		if (op) {
			read(x);
			update(1, 1, n, p, x);
		}
		else update(1, 1, n, p, -1);
		printf("%d\n", t[1].top);
	}
	return 0;
}