#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T& x, const T& y) {
	if (x > y) x = y;
}
template<typename T>
void chmax(T& x, const T& y) {
	if (x < y) x = y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int, int> pii;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define rep0(i, l, r) for (int i = l; i < r; ++i)
#define gc (c = getchar())
char readc() {
	char c;
	while (isspace(gc))
		;
	return c;
}
int read() {
	char c;
	while (gc < '-')
		;
	if (c == '-') {
		int x = gc - '0';
		while (gc >= '0') x = x * 10 + c - '0';
		return -x;
	}
	int x = c - '0';
	while (gc >= '0') x = x * 10 + c - '0';
	return x;
}
#undef gc

const int N = 4e5 + 5;

struct edge_t {
	int u, v, nxt, val;
} G[N * 4];

vector<int> a[N], ans[N];
vector<pair<int, int> > vec[N];
int l[N], b[N], head[N], nowhead[N], vis[N];
int n, len, tot = 1;

inline void addedge(int u, int v) {
	G[++tot] = (edge_t) { u, v, head[u], 0 }, head[u] = tot;
	G[++tot] = (edge_t) { v, u, head[v], 0 }, head[v] = tot;
}

void dfs(int u) {
	vis[u] = 1;
	while (nowhead[u]) {
		while (nowhead[u] && G[nowhead[u]].val) nowhead[u] = G[nowhead[u]].nxt;
		if (nowhead[u]) {
			int v = G[nowhead[u]].v;
			G[nowhead[u]].val = 1;
			G[nowhead[u] ^ 1].val = -1;
			dfs(v);
		}
	}
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	for (int i = 1; i <= n; i++) {
		l[i] = read();
		a[i].resize(l[i] + 1);
		ans[i].resize(l[i] + 1);
		for (int j = 1; j <= l[i]; j++) {
			a[i][j] = read();
			b[++len] = a[i][j];
		}
	}
	sort(b + 1, b + len + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= l[i]; j++) {
			a[i][j] = lower_bound(b + 1, b + len + 1, a[i][j]) - b;
			vec[a[i][j]].push_back(make_pair(i, j));
		}
	}
	for (int i = 1; i <= len; i++) {
		if (!vec[i].size()) continue;
		if (vec[i].size() % 2 == 1) {
			printf("NO\n");
			return 0;
		}
		for (auto j: vec[i]) addedge(i, len + j.first);
	}
	memcpy(nowhead, head, sizeof(nowhead));
	for (int i = 1; i <= len; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	for (int i = 1; i <= len; i++) {
		int now = (int)vec[i].size() - 1;
		for (int j = head[i]; j; j = G[j].nxt) {
			int v = G[j].v;
			if (G[j].val == 1) {
				while (vec[i][now].first != v - len) --now;
				ans[vec[i][now].first][vec[i][now].second] = 1;
				--now;
			}
		}
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= l[i]; j++) {
			if (ans[i][j] == 1)
				putchar('L');
			else
				putchar('R');
		}
		putchar('\n');
	}
}