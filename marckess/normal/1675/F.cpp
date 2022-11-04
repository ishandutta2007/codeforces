// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 200005, LG = 20;
int n, k, x, y, a[MX], ini[MX], fin[MX], inv[MX], lvl[MX], cn, p[LG][MX];
set<int> st;
vi adj[MX];

void dfs (int u) {
	ini[u] = ++cn;
	inv[cn] = u;
	
	for (int v : adj[u])
		if (v != p[0][u]) {
			p[0][v] = u;
			lvl[v] = lvl[u] + 1;
			dfs(v);
		}
	
	fin[u] = cn;
}

int LCA (int u, int v) {
	if (lvl[u] < lvl[v])
		swap(u, v);
	
	forn (j, LG)
		if ((lvl[u] - lvl[v]) & (1 << j))
			u = p[j][u];
	
	if (u == v)
		return u;
	
	for (int j = LG - 1; j >= 0; j--)
		if (p[j][u] != p[j][v]) {
			u = p[j][u];
			v = p[j][v];
		}
	
	return p[0][u];
}

int dist (int u, int v) {
	return lvl[u] + lvl[v] - 2 * lvl[LCA(u, v)];
}

void main_() {
	cin >> n >> k >> x >> y;
	forn (i, k) {
		cin >> a[i];
	}
	
	st.clear();
	cn = 0;
	forr (i, 1, n) {
		adj[i].clear();
		lvl[i] = 0;
	}
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	p[0][1] = 1;
	dfs(1);
	
	forr (j, 1, LG - 1)
		forr (i, 1, n)
			p[j][i] = p[j - 1][p[j - 1][i]];
	
	st.insert(ini[x]);
	st.insert(ini[y]);
	forn (i, k)
		st.insert(ini[a[i]]);
	
	vi o;
	for (int x : st)
		o.pb(x);
	
	ll res = 0;
	forn (i, o.size()) {
		int u = inv[o[i]];
		int v = inv[o[(i + 1) % o.size()]];
		
		res += dist(u, v);
	}
	
	res -= dist(y, x);
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}