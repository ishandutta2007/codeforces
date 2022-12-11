// =================================
//   author: memset0
//   date: 2018.12.08 08:53:28
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;
#define int long long

template < class T >
inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}

template < class T >
inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
	print(x), putchar(c);
}

const int N = 1e5 + 10;
int n, m, u, v, op;
int a[N], b[N], c[N], d[N], e[N];
std::multiset < int > ans, f[N];

inline void erase(std::multiset < int > &s, int x) { s.erase(s.find(x)); }
inline void insert(std::multiset < int > &s, int x) { s.insert(x); }
inline void insert_ans(int x) {
	if (f[x].size() == 0) return;
	insert(ans, e[x] + *f[x].begin());
	insert(ans, e[x] + *--f[x].end());
}
inline void erase_ans(int x) {
	if (f[x].size() == 0) return;
	erase(ans, e[x] + *f[x].begin());
	erase(ans, e[x] + *--f[x].end());
}

// inline void print_ans() {
// 	std::vector < int > t;
// 	for (int i = 1; i <= n; i++)
// 		if (f[i].size()) {
// 			t.push_back(e[i] + *f[i].begin());
// 			t.push_back(e[i] + *--f[i].end());
// 		}
// 	std::sort(t.begin(), t.end());
// 	for (auto x : t) print(x, ' '); puts("");
// 	for (auto x : ans) print(x, ' '); puts("");
// 	puts("-----");
// 	// for (int i = 1; i <= n; i++) {
// 	// 	printf("%lld %lld >> ", i, c[i]);
// 	// 	for (auto u : f[a[i]])
// 	// 		print(u, ' ');
// 	// 	puts("");
// 	// }
// 	// for (int i = 1; i <= n; i++) {
// 	// 	printf("%lld => ", i);
// 	// 	for (auto u : f[i])
// 	// 		print(u, ' ');
// 	// 	puts("");
// 	// }
// }

void cut(int u, int v) {
	// printf("cut %lld %lld\n", u, v);
	int dt_e = b[v] / (d[v] - 1) - e[v];
	erase_ans(v), erase_ans(a[v]), erase_ans(a[a[v]]);
	erase(f[a[v]], c[v]), erase(f[a[a[v]]], c[a[v]]);
	c[v] += (1 - d[v]) * dt_e;  
	--d[v];
	e[v] += dt_e, c[a[v]] += dt_e;
	c[v] -= e[u], c[v] += e[v];
	insert(f[a[v]], c[v]), insert(f[a[a[v]]], c[a[v]]);
	insert_ans(v), insert_ans(a[v]), insert_ans(a[a[v]]);
	// printf("finish cut\n");
}

void link(int u, int v) {
	// printf("link %lld %lld\n", u, v);
	int dt_e = b[v] / (d[v] + 1) - e[v];
	erase_ans(v), erase_ans(a[v]), erase_ans(a[a[v]]);
	erase(f[a[v]], c[v]), erase(f[a[a[v]]], c[a[v]]);
	c[v] += (1 - d[v]) * dt_e;
	++d[v];
	e[v] += dt_e, c[a[v]] += dt_e;
	c[v] -= e[v], c[v] += e[u];
	insert(f[a[v]], c[v]), insert(f[a[a[v]]], c[a[v]]);
	insert_ans(v), insert_ans(a[v]), insert_ans(a[a[v]]);
	// printf("finish link\n");
}

void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) read(b[i]);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) ++d[a[i]];
	for (int i = 1; i <= n; i++) d[i] += 2;
	for (int i = 1; i <= n; i++) e[i] = b[i] / d[i];
	for (int i = 1; i <= n; i++) c[i] = b[i] - d[i] * e[i] + e[i];
	for (int i = 1; i <= n; i++) c[a[i]] += e[i];
	for (int i = 1; i <= n; i++) f[a[i]].insert(c[i]);
	for (int i = 1; i <= n; i++)
		if (f[i].size()) insert_ans(i);
	for (int i = 1; i <= m; i++) {
		read(op);
		if (op == 1) {
			read(u), read(v);
			cut(u, a[u]);
			erase_ans(a[u]);
			erase(f[a[u]], c[u]);
			insert_ans(a[u]);
			a[u] = v;
			erase_ans(a[u]);
			insert(f[a[u]], c[u]);
			insert_ans(a[u]);
			link(u, a[u]);
		} else if (op == 2) {
			read(u);
			print(c[u] + e[a[u]], '\n');
		} else {
			print(*ans.begin(), ' ');
			print(*--ans.end(), '\n');
		}
	}
}

} signed main() { return ringo::main(), 0; }