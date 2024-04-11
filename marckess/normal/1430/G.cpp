#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 18;
int n, m, cn[MX], res[MX];
int f[MX], sz, val[MX], to[MX], vis[MX], inv[MX];
int mem[1 << MX][MX];
vi adj[MX];

void dfs (int u) {
	vis[u] = 1;
	
	for (int v : adj[u])
		if (!vis[v])
			dfs(v);
	
	inv[sz] = u;
	f[u] = sz++;
}

int dp (int mk, int i) {
	if (!mk) return 0;
	if (i < 0) return dp(mk, n - 1);
	
	int &res = mem[mk][i];
	if (res != -1) return res;
	res = 1e9;
	
	if (!(mk & (1 << i))) return res = dp(mk, i - 1);
	
	if (!(mk & to[i])) res = min(res, dp(mk ^ (1 << i), i - 1));
	
	res = min(res, dp(mk, i - 1) + val[i]);
	
	return res;
}

void rec (int mk, int i) {
	if (!mk) return;
	if (i < 0) return rec(mk, n - 1);
	
	if (!(mk & (1 << i))) return rec(mk, i - 1);
	
	if (!(mk & to[i]) && dp(mk, i) == dp(mk ^ (1 << i), i - 1))
		return rec(mk ^ (1 << i), i - 1);
	
	res[inv[i]]++;
	return rec(mk, i - 1);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	forn (i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		
		adj[a].pb(b);
		
		cn[a] += c;
		cn[b] -= c;
	}
	
	forn (i, n) if (!vis[i]) dfs(i);
	
	forn (i, n) {
		for (int j : adj[i]) to[f[i]] |= 1 << f[j];
		val[f[i]] = cn[i];
	}
	
	memset(mem, -1, sizeof(mem));
	dp((1 << n) - 1, n - 1);
	rec((1 << n) - 1, n - 1);
	
	forn (i, n) cout << res[i] << " ";
	cout << endl;
	
	return 0;
}