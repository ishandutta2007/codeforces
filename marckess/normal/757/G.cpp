#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

struct Node {
	int u, cn;
	ll sum, con;
	vector<Node*> to;
	
	Node (int u, int cn, ll sum, ll con, vector<Node*> to) : u(u), cn(cn), sum(sum), con(con), to(to) {}
};

const int MX = 400005, LG = 19;
int n, q, a[MX], cn, sz[MX], ex[MX], par[MX];
ll w[LG][MX], res;
vii adj[MX], aux[MX];
Node *st[MX];

void dfs (int u, int p) {
	vii h;
	
	for (ii &v : adj[u])
		if (v.fi != p) {
			dfs(v.fi, u);
			h.pb(v);
		}
	
	if (h.size() <= 2) aux[u] = h;
	else {
		aux[u] = {h[0], {cn + 1, 0}};
		
		for (int i = 1; i + 1 < h.size(); i++) {
			aux[cn + i].pb(h[i]);
			
			if (i + 2 < h.size())
				aux[cn + i].pb({cn + i + 1, 0});
			else
				aux[cn + i].pb(h[i + 1]);
		}
		
		cn += (int)h.size() - 2;
	}
}

void pre (int u, int p) {
	sz[u] = 1;
	
	for (ii &v : adj[u])
		if (v.fi != p) {
			pre(v.fi, u);
			sz[u] += sz[v.fi];
		}
}

void dfs (int u, int p, int lvl, ll to) {
	w[lvl][u] = to;
	
	for (ii &v : adj[u])
		if (v.fi != p && !ex[v.fi])
			dfs(v.fi, u, lvl, to + v.se);
}

Node * cen (int u, int lvl) {
	while (1) {
		int ind = -1;
		
		for (ii &v : adj[u])
			if (!ex[v.fi])
				if (2 * sz[v.fi] > sz[u])
					ind = v.fi;
		
		if (ind == -1) break;
		
		sz[u] -= sz[ind];
		sz[ind] += sz[u];
		u = ind;
	}
	
	ex[u] = 1;
	dfs(u, u, lvl, 0);
	
	Node *n = new Node(u, 0, 0, 0, {});
	
	
	for (ii &v : adj[u])
		if (!ex[v.fi]) {
			Node *m = cen(v.fi, lvl + 1);
			par[m->u] = u;
			n->to.pb(m);
		}
	
	return n;
}

Node * update (Node *r, int a) {
	vi v;
	for (int i = a; i; i = par[i])
		v.pb(i);
	reverse(all(v));
	
	vector<Node*> n;
	n.pb(new Node(r->u, r->cn, r->sum, r->con, r->to));
	
	forn (i, v.size()) {
		Node *act = n.back();
		
		act->sum += w[i][a];
		act->cn++;
		
		if (i) act->con += w[i - 1][a];
		
		if (i + 1 < v.size()) {
			vector<Node*> n_to;
			
			for (Node *to : act->to)
				if (to->u == v[i + 1])
					n.pb(new Node(to->u, to->cn, to->sum, to->con, to->to));
				else
					n_to.pb(to);
			
			n_to.pb(n.back());
			act->to = n_to;
		}		
	}
	
	return n[0];
}

ll query (Node *r, int a) {
	vi v;
	for (int i = a; i; i = par[i])
		v.pb(i);
	reverse(all(v));
	
	ll res = 0;
	
	forn (i, v.size()) {
		res += (r->sum - r->con) + r->cn * (w[i][a] - (i ? w[i - 1][a] : 0));
		if (i + 1 < v.size()) {
			
			for (Node *to : r->to)
				if (to->u == v[i + 1]) {
					r = to;
					break;
				}
			}
	}
	
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	forn (i, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	
	cn = n;
	dfs(1, 1);
	
	for (int i = 1; i <= n; i++)
		adj[i].clear();
		
	n = cn;
	for (int u = 1; u <= n; u++)
		for (ii v : aux[u]) {
			adj[u].pb(v);
			adj[v.fi].pb({u, v.se});
		}
	
	pre(1, 1);
	st[0] = cen(1, 0);
	
	for (int u = 1; u <= n; u++) {
		adj[u].clear();
		aux[u].clear();
	}
	
	for (int i = 1; i <= n; i++)
		st[i] = update(st[i - 1], a[i]);
	
	forn (i, q) {
		int t;
		cin >> t;
		
		if (t == 1) {
			int l, r, v;
			cin >> l >> r >> v;
			l ^= res;
			r ^= res;
			v ^= res;
			
			res = query(st[r], v) - query(st[l - 1], v);
			cout << res << endl;
			res &= (1 << 30) - 1;
		} else {
			int x;
			cin >> x;
			x ^= res;
			
			swap(a[x], a[x + 1]);
			st[x] = update(st[x - 1], a[x]);
		}
	}
	
	return 0;
}