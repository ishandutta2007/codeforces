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

const int MX = 200005;
int n, f[MX], ex[MX], bs[MX], sz[40][MX], p[40][MX];
vii adj[MX];

void dfs (int u, int lvl, vi &t) {
	sz[lvl][u] = 1;
	t.pb(u);
	
	for (ii &v : adj[u])
		if (v.fi != p[lvl][u] && !bs[v.se]) {
			p[lvl][v.fi] = u;
			dfs(v.fi, lvl, t);
			sz[lvl][u] += sz[lvl][v.fi];
		}
}

bool solve (int u, int n, int lvl) {
	if (n == 1) return 1;
	
	vi t;
	p[lvl][u] = u;
	dfs(u, lvl, t);
	
	for (int v : t) {
		int s = sz[lvl][v];
		
		if (ex[s] && ex[n - s]) {
			for (ii &w : adj[v])
				if (w.fi == p[lvl][v])
					bs[w.se] = 1;
			
			return solve(v, s, lvl + 1) && solve(p[lvl][v], n - s, lvl + 1);
		}
	}
	
	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	f[0] = f[1] = 1;
	ex[1] = 1;
	for (int i = 2; i < MX; i++) {
		f[i] = f[i - 1] + f[i - 2];
		if (f[i] > MX)
			break;
		ex[f[i]] = i;
	}
	
	cin >> n;
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb({v, i});
		adj[v].pb({u, i});
	}
	
	if (!ex[n]) {
		cout << "NO" << endl;
		return 0;
	}
	
	if (solve(1, n, 0)) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}