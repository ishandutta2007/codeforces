#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e6 + 5;
typedef long long LL;

int m, n, match[N], tr[N][26], fail[N], idx;
int q[N], sz[N], c[N], dfn[N], cnt[N], dfncnt;
char s[N];

int head[N], numE = 0;
struct E{
	int next, v;
} e[N];

void add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
}

void insert(int id) {
	int p = 0;
	for (int i = 1; s[i]; i++) {
		int ch = s[i] - 'a';
		if (!tr[p][ch]) tr[p][ch] = ++idx;
		p = tr[p][ch];
	}
	match[id] = p;
}

void build() {
	int hh = 0, tt = -1;
	for (int i = 0; i < 26; i++)
		if (tr[0][i]) q[++tt] = tr[0][i];
	while (hh <= tt) {
		int u = q[hh++];
		for (int i = 0; i < 26; i++) {
			int v = tr[u][i];
			if (v) {
				fail[v] = tr[fail[u]][i];
				q[++tt] = v;
			} else tr[u][i] = tr[fail[u]][i];
		}
	}
	for (int i = 1; i <= idx; i++) add(fail[i], i);
}

void dfs(int u) {
	dfn[u] = ++dfncnt, sz[u] = 1;
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		dfs(v);
		sz[u] += sz[v];
	}
}

void insert(int x, int k) {
	for (; x <= dfncnt; x += x & -x) c[x] += k;
}

int ask(int x) {
	int res = 0;
	for (; x; x -= x & -x) res += c[x];
	return res;
}

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		insert(i);
	}
	build();
	dfs(0);
	for (int i = 1; i <= n; i++) {
	    insert(dfn[match[i]], 1);
		insert(dfn[match[i]] + sz[match[i]], -1);
		cnt[i] = 1;
	}
	while (m--) {
		char op; cin >> op;
		if (op == '?') {
			scanf("%s", s + 1);
			int p = 0; LL ans = 0;
			for (int i = 1; s[i]; i++) {
				int ch = s[i] - 'a';
				p = tr[p][ch];
				ans += ask(dfn[p]);
			}
			printf("%lld\n", ans);
		} else {
			int x; scanf("%d", &x);
			if ((op == '+' && cnt[x]) || (op == '-' && !cnt[x])) continue;
			cnt[x] = op == '+' ? 1 : 0;
			insert(dfn[match[x]], op == '+' ? 1 : -1);
			insert(dfn[match[x]] + sz[match[x]], op == '+' ? -1 : 1);
		} 
	}
	return 0;
}