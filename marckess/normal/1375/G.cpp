#include <bits/stdc++.h>

//#define endl '\n'
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

const int MX = 200005;
int n, cn[2];
vi adj[MX];

void dfs (int u, int p, int lvl) {
	cn[lvl]++;

	for (int v : adj[u])
		if (v != p)
			dfs(v, u, 1 - lvl);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1, 1, 1);

	cout << min(cn[0], cn[1]) - 1 << endl;

	return 0;
}