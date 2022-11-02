// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 4e5 + 5;

int n, m;

bool o = 0;

struct D1{
	int f[N], sz[N], d[N];
	void init(int n) { for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1, d[i] = 0; }
	int inline find(int x) { 
		if (f[x] == x) return x;
		int fa = find(f[x]);
		d[x] ^= d[f[x]];
		return f[x] = fa;
	}
	void inline merge(int x, int y, int z) {
		int A = find(x), B = find(y);
		if (A == B) {
			if ((d[x] ^ d[y]) != z) o = 1;
		} else {
			if (A < B) swap(A, B);
			d[A] = z ^ d[x] ^ d[y];
			sz[B] += sz[A], f[A] = B;
		}
	}
} t, h;

int fa[N], d[N];

vector<int> g[N];

void dfs1(int u) {
	for (int v: g[u]) {
		if (v == fa[u]) continue;
		fa[v] = u;
		dfs1(v);
	}
}

vector<int> b[N], c[N];

void inline clr() {
	for (int i = 1; i <= n; i++) g[i].clear(), b[i].clear(), c[i].clear(), d[i] = 0;
}

int inline pct(int x) {
	int c = 0;
	while (x) x -= x & -x, c++;
	return c % 2;
}


int main() {
	int T; read(T);
	while (T--) {
		o = 0;
		read(n), read(m);
		t.init(n), h.init(n);
		for (int i = 1; i < n; i++) {
			int u, v, w;
			read(u), read(v), read(w);
			g[u].pb(v), g[v].pb(u);
			if (w != -1) h.merge(u, v, w), t.merge(u, v, pct(w) & 1);
		}
		while (m--) {
			int a, b, p; read(a), read(b), read(p);
			t.merge(a, b, p);
		}
		dfs1(1);
		if (o) puts("NO");
		else {
			puts("YES");
			for (int i = 1; i <= n; i++)
				b[t.find(i)].pb(i), c[h.find(i)].pb(i);
			for (int i = 1; i <= n; i++) {
				if (b[i].size()) {
					for (int v: b[i]) {
						if (c[v].size()) {
							t.find(v);
							int z = t.d[v];
							for (int x: c[v]) {
								h.find(x);
								d[x] = h.d[x] ^ z;
							}
						}
					}
				}
			}
			for (int i = 2; i <= n; i++) {
				printf("%d %d %d\n", fa[i], i, d[i] ^ d[fa[i]]);
			}
		}
		clr();
	}
    return 0;
}