#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, w[MX], u, v, c;
ll res = 0;
ii mx[MX];
vii adj[MX];

void insert (int i, ll x) {
	if (x > mx[i].fi) {
		mx[i].se = mx[i].fi;
		mx[i].fi = x;
	} else if (x > mx[i].se) {
		mx[i].se = x;
	}
}

void dfs (int u, int p) {
	for (ii &v : adj[u])
		if (v.fi != p) {
			dfs(v.fi, u);
			insert(u, mx[v.fi].fi - v.se);
		}

	res = max(res, mx[u].fi + mx[u].se + w[u]);
	mx[u].fi += w[u];
	mx[u].se += w[u];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> w[i];

	for (int i = 1; i < n; i++) {
		cin >> u >> v >> c;
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}

	dfs(1, 1);
	cout << res << endl;

	return 0;
}