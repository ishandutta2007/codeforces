// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005, mod = 1000000007;
int n, k;
ll fac[MX], inv[MX], res, sz[MX];
vi adj[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll comb (int n, int k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void dfs1 (int u, int p) {
	sz[u] = 1;
	
	for (int v : adj[u])
		if (v != p) {
			dfs1(v, u);
			sz[u] += sz[v];
		}
}

void dfs2 (int u, int p) {
	ll acu = 0;
	for (int v : adj[u])
		(acu += comb(sz[v], k)) %= mod;
	(res += n * (comb(n, k) - acu)) %= mod;
	
	for (int v : adj[u]) {
		ll sub = (acu - comb(sz[v], k)) % mod;
		(res += (n - sz[v]) * sz[v] % mod * (comb(n - sz[v], k) - sub) % mod) %= mod;
	}
	
	for (int v : adj[u])
		if (v != p) {
			int au = sz[u];
			int av = sz[v];
			
			sz[u] -= sz[v];
			sz[v] = n;
			
			dfs2(v, u);
			
			sz[u] = au;
			sz[v] = av;
		}
}

void main_() {
	cin >> n >> k;
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs1(1, -1);
	dfs2(1, -1);
	
	cout << MOD(res, mod) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fac[0] = inv[0] = 1;
	forr (i, 1, MX - 1) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = pot(fac[i], mod - 2);
	}
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}