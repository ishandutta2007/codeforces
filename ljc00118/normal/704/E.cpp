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

const double eps = 1e-10;
const int N = 1e5 + 5;

vector <int> adj[N];
int siz[N], wson[N], top[N], tops[N], fa[N], d[N], id[N];
int n, m, dfn, tot;

void dfs1(int u) {
	siz[u] = 1;
	for (auto v : adj[u]) {
		if (v == fa[u]) continue;
		fa[v] = u; d[v] = d[u] + 1; dfs1(v); siz[u] += siz[v];
		id[v] = tot; tot += 2;
		if (siz[v] > siz[wson[u]]) wson[u] = v;
	}
}

void dfs2(int u, int tp) {
	tops[u] = ++dfn; top[u] = tp;
	if (wson[u]) dfs2(wson[u], tp);
	for (auto v : adj[u]) {
		if (v == fa[u] || v == wson[u]) continue;
		dfs2(v, v);
	}
}

vector <pii> getpath(int u, int v) {
	vector <pii> p[2];
	int opt = 0;
	while (top[u] != top[v]) {
		if (d[top[u]] < d[top[v]]) swap(u, v), opt ^= 1;
		p[opt].push_back(make_pair(u, top[u]));
		u = fa[top[u]];
	}
	if (d[u] < d[v]) swap(u, v), opt ^= 1;
	p[opt].push_back(make_pair(u, v));
	for (int i = (int)p[1].size() - 1; i >= 0; i--) p[0].push_back(make_pair(p[1][i].second, p[1][i].first));
	return p[0];
}

struct ele {
	double st, ed;
	int v, pos;
};

double TT, ans = 1e18;
bool operator < (const ele a, const ele b) {
	double ap = a.pos + (TT - a.st) * a.v;
	double bp = b.pos + (TT - b.st) * b.v;
	if (fabs(ap - bp) <= eps) return 0;
	return ap < bp;
}

bool operator == (const ele a, const ele b) {
	return !(a < b) && !(b < a);
}

set <ele> all;

struct naive {
	ele val;
	double t;
	int opt;
};

bool operator < (const naive a, const naive b) {
	if (fabs(a.t - b.t) < eps) return a.opt > b.opt;
	return a.t < b.t;
}

vector <naive> e;

void solve(ele a, ele b) {
	double ap = a.pos + (TT - a.st) * a.v;
	double bp = b.pos + (TT - b.st) * b.v;
	// fprintf(stderr, "%d %d %.6lf %.6lf %.6lf %.6lf\n", a.pos, b.pos, a.st, b.st, a.ed, b.ed);
	if (fabs(ap - bp) < eps) ans = min(ans, TT);
	if (a.v == b.v) return;
	double T = (bp - ap) / (a.v - b.v);
	if (T < 0) return;
	T += TT; T -= eps;
	if (T <= a.ed && T <= b.ed) ans = min(ans, T);
}

int main() {
	read(n); read(m); tot = n + 1;
	for (int i = 1; i < n; i++) {
		int u, v;
		read(u); read(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1); dfs2(1, 1);
	for (int i = 1; i <= m; i++) {
		int t, c, u, v;
		read(t); read(c); read(u); read(v);
		vector <pii> p = getpath(u, v);
		double nowt = t;
		for (int j = 0; j < (int)p.size(); j++) {
			ele now;
			if (tops[p[j].first] <= tops[p[j].second]) now = (ele) {nowt, nowt + (double)(d[p[j].second] - d[p[j].first]) / c, c, tops[p[j].first]};
			else now = (ele) {nowt, nowt + (double)(d[p[j].first] - d[p[j].second]) / c, -c, tops[p[j].first]};
			e.push_back((naive) {now, nowt, 1}); nowt = now.ed; e.push_back((naive) {now, nowt, -1});
			if (j == (int)p.size() - 1) break;
			int x = p[j].second, y = p[j + 1].first;
			if (tops[x] > tops[y]) {
				now = (ele) {nowt, nowt + 1.0 / c, c, id[x]};
				e.push_back((naive) {now, nowt, 1}); nowt = now.ed; e.push_back((naive) {now, nowt, -1});
			} else {
				now = (ele) {nowt, nowt + 1.0 / c, -c, id[y] + 1};
				e.push_back((naive) {now, nowt, 1}); nowt = now.ed; e.push_back((naive) {now, nowt, -1});
			}
		}
	}
	sort(e.begin(), e.end());
	for (auto i : e) {
		TT = i.t;
		if (TT > ans) break;
		if (i.opt == -1) {
			auto it = all.upper_bound(i.val), it2 = it;
			--it2;
			if (it != all.end() && it2 != all.begin()) {
				--it2;
				solve(*it, *it2);
			}
			all.erase(i.val);
			continue;
		}
		auto it = all.lower_bound(i.val);
		if (it != all.end()) solve(i.val, *it);
		if (it != all.begin()) --it, solve(i.val, *it);
		all.insert(i.val);
	}
	if (fabs(ans - 1e18) <= eps) puts("-1");
	else printf("%.7lf\n", ans);
	return 0;
}