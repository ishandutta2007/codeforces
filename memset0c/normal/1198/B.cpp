// =================================
//   author: memset0
//   date: 2019.07.30 22:52:48
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define rep(i, l, r) for (int i = (l), i##ed = (r); i <= i##ed; ++i)
#define for_each(i, a) for (size_t i = 0, i##ed = a.size(); i < i##ed; ++i)
namespace ringo {

template <class T> inline void read(T &x) {
	x = 0; char c = getchar(); bool f = 0;
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
template <class T> inline void print(T a, int l, int r, std::string s = "") {
	if (s != "") std::cout << s << ": ";
	for (int i = l; i <= r; i++) print(a[i], " \n"[i == r]);
}

const int N = 2e5 + 10;
int n, m, a[N];
std::pair<int, int> c[N];
std::vector<std::pair<int, int>> vet;

struct node {
	int l, r, mid;
	std::pair<int, int> x;
} p[N << 2];

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) {
		p[u].x.first = a[l];
		p[u].x.second = 0;
		return;
	}
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}

void modify(int u, int k, int v, int t) {
	if (p[u].l == p[u].r) {
		p[u].x = std::make_pair(v, t);
		return;
	}
	modify(k <= p[u].mid ? u << 1 : u << 1 | 1, k, v, t);
}

void dfs(int u) {
	if (p[u].l == p[u].r ) {
		c[p[u].l] = p[u].x;
		return;
	}
	dfs(u << 1), dfs(u << 1 | 1);
}

void main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	build(1, 1, n);
	read(m);
	for (int i = 1, x, v, op; i <= m; i++) {
		read(op);
		if (op == 1) {
			read(x), read(v);
			modify(1, x, v, i);
		} else {
			read(v);
			vet.push_back(std::make_pair(i, v));
		}
	}
	dfs(1);
	for (int i = vet.size() - 2; i >= 0; i--)
		vet[i].second = std::max(vet[i].second, vet[i + 1].second);
	// for (auto it : vet) printf(">> %d %d\n", it.first, it.second);
	for (int i = 1; i <= n; i++) {
		int j = std::lower_bound(vet.begin(), vet.end(), std::make_pair(c[i].second, 0)) - vet.begin();
		// printf(">> %d %d %d\n", c[i].first, c[i].second, j);
		if (j != vet.size()) {
			c[i].first = std::max(c[i].first, vet[j].second);
		}
	}
	for (int i = 1; i <= n; i++)
		print(c[i].first, " \n"[i == n]);
}

} signed main() {
#ifdef memset0
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}