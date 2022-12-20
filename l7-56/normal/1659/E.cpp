#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxn = 1e5 + 10;
int n,m,q,haveeven[maxn];
struct edge {
	int u, v, w;
}e[maxn];
struct dsu {
	int fa[maxn],flg[maxn];
	int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
	void init() {
		for (int i = 1; i <= n; ++i)
			fa[i] = i, flg[i] = haveeven[i];
	}
	void merge(int u, int v) {
		u = get(u), v = get(v);
		if (u == v) return;
		fa[u] = v, flg[v] |= flg[u];
	}
}a[30];

int main() {
	read(n, m);
	for (int i = 1; i <= m; ++i) {
		read(e[i].u, e[i].v, e[i].w);
		if (e[i].w % 2 == 0) haveeven[e[i].u] = haveeven[e[i].v] = 1;
	}
	for (int bit = 0; bit < 30; ++bit) a[bit].init();
	for (int i = 1; i <= m; ++i)
		for (int bit = 0; bit < 30; ++bit)
			if ((e[i].w >> bit) & 1) a[bit].merge(e[i].u, e[i].v);
	read(q);
	while (q--) {
		int u, v, ans = 2; read(u, v);
		for (int bit = 0; bit < 30; ++bit) {
			if (a[bit].get(u) == a[bit].get(v)) ans = 0;
			if (bit && a[bit].flg[a[bit].get(u)]) ans = min(ans, 1);
		}
		write(ans, '\n');
	}
	return 0;
}