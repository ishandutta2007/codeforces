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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5005;
int n, no[MX];
ll res = 1e18, sz[MX], to[MX], tot, w[MX];
vii adj[MX];

void pre (int u, int p = 0) {
	sz[u] = 1;
	to[u] = 0;

	for (ii &v : adj[u])
		if (v.fi != p && v.fi != no[u]) {
			pre(v.fi, u);

			tot += to[v.fi] * sz[u] + to[u] * sz[v.fi] + v.se * sz[u] * sz[v.fi];
			to[u] += to[v.fi] + v.se * sz[v.fi];
			sz[u] += sz[v.fi];
		}
}

void dfs (int u, ll &x, int p = 0) {
	x = min(x, to[u]);

	for (ii &v : adj[u])
		if (v.fi != p && v.fi != no[u]) {
			to[v.fi] = to[u] + v.se * ((sz[u] - sz[v.fi]) - sz[v.fi]);
			sz[v.fi] = sz[u];
			dfs(v.fi, x, u);
		}
}

void go (int u, int p = 0) {
	if (p) {
		ll x = 1e18, y = 1e18;

		tot = 0;
		no[u] = p, no[p] = u;
		pre(u), pre(p);
		dfs(u, x), dfs(p, y);

		ll a = tot + sz[u] * y + sz[p] * x + w[u] * sz[u] * sz[p];
		res = min(res, a);

		no[u] = 0, no[p] = 0;
	}

	for (ii &v : adj[u])
		if (v.fi != p) {
			w[v.fi] = v.se;
			go(v.fi, u);
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}

	go(1);
	cout << res << endl;

	return 0;
}