#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define N 402055
int n, m;
int a[N];

struct Node {
	int l, r, v;
} t[N  *2];
int tcnt = 0;

int build(int l, int r) {
	int x = ++tcnt;
	if (l < r) {
		int mid = (l + r) >> 1;
		t[x].l = build(l, mid);
		t[x].r = build(mid + 1, r);
		t[x].v = -1;
	}
	else {
		t[x].v = a[l];
	}
	return x;
}

void upd(int x, int l, int r, int p, int v) {
	if (l == r) {
		t[x].v = v;
	}
	else {
		if (t[x].v != -1) {
			t[t[x].l].v = max(t[t[x].l].v, t[x].v);
			t[t[x].r].v = max(t[t[x].r].v, t[x].v);
			t[x].v = -1;
		}
		int mid = (l + r) >> 1;
		if (p <= mid) upd(t[x].l, l, mid, p, v);
		else 		  upd(t[x].r, mid + 1, r, p, v);
	}
}

void dfs(int x, int l, int r) {
	if (l == r) {
		printf("%d ", t[x].v);
	}
	else {
		if (t[x].v != -1) {
			t[t[x].l].v = max(t[t[x].l].v, t[x].v);
			t[t[x].r].v = max(t[t[x].r].v, t[x].v);
			t[x].v = -1;
		}
		int mid = (l + r) >> 1;
		dfs(t[x].l, l, mid);
		dfs(t[x].r, mid + 1, r);
	}
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	build(1, n);
	read(m);
	for (int i = 1; i <= m; i++) {
		int op, p, x;
		scanf("%d%d", &op, &p);
		if (op == 1) {
			read(x);
			upd(1, 1, n, p, x);
		}
		else {
			t[1].v = max(t[1].v, p);
		}
	}
	dfs(1, 1, n);

}