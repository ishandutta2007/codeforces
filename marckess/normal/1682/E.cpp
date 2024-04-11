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

const int MX = 200005;
int n, m, p[MX], sz[MX], cid[MX], pos[MX], vis[MX];
vii adj[MX];
vi dag[MX];

void dfs (int u) {
	vis[u] = 1;
	
	for (int v : dag[u])
		if (!vis[v])
			dfs(v);
	
	cout << u << " ";
}

void main_() {
	cin >> n >> m;
	
	forr (i, 1, n)
		cin >> p[i];
	
	forr (i, 1, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb({v, i});
		adj[v].pb({u, i});
	}
	
	forr (i, 1, n) {
		if (vis[i])
			continue;
		
		int u = i, t = 0;
		while (!vis[u]) {
			cid[u] = i;
			pos[u] = t++;
			vis[u] = 1;
			sz[i]++;
			
			u = p[u];
		}
	}
	
	forr (i, 1, n) {
		sort(all(adj[i]), [&] (const ii &x, const ii &y) {
			return MOD(pos[x.fi] - pos[i], sz[cid[i]]) < MOD(pos[y.fi] - pos[i], sz[cid[i]]);
		});
		
		forr (j, 1, (int)adj[i].size() - 1) {
			dag[adj[i][j].se].pb(adj[i][j - 1].se);
		}
	}
	
	memset(vis, 0, sizeof(vis));
	forr (i, 1, m)
		if (!vis[i])
			dfs(i);
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}