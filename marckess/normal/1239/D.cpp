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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1000005;
int n, m, vis[MX], p[MX], cn[MX], x;
vi adja[MX], adjb[MX];

void dfs (int u, vi adj[]) {
	vis[u] = 1;
	x++;
	for (int v : adj[u])
		if (!vis[v])
			dfs(v, adj);
}

void yes (int f) {
	cout << "Yes" << endl;
	if (f) cout << x << " " << n - x;
	else cout << n - x << " " << x;
	cout << endl;

	for (int i = 1; i <= n; i++)
		if (vis[i] == f)
			cout << i << " ";
	cout << endl;

	for (int i = 1; i <= n; i++)
		if (vis[i] != f)
			cout << i << " ";
	cout << endl;
}

void solve () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		adja[i].clear();
		adjb[i].clear();
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		adja[a].pb(b);
		adjb[b].pb(a);
	}

	fill(vis+1, vis+n+1, 0);
	x = 0;
	dfs(1, adja);

	if (x < n)
		return yes(1);

	fill(vis+1, vis+n+1, 0);
	x = 0;
	dfs(1, adjb);

	if (x < n)
		return yes(0);

	cout << "No" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}