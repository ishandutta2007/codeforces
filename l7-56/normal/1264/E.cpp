#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
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

const int maxn = 60, maxm = 1e6 + 10, inf = 1e9;
int n, m, mp[maxn][maxn], s, t, id[maxn][maxn], idx;
struct Edge {
	int v, w, c, nxt;
} e[maxm];
int h[maxm], cnt_e = 1;
void add(int x, int y, int w, int c) {
	e[++cnt_e] = {y, w, c, h[x]}, h[x] = cnt_e;
	e[++cnt_e] = {x, 0, -c, h[y]}, h[y] = cnt_e;
}

int val[maxm], pre[maxm], dis[maxm];
bool spfa() {
	for (int i = 1; i <= t; ++i) dis[i] = inf, val[i] = 0;
	queue <int> q;
	val[s] = inf, q.push(s), dis[s] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int j = h[u]; j; j = e[j].nxt) {
			int v = e[j].v, w = e[j].w, c = e[j].c;
			if (!w || dis[v] <= dis[u] + c) continue;
			val[v] = min(val[u], w), pre[v] = j, q.push(v), dis[v] = dis[u] + c;
		}
	}
	return val[t] > 0;
}

int maxflow, cost;
void update() {
	int flow = val[t]; maxflow += flow;
	for (int nw = t; nw != s; nw = e[pre[nw] ^ 1].v) {
		int j = pre[nw];
		e[j].w -= flow, e[j ^ 1].w += flow, cost += e[j].c * flow;
	}
}

int main() {
	read(n, m);
	idx = n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			mp[i][j] = mp[j][i] = 2, id[i][j] = ++idx;
	s = ++idx, t = ++idx;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < n - 1; ++j)
			add(i, t, 1, j);
	for (int i = 1; i <= m; ++i) {
		int u, v; read(u, v);
		mp[u][v] = 1, mp[v][u] = 0;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j) {
			add(s, id[i][j], 1, 0);
			if (mp[i][j] == 2) add(id[i][j], i, 1, 0), add(id[i][j], j, 1, 0);
			else if (mp[i][j] == 1) add(id[i][j], i, 1, 0);
			else add(id[i][j], j, 1, 0);
		}
	while (spfa()) update();
	// write(n * (n - 1) * (n - 2) / 6 - cost, '\n');
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j) {
			int u = id[i][j];
			for (int o = h[u]; o; o = e[o].nxt) {
				int v = e[o].v, w = e[o].w;
				if (!w && v == i) mp[i][j] = 1, mp[j][i] = 0;
				if (!w && v == j) mp[i][j] = 0, mp[j][i] = 1;
			}
		}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) write(mp[i][j]);
		write('\n');
	}
	return 0;
}