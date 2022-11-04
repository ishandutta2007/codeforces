#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5005, mod = 998244353;
int n, k, dp[MX][MX], acu[MX][MX], der[MX];
vi adj[MX];

void dfs (int u, int p) {
	for (int v : adj[u])
		if (v != p)
			dfs(v, u);
	
	for (int h = 0; h <= k; h++) {
		int ot = min(h, k - h) - 1;
		
		int m = 1;
		der[0] = 1;
		ll x = 1;
		
		for (int v : adj[u])
			if (v != p) {
				ll fac = 0;
				if (ot >= 0)
					fac = acu[v][ot];
				fac += acu[v][k];
				
				(x *= fac) %= mod;
				der[m] = x;
				m++;
			}
		
		reverse(all(adj[u]));
		reverse(der, der + m);
		
		if (!h)
			dp[u][h] = x;
		else {
			ll izq = 1;
			int ot = min(h - 1, k - h) - 1;
			int ind = 1;
			
			for (int v : adj[u])
				if (v != p) {
					dp[u][h] += izq * dp[v][h - 1] % mod * der[ind] % mod;
					if (dp[u][h] >= mod) dp[u][h] -= mod;
					
					ind++;
					
					ll fac = 0;
					if (ot >= 0)
						fac = acu[v][ot];
					fac += acu[v][k];
					
					(izq *= fac) %= mod;
				}
		}
	}
	
	forn (i, k + 1) {
		acu[u][i] = dp[u][i];
		if (i) {
			acu[u][i] += acu[u][i - 1];
			if (acu[u][i] >= mod)
				acu[u][i] -= mod;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	
	forn (i, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	dfs(1, 1);
	cout << acu[1][k] << endl;
	
	return 0;
}