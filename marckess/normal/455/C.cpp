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

		if (rk[a] > rk[b]) {
			p[b] = a;
		} else {
			p[a] = b;
			if (rk[a] == rk[b])
				rk[b]++;
		}

		return 1;
	}
};

int n, m, q, a, b, op, d[300'005] = {0};
vvi adj(3e5+5);
DSU ds(3e5);

bitset<300'005> vis;
ii dfs (int u, int p) {
	vis[u] = 1;

	ii res = {-1, -1};
	for (int v : adj[u]) {
		if (v == p)
			continue;
		ii d = dfs(v, u);
		if (d.se > res.se)
			res = d;
	}

	if (res.fi == -1)
		return {u, 0};
	return {res.fi, res.se+1};
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m >> q;
    while (m--) {
    	cin >> a >> b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    	ds.joint(a, b);
    }

    for (int i = 1; i <= n; i++) {
    	if (vis[i])
    		continue;
    	d[ds.parent(i)] = dfs(dfs(i, -1).fi, -1).se;
    }

    while (q--) {
    	cin >> op;
    	if (op == 1) {
    		cin >> a;
    		cout << d[ds.parent(a)] << endl;
    	} else {
    		cin >> a >> b;
    		a = ds.parent(a), b = ds.parent(b);

    		if (a != b) {
    			ds.joint(a, b);
    			d[ds.parent(a)] = max(max(d[a], d[b]), (d[a] + 1) / 2 + (d[b] + 1) / 2 + 1);
    		}
    	}
    }

    return 0;
}