#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, m, in[MX], f[MX], vis[MX], cn = 1;
vi adj[MX];
set<int> gra[MX];
map<vi, int> mp;

void no () {
	cout << "NO" << endl;
	exit(0);
}

void dfs (int u) {
	if (gra[u].size() > 2) no();
	f[u] = cn++;
	vis[u] = 1;

	for (int v : gra[u])
		if (!vis[v])
			dfs(v);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		adj[i].pb(i);

	forn (i, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(all(adj[i]));

		if (!mp.count(adj[i])) {
			int t = mp.size();
			mp[adj[i]] = t;
		}

		in[i] = mp[adj[i]];
	}

	for (int i = 1; i <= n; i++)
		for (int v : adj[i])
			if (in[i] != in[v])
				gra[in[i]].insert(in[v]);

	forn (i, mp.size())
		if (gra[i].size() < 2 && !vis[i]) {
			dfs(i);
			cn += 2;
		}

	forn (i, mp.size())
		if (!vis[i])
			no();

	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
		cout << f[in[i]] << " ";
	cout << endl;

	return 0;
}