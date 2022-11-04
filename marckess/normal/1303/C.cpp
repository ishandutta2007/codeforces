#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int f, vis[255];
string s, res;
vi adj[255];

void dfs (int u) {
	vis[u] = 1;
	res.pb(u);
	for (int v : adj[u])
		if (!vis[v])
			dfs(v);
}

void solve () {
	for (int i = 'a'; i <= 'z'; i++)
		adj[i].clear();
	memset(vis, 0, sizeof(vis));
	res.clear();

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (i)
			adj[s[i]].pb(s[i-1]);
		if (i + 1 < s.size())
			adj[s[i]].pb(s[i+1]);
	}

	for (int i = 'a'; i <= 'z'; i++) {
		sort(all(adj[i]));
		adj[i].erase(unique(all(adj[i])), adj[i].end());

		if (adj[i].size() > 2) {
			cout << "NO" << endl;
			return;
		}
	}

	for (int i = 'a'; i <= 'z'; i++)
		if (!vis[i] && adj[i].size() == 1)
			dfs(i);

	for (int i = 'a'; i <= 'z'; i++)
		if (!vis[i]) {
			res.pb(i);

			if (adj[i].size()) {
				cout << "NO" << endl;
				return;
			}
		}

	cout << "YES" << endl << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}