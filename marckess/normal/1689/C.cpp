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

const int MX = 300005;
int n, sz[MX], dp[MX];
vi adj[MX];

void dfs (int u, int p = -1) {
	sz[u] = 1;
	
	vi c;
	for (int v : adj[u])
		if (v != p) {
			c.pb(v);
			dfs(v, u);
			
			sz[u] += sz[v];
		}
		
	dp[u] = 0;
	forn (i, c.size()) {
		dp[u] = max(
			dp[u],
			sz[c[i]] - 1 + (c.size() > 1 ? dp[c[i ^ 1]] : 0)
		);	
	}
}

void main_() {
	cin >> n;
	forr (i, 1, n)
		adj[i].clear();
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs(1);
	cout << dp[1] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}