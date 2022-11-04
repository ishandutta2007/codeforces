#include <bits/stdc++.h>
 
//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 200005;
int n, b[MX], c[MX];
ll res, a[MX];
vi adj[MX];

ii operator + (ii a, ii b) {
	return {a.fi + b.fi, a.se + b.se};
}

ii dfs (int u, int p) {
	ii r(0, 0);

	if (b[u] != c[u]) {
		if (b[u]) r.fi++;
		else r.se++;
	}

	for (int v : adj[u])
		if (v != p) {
			a[v] = min(a[v], a[u]);
			r = r + dfs(v, u);
		}

	ll d = min(r.fi, r.se);
	res += 2 * d * a[u];
	r.fi -= d;
	r.se -= d;

	return r;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> c[i];

	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	ii r = dfs(1, 1);

	if (r.fi || r.se) cout << -1 << endl;
	else cout << res << endl;

	return 0;
}