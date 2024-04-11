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

const int MX = 3005;
int n, dis[MX][MX], v[MX], res[MX], suf[MX];
vi adj[MX];

void dfs (int u, int p, int dis[]) {
	for (int v : adj[u])
		if (v != p) {
			dis[v] = dis[u] + 1;
			dfs(v, u, dis);
		}
}

void main_() {
	cin >> n;
	
	forn (i, n) {
		adj[i].clear();
	}
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	forn (i, n)
		dfs(i, i, dis[i]);
	
	forr (i, 1, n)
		res[i] = n;
	
	iota(v, v + n, 0);
	
	forn (i, n) {
		sort(v, v + n, [&] (int x, int y) {
			return dis[0][x] - dis[i][x] < dis[0][y] - dis[i][y];
		});
		
		suf[n] = -1e9;
		for (int j = n - 1; j >= 0; j--)
			suf[j] = max(dis[i][v[j]], suf[j + 1]);
		
		int mx = 0, j = 0;
		for (int x = 1; x <= n; x++) {
			while (j < n && dis[i][v[j]] + x > dis[0][v[j]]) {
				mx = max(mx, dis[0][v[j]]);
				j++;
			}
			
			res[x] = min(res[x], max(mx, suf[j] + x));
		}
	}
	
	forr (i, 1, n)
		cout << res[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}