// =================================
//   author: memset0
//   date: 2019.01.06 18:16:41
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
namespace ringo {
template <class T> inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }

const int N = 2e5 + 10, M = 5;
int n, m, t, ans;

struct node {
	int b[M];
} u, a[N];

struct status {
	int ans[1 << M];
	inline status () {}
	inline status (const node &a) {
		memset(ans, 0, sizeof(ans));
		for (int x = 0; x < (1 << m); x++) {
			for (int i = 0; i < m; i++)
				ans[x] += (x & (1 << i) ? 1 : -1) * a.b[i];
		}
	}
} ret;
inline status operator ^ (const status &x, const status &y) {
	status ans;
	for (int i = 0; i < (1 << m); i++)
		ans.ans[i] = std::max(x.ans[i], y.ans[i]);
	return ans;
}

struct seg_node {
	int l, r, mid;
	status x;
} p[N << 2];

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) return (void)(p[u].x = status(a[l]));
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].x = p[u << 1].x ^ p[u << 1 | 1].x;
}

void modify(int u, int k, const node &x) {
	if (p[u].l == p[u].r) return (void)(p[u].x = status(x));
	if (k <= p[u].mid) modify(u << 1, k, x);
	else modify(u << 1 | 1, k, x);
	p[u].x = p[u << 1].x ^ p[u << 1 | 1].x;
}

status query(int u, int l, int r) {
	if (p[u].l == l && p[u].r == r) return p[u].x;
	if (r <= p[u].mid) return query(u << 1, l, r);
	if (l > p[u].mid) return query(u << 1 | 1, l, r);
	return query(u << 1, l, p[u].mid) ^ query(u << 1 | 1, p[u].mid + 1, r);
}

void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
			read(a[i].b[j]);
	build(1, 1, n), read(t);
	for (int i = 1, k, l, r, op; i <= t; i++)
		if (read(op), op == 1) {
			read(k);
			for (int i = 0; i < m; i++)
				read(u.b[i]);
			modify(1, k, u);
		} else {
			read(l), read(r), ans = 0;
			ret = query(1, l, r);
			for (int x = 0; x < (1 << m); x++)
				ans = std::max(ans, ret.ans[x] + ret.ans[((1 << m) - 1) ^ x]);
			print(ans, '\n');
		}
}

} signed main() { return ringo::main(), 0; }