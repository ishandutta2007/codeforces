/* Never say die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <bitset>
using namespace std;
int _c = 0;
template <class T> inline void read(T &_a) {
	bool f = 0;
	while (_c < '0' || _c>'9') {if (_c == '-') f = 1; _c=getchar();}
	_a = 0;
	while (_c >= '0' && _c <= '9') {_a = _a * 10 + _c - '0'; _c = getchar();}
	if (f) _a = -_a;
}

#define MAXN 300319
#define INF 0x3f3f3f3f3f3f3f3f

struct edge {
	int next, to, w;
} e[MAXN * 33];

int head[MAXN * 5], ecnt = 0;

void add(int u, int v, int w) {
	e[++ecnt].to = v; e[ecnt].w = w; e[ecnt].next = head[u]; head[u] = ecnt;
}

struct Node {
	int l, r;
} t[MAXN * 4];

int n, q, S, tcnt = 0, rt1, rt2;

int build(int l, int r, int type) {
	int x = ++tcnt;
	if (l < r) {
		int mid = (l + r) >> 1;
		t[x].l = build(l, mid, type);
		t[x].r = build(mid + 1, r, type);
		if (type == 2) add(x, t[x].l, 0), add(x, t[x].r, 0);
		else add(t[x].l, x, 0), add(t[x].r, x, 0);
	}
	else {
		if (type == 2) add(x, l, 0);
		else add(l, x, 0);
	}
	return x;
}

void update(int x, int l, int r, int ql, int qr, int v, int w, int op) {
	if (l == ql && r == qr) {
		if (op == 2) add(v, x, w);
		else add(x, v, w);
		return;
	}
	int mid = (l + r) >> 1;
	if (ql <= mid) update(t[x].l, l, mid, ql, min(mid, qr), v, w, op);
	if (qr > mid) update(t[x].r, mid + 1, r, max(mid + 1, ql), qr, v, w, op);
}

typedef long long LL;
#define s 524288

LL dis[MAXN * 5], zkw[s * 2]; bool vis[MAXN * 5];

inline int query() {
	register int x = 1;
	while (x < s) {x <<= 1, x ^= zkw[x] > zkw[x ^ 1];}
	return x - s;
}

inline void update(register int x, register LL v) {for (zkw[x += s] = v; x >>= 1; zkw[x] = min(zkw[x << 1], zkw[(x << 1) ^ 1]));}

void dijkstra() {
	memset(dis, -1, sizeof(dis));
	memset(zkw, 0x3f, sizeof(zkw));
	update(S, 0);
	register int x = S;
	register LL *Dis = zkw + s;
	while (Dis[x] < INF) {
		dis[x] = Dis[x];
		update(x, INF); vis[x] = 1;
		for (int now = head[x]; now; now = e[now].next) {
			if (!vis[e[now].to] && Dis[e[now].to] > dis[x] + e[now].w) update(e[now].to, dis[x] + e[now].w);
		}
		x = query();
	}
}

int main() {
	read(n); read(q); read(S);
	tcnt = n; rt1 = build(1, n, 2), rt2 = build(1, n, 3);
	for (int i = 1, op, l, r, v, w; i <= q; i++) {
		read(op);
		if (op == 1) read(l), read(v), read(w), add(l, v, w);
		else {
			read(v); read(l); read(r); read(w);
			update(op == 2 ? rt1 : rt2, 1, n, l, r, v, w, op);
		}
	}
	dijkstra();
	for (int i = 1; i <= n; i++) {
		printf("%lld ", dis[i]);
	}
	return 0;
}