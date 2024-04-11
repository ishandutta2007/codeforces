#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T& x, const T& y) {
	if (x > y) x = y;
}
template<typename T>
void chmax(T& x, const T& y) {
	if (x < y) x = y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int, int> pii;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define rep0(i, l, r) for (int i = l; i < r; ++i)
#define gc (c = getchar())
char readc() {
	char c;
	while (isspace(gc))
		;
	return c;
}
int read() {
	char c;
	while (gc < '-')
		;
	if (c == '-') {
		int x = gc - '0';
		while (gc >= '0') x = x * 10 + c - '0';
		return -x;
	}
	int x = c - '0';
	while (gc >= '0') x = x * 10 + c - '0';
	return x;
}
#undef gc

const int N = 2e5 + 5;

struct edge {
	int u, v;
	edge(int a = 0, int b = 0): u(a), v(b) {}
} e[N];

vector<int> adj[N];
int f[N], tops[N], dep[N], siz[N], x[N], y[N], s[N], par[N][20];
int n, m, tot, len;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void dfs1(int u, int fa) {
	tops[u] = ++tot;
	siz[u] = 1;
	par[u][0] = fa;
	rep(i, 1, 19) par[u][i] = par[par[u][i - 1]][i - 1];
	for (auto v: adj[u]) {
		if (v == fa) continue;
		dep[v] = dep[u] + 1;
		dfs1(v, u);
		siz[u] += siz[v];
	}
}

int jump(int u, int v) {
	int len = dep[u] - dep[v] - 1;
	for (int i = 0; i <= 19; i++) {
		if ((len >> i) & 1) {
			u = par[u][i];
		}
	}
	return u;
}

bool insub(int u, int v) {
	return tops[u] >= tops[v] && tops[u] < tops[v] + siz[v];
}

void cover(int l, int r) {
	++s[l];
	--s[r + 1];
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	m = read();
	rep(i, 1, n) f[i] = i;
	rep(i, 1, m) e[i].u = read(), e[i].v = read();
	rep(i, 1, m) {
		int x = find(e[i].u), y = find(e[i].v);
		if (x != y) {
			adj[e[i].u].push_back(e[i].v);
			adj[e[i].v].push_back(e[i].u);
			f[x] = y;
		} else {
			++len;
			::x[len] = e[i].u;
			::y[len] = e[i].v;
		}
	}
	dfs1(1, 0);
	rep(i, 1, len) {
		if (insub(y[i], x[i])) swap(x[i], y[i]);
		if (insub(x[i], y[i])) {
			cover(tops[x[i]], tops[x[i]] + siz[x[i]] - 1);
			int t = jump(x[i], y[i]);
			cover(1, tops[t] - 1);
			cover(tops[t] + siz[t], n);
		} else {
			cover(tops[x[i]], tops[x[i]] + siz[x[i]] - 1);
			cover(tops[y[i]], tops[y[i]] + siz[y[i]] - 1);
		}
	}
	rep(i, 1, n) s[i] += s[i - 1];
	rep(i, 1, n) printf("%d", (int)(s[tops[i]] == len));
	printf("\n");
}