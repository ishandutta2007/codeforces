#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 200005, L = 18;
const LL INF = 9e18;

int n, q, dep[N], fa[N][L];

int head[N], numE = 0;

char buf[1<<23], *p1=buf, *p2=buf, obuf[1<<23], *O=obuf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)

struct E{
	int next, v;
} e[N << 1];

void inline read(int &x) {
	x = 0; char s = getchar();
	while (s > '9' || s < '0') s = getchar();
	while (s <= '9' && s >= '0') x = (x << 1) + (x << 3) + s - '0', s = getchar();
}

void inline add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE; 
}

void dfs(int u) {
	for (int i = 1; i < L && fa[u][i - 1]; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == fa[u][0]) continue;
		fa[v][0] = u, dep[v] = dep[u] + 1;
		dfs(v);
	}
}

int inline lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = L - 1; ~i; i--) 
		if (dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	for (int i = L - 1; ~i; i--)
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

int inline d(int x, int y, int p) {
	return dep[x] + dep[y] - 2 * dep[p];
}

LL exgcd(LL a, LL b, LL &x, LL &y) {
	if (b == 0) { x = 1, y = 0; return a; }
	LL d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

LL inline work1(LL a, LL b, LL T1, LL T2) {
	LL x, y, c = T2 - T1, D1 = a; LL d = exgcd(a, b, x, y);
	if (c % d) return INF;
	x *= c / d, y *= -c / d;
	a /= d, b /= d;
	if (x < 0 || y < 0) {
		LL k = max((- x - 1) / b + 1, (- y - 1) / a + 1);
		x += k * b, y += k * a;
	}
	LL k = min(x / b, y / a); x -= k * b;
	return x * D1 + T1;
}

LL G(LL L, LL R, LL D, LL P) {
	if (!D) return INF;
	if (R / D * D >= L) return (L + D - 1) / D;
	LL x = G(((-R) % D + D) % D, ((-L) % D + D) % D, P % D, D);
	if (x == INF) return INF;
	return (x * P + L + D - 1) / D;
}

LL inline work2(LL D1, LL D2, LL T1, LL T2, LL D) {
	if (D1 == 1 || D2 == 1) return INF;
	if ((D + T1 + T2) & 1) return INF;
	LL L = ((T2 - T1 - D) % D2 + D2) % D2, R = ((T2 - T1 + D) % D2 + D2) % D2;
	LL x1 = 0;
	if (L && L <= R && 2 * D < D2) x1 = G(L, R, D1 % D2, D2); 
	if (x1 == INF) return INF;
	LL x2 = (x1 * D1 + T1 - T2 + D) / D2;
	if (x1 * D1 + T1 - T2 - D >= 0) x2 = min(x2, (x1 * D1 + T1 - T2 - D + D2 - 1) / D2);
	return (x1 * D1 + x2 * D2 + T1 + T2 + D) / 2;
}

LL inline query(int u, int v, int x, int y) {
	int p[4] = { lca(u, x), lca(u, y), lca(v, x), lca(v, y)};
	int w = lca(u, v), z = lca(x, y);
	int p1 = 0, p2 = 0;
	for (int i = 0; i < 4; i++)
		if (dep[p[i]] > dep[p1]) p2 = p1, p1 = p[i];
		else if (dep[p[i]] > dep[p2]) p2 = p[i];
	if (p1 == p2 && (dep[p1] < dep[w] || dep[p1] < dep[z])) return -1;
	// p1 - p2 
	int D1 = d(u, v, w) * 2, D2 = d(x, y, z) * 2, D = d(p1, p2, lca(p1, p2));
	int U1 = d(u, p1, lca(u, p1)), U2 = d(u, p2, lca(u, p2));
	if (U1 < U2) U2 = D1 - U2;
	else U1 = D1 - U1;
	int X1 = d(x, p1, lca(x, p1)), X2 = d(x, p2, lca(x, p2));
	if (X1 < X2) X2 = D2 - X2;
	else X1 = D2 - X1;
	if (D1 == 0) D1 = 1;
	if (D2 == 0) D2 = 1;
	// U1 U1  p1 - p2  p1 
	LL res = min(work1(D1, D2, U1, X1), work1(D1, D2, U2, X2));
	res = min(res, min(work2(D1, D2, U1, X2, D), work2(D1, D2, U2, X1, D)));
	return res == INF ? -1 : res;
}

int main() {
	read(n);
	for (int i = 1, u, v; i < n; i++)
		read(u), read(v), add(u, v), add(v, u);
	dep[1] = 1, dfs(1);
	read(q);
	while (q--) {
		int u, v, x, y; read(u), read(v), read(x), read(y);
		printf("%lld\n", query(u, v, x, y));
	}
	return 0;
}