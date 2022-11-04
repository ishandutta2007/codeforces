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

const int MX = 500005;
int n, m, k, c[MX], p[MX], col[MX], off[MX], val[MX], cn, a[MX], b[MX];
int p2[MX], f[MX];
ll res;
vi adj[MX];
map<int, vi> mp[MX];

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

ii parent2 (int a) {
	if (a == p2[a]) return {a, 0};
	ii res = parent2(p2[a]);
	if (f[a]) res.se ^= 1;
	return res;
}

void join (int a, int b) {
	p[parent(a)] = parent(b);
}

void dfs (int u) {
	for (int v : adj[u])
		if (c[u] == c[v]) {
			if (col[v] == -1) {
				col[v] = 1 - col[u];
				dfs(v);
			} else if (col[u] == col[v]) {
				val[c[u]] = 0;
			}
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(p, p + MX, 0);
	iota(p2, p2 + MX, 0);
	memset(off, -1, sizeof(off));
	memset(col, -1, sizeof(col));
	
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i++)
		cin >> c[i];
		
	for (int i = 1; i <= k; i++)
		val[i] = 1;
	
	forn (i, m) {
		cin >> a[i] >> b[i];
		
		adj[a[i]].pb(b[i]);
		adj[b[i]].pb(a[i]);
		
		if (c[a[i]] == c[b[i]]) join(a[i], b[i]);
		else {
			int x = c[a[i]];
			int y = c[b[i]];
			if (x > y) swap(x, y);
			mp[x][y].pb(i);
		}
	}
	
	for (int i = 1; i <= n; i++)
		if (col[i] == -1) {
			col[i] = 0;
			dfs(i);
		}
	
	for (int i = 1; i <= k; i++)
		if (val[i])
			cn++;
	
	res = 1ll * cn * (cn - 1) / 2;
	
	for (int j = 1; j <= k; j++) if (val[j])
		for (const auto &it : mp[j]) {
			if (!val[it.fi]) continue;
			
			const vi &v = it.se;
			
			for (int i : v) {
				int pa = parent(a[i]);
				int pb = parent(b[i]);
				
				ii p2a = parent2(pa);
				ii p2b = parent2(pb);
				
				if (p2a.fi == p2b.fi) {
					if ((col[a[i]] ^ p2a.se) == (col[b[i]] ^ p2b.se)) {
						res--;
						break;
					}
				} else {
					p2[p2a.fi] = p2b.fi;
					if ((col[a[i]] ^ p2a.se) == (col[b[i]] ^ p2b.se))
						f[p2a.fi] = 1;
				}
			}
			
			for (int i : v) {
				int pa = parent(a[i]);
				int pb = parent(b[i]);
				p2[pa] = pa;
				p2[pb] = pb;
				f[pa] = f[pb] = 0;
			}
		}
	
	cout << res << endl;
	
	return 0;
}