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

#define MAXN 200005
#define INF LL(2e14)

struct edge {
	int next, to, w;
} e[MAXN];

struct Node {
	int l, r, v;
} t[MAXN * 47];

int n, ecnt = 0, head[MAXN], fa[MAXN];

void add(int u, int v, int w) {
	e[++ecnt].to = v; e[ecnt].next = head[u]; e[ecnt].w = w; head[u] = ecnt;
}

int a[MAXN], ans[MAXN], root, tcnt = 0;
LL dep[MAXN];

int query(int x, LL l, LL r, LL ql, LL qr) {
	//cout << x << " " << l << " " << r << " " << ql << " " << qr << endl;
	if (!t[x].v) return 0;
	if (l == ql && r == qr) return t[x].v;
	LL mid = (l + r) >> 1; int ret = 0;
	if (ql <= mid) ret += query(t[x].l, l, mid, ql, min(mid, qr));
	if (qr > mid) ret += query(t[x].r, mid + 1, r, max(mid + 1, ql), qr);
	return ret;
}

void update(int &x, LL l, LL r, LL v) {
	if (!x) x = ++tcnt;
	t[x].v++;
	if (l < r) {
		LL mid = (l + r) >> 1;
		if (v <= mid) update(t[x].l, l, mid, v);
		else update(t[x].r, mid + 1, r, v);
	}
}


void dfs(int x) {
	ans[x] -= query(root, -INF, INF, -INF, dep[x]);
	for (int now = head[x]; now; now = e[now].next) {
		dep[e[now].to] = dep[x] + e[now].w;
		dfs(e[now].to);
	}
	ans[x] += query(root, -INF, INF, -INF, dep[x]);
	update(root, -INF, INF, dep[x] - a[x]);
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 2; i <= n; i++) {
		int w; read(fa[i]), read(w); add(fa[i], i, w);
	}
	dep[1] = 0;
	dfs(1);	
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}