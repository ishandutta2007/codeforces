// Skyqwq
#include <iostream>
#include <cstdio>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

#define ls (p << 1)
#define rs (p << 1 | 1)

const int N = 2e5 + 5;

int n, q, s[N], L[N << 2], R[N << 2];

char g[N];

struct Node {
	int d, a, b, vA, vB, preA, sufA, preB, sufB;
} t[N << 2];

void chk(Node &x, Node y) {
	if (y.d > x.d) x = y;
}

int mn[N << 2], add[N << 2];

void inline Add(int p, int k) {
	add[p] += k, mn[p] += k;
	t[p].vA += k, t[p].vB += k;
	t[p].preA += k, t[p].sufA += k;
	t[p].preB += k, t[p].sufB += k;
}

void inline pushdown(int p) {
	if (add[p]) {
		Add(ls, add[p]);
		Add(rs, add[p]);
		add[p] = 0;
	}
}

Node inline get(int d, int a, int b, int vA, int vB, int preA, int sufA, int preB, int sufB) {
	return (Node) {  d, a, b, vA, vB, preA, sufA, preB, sufB };
}

void inline pushup(int p) {
	mn[p] = min(mn[ls], mn[rs]);
	Node x = t[ls], y = t[rs];
	chkMin(x.sufA, mn[rs]);
	chkMin(x.sufB, mn[rs]);
	chkMin(y.preA, mn[ls]);
	chkMin(y.preB, mn[ls]);
	t[p] = x;
	chk(t[p], y);
	chk(t[p], get(x.vA + y.vA - 2 * min(t[ls].sufA, t[rs].preA), x.a, y.a, x.vA, y.vA, x.preA, x.sufA, y.preA, y.sufA));
	chk(t[p], get(x.vA + y.vB - 2 * min(t[ls].sufA, t[rs].preB), x.a, y.b, x.vA, y.vB, x.preA, x.sufA, y.preB, y.sufB));
	chk(t[p], get(x.vB + y.vA - 2 * min(t[ls].sufB, t[rs].preA), x.b, y.a, x.vB, y.vA, x.preB, x.sufB, y.preA, y.sufA));
	chk(t[p], get(x.vB + y.vB - 2 * min(t[ls].sufB, t[rs].preB), x.b, y.b, x.vB, y.vB, x.preB, x.sufB, y.preB, y.sufB));
}

void build(int p, int l, int r) {
	L[p] = l, R[p] = r;
	if (l == r) {
		mn[p] = s[r];
		t[p].a = t[p].b = r;
		t[p].vA = t[p].vB = t[p].preA = t[p].sufA = t[p].preB = t[p].sufB = s[r];
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}

void change(int p, int l, int r, int x, int y, int k) {
	if (x <= l && r <= y) {
		Add(p, k);
		return;
	}
	pushdown(p);
	int mid = (l + r) >> 1;
	if (x <= mid) change(ls, l, mid, x, y, k);
	if (mid < y) change(rs, mid + 1, r, x, y, k);
	pushup(p);
}

void inv(int i) {
	if (g[i] == '(') {
		change(1, 1, n, i, n, -2);
		g[i] = ')';
	} else {
		change(1, 1, n, i, n, 2);
		g[i] = '(';
	}
}


int main() {
	read(n), read(q);
	n = 2 * (n - 1);
	scanf("%s", g + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + (g[i] == '(' ? 1 : -1);
	build(1, 1, n);
	printf("%d\n", t[1].d);
	while (q--) {
		int a, b; read(a), read(b);
		if (g[a] != g[b]) 
			inv(a), inv(b);
		printf("%d\n", t[1].d);
	}
	return 0;
}