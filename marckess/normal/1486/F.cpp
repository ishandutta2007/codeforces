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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005, LG = 20;
int n, m, lvl[MX], p[LG][MX], a[MX], b[MX], s1[MX], s2[MX], s3[MX];
ll res, off;
vi adj[MX], in[MX];
map<ii, int> mp[MX];

void dfs (int u) {
	for (int v : adj[u])
		if (v != p[0][u]) {
			p[0][v] = u;
			lvl[v] = lvl[u] + 1;
			dfs(v);
		}
}

int LCA (int u, int v) {
	if (lvl[u] < lvl[v]) swap(u, v);
	
	forn (j, LG)
		if ((lvl[u] - lvl[v]) & (1 << j))
			u = p[j][u];
	
	if (u == v) return u;
	
	for (int j = LG - 1; j >= 0; j--)
		if (p[j][u] != p[j][v]) {
			u = p[j][u];
			v = p[j][v];
		}
	
	return p[0][u];
}

int find (int u, int to) {
	for (int j = LG - 1; j >= 0; j--)
		if (lvl[p[j][u]] > lvl[to])
			u = p[j][u];
	return u;
}

void d2 (int u) {
	for (int v : adj[u])
		if (v != p[0][u]) {
			d2(v);
			s1[u] += s1[v];
			s2[u] += s2[v];
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	p[0][1] = 1;
	dfs(1);
	
	for (int j = 1; j < LG; j++)
		for (int i = 1; i <= n; i++)
			p[j][i] = p[j - 1][p[j - 1][i]];
		
	cin >> m;
	forn (i, m)
		cin >> a[i] >> b[i];
	
	forn (i, m) {
		int lca = LCA(a[i], b[i]);
		s1[a[i]]++;
		s1[b[i]]++;
		s1[lca]--;
		if (lca != 1) s1[p[0][lca]]--;
		
		s2[a[i]]++;
		s2[b[i]]++;
		s2[lca] -= 2;
		
		s3[lca]++;
		in[lca].pb(i);
		
		if (a[i] != lca && b[i] != lca) {
			ii p = ii(find(a[i], lca), find(b[i], lca));
			if (p.fi > p.se) swap(p.fi, p.se);
			mp[lca][p]++;
		}
	}
	
	d2(1);
	
	forn (i, m) {
		int lca = LCA(a[i], b[i]);
		
		res += s1[lca];
		if (a[i] != lca) res -= s2[find(a[i], lca)];
		if (b[i] != lca) res -= s2[find(b[i], lca)];
		if (a[i] != lca && b[i] != lca) {
			ii p = ii(find(a[i], lca), find(b[i], lca));
			if (p.fi > p.se) swap(p.fi, p.se);
			res += mp[lca][p];
		}
	}
	
	for (int lca = 1; lca <= n; lca++) {
		map<int, int> cn;
		
		for (int i : in[lca]) {
			if (a[i] != lca) cn[find(a[i], lca)]++;
			if (b[i] != lca) cn[find(b[i], lca)]++;
		}
		
		for (int i : in[lca]) {
			off += s3[lca];
			if (a[i] != lca) off -= cn[find(a[i], lca)];
			if (b[i] != lca) off -= cn[find(b[i], lca)];
			if (a[i] != lca && b[i] != lca) {
				ii p = ii(find(a[i], lca), find(b[i], lca));
				if (p.fi > p.se) swap(p.fi, p.se);
				off += mp[lca][p];
			}
		}
	}
	
	forn (i, m)
		if (a[i] == b[i])
			off++;
	
	cout << res - off / 2 << endl;
	
	return 0;
}