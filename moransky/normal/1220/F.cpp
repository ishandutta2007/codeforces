// Skyqwq
#include <iostream>
#include <cstdio>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

const int N = 4e5 + 5;

int n, a[N], pos[N], dep[N], S, ans = 2e9, ct, R[N], L[N];

int s[N], top;

int mx[N << 2], mn[N << 2], add[N << 2];

#define ls (p << 1)
#define rs (p << 1 | 1)

void inline Add(int p, int k) {
	add[p] += k, mx[p] += k, mn[p] += k;
}

void inline pushup(int p) {
	mx[p] = max(mx[ls], mx[rs]);
	mn[p] = min(mn[ls], mn[rs]);
}

void inline pushdown(int p) {
	if (add[p]) {
		Add(ls, add[p]);
		Add(rs, add[p]);
		add[p] = 0;
	}
}

void build(int p, int l, int r, int *b) {
	add[p] = 0;
	if (l == r) {
		mx[p] = mn[p] = b[r];
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid, b);
	build(rs, mid + 1, r, b);
	pushup(p);
}

void inline change(int p, int l, int r, int x, int y, int k) {
	if (x > y) return ;
	if (x <= l && r <= y) { Add(p, k); return; }
	pushdown(p);
	int mid = (l + r) >> 1;
	if (x <= mid) change(ls, l, mid, x, y, k);
	if (mid < y) change(rs, mid + 1, r, x, y, k);
	pushup(p);
}

int inline queryMn(int p, int l, int r, int x, int y) {
	if (x <= l && r <= y) return mn[p];
	pushdown(p);
	int mid = (l + r) >> 1, res = 2e9;
	if (x <= mid) res = min(res, queryMn(ls, l, mid, x, y));
	if (mid < y) res = min(res, queryMn(rs, mid + 1, r, x, y));
	return res;
}

int inline queryMx(int p, int l, int r, int x, int y) {
	if (x <= l && r <= y) return mx[p];
	pushdown(p);
	int mid = (l + r) >> 1, res = -2e9;
	if (x <= mid) res = max(res, queryMx(ls, l, mid, x, y));
	if (mid < y) res = max(res, queryMx(rs, mid + 1, r, x, y));
	return res;
}

void solve(int l, int r, int d) {
	if (l > r) return;
	int v = queryMn(1, 1, S, l, r);
	int p = pos[v];
	dep[p] = d;
	solve(l, p - 1, d + 1);
	solve(p + 1, r, d + 1);
}

int main() {
	scanf("%d", &n); S = 2 * n;
	for (int i = 1; i <= n; i++) scanf("%d", a + i), pos[a[i]] = i;
	build(1, 1, S, a);
	solve(1, n, 1);
	for (int i = 1; i <= n; i++) a[i + n] = a[i];

	build(1, 1, S, dep);
	ans = queryMx(1, 1, S, 1, n);

	for (int i = 1; i <= 2 * n; i++) {
		while (top && (s[top] <= i - n || a[s[top]] > a[i])) top--;
		if (!top) L[i] = i - n + 1;
		else L[i] = s[top] + 1;
		s[++top] = i;
	}

	top = 0;

	for (int i = 2 * n; i; i--) {
		while (top && (s[top] >= i + n || a[s[top]] > a[i])) top--;
		if (!top) R[i] = i + n - 1;
		else R[i] = s[top] - 1;
		s[++top] = i;
	}

	for (int i = 1; i < n; i++) {
		change(1, 1, S, i + 1, R[i], -1);
		change(1, 1, S, L[i + n], i + n - 1, 1);
		if (L[i + n] <= i + n - 1) {
			change(1, 1, S, i + n, i + n, queryMn(1, 1, S, L[i + n], i + n - 1) - 1);
		} else {
			change(1, 1, S, i + n, i + n, queryMn(1, 1, S, i + n - 1, i + n - 1) + 1);
		}
		int now = queryMx(1, 1, S, i + 1, i + n);
		if (now < ans) ans = now, ct = i;
	}
	printf("%d %d\n", ans, ct);
	return 0;
}