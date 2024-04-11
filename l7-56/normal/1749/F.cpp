#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
void read(char &ch) { for (ch = getchar(); isspace(ch); ch = getchar()); }
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (; *s; ++s) putchar(*s); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxn = 3e5 + 10;
int n, m, f[maxn][21], st[maxn], ed[maxn], idx, dep[maxn];
vi e[maxn];
void dfs(int u, int pre) {
	f[u][0] = pre, dep[u] = dep[pre] + 1;
	st[u] = ++idx;
	for (int i = 1; i <= 20; ++i) f[u][i] = f[f[u][i - 1]][i - 1];
	for (int v : e[u]) if (v != pre) dfs(v, u);
	ed[u] = idx;
}
int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 20; i >= 0; --i)
		if (dep[x] - dep[y] >= (1 << i)) x = f[x][i];
	if (x == y) return x;
	for (int i = 20; i >= 0; --i)
		if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

struct BIT {
	int c[maxn];
	void add(int x, int y) { for (; x <= n; x += x & -x) c[x] += y; }
	int ask(int x) {
		int res = 0;
		for (; x > 0; x &= x - 1) res += c[x];
		return res;
	}
	int ask(int l, int r) { return ask(r) - ask(l - 1); }
} tr[21];

int main() {
	read(n);
	for (int i = 1; i < n; ++i) {
		int u, v; read(u, v);
		e[u].push_back(v), e[v].push_back(u);
	}
	e[1].push_back(++n), e[n].push_back(1);
	for (int i = 1; i <= 20; ++i)
		e[n].push_back(n + 1), e[n + 1].push_back(n), ++n;
	dfs(n, 0);
	read(m);
	for (int i = 1; i <= m; ++i) {
		int op, u, v, k, d; read(op, u);
		if (op == 1) {
			int res = 0;
			for (int i = 0; i <= 20 && u; ++i, u = f[u][0])
				res += tr[i].ask(st[u], ed[u]);
			write(res, '\n');
		}
		else {
			read(v, k, d);
			int z = lca(u, v);
			tr[d].add(st[u], k), tr[d].add(st[v], k);
			tr[d].add(st[z], -2 * k);
			auto upd = [&] (int u, int i, int v) {
				if (i < 0) return;
				tr[i].add(st[u], v);
				if (f[u][0]) tr[i].add(st[f[u][0]], -v);
			};
			for (int i = d; i >= 0 && z; --i, z = f[z][0]) upd(z, i, k), upd(z, i - 1, k);
		}
	}
	return 0;
}