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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005, LG = 20;
int n, a[MX], p[LG][MX], ft[MX], lvl[MX], ini[MX], fin[MX], inv[MX], cn;
vi adj[MX];
map<int, vi> mp;
set<int> st;

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
	if (lvl[u] < lvl[v]) swap(u, v);
	
	forn (j, LG)
		if ((lvl[u] - lvl[v]) & (1 << j))
			u = p[j][u];
	
	if (u == v) return u;
	
	for (int j = LG - 1; j >= 0; j--)
		if (p[j][u] != p[j][v]) {
			u = p[j][u];
			v = p[j][v];
		}
	
	return p[0][u];
}

int dist (int u, int v) {
	int lca = LCA(u, v);
	return lvl[u] + lvl[v] - 2 * lvl[lca]; 
}
 
 int cost (int u) {
	if (st.empty()) return 1;
	int s, t;
 
	auto it = st.upper_bound(ini[u]);
	if (it == st.end()) t = *st.begin();
	else t = *it;
	
	if (it == st.begin()) it = st.end();
	it--;
	s = *it;
 
	return (dist(u, inv[s]) + dist(u, inv[t]) - dist(inv[s], inv[t])) / 2;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]].pb(i);
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
	
	for (auto it = mp.begin(); it != mp.end(); it++) {
		const vi &v = it->se;
		if (v.size() <= 1) continue;
		
		st.clear();
		int lca = v[0], sz = 0;
		
		for (int u : v) {
			lca = LCA(lca, u);
			sz += cost(u);
			st.insert(ini[u]);
		}
		
		for (int u : v) {
			st.erase(ini[u]);
			if (!cost(u)) {
				cout << 0 << endl;
				return 0;
			}
			st.insert(ini[u]);
		}
		
		for (int u : v) {
			if (u == lca) {
				update(1, 1);
				
				int w = v[0];
				if (w == lca) w = v[1];
				
				for (int j = LG - 1; j >= 0; j--)
					if (lvl[p[j][w]] > lvl[lca])
						w = p[j][w];
				
				update(ini[w], -1);
				update(fin[w] + 1, 1);
			} else {
				update(ini[u], 1);
				update(fin[u] + 1, -1);
			}
		}
	}
	
	int res = 0;
	for (int i = 1; i <= n; i++)
		if (!query(ini[i]))
			res++;
	cout << res << endl;
	
	return 0;
}