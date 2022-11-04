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


const int MX = 100005, mod = 1000000007;
int n, m;
ll p[MX], t[MX], sz[MX], k;
vi adj[MX];

void clear () {
	k = 0;
	forn (i, n) {
		adj[i].clear();
	}
}

void dfs (int u, int p) {
	sz[u] = 1;
	for (int v : adj[u]) if (v != p) {
		dfs(v, u);
		sz[u] += sz[v];
		t[k++] = sz[v] * (n - sz[v]);
	}
}

void solve () {
	cin >> n;
	clear();

	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(0, 0);

	n--;
	sort(t, t + n, greater<ll>());

	cin >> m;
	forn (i, m) cin >> p[i];
	sort (p, p + m, greater<ll>());

	ll res = 0;
	for (int i = 0, j = 0; i < n; i++) {
		t[i] %= mod;
		ll f = 1;

		if (j < m) {
			(f *= p[j]) %= mod;
			j++;

			while (n - (i + 1) < m - j) {
				(f *= p[j]) %= mod;
				j++;
			}
		}

		(res += t[i] * f) %= mod;
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}