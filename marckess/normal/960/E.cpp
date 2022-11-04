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
typedef vector<ii> vii;

const int MX = 200005, mod = 1000000007;
int n, par[MX];
ll a[MX], cn[MX][2], up[MX][2], sz[MX], res;
vi adj[MX];

void dfs (int u, int p = -1) {
	sz[u] = 1;
	cn[u][0] = 1;
	par[u] = p;

	for (int v : adj[u])
		if (v != p) {
			dfs(v, u);
			cn[u][0] += cn[v][1];
			cn[u][1] += cn[v][0];
			sz[u] += sz[v];
		}
}

void go (int u, int p = -1) {
	for (int v : adj[u])
		if (v != p) {
			up[v][0] = up[u][1] + cn[u][1] - cn[v][0];
			up[v][1] = up[u][0] + cn[u][0] - cn[v][1];
			go(v, u);
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs(1);
	go(1);

	for (int u = 1; u <= n; u++) {
		(res += a[u] * n) %= mod;

		for (int v : adj[u]) {
			if (v != par[u]) {
				(res += a[u] * cn[v][1] % mod * (n - sz[v])) %= mod;
				(res -= a[u] * cn[v][0] % mod * (n - sz[v])) %= mod;
			} else {
				(res += a[u] * up[u][0] % mod * sz[u]) %= mod;
				(res -= a[u] * up[u][1] % mod * sz[u]) %= mod;
			}
		}
	}

	cout << MOD(res, mod) << endl;

	return 0;
}