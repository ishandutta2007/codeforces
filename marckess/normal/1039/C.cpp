#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 500005, mod = 1e9+7;
int u[MX], v[MX], k, n, m, z;
ll c[MX], vis[MX], res = 0;
map<ll, vi> mp;
vi adj[MX];

ll pot (ll b, ll p, int mod) {
	ll res = 1;
	b %= mod;

	while (p) {
		if (p & 1) res = res * b % mod;
		b = b * b % mod;
		p /= 2;
	}

	return res;
}

void dfs (int u, ll c) {
	if (vis[u] == c) return;
	vis[u] = c;
	z--;

	for (int v : adj[u])
		dfs(v, c);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> c[i];

	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i];
		mp[c[u[i]]^c[v[i]]].pb(i);
	}

	for (auto it = mp.begin(); it != mp.end(); it++) {
		vi &g = it->se;
		int cn = 0;
		z = n;

		for (int i : g) {
			adj[u[i]].pb(v[i]);
			adj[v[i]].pb(u[i]);
		}

		for (int i : g)
			if (vis[u[i]] != it->fi) {
				dfs(u[i], it->fi);
				cn++;
			}

		for (int i : g) {
			adj[u[i]].clear();
			adj[v[i]].clear();
		}

		res += pot(2, cn, mod) * pot(2, z, mod) % mod;
	}

	res %= mod;

	res += (((1ll << k) - (ll)mp.size()) % mod) * pot(2, n, mod) % mod; 

	cout << res % mod << endl;

	return 0;
}