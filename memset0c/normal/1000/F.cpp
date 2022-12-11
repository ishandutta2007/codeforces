// ==============================
//  author: memset0
//  website: https://memset0.cn
//  date: 2018.08.05 20:38:03
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 500010, inf = 1e9 + 10;
int n, m, l, r, a[maxn], pre[maxn], lst[maxn], ans[maxn];

struct ask {
	int k, i;
};
vector < ask > Q[maxn];

struct answer {
	int left, num;
	answer(int _left = -1, int _num = 0) {
		left = _left, num = _num;
	}
	answer operator + (const answer &b) const {
		if (left > b.left) return b;
		return answer(left, num);
	}
};

struct node {
	int l, r, mid;
	answer x;
} p[maxn << 2];

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	p[u].x = answer(-1, 0);
	if (l == r) return;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}

void update(int u, int k, int left, int num) {
	// printf("UPDATE %d %d %d %d\n", u, k, left, num);
	if (p[u].l == p[u].r) { p[u].x = answer(left, num); return; }
	if (k <= p[u].mid) update(u << 1, k, left, num);
	else update(u << 1 | 1, k, left, num);
	p[u].x = p[u << 1].x + p[u << 1 | 1].x; 
}

answer query(int u, int l, int r) {
	// printf("QUERY %d %d %d\n", u, l, r);
	if (p[u].l == l && p[u].r == r) return p[u].x;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else return query(u << 1, l, p[u].mid) + query(u << 1 | 1, p[u].mid + 1, r);
}

int main() {
	// freopen("INPUT", "r", stdin);
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	m = read();
	for (int i = 1; i <= m; i++) {
		l = read(), r = read();
		Q[r].push_back({l, i});
	}
	for (int i = 1; i <= n; i++)
		pre[i] = lst[a[i]], lst[a[i]] = i;
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		update(1, i, pre[i] + 1, a[i]);
		if (pre[i]) update(1, pre[i], inf, a[i]);
		for (vector < ask > ::iterator it = Q[i].begin(); it != Q[i].end(); it++) {
			answer ret = query(1, (*it).k, i);
			if (ret.left <= (*it).k) ans[(*it).i] = ret.num;
			else ans[(*it).i] = 0;
		}
	}
	for (int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
	return 0;
}