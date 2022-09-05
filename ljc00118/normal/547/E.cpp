#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') fu = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		f = f * 10 + c - 48;
		c = getchar();
	}
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x >= 10) print(x / 10);
	putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char c) {
	print(x); putchar(c);
}

const int N = 2e5 + 5, M = 5e5 + 5;

queue <int> q;
vector <int> gl[N], gr[N], adj[N];
char c[N], t[N]; ll ans[M], f[N];
int ch[N][26], fail[N], l[N], r[N], tops[N], siz[N], id[M], tmp[N];
int n, m, tot, cnt, len;

inline int lowbit(int x) { return x & -x; }

inline void add(int x, int y) {
	while (x <= tot + 1) {
		f[x] += y;
		x += lowbit(x);
	}
}

inline int query(int x) {
	int ans = 0;
	while (x) {
		ans += f[x];
		x ^= lowbit(x);
	}
	return ans;
}

void insert(char *c, int len, int nowid) {
	int now = 0;
	for (int i = 0; i < len; i++) {
		int x = c[i] - 'a';
		if (!ch[now][x]) ch[now][x] = ++tot;
		now = ch[now][x];
	}
	tmp[nowid] = now;
}

void build() {
	q.push(0);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u) adj[fail[u]].push_back(u);
		for (int i = 0; i < 26; i++) {
			if (!ch[u][i]) continue;
			int v = ch[u][i], las = u, now = fail[u];
			while (las) {
				if (ch[now][i]) {
					fail[v] = ch[now][i];
					break;
				}
				las = now; now = fail[now];
			}
			q.push(v);
		}
	}
}

void dfs1(int u) {
	tops[u] = ++cnt; siz[u] = 1;
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		dfs1(v); siz[u] += siz[v];
	}
}

int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", c + r[i - 1] + 1);
		l[i] = r[i - 1] + 1; r[i] = l[i] + strlen(c + r[i - 1] + 1) - 1;
	}
	for (int i = 1; i <= n; i++) insert(c + l[i], r[i] - l[i] + 1, i);
	for (int i = 1; i <= m; i++) {
		int L, R, K;
		read(L); read(R); read(K);
		gl[L - 1].push_back(i);
		gr[R].push_back(i);
		id[i] = tmp[K];
	}
	build(); dfs1(0);
	for (int i = 1; i <= n; i++) {
		int now = 0;
		for (int j = l[i]; j <= r[i]; j++) {
			int x = c[j] - 'a';
			if (!ch[now][x]) {
				int las = now; now = fail[now];
				while (las && !ch[now][x]) las = now, now = fail[now];
			}
			if (ch[now][x]) now = ch[now][x];
			add(tops[now], 1);
		}
		for (int j = 0; j < (int)gl[i].size(); j++) {
			int I = gl[i][j];
			ans[I] -= query(tops[id[I]] + siz[id[I]] - 1) - query(tops[id[I]] - 1);
		}
		for (int j = 0; j < (int)gr[i].size(); j++) {
			int I = gr[i][j];
			ans[I] += query(tops[id[I]] + siz[id[I]] - 1) - query(tops[id[I]] - 1);
		}
	}
	for (int i = 1; i <= m; i++) print(ans[i], '\n');
	return 0;
}