#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
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

const int maxn = 1e6 + 10, inf = 1e9;
int nl, nr, n, m, q, s, t, match[maxn];
pii edge[maxn];
struct Edge {
	int v, w, nxt;
} e[maxn << 1];
int h[maxn], cnt_e = 1;
void add(int x, int y, int z) {
	e[++cnt_e] = {y, z, h[x]}, h[x] = cnt_e;
	e[++cnt_e] = {x, 0, h[y]}, h[y] = cnt_e;
}

int dep[maxn], now[maxn];
int bfs() {
	memset(dep, 0, sizeof dep);
	queue <int> q;
	dep[s] = 1, now[s] = h[s], q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int j = h[u]; j; j = e[j].nxt) {
			int v = e[j].v, w = e[j].w;
			if (!w || dep[v]) continue;
			dep[v] = dep[u] + 1, now[v] = h[v], q.push(v);
			if (v == t) return 1;
		}
	}
	return 0;
}

int dfs(int u, int in) {
	if (u == t) return in;
	int rst = in;
	for (int &j = now[u]; j; j = e[j].nxt) {
		int v = e[j].v, w = e[j].w;
		if (!w || dep[v] != dep[u] + 1) continue;
		int out = dfs(v, min(rst, w));
		if (!out) dep[v] = 0;
		e[j].w -= out, e[j ^ 1].w += out, rst -= out;
		if (!rst) break;
	}
	return in - rst;
}

int dinic() {
	int maxflow = 0;
	while (bfs()) maxflow += dfs(s, inf);
	return maxflow;
}

int main() {
	read(nl, nr, m, q); n = nl + nr, s = n + 1, t = s + 1;
	for (int i = 1; i <= m; ++i) {
		read(edge[i].fir, edge[i].sec);
		add(edge[i].fir, edge[i].sec + nl, 1);
	}
	for (int i = 1; i <= nl; ++i) add(s, i, 1);
	for (int i = 1; i <= nr; ++i) add(i + nl, t, 1);

	ll ans = 0;
	int flow = dinic();
	for (int i = 1; i <= m; ++i) if (e[i * 2].w == 0)
		match[edge[i].fir] = match[edge[i].sec + nl] = i, ans += i;

	queue <int> nodes;
	for (int i = 1; i <= nl; ++i) if (!dep[i]) nodes.push(i);
	for (int i = nl + 1; i <= n; ++i) if (dep[i]) nodes.push(i);
	while (q--) {
		int opt; read(opt);
		if (opt == 1) {
			int u = nodes.front(); nodes.pop();
			int i = match[u];
			ans -= i, e[i * 2].w = 1, flow--;
			write(1, '\n', u <= nl ? u : nl - u, '\n', ans, '\n');
		}
		else {
			write(flow, '\n');
			for (int i = 1; i <= m; ++i)
				if (e[i * 2].w == 0) write(i, ' ');
			write('\n');
		}
		fflush(stdout);
	}
	return 0;
}