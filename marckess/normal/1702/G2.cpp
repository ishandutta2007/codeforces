// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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
int n, p[LG][MX], lvl[MX];
vi adj[MX];

void dfs (int u) {
	for (int v : adj[u])
		if (v != p[0][u]) {
			p[0][v] = u;
			lvl[v] = lvl[u] + 1;
			dfs(v);
		}
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

void main_() {
	cin >> n;
	forn (i, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	p[0][1] = 1;
	dfs(1);
	
	forr (j, 1, LG - 1)
		forr (i, 1, n)
			p[j][i] = p[j - 1][p[j - 1][i]];
			
	int q;
	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		vi v(k);
		
		forn (i, k)
			cin >> v[i];
		
		int lca = v[0];
		forr (i, 1, k - 1)
			lca = LCA(lca, v[i]);
		
		int g = 0;
		forn (i, k)
			if (v[i] == lca)
				g = 1;
		if (!g)
			v.pb(lca);
		
		sort(all(v), [&] (int a, int b) {
			return lvl[a] < lvl[b];
		});
		
		int x = v[0], f = 1;
		vi act = {v[0]}, ot = {v[0]};
		
		forr (i, 1, (int)v.size() - 1) {
			if (LCA(x, v[i]) == x) {
				x = v[i];
				act.pb(v[i]);
			} else 
				ot.pb(v[i]);
		}
		
		x = v[0];
		forr (i, 1, (int)ot.size() - 1) {
			if (LCA(x, ot[i]) == x)
				x = ot[i];
			else
				f = 0;
		}
		
		if (act.size() > 1 && ot.size() > 1)
			if (LCA(act[1], ot[1]) != v[0])
				f = 0;
		
		if (f) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}