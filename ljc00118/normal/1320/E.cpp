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

const int N = 2e5 + 5, INF = 0x7fffffff;

struct ele {
	int u, dis, col;
	ele (int a = 0, int b = 0, int c = 0) : u(a), dis(b), col(c) {}
};

priority_queue <ele> Q;
vector <int> adj[N]; vector <pii> fuck[N];
int fa[N][18], tops[N], dep[N], po[N], st[N], used[N], col[N], v[N], s[N], dis[N], qry[N];
int n, m1, m2, q, dfn, top, len;

bool operator < (ele a, ele b) {
	if (a.dis >= 0 && b.dis >= 0) {
		if ((a.dis + s[abs(a.col)] - 1) / s[abs(a.col)] != (b.dis + s[abs(b.col)] - 1) / s[abs(b.col)]) return (a.dis + s[abs(a.col)] - 1) / s[abs(a.col)] < (b.dis + s[abs(b.col)] - 1) / s[abs(b.col)];
	} else {
		a.dis = -a.dis; b.dis = -b.dis;
		if ((a.dis + s[abs(a.col)] - 1) / s[abs(a.col)] != (b.dis + s[abs(b.col)] - 1) / s[abs(b.col)]) return (a.dis + s[abs(a.col)] - 1) / s[abs(a.col)] > (b.dis + s[abs(b.col)] - 1) / s[abs(b.col)];
	}
	return a.col < b.col;
}

void dfs1(int u) {
	tops[u] = ++dfn;
	for (int i = 1; i <= 17; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (auto v : adj[u]) {
		if (v == fa[u][0]) continue;
		fa[v][0] = u; dep[v] = dep[u] + 1; dfs1(v);
	}
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 17; i >= 0; i--) {
		if (dep[fa[u][i]] >= dep[v]) {
			u = fa[u][i];
		}
	}
	if (u == v) return u;
	for (int i = 17; i >= 0; i--) {
		if (fa[u][i] != fa[v][i]) {
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}

bool cmp(int x, int y) { return tops[x] < tops[y]; }

void addedge(int u, int v) {
	// if (!u || !v) {
	// 	printf("fuck %d %d\n", u, v);
	// 	exit(0);
	// }
	fuck[u].emplace_back(v, abs(dep[u] - dep[v]));
	fuck[v].emplace_back(u, abs(dep[u] - dep[v]));
}

int main() {
	read(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		read(u); read(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dep[1] = 1; dfs1(1);
	read(q);
	while (q--) {
		read(m1); read(m2); len = 0;
		for (int i = 1; i <= m1; i++) read(v[i]), read(s[i]), used[v[i]] = 1, po[++len] = v[i];
		for (int i = 1; i <= m2; i++) {
			read(qry[i]);
			if (!used[qry[i]]) {
				used[qry[i]] = 1;
				po[++len] = qry[i];
			}
		}
		sort(po + 1, po + len + 1, cmp);
		st[top = 1] = 1; fuck[1].clear(); dis[1] = INF;
		for (int i = 1; i <= len; i++) {
			if (po[i] == 1) continue;
			int tmp = lca(po[i], st[top]);
			if (tmp != st[top]) {
				while (dep[tmp] < dep[st[top - 1]]) {
					// if (!st[top - 1] || !st[top]) {
					// 	printf("fuck1 %d %d\n", st[top - 1], st[top]);
					// 	return 0;
					// }
					addedge(st[top - 1], st[top]);
					--top;
				}
				if (dep[tmp] > dep[st[top - 1]]) {
					fuck[tmp].clear(); dis[tmp] = INF;
					// if (!tmp || !st[top]) {
					// 	printf("fuck2 %d %d\n", tmp, st[top]);
					// 	return 0;
					// }
					addedge(tmp, st[top]);
					st[top] = tmp;
				} else {
					// if (!st[top - 1] || !st[top]) {
					// 	printf("fuck3 %d %d %d %d\n", po[i], tmp, st[top - 1], st[top]);
					// 	return 0;
					// }
					addedge(st[top - 1], st[top]), --top;
				}
			}
			fuck[po[i]].clear(); dis[po[i]] = INF; st[++top] = po[i];
		}
		while (top > 1) {
			// if (!st[top - 1] || !st[top]) {
			// 	printf("fuck4 %d %d\n", st[top - 1], st[top]);
			// 	return 0;
			// }
			addedge(st[top - 1], st[top]), --top;
		}
		for (int i = 1; i <= m1; i++) dis[v[i]] = 0, col[v[i]] = i, Q.push(ele(v[i], 0, -i));
		while (!Q.empty()) {
			ele u = Q.top(); Q.pop();
			if (-u.dis != dis[u.u] || -u.col != col[u.u]) continue;
			for (auto i : fuck[u.u]) {
				ele go = ele(i.first, dis[u.u] + i.second, col[u.u]);
				// if (dis[i.first] != INF && col[i.first] == 0) {
				// 	cout << "fuck you " << u.u << " " << i.first << " " << used[i.first] << " " << dis[i.first] << endl;
				// 	return 0;
				// }
				if (dis[i.first] == INF || go < ele(i.first, dis[i.first], col[i.first])) {
					dis[i.first] = go.dis; col[i.first] = go.col;
					Q.push(ele(go.u, -go.dis, -go.col));
				}
			}
		}
		for (int i = 1; i <= m2; i++) print(col[qry[i]], i == m2 ? '\n' : ' ');
		for (int i = 1; i <= len; i++) used[po[i]] = 0;
	}
	return 0;
}