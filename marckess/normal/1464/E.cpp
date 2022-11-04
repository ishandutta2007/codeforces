#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005, mod = 998244353;
int n, m, g[MX], cn[MX], sz, vis[MX];
ll inv;
vi adj[MX], dp[MX];

int mex (vi v) {
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	forn (i, v.size())
		if (i != v[i])
			return i;
	return v.size();
}

int dfs (int u) {
	if (vis[u])
		return g[u];
	vis[u] = 1;
	
	vi a;
	for (int v : adj[u])
		a.pb(dfs(v));
	
	return g[u] = mex(a);
}

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	inv = pot(n + 1, mod - 2);
	
	forn (i, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}
	
	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			dfs(i);
		
		cn[g[i]]++;
		sz = max(sz, g[i]);
	}
	
	n = 1;
	while (n <= sz)
		n *= 2;
		
	forn (i, n) {
		dp[i].resize(n + 1);
		dp[i][i] = 1;
		dp[i][n] = bool(i) * inv;
		
		forn (j, n)
			(dp[i][j] -= cn[i ^ j] * inv) %= mod;
	}
	
	for (int i = 0, j = 0; i < n; i++) {
		int ind = -1;
		for (int k = j; k < n; k++)
			if (dp[k][i])
				ind = k;
		
		if (ind == -1) continue;
		swap(dp[j], dp[ind]);
		
		ll inv = pot(dp[j][i], mod - 2);
		forn (k, n + 1)
			(dp[j][k] *= inv) %= mod;
		
		forn (k, n)
			if (k != j && dp[k][i]) {
				ll aux = dp[k][i];
				
				forn (l, n + 1)
					(dp[k][l] -= dp[j][l] * aux) %= mod;
			}
		
		j++;
	}
	
	cout << MOD(dp[0][n], mod) << endl;
	
	return 0;
}