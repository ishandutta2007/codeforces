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

const int MX = 200005, LG = 20;
int n, k, x[MX], p[MX][LG], lvl[MX], in[MX];
vi adj[MX];

void dfs1 (int u) {
	for (int v : adj[u])
		if (v != p[u][0]) {
			p[v][0] = u;
			lvl[v] = lvl[u] + 1;
			dfs1(v);
		}
}

int res, f;
void dfs2 (int u) {
	if (in[u]) {
		res++;
		return;
	}
	if (u != 1 && adj[u].size() == 1) {
		f = 0;
		return;
	}
	
	for (int v : adj[u])
		if (v != p[u][0])
			dfs2(v);
}

void main_() {
	cin >> n >> k;
	forn (i, k)
		cin >> x[i];
	
	forr (i, 1, n) {
		adj[i].clear();
		in[i] = 0;
	}
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	p[1][0] = 1;
	lvl[1] = 0;
	dfs1(1);
	
	forr (j, 1, LG - 1)
		forr (i, 1, n)
			p[i][j] = p[p[i][j - 1]][j - 1];
	
	forn (i, k) {
		int u = x[i], k = lvl[u] / 2;
		forn (j, LG)
			if (k & (1 << j))
				u = p[u][j];
		in[u] = 1;
	}
	
	res = 0, f = 1;
	dfs2(1);
	
	if (f) cout << res << endl;
	else cout << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}