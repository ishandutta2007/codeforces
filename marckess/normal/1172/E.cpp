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

struct Node {
	Node *p, *l, *r, *pp;
	int sz, vir;
	ll vir2;
	Node () : p(0), l(0), r(0), pp(0), sz(1), vir(0), vir2(0) {}
};

#define sq(n) (ll(n)*(n))

int size (Node *t) {
	if (t)
		return t->sz;
	return 0;
} 

void update (Node *t) {
	if (t) {
		if (t->pp) {
			t->pp->vir -= t->sz;
			t->pp->vir2 -= sq(t->sz);
		}

		t->sz = size(t->l) + size(t->r) + 1 + t->vir;
		
		if (t->pp) {
			t->pp->vir += t->sz;
			t->pp->vir2 += sq(t->sz);
		}
	}
}

void rotate (Node *t) {
	if (!t || !t->p) return;

	Node *p = t->p;

	if (t == p->l) {
		p->l = t->r;
		t->r = p;
	} else {
		p->r = t->l;
		t->l = p;
	}

	t->p = p->p;
	p->p = t;

	if (t->pp) {
		t->pp->vir += p->sz - t->sz;
		t->pp->vir2 += sq(p->sz) - sq(t->sz);
	}
	if (p->pp) {
		p->pp->vir += t->sz - p->sz;
		p->pp->vir2 += sq(t->sz) - sq(p->sz);
	}

	swap(t->pp, p->pp);

	if (p->l) p->l->p = p; 
	if (p->r) p->r->p = p;
	
	if (t->p) {
		if (t->p->l == p)
			t->p->l = t;
		else
			t->p->r = t;
	}

	update(p);
	update(t);
}

void splay (Node *t) {
	if (!t) return;

	while (t->p) {
		Node *p = t->p, *gp = p->p;

		if (gp) {
			if ((t == p->l) == (p == gp->l))
				rotate(p);
			else 
				rotate(t);
		}

		rotate(t);
	} 
}

void access (Node *t) {
	splay(t);
	
	if (t->r) {
		t->vir += t->r->sz;
		t->vir2 += sq(t->r->sz);
		
		t->r->p = 0;
		t->r->pp = t;
		t->r = 0;
	}
	
	while (t->pp) {
		t->pp->vir -= t->sz;
		t->pp->vir2 -= sq(t->sz);

		Node *p = t->pp;
		t->pp = 0;
		
		splay(p);
		if (p->r) {
			p->vir += p->r->sz;
			p->vir2 += sq(p->r->sz);

			p->r->p = 0;
			p->r->pp = p;
		}

		p->r = t;
		t->p = p;
		rotate(t);
	}

	update(t);
}

Node * find_root (Node *t) {
	access(t);
	while (1) {
		if (!t->l) break;
		t = t->l;
	}
	access(t);
	
	return t;
}

void link (Node *a, Node *b) {
	access(a), access(b);
	a->r = b;
	b->p = a;
	update(a);
}

void cut (Node *a) {
	access(a);
	Node *aux = a->l;
	
	a->l->p = 0;
	a->l = 0;

	access(a);
	access(aux);
}

const int MX = 400005;
int n, m, c[MX], p[MX];
ll res[MX];
vi pos[MX], adj[MX];
set<ii> op[MX];
Node *st[MX];

void dfs (int u) {
	for (int v : adj[u])
		if (v != p[u]) {
			link(st[u], st[v]);
			p[v] = u;
			dfs(v);
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		st[i] = new Node;
		pos[c[i]].pb(i);
	}

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	st[0] = new Node;
	link(st[0], st[1]);
	dfs(1);

	for (int i = 1; i <= m; i++) {
		int u, x;
		cin >> u >> x;

		op[c[u]].emplace(i, -u);
		c[u] = x;
		op[c[u]].emplace(i, u);
	}

	for (int i = 1; i <= n; i++) {
		set<int> in;
		if (!pos[i].size() && !op[i].size()) continue;

		for (int u : pos[i]) {
			res[0] += find_root(st[u])->vir2;
			cut(st[u]);
			in.insert(u);
			res[0] -= find_root(st[u])->vir2;
			res[0] -= find_root(st[p[u]])->vir2;
		}

		for (ii v : op[i]) {
			int i = v.fi;

			if (v.se < 0) {
				
				res[i] += find_root(st[-v.se])->vir2;
				res[i] += find_root(st[p[-v.se]])->vir2;
				
				link(st[p[-v.se]], st[-v.se]);
				in.erase(-v.se);
				
				res[i] -= find_root(st[-v.se])->vir2;
			} else {
				res[i] += find_root(st[v.se])->vir2;
				
				cut(st[v.se]);
				in.insert(v.se);
				
				res[i] -= find_root(st[v.se])->vir2;
				res[i] -= find_root(st[p[v.se]])->vir2; 
			}
		}

		for (int x : in)
			link(st[p[x]], st[x]);
	}

	for (int i = 0; i <= m; i++) {
		if (i) res[i] += res[i-1];
		cout << res[i] << endl;
	}

	return 0;
}