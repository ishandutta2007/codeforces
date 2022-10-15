#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

#define N 500501
#define INF 0x3f3f3f3f3f3f3f3f

struct Node {
	int l, r;
	LL v, mi;
} t[N * 2];

int tcnt = 0;
LL dep[N];
int fa[N], fw[N], L[N], R[N];

int n, Q;
vector <pii> E[N];
LL ans[N];

struct query {
	int x, l, r;
};
vector <query> q[N];

int build(int l, int r) {
	int x = ++tcnt;
	if (l < r) {
		int mid = (l + r) >> 1;
		t[x].l = build(l, mid);
		t[x].r = build(mid + 1, r);
		t[x].v = 0; 
		t[x].mi = min(t[t[x].l].mi, t[t[x].r].mi);
	}
	else {
		dep[l] = dep[fa[l]] + fw[l];
		if (!E[l].size()) t[x].mi = t[x].v = dep[l];
		else t[x].mi = t[x].v = INF;
	}
	return x;
}

void upd(int x, int l, int r, int ql, int qr, int v) {
	if (l == ql && r == qr) {
		t[x].v += v;
	}
	else {
		int mid = (l + r) >> 1;
			 if (qr <= mid) upd(t[x].l, l, mid, ql, qr, v);
		else if (ql >  mid) upd(t[x].r, mid + 1, r, ql, qr, v);
		else upd(t[x].l, l, mid, ql, mid, v),
			 upd(t[x].r, mid + 1, r, mid + 1, qr, v);
	}
	t[x].mi = min(t[t[x].l].mi, t[t[x].r].mi) + t[x].v;	
}

LL qry(int x, int l, int r, int ql, int qr) {
	if (l == ql && r == qr) return t[x].mi;
	int mid = (l + r) >> 1;
	if (qr <= mid) return qry(t[x].l, l, mid, ql, qr) + t[x].v;
	else if (ql > mid) return qry(t[x].r, mid + 1, r, ql, qr) + t[x].v;
	else return min(qry(t[x].l, l, mid, ql, mid), qry(t[x].r, mid + 1, r, mid + 1, qr)) + t[x].v;
}

void solve(int x) {
	for (auto v : q[x]) {
		ans[v.x] = qry(1, 1, n, v.l, v.r);
	}
	for (auto v : E[x]) {
		upd(1, 1, n, 1, n, v.y);		
		upd(1, 1, n, L[v.x], R[v.x], -2 * v.y);		
		solve(v.x);
		upd(1, 1, n, 1, n, -v.y);		
		upd(1, 1, n, L[v.x], R[v.x], 2 * v.y);		
	}
}

int main() {
	read(n); read(Q);
	for (int i = 2; i <= n; i++) {
		read(fa[i]); read(fw[i]);
		E[fa[i]].push_back({i, fw[i]});
	}
	for (int i = 1; i <= n; i++) sort(E[i].begin(), E[i].end());
	for (int i = n; i ; i--) {
		L[i] = i;
		if (!R[i]) R[i] = i;
		R[fa[i]] = max(R[fa[i]], R[i]);
	}
	for (int i = 1; i <= Q; i++) {
		int x, l, r;
		read(x); read(l); read(r);
		q[x].push_back({i, l, r});
	}
	build(1, n);
	solve(1);
	for (int i = 1; i <= Q; i++) printf("%lld\n", ans[i]);
}