#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 300005;
int n, k, p[MX], in[MX], out[MX], to[MX], g[MX], root, vis[MX], f[MX];
vi tree[MX], topo, res;
set<int> adj[MX];

void no () {
	cout << 0 << endl;
	exit(0);
}

void dfs1 (int u, int t) {
	if (t && g[u] && t != g[u])
		adj[g[u]].insert(t);
	
	for (int v : tree[u])
		dfs1(v, g[u] ? g[u] : t);
}

void dfs2 (int u) {
	vis[u] = 1;
	
	for (int v : adj[u]) {
		if (vis[v] == 1) no();
		if (!vis[v])
			dfs2(v);
	}
	
	vis[u] = 2;
	topo.pb(u);
}

void dfs3 (int u) {
	if (!vis[u]) {
		vis[u] = 1;
		f[u] = res.size();
		res.pb(u);
	}
	
	for (int v : tree[u])
		dfs3(v);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		if (p[i])
			tree[p[i]].pb(i);
		else
			root = i;
	}
	
	while (k--) {
		int a, b;
		cin >> a >> b;
		if (in[b] || out[a]) no();
		to[a] = b;
		in[b] = 1;
		out[a] = 1;
	}
	
	for (int i = 1; i <= n; i++)
		if (!in[i] && out[i]) {
			int u = i;
			while (u) {
				g[u] = i;
				u = to[u];
			}
		}
	
	for (int i = 1; i <= n; i++)
		if ((in[i] || out[i]) && !g[i])
			no();
	
	dfs1(root, 0);
	
	for (int i = 1; i <= n; i++)
		if (!vis[i] && g[i] == i)
			dfs2(i);
	
	memset(vis, 0, sizeof(vis));
	for (int i : topo) {
		int u = i;
		
		while (u) {
			int v = p[u];
			vi aux;
			
			while (v && !vis[v] && !g[v]) {
				aux.pb(v);
				v = p[v];
			}
			
			reverse(all(aux));
			for (int v : aux) {
				vis[v] = 1;
				f[v] = res.size();
				res.pb(v);
			}
			
			u = to[u];
		}
		
		u = i;
		while (u) {
			vis[u] = 1;
			f[u] = res.size();
			res.pb(u);
			u = to[u];
		}
	}
	
	dfs3(root);
	
	for (int i = 1; i <= n; i++)
		if (p[i])
			if (f[p[i]] > f[i])
				no();
	
	for (int r : res)
		cout << r << " ";
	cout << endl;
	
	return 0;
}