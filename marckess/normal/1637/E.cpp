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

const int MX = 300005;
int n, m, a[MX], ptr[MX];
vi ex, pos[MX];
map<int, int> mp;
map<int, vi> adj;

void main_() {
	cin >> n >> m;
	
	mp.clear();
	adj.clear();
	ex.clear();
	for (int i = 1; i <= n; i++) {
		pos[i].clear();
	}
	
	forn (i, n) {
		cin >> a[i];
		mp[a[i]]++;
	}
	
	forn (i, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	for (auto it : mp) {
		ex.pb(it.se);
		pos[it.se].pb(it.fi);
		
		adj[it.fi].pb(it.fi);
	}
	
	sort(all(ex));
	ex.erase(unique(all(ex)), ex.end());
	
	for (int x : ex) {
		sort(all(pos[x]), greater<int>());
	}
	
	ll res = 0;
	for (auto it : adj) {
		int u = it.fi;
		vi &no = it.se;
		int cn = mp[u];
		
		sort(all(no), greater<int>());
		
		for (const int &x : ex)
			ptr[x] = 0;
		
		for (const int &v : no) {
			int x = mp[v];
			if (pos[x][ptr[x]] == v)
				ptr[x]++;
		}
		
		for (const int &x : ex)
			if (ptr[x] < (int)pos[x].size())
				res = max(res, 1ll * (cn + x) * (u + pos[x][ptr[x]]));
	}
	
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