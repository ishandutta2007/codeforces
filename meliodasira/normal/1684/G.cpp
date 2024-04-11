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

const int INF = 1e9;

struct max_flow_t {
	struct edge_t {
		int u, v, next, cap, flow;
		edge_t() {}
		edge_t(int a, int b, int c, int d, int e): u(a), v(b), next(c), cap(d), flow(e) {}
	};

	vector<edge_t> G;
	vector<int> head, nowhead, d;
	int n, s, t, tot;

	max_flow_t() {
		G.clear();
		head.clear();
		tot = 1;
	}
	max_flow_t(int nn) {
		n = nn;
		s = 0;
		t = n + 1;
		G.clear();
		head.clear();
		head.resize(n + 2, 0);
		tot = 1;
	}

	inline void addedge(int u, int v, int cap) {
		G.resize(tot + 3);
		G[++tot] = (edge_t) { u, v, head[u], cap, 0 }, head[u] = tot;
		G[++tot] = (edge_t) { v, u, head[v], 0, 0 }, head[v] = tot;
	}

	int bfs() {
		d.clear();
		d.resize(n + 2, 0);
		d[s] = 1;
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int i = head[u]; i; i = G[i].next) {
				int v = G[i].v;
				if (G[i].cap > G[i].flow && d[v] == 0) {
					d[v] = d[u] + 1;
					q.push(v);
				}
			}
		}
		return d[t];
	}

	int dfs(int u, int Flow) {
		if (u == t || !Flow) return Flow;
		int flow = 0, f;
		for (int& i = nowhead[u]; i; i = G[i].next) {
			int v = G[i].v;
			if (d[v] == d[u] + 1 && (f = dfs(v, min(Flow, G[i].cap - G[i].flow))) > 0) {
				G[i].flow += f;
				G[i ^ 1].flow -= f;
				flow += f;
				Flow -= f;
				if (!Flow) break;
			}
		}
		return flow;
	}

	int dinic() {
		int ans = 0;
		while (bfs()) {
			nowhead = head;
			ans += dfs(s, INF);
		}
		return ans;
	}
} M;

const int N = 1005;

vector<pii> ans;
int a[N], opt[N], used[N];
int n, m;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		if (a[i] * 2 >= m) {
			printf("-1\n");
			return 0;
		}
	}
	M = max_flow_t(n);
	int need = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] * 3 > m) {
			M.addedge(M.s, i, 1);
			++need;
			opt[i] = 1;
		} else {
			M.addedge(i, M.t, 1);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (opt[i] == 1 && opt[j] == 0 && a[i] % a[j] == 0 && a[i] * 2 + a[j] <= m) {
				M.addedge(i, j, 1);
			}
		}
	}
	if (M.dinic() != need) {
		printf("-1\n");
		return 0;
	}
	for (int u = 1; u <= n; u++) {
		if (!opt[u]) continue;
		for (int i = M.head[u]; i; i = M.G[i].next) {
			int v = M.G[i].v;
			if (v >= 1 && v <= n && M.G[i].flow) {
				ans.emplace_back(a[u] * 2 + a[v], a[u] + a[v]);
				used[u] = used[v] = 1;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			ans.emplace_back(a[i] * 3, a[i] * 2);
		}
	}
	printf("%d\n", (int)ans.size());
	for (auto i: ans) printf("%d %d\n", i.first, i.second);
}