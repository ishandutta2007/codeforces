// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 200010;

int n, len, frm, nxt;
int x[maxn], w[maxn], b[maxn], id[maxn];

bool cmp(int p, int q) {
	return x[p] < x[q];
}

struct node {
	int l, r, mid;
	int max;
} p[maxn << 2];

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) return;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}

void modify(int u, int k, int x) {
//	printf("modify %d %d %d %d %d\n", u, k, x, p[u].l, p[u].r);
	if (p[u].l == p[u].r) {
		p[u].max = max(p[u].max, x);
		return;
	}
	if (k <= p[u].mid) modify(u << 1, k, x);
	else modify(u << 1 | 1, k, x);
	p[u].max = max(p[u << 1].max, p[u << 1 | 1].max);
}

int query(int u, int l, int r) {
	if (l > r) return 0;
//	printf("query %d %d %d %d %d\n", u, l, r, p[u].l, p[u].r);
	if (p[u].l == l && p[u].r == r)
		return p[u].max;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else return max(query(u << 1, l, p[u].mid),
		query(u << 1 | 1, p[u].mid + 1, r));
}

int main(){
//	freopen("clique.in", "r", stdin);
//	freopen("clique.out", "w", stdout);
//	freopen("data.txt", "r", stdin);
//	freopen("out1.txt", "w", stdout);

	n = read();
	for (int i = 1; i <= n; i++) {
		x[i] = read(), w[i] = read();
		id[i] = i, b[i] = x[i] + w[i];
	}
	sort(id + 1, id + n + 1, cmp);
	
	sort(b + 1, b + n + 1);
	len = unique(b + 1, b + n + 1) - b - 1;
	build(1, 1, len);
	
	for (int i = 1, u = id[i]; i <= n; i++, u = id[i]) {
		frm = upper_bound(b + 1, b + len + 1, x[u] - w[u]) - b - 1;
		nxt = lower_bound(b + 1, b + len + 1, x[u] + w[u]) - b;
		modify(1, nxt, query(1, 1, frm) + 1);
//		printf("%d -> %d\n", u, query(1, 1, frm));
	}
	
	printf("%d\n", query(1, 1, len));
	
}