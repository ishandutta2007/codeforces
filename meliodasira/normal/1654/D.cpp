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

const int P = 998244353;

int add(int x, int y) {
	if (x + y >= P) return x + y - P;
	return x + y;
}

int sub(int x, int y) {
	if (x < y) return x - y + P;
	return x - y;
}

int mul(int x, int y) { return 1ull * x * y % P; }

int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1;
		x = mul(x, x);
	}
	return ans;
}

const int N = 2e5 + 5;

struct edge_t {
	int u, v, nxt, x, y;
} G[N << 1];

vector<int> g[N];
int cnt[N], head[N], mn[N];
int T, n, tot, ans;

inline void addedge(int u, int v, int x, int y) {
	G[++tot] = (edge_t) { u, v, head[u], x, y }, head[u] = tot;
	G[++tot] = (edge_t) { v, u, head[v], y, x }, head[v] = tot;
}

void Add(int x, int det) {
	for (auto i: g[x]) {
		cnt[i] += det;
	}
}

void upd(int x) {
	for (auto i: g[x]) {
		mn[i] = min(mn[i], cnt[i]);
	}
}

void dfs1(int u, int fa, int now) {
	ans = add(ans, now);
	for (int i = head[u]; i; i = G[i].nxt) {
		int v = G[i].v;
		if (v == fa) continue;
		Add(G[i].x, -1);
		Add(G[i].y, 1);
		upd(G[i].x);
		dfs1(v, u, mul(now, mul(G[i].y, fpow(G[i].x, P - 2))));
		Add(G[i].x, 1);
		Add(G[i].y, -1);
	}
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	rep(i, 2, 200000) {
		if (!g[i].size()) {
			rep(j, 1, 200000 / i) {
				int x = i * j;
				while (x % i == 0) g[i * j].push_back(i), x /= i;
			}
		}
	}
	T = read();
	while (T--) {
		tot = 0;
		n = read();
		rep(i, 1, n) head[i] = cnt[i] = mn[i] = 0;
		rep(i, 1, n - 1) {
			int u = read(), v = read(), x = read(), y = read();
			addedge(u, v, x, y);
		}
		ans = 0;
		dfs1(1, 0, 1);
		rep(i, 2, n) {
			while (mn[i] < 0) {
				ans = mul(ans, i);
				++mn[i];
			}
		}
		printf("%d\n", ans);
	}
}