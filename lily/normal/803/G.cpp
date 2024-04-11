/* Never Say Die */
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
typedef long long LL;
typedef double D;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define fir first
#define sec second
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
int ch = 0;
template <class T> inline void read(T &a) {
	bool f = 0;
	while (ch < '0' || ch>'9') {if (ch == '-') f = 1; ch=getchar();}
	a = 0;
	while (ch >= '0' && ch <= '9') {a = a * 10 + ch - '0'; ch = getchar();}
	if (f) a = -a;
}

#define MAXN 100319

struct Node {
	int l, r, v;
	bool lazy;
} t[MAXN * 99];

int tcnt = 0, rt = 0;

int n, K, Q, N, Min;

int a[MAXN], Log[MAXN];
int st[MAXN][17];

void init() {
	Log[0] = -1;
	for (int i = 1; i <= n; i++) Log[i] = Log[i >> 1] + 1;
	for (int i = 0; i < n; i++) st[i][0] = a[i];
	for (int k = 1; k <= Log[n]; k++) {
		for (int i = 0, x = 1 << (k - 1), j = n - (x << 1); i <= j; i++) {
			st[i][k] = min(st[i][k - 1], st[i + x][k - 1]);
		}
	}
}

inline int get(int l, int r) {
	return min(st[l][Log[r - l + 1]], st[r - (1 << Log[r - l + 1]) + 1][Log[r - l + 1]]);
}

inline int rmq(int l, int r) {
	if (r - l + 1 >= n) return Min;
	l %= n, r %= n;
	if (l <= r) return get(l, r);
	else return min(get(l, n - 1), get(0, r));
}

void update(int &x, int l, int r, int ql, int qr, int v) {
	if (!x) x = ++tcnt;
	if (l == ql && r == qr) {
		t[x].v = v; t[x].lazy = 1;
		return;
	}
	int mid = (l + r) >> 1;
	if (t[x].lazy) {
		if (!t[x].l) t[x].l = ++tcnt;
		if (!t[x].r) t[x].r = ++tcnt;
		t[t[x].l].v = t[t[x].r].v = t[x].v;
		t[t[x].l].lazy = t[t[x].r].lazy = 1;
		t[x].lazy = 0;
	}
	if (ql <= mid) update(t[x].l, l, mid, ql, min(mid, qr), v);
	if (qr >  mid) update(t[x].r, mid + 1, r, max(mid + 1, ql), qr, v);
	t[x].v = min(t[x].l ? t[t[x].l].v : rmq(l, mid), t[x].r ? t[t[x].r].v : rmq(mid + 1, r));
}

int query(int x, int l, int r, int ql, int qr) {
	if (!x) return rmq(ql, qr);
	if ((l == ql && r == qr) || t[x].lazy) return t[x].v;
	int mid = (l + r) >> 1, ret = 0x7fffffff;
	if (ql <= mid) ret = min(ret, query(t[x].l, l, mid, ql, min(mid, qr)));
	if (qr >  mid) ret = min(ret, query(t[x].r, mid + 1, r, max(mid + 1, ql), qr));
	return ret;
}

int main() {
	read(n); read(K);
	Min = 0x7fffffff;
	for (int i = 0; i < n; i++) read(a[i]), Min = min(Min, a[i]);
	init();
	N = n * K - 1;
	read(Q);
	for (int i = 1, l, r, op, x; i <= Q; i++) {
		read(op), read(l), read(r); l--, r--;
		if (op == 1) {
			read(x);
			update(rt, 0, N, l, r, x);
		}
		else {
			printf("%d\n", query(rt, 0, N, l, r));
		}
	}
	return 0;
}