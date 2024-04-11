#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, P = 1000000000;
struct node {
	int add,ls,rs,mn,mx;
}tr[maxn * 250];
int tot;

int New(int Mn, int Mx) {
	tr[++tot] = (node) {0, 0, 0, Mn, Mx};
	return tot;
}

void push_up(int rt) {
	if(!tr[rt].ls) return;
	tr[rt].mn = min(tr[tr[rt].ls].mn, tr[tr[rt].rs].mn);
	tr[rt].mx = max(tr[tr[rt].ls].mx, tr[tr[rt].rs].mx);
}

#define A(p, v) (tr[p].add += v, tr[p].mn += v, tr[p].mx += v)
void push_down(int rt, int l, int r) {
	int mid = (l + r) >> 1;
	if(!tr[rt].ls) tr[rt].ls = New(l, mid);
	if(!tr[rt].rs) tr[rt].rs = New(mid + 1, r);
	if(tr[rt].add) {
		A(tr[rt].ls, tr[rt].add);
		A(tr[rt].rs, tr[rt].add);
		tr[rt].add = 0;
	}
}

void Add(int rt, int l, int r, int L, int R, int val) {
//	printf("Add %d to [%d, %d]\n", val, l, r);
	if(L <= l && r <= R) { A(rt, val); return; }
	push_down(rt, l, r);
	int mid = (l + r) >> 1;
	if(L <= mid) Add(tr[rt].ls, l, mid, L, R, val);
	if(R > mid) Add(tr[rt].rs, mid + 1, r, L, R, val);
	push_up(rt);
}

int query_lbound(int rt, int l, int r, int val) {
	if(l == r) return l;
	push_down(rt, l, r);
	int mid = (l + r) >> 1;
	if(tr[tr[rt].ls].mx >= val) return query_lbound(tr[rt].ls, l, mid, val);
	return query_lbound(tr[rt].rs, mid + 1, r, val);
}

int query_rbound(int rt, int l, int r, int val) {
//	printf("Qr [%d, %d] %d %d %d\n", l, r, val, tr[rt].mn, tr[rt].mx);
	if(l == r) return l;
	push_down(rt, l, r);
	int mid = (l + r) >> 1;
	if(tr[tr[rt].rs].mn <= val) return query_rbound(tr[rt].rs, mid + 1, r, val);
	return query_rbound(tr[rt].ls, l, mid, val);
}

int query_val(int rt, int l, int r, int pos) {
	if(l == r) return tr[rt].mn;
	push_down(rt, l, r);
	int mid = (l + r) >> 1;
	if(pos <= mid) return query_val(tr[rt].ls, l, mid, pos);
	return query_val(tr[rt].rs, mid + 1, r, pos);
}

int n,last_ans;

int main() {
	New(-1, P + 1);
	scanf("%d", &n);
	for(int i = 1, t, k, x; i <= n; ++i) {
		scanf("%d", &t);
		int lb = query_lbound(1, -1, P + 1, t), rb = query_rbound(1, -1, P + 1, t);
//		printf("[%d, %d]\n", lb, rb);
		if(lb > 0) Add(1, -1, P + 1, 0, lb - 1, 1);
		if(rb < P) Add(1, -1, P + 1, rb + 1, P, -1);
		scanf("%d", &k);
		while(k--) {
			scanf("%d", &x);
			printf("%d\n", last_ans = query_val(1, -1, P + 1, (x + last_ans) % (P + 1)));
		}
	}
	return 0;
}