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

const int N = 2e5 + 5;

struct edge_t { int u, v, next, w; } G[N << 1];

int head[N], a[N], siz[N], maxn[N], vis[N];
int n, tot, allsize, root;

inline void addedge(int u, int v, int w) {
	G[++tot] = (edge_t) {u, v, head[u], w}, head[u] = tot;
}

void getroot(int u, int fa) {
	siz[u] = 1; maxn[u] = 0;
	for (int i = head[u]; i; i = G[i].next) {
		int v = G[i].v;
		if (vis[v] || v == fa) continue;
		getroot(v, u); siz[u] += siz[v];
		maxn[u] = max(maxn[u], siz[v]);
	}
	maxn[u] = max(maxn[u], allsize - siz[u]);
	if (maxn[u] < maxn[root]) root = u;
}

double getans(int u, int fa, int dis) {
	double ans = dis * sqrt(dis) * a[u];
	for (int i = head[u]; i; i = G[i].next) {
		int v = G[i].v;
		if (v == fa) continue;
		ans += getans(v, u, dis + G[i].w);
	}
	return ans;
}

double getdao(int u, int fa, int dis) {
	double ans = 1.5 * sqrt(dis) * a[u];
	for (int i = head[u]; i; i = G[i].next) {
		int v = G[i].v;
		if (v == fa) continue;
		ans += getdao(v, u, dis + G[i].w);
	}
	return ans;
}

int solve(int u) {
	vis[u] = 1;
	double maxn = -1; int id = 0;
	for (int i = head[u]; i; i = G[i].next) {
		int v = G[i].v;
		if (vis[v]) continue;
		double dao = getdao(v, u, G[i].w);
		if (dao > maxn) maxn = dao, id = v;
	}
	if (!id || getans(id, 0, 0) >= getans(u, 0, 0)) return u;
	if (siz[id] > siz[u]) allsize -= siz[u];
	else allsize = siz[id];
	root = 0; getroot(id, u);
	return solve(root);
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i < n; i++) { 
		int u, v, w;
		read(u); read(v); read(w);
		addedge(u, v, w);
		addedge(v, u, w);
	}
	maxn[0] = n + 1; allsize = n; root = 0; getroot(1, 0);
	int rt = solve(root);
	printf("%d %.10lf\n", rt, getans(rt, 0, 0));
	return 0;
}