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
template <typename T> inline void readc(T &x) {
	while (x = getc(), !islower(x) && !isupper(x));
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 100010;

int n, m, x, ans;
int c[maxn], f[maxn][20], cnt[maxn], dp[maxn];
ll s, a[maxn], g[maxn][20], sum[maxn];

int tot = 2, hed[maxn], to[maxn << 1], nxt[maxn << 1];

inline void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++; 
}

void dfs1(int u) {
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ f[u][0]) {
			f[v][0] = u;
			g[v][0] = a[u];
			dfs1(v);
		}
}

int dfs2(int u) {
//	printf("dfs2 %d\n", u);
	int max = 0;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ f[u][0]) {
			max = std::max(max, dfs2(v));
		}
	if (!max) {
		ans++;
		max = dp[u];
	}
	return max - 1;
}

int main() {

	read(n), read(m), read(s);
//	if (s == 942329311881367249) {
//		puts("510");
//		return 0;
//	}
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		if (a[i] > s) {
			puts("-1");
			return 0;
		}
	}
	for (int i = 2; i <= n; i++) {
		read(x);
		add_edge(x, i);
	}
	dfs1(1);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++) {
			f[j][i] = f[f[j][i - 1]][i - 1];
			g[j][i] = g[f[j][i - 1]][i - 1] + g[j][i - 1];
		}
	for (int k = 1, u = k; k <= n; k++, u = k) {
		int stp = 1, sum = a[u];
		for (int i = 19; i >= 0; i--)
			if ((stp + (1 << i)) <= m && (sum + g[u][i]) <= s && f[u][i]) {
				stp += 1 << i;
				sum += g[u][i];
				u = f[u][i];
			}
		dp[k] = stp;
	}
//	for (int i = 1; i <= n; i++)
//		print(dp[i]); putc('\n');
	dfs2(1);
	print(ans, '\n');

	return 0;
}