#include <bits/stdc++.h>
using namespace std;

#define N 1010111

struct Node {
	int l, r, v, a;
} t[N * 2];

int tcnt = 0;

int build(int l, int r) {
	int x = ++tcnt;
	t[x] = {0, 0, 0, 0};
	if (l < r) {
		int mid = (l + r) / 2;
		t[x].l = build(l, mid); 
		t[x].r = build(mid + 1, r); 
	}
	return x;
}

int qry(int x, int l, int r, int ql, int qr) {
	if (l == ql && r == qr) return t[x].v;
	int mid = (l + r) / 2;
	if (qr <= mid) return qry(t[x].l, l, mid, ql, qr);
	else if (ql > mid) return qry(t[x].r, mid + 1, r, ql, qr);
	else return max(qry(t[x].l, l, mid, ql, mid), qry(t[x].r, mid + 1, r, mid + 1, qr));
}

void push_up(int x) {
	t[x].v = max(t[t[x].l].v, t[t[x].r].v);
}

void gomark(int x, int l, int r) {
	if (t[x].a) return;
	if (l == r) {
		t[x].v ++;
		t[x].a = 1;
	} else {
		int mid = (l + r) / 2;
		gomark(t[x].l, l, mid);
		gomark(t[x].r, mid + 1, r);
		t[x].a = 1;
		push_up(x);
	}
}


void mark(int x, int l, int r, int ql, int qr) {
	if (t[x].a) return ;
	if (l == ql && r == qr) {
		gomark(x, l, r);
	} else {
		int mid = (l + r) / 2;
		if (qr <= mid) mark(t[x].l, l, mid, ql, qr);
		else if (ql > mid) mark(t[x].r, mid + 1, r, ql, qr);
		else mark(t[x].l, l, mid, ql, mid), mark(t[x].r, mid + 1, r, mid + 1, qr);
		push_up(x);
	}
}


void upd(int x, int l, int r, int p, int v) {
	t[x].a = 0;
	if (l == r) {
		t[x].v = v;
		t[x].a = 0;
	} else {
		int mid = (l + r) / 2;
		if (p <= mid) upd(t[x].l, l, mid, p, v);
		else upd(t[x].r, mid + 1, r, p, v);
		push_up(x);
	}
}

int n;
int a[N];

void work() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	tcnt = 0;
	build(1, n);
	for (int i = 1; i <= n; i++) {
		int x = a[i];
		int ans = qry(1, 1, n, 1, x) + 1;
		// 1 ~ x - 1
		if (x > 1) {
			mark(1, 1, n, 1, x - 1);
		}
		upd(1, 1, n, x, ans);
	}
	printf("%d\n", qry(1, 1, n, 1, n));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
}