#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 600005, LG = 19, SQ = 775;
int n, q, a[MX], c[MX], t, ini[MX], fin[MX], p[LG][MX], lvl[MX];
vi adj[MX];

void dfs (int u) {
	ini[u] = ++t;
	a[t] = u;
	
	for (int v : adj[u])
		if (v != p[0][u]) {
			p[0][v] = u;
			lvl[v] = lvl[u] + 1;
			dfs(v);
		}
	
	fin[u] = ++t;
	a[t] = u;
}

int LCA (int u, int v) {
	if (lvl[u] < lvl[v]) swap(u, v);
	
	forn (i, LG)
		if ((lvl[u] - lvl[v]) & (1 << i))
			u = p[i][u];
	
	if (u == v)
		return u;
	
	for (int i = LG - 1; i >= 0; i--)
		if (p[i][u] != p[i][v]) {
			u = p[i][u];
			v = p[i][v];
		}
	
	return p[0][u];
}

struct query {
	int l, r, a, b, i, lca;
	
	bool operator < (const query &ot) const {
		if ((l / SQ) ^ (ot.l / SQ)) return l < ot.l;
		return r < ot.r;
	}
};

int res[MX], f[MX], cnt[MX / SQ + 5], blo[MX];
vector<query> vq;

inline void update (int u) {
	f[c[u]] ^= 1;
	if (f[c[u]])
		cnt[blo[c[u]]]++;
	else
		cnt[blo[c[u]]]--;
}

inline int find (int a, int b) {
	for (int i = a; i <= b && blo[i] == blo[a]; i++)
		if (f[i])
			return i;
	
	for (int i = b; i >= a && blo[i] == blo[b]; i--)
		if (f[i])
			return i;
	
	for (int i = blo[a] + 1; i < blo[b]; i++)
		if (cnt[i])
			for (int j = SQ * i;;j++)
				if (f[j])
					return j;
	
	return -1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		blo[i] = i / SQ;
	}
		
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	p[0][1] = 1;
	dfs(1);
	
	for (int j = 1; j < LG; j++)
		for (int i = 1; i <= n; i++)
			p[j][i] = p[j - 1][p[j - 1][i]];
	
	for (int i = 1; i <= q; i++) {
		int u, v, a, b;
		cin >> u >> v >> a >> b;
		if (ini[u] > ini[v]) swap(u, v);
		if (fin[u] < ini[v]) vq.pb({fin[u], ini[v], a, b, i, LCA(u, v)});
		else vq.pb({ini[u], ini[v], a, b, i, -1});
	}
		
	sort(all(vq));
	
	int l = 1, r = 0, k = 0;
	for (auto &q : vq) {
		while (q.l < l) update(a[--l]);
		while (r < q.r) update(a[++r]);
		while (q.l > l) update(a[l++]);
		while (r > q.r) update(a[r--]);
		
		if (q.lca != -1) update(q.lca);
		res[q.i] = find(q.a, q.b);
		if (q.lca != -1) update(q.lca);
	}
	
	for (int i = 1; i <= q; i++)
		if (res[i])
			cout << res[i] << endl;
	
	return 0;
}