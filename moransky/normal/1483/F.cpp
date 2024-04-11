// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e6 + 5, S = 26, L = 20;

int n, idx, tr[N][S], pos[N], q[N], fail[N], h[N], tp[N], len[N], w[N], ban[N], lt[N];

char s[N];

vector<int> loc[N];

void inline ins(int w) {
	int p = 0;
	loc[w].pb(0);
	for (int i = 1; s[i]; i++) {
		int ch = s[i] - 'a';
		if (!tr[p][ch]) tr[p][ch] = ++idx;
		p = tr[p][ch];
		loc[w].pb(p);
		lt[p] = i;
	}
	pos[w] = p;
	tp[p] = h[p] = w;
}

void build() {
	int hh = 1, tt = 0;
	for (int i = 0; i < S; i++)
		if (tr[0][i]) q[++tt] = tr[0][i];
	while (hh <= tt) {
		int u = q[hh++];
		for (int i = 0; i < S; i++) {
			int v = tr[u][i];
			if (!v) tr[u][i] = tr[fail[u]][i];
			else fail[v] = tr[fail[u]][i], q[++tt] = v;
		} 
	}
}

vector<int> g[N];

int fa[N][L], dfn[N], dfncnt, sz[N];

void dfs(int u) {
	dfn[u] = ++dfncnt;
	sz[u] = 1;
	for (int i = 1; i < L; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int v: g[u]) {
		if (!h[v]) h[v] = h[u];
		fa[v][0] = u;
		dfs(v);
		sz[u] += sz[v];
	}
}

vector<int> stk;

int c[N];

void inline add(int x, int k) {
	stk.pb(x);
	for (; x <= dfncnt; x += x & -x) c[x] += k;
}

void inline clr(int x) {
	for (; x <= dfncnt; x += x & -x) c[x] = 0;
}

int inline ask(int x) {
	int ret = 0;
	for (; x; x -= x & -x) ret += c[x];
	return ret;
}

void inline fl(int p, int k) {
	for (int i = L - 1; ~i; i--)
		if (lt[fa[p][i]] > k) p = fa[p][i];
	if (lt[p] > k) p = fa[p][0];
	add(dfn[p], 1);
}

bool vis[N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		len[i] = strlen(s + 1);
		ins(i);
	}
	build();
	for (int i = 1; i <= idx; i++) g[fail[i]].pb(i);
	dfs(0);
	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		int m = len[i];
		loc[i][m] = fail[loc[i][m]];
		for (int j = 1; j <= m; j++) {
			w[j] = h[loc[i][j]];	
		}
		w[m + 1] = 0;
		ban[m + 1] = 0;
		for (int j = m; j; j--) {
			ban[j] = max(ban[j + 1] - 1, len[w[j + 1]] - 1);
			chkMax(ban[j], len[w[j]] - 1);
			fl(loc[i][j], ban[j]);
		}
		
		for (int j = 1; j <= m; j++) {
			if (w[j] && !vis[w[j]]) {
				vis[w[j]] = 1;
				int p = pos[w[j]];
				int t = ask(dfn[p] + sz[p] - 1) - ask(dfn[p] - 1);
				if (!t) ans++;
			}
		}
		for (int j = 1; j <= m; j++) vis[w[j]] = 0, w[j] = ban[j] = 0;
		while (stk.size()) clr(stk.back()), stk.pop_back();
	}
	
	printf("%lld\n", ans);
    return 0;
}