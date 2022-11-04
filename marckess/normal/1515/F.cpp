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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, m, x, vis[MX];
ll a[MX], s;
vi adj[MX], res;
set<vi> st[MX];
map<ii, int> mp;

void dfs (int u) {
	vis[u] = 1;
	
	for (int v : adj[u])
		if (!vis[v]) {
			dfs(v);
			st[u].insert({a[v], v, u});
		}
	
	while (st[u].size() && a[u] + (*st[u].rbegin())[0] >= x) {
		int o = (*st[u].rbegin())[2];
		int v = (*st[u].rbegin())[1];
		res.pb(mp[ii(o, v)]);
		
		a[u] += (*st[u].rbegin())[0] - x;
		st[u].erase(*st[u].rbegin());
		
		if (st[u].size() < st[v].size())
			swap(st[u], st[v]);
			
		for (const vi &p : st[v])
			st[u].insert(p);
		st[v].clear();
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> x;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
	}
	
	forn (i, m) {
		int u, v;
		cin >> u >> v;
		
		adj[u].pb(v);
		adj[v].pb(u);
		
		mp[ii(u, v)] = i + 1;
		mp[ii(v, u)] = i + 1;
	}
	
	dfs(1);
	
	if (res.size() < n - 1) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int r : res)
			cout << r << endl;
		cout << endl;
	}
		
	return 0;
}