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

const int MX = 500005;
int n, m, p[MX], q[MX], d[MX], cn;
vvi res;
set<int> adj[MX], ex;
set<ii> dg;

void clear () {
	cn = 1;
	ex.clear();
	dg.clear();
	res.clear();
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		ex.insert(i);
	}
}

bool dfs (int u) {
	vi g = {u};
	ex.erase(u);
	
	int v = 0;
	while (1) {
		auto it = ex.upper_bound(v);
		if (it == ex.end()) break;
		v = *it;
		
		if (adj[u].count(v)) continue;
		
		if (!dfs(v)) g.pb(v);
	};
	
	if (g.size() > 1) {
		res.pb(g);
		return 1;
	}
	
	return 0;
}

void solve () {
	cin >> n >> m;
	clear();
	
	forn (i, m) {
		int l, r;
		cin >> l >> r;
		adj[l].insert(r);
		adj[r].insert(l);
	}
	
	for (int i = 1; i <= n; i++)
		dg.emplace(d[i] = adj[i].size(), i);
	
	while (dg.size() && dg.rbegin()->fi == (int)dg.size() - 1) {
		int u = dg.rbegin()->se;
		dg.erase(ii(d[u], u));
		ex.erase(u);
		
		for (int v : adj[u])
			if (ex.count(v)) {
				dg.erase(ii(d[v], v));
				d[v]--;
				dg.emplace(ii(d[v], v));
			}
		
		p[u] = q[u] = cn++; 
	}
	
	while (ex.size()) {
		int u = *ex.begin();
		if (!dfs(u)) 
			res.back().pb(u);
	}
	
	for (vi &g : res) {
		int k = g.size();
		
		forn (i, k) {
			p[g[i]] = cn + i;
			q[g[i]] = cn + (i - 1 + k) % k;
		}
		
		cn += k;
	}
	 
	for (int i = 1; i <= n; i++)
		cout << p[i] << " ";
	cout << endl;
	
	for (int i = 1; i <= n; i++)
		cout << q[i] << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
			
	return 0;
}