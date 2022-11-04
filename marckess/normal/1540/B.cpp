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

const int MX = 205, mod = 1000000007;
int n, sz[MX], p[MX];
ll mem[MX][MX], inv2;
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

void dfs (int u) {
	sz[u] = 1;
	
	for (int v : adj[u])
		if (v != p[u]) {
			p[v] = u;
			dfs(v);
			sz[u] += sz[v];
		}
}

ll dp (int i, int j) {
	if (!i) return 1;
	if (!j) return 0;
	
	ll &res = mem[i][j];
	if (res != -1) return res;
	
	return res = (dp(i - 1, j) + dp(i, j - 1)) * inv2 % mod;
}

void solve () {
	cin >> n;
	
	forn (i, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	ll res = 0;
	ll inv = pot(n, mod - 2);
	
	for (int i = 1; i < n; i++) {
		p[i] = -1;
		dfs(i);
		
		for (int j = i + 1; j <= n; j++) {
			ll x = sz[j];
			
			int u = p[j];
			vi v;
			
			while (u != i && u != -1) {
				v.pb(u);
				u = p[u];
			}
			
			int ant = j;
			forn (k, v.size()) {
				(x += ll(sz[v[k]] - sz[ant]) * dp(k + 1, (int)v.size() - k)) %= mod;
				ant = v[k];
			}
			
			(res += x * inv) %= mod;
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(mem, -1, sizeof(mem));
	
	inv2 = pot(2, mod - 2);
	
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
	
	return 0;
}