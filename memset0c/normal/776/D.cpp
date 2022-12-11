// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void print(T x, char c = '\n') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 200010, maxm = 400010;

int n, m, t, x, cnt, pos, top;
int a[maxn], b[maxn][2], low[maxn], dfn[maxn], stk[maxn], ins[maxn], col[maxn];

int tot = 2, hed[maxn], nxt[maxm], to[maxm];

inline void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v;
	hed[u] = tot++;
//	printf("add edge %d %d\n", u, v);
}

void tarjan(int u) {
	dfn[u] = low[u] = ++pos;
	ins[u] = 1, stk[++top] = u;
	for (int i = hed[u]; i; i = nxt[i]) {
		int v = to[i];
		if (!dfn[v]) {
			tarjan(v);
			low[u] = std::min(low[u], low[v]);
		} else if (ins[v]) {
			low[u] = std::min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		++cnt;
		while (top) {
			int v = stk[top--];
			col[v] = cnt;
			ins[v] = 0;
			if (u == v) break;
		}
	}
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= m; i++) {
		read(t);
		for (int j = 1; j <= t; j++) {
			read(x);
			b[x][b[x][0] ? 1 : 0] = i;
		}
	}

//	for (int i = 1; i <= n; i++)
//		print(b[i][0], ' ');
//	putc('\n');
//	for (int i = 1; i <= n; i++)
//		print(b[i][1], ' ');
//	putc('\n');
	for (int i = 1; i <= n; i++)
		if (a[i]) {
//			printf("=== %d %d ===\n", i, a[i]);
			add_edge(b[i][0], b[i][1]);
			add_edge(b[i][1], b[i][0]);
			add_edge(b[i][0] + m, b[i][1] + m);
			add_edge(b[i][1] + m, b[i][0] + m);
		} else {
//			printf("=== %d %d ===\n", i, a[i]);
			add_edge(b[i][0], b[i][1] + m);
			add_edge(b[i][1] + m, b[i][0]);
			add_edge(b[i][1], b[i][0] + m);
			add_edge(b[i][0] + m, b[i][1]);
		}
	
	for (int i = 1; i <= (m << 1); i++)
		if (!dfn[i])
			tarjan(i);
	
//	for (int i = 1; i <= (m << 1); i++)
//		print(col[i], ' ');
//	putc('\n');
	for (int i = 1; i <= (m << 1); i++)
		if (col[i] == col[i + m]) {
			puts("NO");
			return 0;
		}
	puts("YES");

	return 0;
}