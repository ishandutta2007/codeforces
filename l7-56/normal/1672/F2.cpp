#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
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

const int maxn = 2e5 + 10;
int n,a[maxn],b[maxn],cnt[maxn];
struct Edge {
	int v, nxt;
} e[maxn];
int h[maxn], cnt_e, vis[maxn];
void add(int x, int y) { e[++cnt_e] = {y, h[x]}, h[x] = cnt_e, vis[cnt_e] = 0; }

int ins[maxn];
bool dfs(int u) {
	ins[u] = 1;
	for (int &j = h[u]; j; j = e[j].nxt) {
		if (vis[j]) continue;
		vis[j] = 1;
		int v = e[j].v;
		if (ins[v]) return 1;
		if (dfs(v)) return 1;
	}
	ins[u] = 0;
	return 0;
}

void work() {
	read(n);
	for (int i = 1; i <= n; ++i) cnt[i] = 0;
	for (int i = 1; i <= n; ++i) read(a[i]), cnt[a[i]]++;
	for (int i = 1; i <= n; ++i) read(b[i]);
	int mxcnt = 0;
	for (int i = 1; i <= n; ++i) mxcnt = max(mxcnt, cnt[i]);
	cnt_e = 0;
	for (int i = 1; i <= n; ++i) h[i] = 0, ins[i] = 0;
	for (int o = 1; o <= n; ++o)
		if (cnt[o] == mxcnt) {
			for (int i = 1; i <= n; ++i)
				if (a[i] != o && b[i] != o) add(a[i], b[i]);
			for (int i = 1; i <= n; ++i)
				if (dfs(i)) return printf("WA\n"), void();
			printf("AC\n");
			return;
		}
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}