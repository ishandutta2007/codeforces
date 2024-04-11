#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 5005;
int n, m, res[MX], vis[MX], k = 1;
vii adj[MX];

void dfs (int u) {
	vis[u] = 1;
	for(ii &v : adj[u]) {
		if (!vis[v.fi]) {
			res[v.se] = 1;
			dfs(v.fi);
		} else if (vis[v.fi] == 1) {
			res[v.se] = 2;
			k = 2;
		} else {
			res[v.se] = 1;
		}
	}
	vis[u] = 2;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n >> m;
	forn(i, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v, i);
	}

	forr(i, 1, n)
		if (!vis[i])
			dfs(i);

	cout << k << endl;
	forn(i, m) cout << res[i] << " ";
	cout << endl;

	return 0;
}