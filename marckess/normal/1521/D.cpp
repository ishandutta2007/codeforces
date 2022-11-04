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

const int MX = 100005;
int n, ex[MX], vis[MX];
vvi res;
vii adj[MX];

int dfs (int u, int p) {
	int d = adj[u].size();
	
	for (ii &v : adj[u])
		if (v.fi != p) {
			int r = dfs(v.fi, u);
			
			if (r > 2) {
				res.pb({u, v.fi});
				ex[v.se] = 0;
				d--;
			}
		}
	
	for (ii &v : adj[u])
		if (v.fi != p && (u == p ? d > 2 : d > 3) && ex[v.se]) {
			res.pb({u, v.fi});
			ex[v.se] = 0;
			d--;
		}
	
	return d;
}

vi h;
void dfs (int u) {
	int d = 0;
	vis[u] = 1;
	
	for (ii &v : adj[u])
		if (ex[v.se]) {
			d++;
			if (!vis[v.fi])
				dfs(v.fi);
		}
	
	if (d <= 1)
		h.pb(u);
}

void solve () {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		vis[i] = 0;
	}
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		
		adj[u].pb({v, i});
		adj[v].pb({u, i});
		
		ex[i] = 1;
	}
	
	res.clear();
	dfs(1, 1);
	
	vvi vh;
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			h.clear();
			dfs(i);
			vh.pb(h);
		}
	
	forn (i, res.size()) {
		res[i].pb(vh[i].back());
		res[i].pb(vh[i + 1][0]);
	}
	
	cout << res.size() << endl;
	for (vi &v : res) {
		for (int x : v)
			cout << x << " ";
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		
	int t;
	cin >> t;
	while (t--)
		solve();
 
	return 0;
}