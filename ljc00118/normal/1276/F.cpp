#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 4e5 + 5;

set <int> id[N];
vector <int> aaa[N];
int par[N][20], dep[N], val[N], tops[N], pre[N], pos[2][N];
char c[N];
int n, dfn; ll res[N], ans;

struct sam_t {
	vector <int> adj[N];
	int ch[N][26], len[N], fa[N], siz[N], wson[N];
	int las, cnt;

	void reset() { las = cnt = 1; }

	void extend(int x) {
        int p = las, np = las = ++cnt; len[np] = len[p] + 1;
        for (; p && !ch[p][x]; p = fa[p]) ch[p][x] = np;
        if (!p) fa[np] = 1;
        else {
            int q = ch[p][x];
            if (len[q] == len[p] + 1) fa[np] = q;
            else {
                int nq = ++cnt; len[nq] = len[p] + 1;
                memcpy(ch[nq], ch[q], sizeof(ch[q]));
                fa[nq] = fa[q]; fa[q] = fa[np] = nq;
                for (; ch[p][x] == q; p = fa[p]) ch[p][x] = nq;
            }
        }
    }

    void build() {
    	for (int i = 1; i <= cnt; i++) ++len[i]; //, fprintf(stderr, "len[%d] = %d\n", i, len[i]);
    	for (int i = 2; i <= cnt; i++) adj[fa[i]].push_back(i);
    }

	void dfs1(int u) {
		tops[u] = ++dfn; pre[dfn] = u; val[u] = len[u];
		for (int i = 1; i < 20; i++) par[u][i] = par[par[u][i - 1]][i - 1];
		for (int i = 0; i < (int)adj[u].size(); i++) {
			int v = adj[u][i];
			par[v][0] = u;
			dep[v] = dep[u] + 1;
			dfs1(v);
		}
	}

	int lca(int u, int v) {
		if (dep[u] < dep[v]) swap(u, v);
		int jump = dep[u] - dep[v];
		for (int i = 0; i < 20; i++) if ((jump >> i) & 1) u = par[u][i];
		if (u == v) return u;
		for (int i = 19; i >= 0; i--) {
			if (par[u][i] != par[v][i]) {
				u = par[u][i];
				v = par[v][i];
			}
		}
		return par[u][0];
	}

	void dfs2(int u) {
		siz[u] = 1;
		for (int i = 0; i < (int)adj[u].size(); i++) {
			int v = adj[u][i];
			dfs2(v);
			if (siz[v] > siz[wson[u]]) wson[u] = v;
			siz[u] += siz[v];
		}
	}

	void add(int u, int x) {
		int d = 0;
		set <int> :: iterator it = id[u].lower_bound(tops[x]);
		if (it != id[u].end()) d = lca(x, pre[*it]);
		if (it != id[u].begin()) {
			--it;
			int po = lca(x, pre[*it]);
			if (dep[d] < dep[po]) d = po;
		}
		res[u] += val[x] - val[d];
		id[u].insert(tops[x]);
	}

	void dfs3(int u, int tp) {
		if (wson[u]) dfs3(wson[u], tp);
		for (int i = 0; i < (int)adj[u].size(); i++) {
			int v = adj[u][i];
			if (v == wson[u]) continue;
			dfs3(v, v);
			for (auto j : id[v]) add(tp, pre[j]);
			id[v].clear();
		}
		for (auto i : aaa[u]) add(tp, i);
		// fprintf(stderr, "u = %d, fa[u] = %d, v2 = %lld\n", u, fa[u], res[tp] + 1);
		ans += (len[u] - len[fa[u]]) * (res[tp] + 1);
	}
} a, b;

int main() {
	scanf("%s", c + 1); n = strlen(c + 1);
	pos[0][0] = pos[1][n + 1] = 1; a.reset(); b.reset();
	for (int i = 1; i <= n; i++) a.extend(c[i] - 'a'), pos[0][i] = a.las;
	for (int i = n; i >= 1; i--) b.extend(c[i] - 'a'), pos[1][i] = b.las;
	for (int i = 0; i < n; i++) aaa[pos[0][i]].push_back(pos[1][i + 2]);
	a.build(); b.build(); dep[1] = 1; b.dfs1(1); a.dfs2(1); a.dfs3(1, 1);
	print(ans, '\n');
    return 0;
}