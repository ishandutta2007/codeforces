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

const int MX = 100005, LG = 18, mod = 1000000007;
int n, p[MX][LG], lvl[MX];
ll x[MX], g[MX][LG], res;
vi adj[MX];

void dfs (int u) {
	for (int v : adj[u])
		if (v != p[u][0]) {
			p[v][0] = u;
			g[v][0] = __gcd(x[u], x[v]);
			lvl[v] = lvl[u] + 1;
			dfs(v);
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i];

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	p[1][0] = 1;
	dfs(1);

	for (int j = 1; j < LG; j++)
		for (int i = 1; i <= n; i++) {
			p[i][j] = p[p[i][j-1]][j-1];
			g[i][j] = __gcd(g[i][j-1], g[p[i][j-1]][j-1]);
		}

	for (int i = 1; i <= n; i++) {
		ll act = x[i];
		int u = i;

		while (1) {
			int k = lvl[u];

			for (int j = LG - 1; j >= 0; j--)
				if (__gcd(act, g[u][j]) == act)
					u = p[u][j];
			res += act * (k - lvl[u] + 1);
			res %= mod;

			if (u == 1)
				break;
			
			u = p[u][0];
			act = __gcd(act, x[u]);
		}
	}

	cout << res << endl;

	return 0;
}