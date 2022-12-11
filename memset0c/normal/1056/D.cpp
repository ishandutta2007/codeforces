#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

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
int n, p, siz[N], ans[N];
std::vector < int > son[N];

void dfs(int u) {
	siz[u] = 1;
	for (auto v : son[u]) {
		dfs(v);
		siz[u] += siz[v];
		ans[u] += ans[v];
	}
	if (siz[u] == 1)
		ans[u] = 1;
}

void main() {
	read(n);
	for (int i = 2; i <= n; i++) {
		read(p);
		son[p].push_back(i);
	}
	dfs(1);
	std::sort(ans + 1, ans + n + 1);
	for (int i = 1; i <= n; i++)
		print(ans[i], " \n"[i == n]);
}

} signed main() { return ringo::main(), 0; }