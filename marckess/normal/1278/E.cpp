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

const int MX = 1000005;
int n, l[MX], r[MX], cn;
vi adj[MX];

void dfs (int u, int p) {
	if (!p)
		l[u] = ++cn;

	for (int v : adj[u])
		if (p != v)
			l[v] = ++cn;

	r[u] = ++cn;

	reverse(all(adj[u]));
	for (int v : adj[u])
		if (p != v)
			dfs(v, u);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1, 0);

	for (int i = 1; i <= n; i++)
		cout << l[i] << " " << r[i] << endl;

	return 0;
}