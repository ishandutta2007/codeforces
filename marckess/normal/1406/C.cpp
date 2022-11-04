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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, sz[MX], f;
vi adj[MX];

void dfs (int u, int p) {
	sz[u] = 1;

	for (int v : adj[u])
		if (v != p) {
			dfs(v, u);
			sz[u] += sz[v];
		}

	if (sz[u] == n - sz[u] && !f) {
		for (int v : adj[u])
			if (v != p) {
				cout << u << " " << v << endl;
				cout << v << " " << p << endl;
				break;
			}
		f = 1;
	}
}

void solve () {
	cin >> n;
	forn (i, n) adj[i + 1].clear();
	forn (i, n - 1) {
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	f = 0;
	dfs(1, 1);

	if (!f) {
		cout << 1 << " " << adj[1][0] << endl;
		cout << 1 << " " << adj[1][0] << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		solve();
	}	

	return 0;
}