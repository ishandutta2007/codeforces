#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
	f = 0; _T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 1e6 + 5;

struct tree_t {
	int lc[N], rc[N], f[N], siz[N];
	int tot;

	int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

	void ini(int n) {
		for (int i = 1; i <= n; i++) f[i] = i, siz[i] = 1;
		tot = n;
	}

	void merge(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		++tot; f[tot] = f[x] = f[y] = tot; lc[tot] = x; rc[tot] = y; siz[tot] = siz[x] + siz[y];
	}
} tr1, tr2;

char opt[N];
vector <int> t1[N], t2[N], q[N];
ll f[N], ans[N];
int x[N], y[N];
int n, m, qcnt;

inline int lowbit(int x) { return x & -x; }

inline void add(int x, int y) {
	while (x <= m) {
		f[x] += y;
		x += lowbit(x);
	}
}

inline ll query(int x) {
	ll ans = 0;
	while (x) {
		ans += f[x];
		x ^= lowbit(x);
	}
	return ans;
}

set <int> now;
void dfs2(int u) {
	for (auto i : t2[u]) now.insert(i);
	for (auto i : q[u]) {
		auto it = now.lower_bound(i);
		if (it != now.begin()) --it, ans[i] = *it;
	}
	if (tr2.lc[u]) dfs2(tr2.lc[u]), dfs2(tr2.rc[u]);
	for (auto i : t2[u]) now.erase(i);
}

void dfs1(int u) {
	for (auto i : t1[u]) add(i, tr1.siz[u]);
	for (auto i : q[u]) ans[i] = query(i) - query(ans[i]);
	if (tr1.lc[u]) dfs1(tr1.lc[u]), dfs1(tr1.rc[u]);
	for (auto i : t1[u]) add(i, -tr1.siz[u]);
}

int main() {
	read(n); read(m); tr1.ini(n); tr2.ini(n);
	for (int i = 1; i <= m; i++) {
		opt[i] = getchar();
		while (opt[i] < 'A' || opt[i] > 'Z') opt[i] = getchar();
		if (opt[i] == 'U' || opt[i] == 'M') read(x[i]), read(y[i]);
		else read(x[i]);
		if (opt[i] == 'U') tr1.merge(x[i], y[i]);
		if (opt[i] == 'M') tr2.merge(x[i], y[i]);
		if (opt[i] == 'A') t1[tr1.find(x[i])].push_back(i);
		if (opt[i] == 'Z') t2[tr2.find(x[i])].push_back(i);
		if (opt[i] == 'Q') q[x[i]].push_back(i);
	}
	for (int i = 1; i <= tr2.tot; i++) if (tr2.find(i) == i) dfs2(i);
	for (int i = 1; i <= tr1.tot; i++) if (tr1.find(i) == i) dfs1(i);
	for (int i = 1; i <= m; i++) if (opt[i] == 'Q') print(ans[i], '\n');
	return 0;
}