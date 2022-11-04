// Problem : F. Tree Queries
// Contest : Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1606/problem/F
// Memory Limit : 512 MB
// Time Limit : 6000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

const int MX = 200005, SQ = 450;
int n, q, dp[MX][SQ], res[MX], sz[MX];
vi adj[MX];
vii pos[SQ];

void dfs1 (int u, int p) {
	forn (k, SQ)
		dp[u][k] = 0;
	
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs1(v, u);
		
		forn (k, SQ)
			dp[u][k] += max(1, dp[v][k] - k);
	}
	
	forn (k, SQ)
		dp[u][k] = max(dp[u][k], (int)adj[u].size() - (u != p));
}

int aux[SQ];
void dfs2 (int u, int p) {
	dp[u][0] = (int)adj[u].size() - (u != p);
	sz[u] = 1;
	
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs2(v, u);
		
		forn (k, SQ)
			aux[k] = dp[u][k];
		
		forn (i, min(SQ, sz[u] + 1))
			forn (j, min(SQ, sz[v])) {
				if (i + j >= SQ) break;
				
				aux[i + j + 1] = max(aux[i + j + 1], dp[u][i] - 1 + dp[v][j]);
			}
				
		forn (k, SQ)
			dp[u][k] = aux[k];
		sz[u] += sz[v];
	}
}

void main_() {
	cin >> n;
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs2(1, 1);
	
	cin >> q;
	forn (i, q) {
		int u, k;
		cin >> u >> k;
		
		if (k < SQ) pos[k].pb({i, u});
		else {
			forn (j, SQ)
				res[i] = max(1ll * res[i], dp[u][j] - 1ll * j * k);
		}
	}
	
	dfs1(1, 1);
	forn (i, SQ)
		for (ii &p : pos[i])
			res[p.fi] = dp[p.se][i];
	
	forn (i, q)
		cout << res[i] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}