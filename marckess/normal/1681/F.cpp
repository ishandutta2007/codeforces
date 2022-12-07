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

const int MX = 500005;
int n, sz[MX];
ll res;
vii adj[MX];
map<int, int> ex[MX], ge[MX];

ll dfs (int u, int p) {
	ll ret = 0;
	sz[u] = 1;
	
	for (auto [v, w] : adj[u]) {
		if (v == p) continue;
		ll d = dfs(v, u);
		
		d -= ex[v][w];
		ex[v][w] = sz[v] - ge[v][w];
		ge[v][w] = sz[v];
		d += ex[v][w];
			
		res += 1ll * ret * sz[v] + 1ll * d * sz[u];
		
		ret += d;
		sz[u] += sz[v];
		
		if (ge[v].size() > ge[u].size()) {
			swap(ex[u], ex[v]);
			swap(ge[u], ge[v]);
		}
		
		for (auto [k, _] : ge[v]) {
			res -= 1ll * ex[u][k] * ge[v][k] + 1ll * ex[v][k] * ge[u][k];
			
			ex[u][k] += ex[v][k];
			ge[u][k] += ge[v][k];
		}
		
		ex[v].clear();
		ge[v].clear();
	}
	
	return ret;
}

void main_() {
	cin >> n;
	
	forn (i, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	
	dfs(1, 1);
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}