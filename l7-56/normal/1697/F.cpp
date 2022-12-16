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

const int maxn = 1e6 + 10, maxm = 1e7 + 10;
int n, m, K, id[200010][20][2], idx;

struct Edge {
	int v, nxt;
} e[maxm];
int h[maxn], cnt_e;
void add(int x, int y) { e[++cnt_e] = {y, h[x]}, h[x] = cnt_e; }

int dfn[maxn], low[maxn], tim, sta[maxn], tp, ins[maxn], scc[maxn], cnt_scc;
void dfs(int u) {
	dfn[u] = low[u] = ++tim;
	ins[sta[++tp] = u] = 1;
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if (!dfn[v]) dfs(v), low[u] = min(low[u], low[v]);
		else if (ins[v]) low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		int x; ++cnt_scc;
		do {
			x = sta[tp--];
			ins[x] = 0, scc[x] = cnt_scc;
		} while (x != u);
	}
}

void add1(int i, int j, int x) { add(id[i][j][x ^ 1], id[i][j][x]); } // (i, j) = x
void add1(int i, int j, int x, int a, int b, int y) {
	add(id[i][j][x ^ 1], id[a][b][y]);
	add(id[a][b][y ^ 1], id[i][j][x]);
} // (i, j) = x / (a, b) = y

void work() {
	read(n, m, K);
	idx = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= K; ++j)
			id[i][j][0] = ++idx, id[i][j][1] = ++idx;

	cnt_e = cnt_scc = tim = tp = 0;
	for (int i = 1; i <= idx; ++i) h[i] = dfn[i] = low[i] = ins[i] = scc[i] = 0;
	for (int i = 1; i <= n; ++i) {
		add1(i, 0, 0), add1(i, K, 1);
		for (int j = 0; j < K; ++j)
			add1(i, j, 0, i, j + 1, 1);
	}
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < K; ++j)
			add1(i, j, 1, i + 1, j, 0);
	while (m--) {
		int i, j, x, op; read(op);
		if (op == 1) read(i, x), add1(i, x - 1, 1, i, x, 0);
		else {
			read(i, j, x);
			for (int k = 0; k <= K; ++k) {
				int l = x - k - 1;
				if (0 <= l && l <= K) add1(i, k, op == 2, j, l, op == 2);
			}
		}
	}

	for (int i = 1; i <= idx; ++i) if (!dfn[i]) dfs(i);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= K; ++j)
			if (scc[id[i][j][0]] == scc[id[i][j][1]]) return write("-1\n"), void();
	for (int i = 1; i <= n; ++i) {
		int a = 0;
		for (int j = 1; j <= K; ++j)
			if (scc[id[i][j][1]] < scc[id[i][j][0]]) { a = j; break; }
		write(a, " \n"[i == n]);
	}
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}