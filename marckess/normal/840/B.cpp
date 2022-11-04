#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

struct DSU {
	vi p, rk;

	DSU (int n) : p(n+1), rk(n+1) {
		iota(p.begin(), p.end(), 0);
	}

	int parent (int a) {
		return a == p[a] ? a : p[a] = parent(p[a]);
	}

	bool joint (int a, int b) {
		a = parent(a), b = parent(b);
		if (a == b)
			return 0;

		if (rk[a] < rk[b]) {
			p[a] = b;
		} else {
			p[b] = a;
			if (rk[a] == rk[b])
				rk[a]++;
		}

		return 1;
	}
};

int n, m, u[300005], v[300005], d[300005], pd = 0;
vvii adj(3e5+5);
vi res, ed(3e5+5);
bitset<300005> vis;
DSU ds(0);

void kruskal () {
	ds = DSU(n);
	for (int i = 1; i <= m; i++) {
		if (ds.joint(u[i], v[i])) {
			adj[u[i]].emplace_back(v[i], i);
			adj[v[i]].emplace_back(u[i], i);
		}
	}
}

int dfs (int u) {
	int cn = 0;
	vis[u] = 1;

	for (ii &v : adj[u]) {
		if (vis[v.fi])
			continue;
		ed[v.fi] = v.se;
		cn ^= dfs(v.fi);
	}

	if (d[u] == 1)
		cn ^= 1;

	if (cn)
		res.push_back(ed[u]);
	return cn;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
    	cin >> d[i];
    	if (d[i] == 1)
    		pd ^= 1;
    }
    for (int i = 1; i <= m; i++)
    	cin >> u[i] >> v[i];

    if (pd) {
    	for (int i = 1; i <= n; i++) {
    		if (d[i] == -1) {
    			d[i] = 1;
    			pd = 0;
    			break;
    		}
    	}
    }

    if (pd) {
    	cout << -1 << endl;
    	return 0;
    }

    kruskal();
    dfs(1);

    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (int x : res)
    	cout << x << endl;

    return 0;
}