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

const int MX = 100005;
int n, k, a[MX], res[MX];
int acu[MX][44];
vi adj[MX];

void dfs (int u, int p) {
	acu[u][0] = a[u];
	
	for (int v : adj[u])
		if (v != p) {
			dfs(v, u);
			
			forn (i, 2 * k)
				acu[u][(i + 1) % (2 * k)] ^= acu[v][i];
		}
}

void dfs (int u, int p, vi w) {
	for (int i = k; i < 2 * k; i++)
		res[u] ^= acu[u][i] ^ w[i];
	res[u] = res[u] && 1;
	
	for (int i = 2 * k - 2; i >= 0; i--)
		swap(w[i], w[i + 1]);
	
	forn (i, 2 * k)
		w[(i + 1) % (2 * k)] ^= acu[u][i];
	
	for (int v : adj[u])
		if (v != p) {
			vi x = w;
			
			forn (i, 2 * k)
				x[(i + 2) % (2 * k)] ^= acu[v][i];
			
			dfs(v, u, x);
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	forn (i, n)
		cin >> a[i + 1];
	
	dfs(1, 1);
	
	vi w(2 * k);
	dfs(1, 1, w);
	
	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;
	
	return 0;
}