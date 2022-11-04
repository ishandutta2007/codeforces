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

const int MX = 3005;
int n, m, ex[MX], us[MX], ptr[MX], vis[MX];
vii adj[MX];

void ans (vi res) {
	cout << res.size() << endl;
	for (int r : res)
		cout << r << " ";
	cout << endl;
	exit(0);
}

vi euler (int s) {
	vi res;
	stack<int> st;
	st.push(s);
	
	memset(ptr, 0, sizeof(ptr));
	memset(us, 0, sizeof(us));
	
	while (st.size()) {
		int u = st.top();
		
		while (ptr[u] < (int)adj[u].size() &&
			   (us[adj[u][ptr[u]].se] || !ex[adj[u][ptr[u]].se]))
			   ptr[u]++;
		
		if (ptr[u] == (int)adj[u].size()) {
			res.pb(u);
			st.pop();
		} else {
			us[adj[u][ptr[u]].se] = 1;
			st.push(adj[u][ptr[u]].fi);
		}
	}
	
	return res;
}

void dfs (int u) {
	vis[u] = 1;
	
	for (ii &v : adj[u])
		if (!vis[v.fi] && ex[v.se])
			dfs(v.fi);
}

bool eulerCyc (int s) {
	memset(vis, 0, sizeof(vis));
	dfs(s);
	
	for (int u = 1; u <= n; u++) {
		int d = 0;
		for (ii &v : adj[u])
			if (ex[v.se])
				d++;
		
		if (d && !vis[u])
			return 0;
				
		if (d & 1)
			return 0;
	}
	
	return 1;
}

vi eulerPath (int s) {
	memset(vis, 0, sizeof(vis));
	dfs(s);
	
	vi odd;
	for (int u = 1; u <= n; u++) {
		int d = 0;
		for (ii &v : adj[u])
			if (ex[v.se])
				d++;
		
		if (d && !vis[u])
			return {};
				
		if (d & 1)
			odd.pb(u);
	}
	
	if (odd.size() != 2)
		return {};
	return odd;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn (i, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb({v, i});
		adj[v].pb({u, i});
		ex[i] = 1;
	}
	
	if (eulerCyc(1))
		ans(euler(1));
	
	vi odd = eulerPath(1);
	if (odd.size())
		ans(euler(odd[0]));
	
	for (int u = 1; u <= n; u++) {
		for (ii &v : adj[u])
			if (adj[v.fi].size() & 1)
				ex[v.se] = 0;
		
		forn (i, adj[u].size() + 1) {
			if (i < adj[u].size())
				ex[adj[u][i].se] ^= 1;
			
			if (eulerCyc(u)) {
				vi res = euler(u);
				res.pb(-1);
		
				for (ii &v : adj[u])
					if (!ex[v.se]) {
						res.pb(v.fi);
						res.pb(u);
					}
				
				ans(res);
			}
			
			odd = eulerPath(u);
			if (odd.size() && (odd[0] == u || odd[1] == u)) {
				vi res = euler(u);
				res.pb(-1);
				
				for (ii &v : adj[u])
					if (!ex[v.se]) {
						res.pb(v.fi);
						res.pb(u);
					}
				
				ans(res);
			}
			
			if (i < adj[u].size())
				ex[adj[u][i].se] ^= 1;
		}
		
		for (ii &v : adj[u])
			ex[v.se] = 1;
	}
	
	cout << 0 << endl;
	
	return 0;
}