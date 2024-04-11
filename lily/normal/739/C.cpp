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

#define MAXN 300005


int n, m;
LL a[MAXN], b[MAXN];

struct Node {
	int l, r;
	int st, ed, ans;
} t[1048576];

int tcnt = 0;
#define lch t[x].l
#define rch t[x].r
#define sign(a) (a < 0 ? -1 : 1)
#define ok(x, y) (x && y && sign(x) >= sign(y))
void pushup(int x, int l, int mid, int r) {
	t[x].ans = max(t[lch].ans, t[rch].ans);
	if (ok(a[mid], a[mid + 1])){
		t[x].ans = max(t[x].ans, t[lch].ed + t[rch].st);
		t[x].st = t[lch].st == mid - l + 1 ? t[lch].st + t[rch].st : t[lch].st;
		t[x].ed = t[rch].ed == r - mid ? t[rch].ed + t[lch].ed : t[rch].ed;
	}
	else t[x].st = t[lch].st, t[x].ed = t[rch].ed;
}

int build(int l, int r) {
	int x = ++tcnt;
	if (l < r) {
		int mid = (l + r) >> 1;
		t[x].l = build(l, mid);
		t[x].r = build(mid + 1, r);
		pushup(x, l, mid, r);
	}
	else t[x].st = t[x].ed = t[x].ans = !!(a[l]);
	return x;
}

void update(int x, int l, int r, int p, int v) {
	if (l == r) t[x].st = t[x].ed = t[x].ans = !!(a[l] += v);
	else {
		int mid = (l + r) >> 1;
		if (p <= mid) update(t[x].l, l, mid, p, v);
		else update(t[x].r, mid + 1, r, p, v);
		pushup(x, l, mid, r);
	}
}

int main() {
	read(n); 
	for (int i = 1; i <= n; i++) read(b[i]);
	for (int i = 2; i <= n; i++) a[i] = b[i] - b[i - 1];
	read(m);
	if (n == 1) {
		for (int i = 1; i <= m; i++) puts("1");
		return 0;
	}
	build(2, n);
	for (int i = 1, l, r, v; i <= m; i++) {
		read(l); read(r); read(v);
		if (l > 1) update(1, 2, n, l, v);
		if (r < n) update(1, 2, n, r + 1, -v);
		printf("%d\n", t[1].ans + 1);
	}
	return 0;
}