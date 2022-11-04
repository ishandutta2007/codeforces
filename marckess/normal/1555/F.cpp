
// Problem : F. Good Graph
// Contest : Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1555/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005, LG = 20;
int n, q, u[MX], v[MX], x[MX], res[MX], par[MX], sz;
vii adj[MX];

int parent (int u) {
	return u == par[u] ? u : par[u] = parent(par[u]);
}

void add (int u, int v, int w) {
	adj[u].pb({v, w});
	adj[v].pb({u, w});
}

int ft[MX];
void update (int i, int k) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query (int i) {
	int s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

int ini[MX], fin[MX], p[MX][LG], lvl[MX], cn, acu[MX];

int LCA (int u, int v) {
	if (lvl[u] < lvl[v]) swap(u, v);
	
	forn (j, LG)
		if ((lvl[u] - lvl[v]) & (1 << j))
			u = p[u][j];
	
	if (u == v) return u;
	
	for (int j = LG - 1; j >= 0; j--)
		if (p[u][j] != p[v][j]) {
			u = p[u][j];
			v = p[v][j];
		}
		
	return p[u][0];
}

void dfs (int u) {
	ini[u] = ++cn;
	
	for (auto& [v, x] : adj[u])
		if (v != p[u][0]) {
			p[v][0] = u;
			lvl[v] = lvl[u] + 1;
			acu[v] = acu[u] ^ x;
			
			dfs(v);
		}
	
	fin[u] = cn;
}

void to (int u, int lca) {
	while (u != lca) {
		if (u > n) {
			update(ini[u], 1);
			update(fin[u] + 1, -1);
		}
		u = p[u][0];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(res, -1, sizeof(res));
	iota(par, par + MX, 0);
	
	cin >> n >> q;
	sz = n + 1;
	
	forn (i, q) {
		cin >> u[i] >> v[i] >> x[i];
		
		if (parent(u[i]) != parent(v[i])) {
			par[parent(u[i])] = parent(v[i]);
			
			add(u[i], sz, 0);
			add(sz, v[i], x[i]);
			sz++;
			
			res[i] = 1;
		}
	}
	
	for (int u = 1; u <= n; u++)
		if (!ini[u]) {
			p[u][0] = u;
			dfs(u);
		}
	
	for (int j = 1; j < LG; j++)
		for (int i = 1; i < sz; i++)
			p[i][j] = p[p[i][j - 1]][j - 1];
	
	forn (i, q) if (res[i] == -1) {
		res[i] = 0;
		
		if (!(acu[u[i]] ^ acu[v[i]] ^ x[i]))
			continue;
		
		int lca = LCA(u[i], v[i]);
		
		if (query(ini[u[i]]) + query(ini[v[i]]) - 2 * query(ini[lca]))
			continue;
		
		res[i] = 1;
		
		to(u[i], lca);
		to(v[i], lca);
	}
	
	forn (i, q) {
		if (res[i] == 0) cout << "NO" << endl;
		else if (res[i] == 1) cout << "YES" << endl; 
		else cout << res[i] << endl;
	}
	
	return 0;
}