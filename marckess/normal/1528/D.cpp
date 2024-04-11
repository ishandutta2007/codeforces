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

const int MX = 602;
int n, m, adj[MX][MX], vis[MX];
int res[MX][MX];

void dij (int s, int dis[]) {
	forn (i, n) {
		dis[i] = 2e9;
		vis[i] = 0;
	}
	dis[s] = 0;
	
	forn (kk, n) {
		int u = -1, d = 2e9;
		
		forn (i, n)
			if (!vis[i] && dis[i] < d) {
				u = i;
				d = dis[i];
			}
		
		vis[u] = 1;
		
		for (int v = 0, off = n - d % n; v < n; v++, off++) {
			if (off == n)
				off = 0;
			
			int w = d + adj[u][off];
			if (dis[v] > w)
				dis[v] = w;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 	
	cin >> n >> m;
	
	forn (i, n)
		forn (j, n)
			adj[i][j] = 2e9;
	
	while (m--) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u][v] = c;
	}
	
	forn (i, n)
		forn (kk, n)
			forn (j, n)
				adj[i][j] = min(adj[i][j], adj[i][j ? j - 1 : n - 1] + 1);
	
	forn (i, n) {
		dij(i, res[i]);
		
		forn (j, n)
			cout << res[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}