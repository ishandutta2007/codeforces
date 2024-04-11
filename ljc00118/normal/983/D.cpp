#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
	f = 0; _T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 2e5 + 5;

struct ele { int lx, rx, ly, ry; } a[N];
struct event_t { int t, l, r, id; } q[N];

bool operator < (const event_t a, const event_t b) { return a.t < b.t; }

set <int> col[N << 2];
int mx[N << 2], lim[N << 2], cando[N];
int bx[N], by[N];
int n, lenx, leny, tot, ans;

void update(int u, int l, int r) {
	if (l == r) mx[u] = lim[u] = 0;
	else {
		mx[u] = max(mx[u << 1], mx[u << 1 | 1]);
		lim[u] = min(lim[u << 1], lim[u << 1 | 1]);
	}
	if (!col[u].size()) return;
	int id = *col[u].rbegin();
	if (cando[id]) lim[u] = max(lim[u], id);
	else mx[u] = max(mx[u], id);
	if (mx[u] < lim[u]) mx[u] = 0;
}

void change(int u, int L, int R, int l, int r, int x) {
	if (l <= L && R <= r) {
		if (x > 0) col[u].insert(x);
		if (x < 0) col[u].erase(-x);
		update(u, L, R);
		return;
	}
	int mid = (L + R) >> 1;
	if (mid >= l) change(u << 1, L, mid, l, r, x);
	if (mid + 1 <= r) change(u << 1 | 1, mid + 1, R, l, r, x);
	update(u, L, R);
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i].lx); read(a[i].ly);
		read(a[i].rx); read(a[i].ry);
		bx[++lenx] = a[i].lx; bx[++lenx] = a[i].rx;
		by[++leny] = a[i].ly; by[++leny] = a[i].ry;
	}
	sort(bx + 1, bx + lenx + 1); lenx = unique(bx + 1, bx + lenx + 1) - bx - 1;
	sort(by + 1, by + leny + 1); leny = unique(by + 1, by + leny + 1) - by - 1;
	for (int i = 1; i <= n; i++) {
		a[i].lx = lower_bound(bx + 1, bx + lenx + 1, a[i].lx) - bx;
		a[i].rx = lower_bound(bx + 1, bx + lenx + 1, a[i].rx) - bx - 1;
		a[i].ly = lower_bound(by + 1, by + leny + 1, a[i].ly) - by;
		a[i].ry = lower_bound(by + 1, by + leny + 1, a[i].ry) - by - 1;
	}
	for (int i = 1; i <= n; i++) {
		q[++tot] = (event_t) {a[i].lx, a[i].ly, a[i].ry, i};
		q[++tot] = (event_t) {a[i].rx + 1, a[i].ly, a[i].ry, -i};
	}
	sort(q + 1, q + tot + 1);
	for (int l = 1, r; l <= tot; l = r + 1) {
		r = l;
		while (r < tot && q[r + 1].t == q[l].t) ++r;
		for (int i = l; i <= r; i++) change(1, 1, leny - 1, q[i].l, q[i].r, q[i].id);
		while (mx[1]) {
			cando[mx[1]] = 1; ++ans;
			change(1, 1, leny - 1, a[mx[1]].ly, a[mx[1]].ry, 0);
		}
	}
	print(ans + 1, '\n');
	return 0;
}