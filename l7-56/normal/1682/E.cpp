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

const int maxn = 2e5 + 10;
int n, m, p[maxn];
map <pii, int> id;
vector <int> to[maxn];
int pos[maxn];

int now[maxn], usd[maxn];
void dfs(int u) {
	if (now[u] >= (int) to[u].size()) return;
	int v = to[u][now[u]];
	if (to[v][now[v]] != u) return;
	++now[u], ++now[v], printf("%d ", id[make_pair(u, v)]), dfs(u), dfs(v);
}

int main() {
	read(n, m);
	for (int i = 1; i <= n; ++i) read(p[i]);
	for (int i = 1; i <= m; ++i) {
		int x, y; read(x, y);
		id[make_pair(x, y)] = id[make_pair(y, x)] = i;
		to[x].push_back(y), to[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i) {
		if (pos[i]) continue;
		int len = 1;
		int j = i;
		do {
			pos[j] = ++len;
			j = p[j];
		} while (j != i);
		auto get = [&] (int x, int y) { return ((pos[x] - pos[y]) % len + len) % len; };
		j = i;
		do {
			sort(to[j].begin(), to[j].end(), [&] (int x, int y) { return get(x, j) < get(y, j); });
			j = p[j];
		} while (j != i);
	}
	for (int i = 1; i <= n; ++i) dfs(i);
	printf("\n");
	return 0;
}