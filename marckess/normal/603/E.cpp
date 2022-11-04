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
	Node *p, *l, *r, *pp, *mx;
	int v, sz, vir;
	bool inv;
	
	Node () : p(0), l(0), r(0), pp(0), inv(0), sz(1), vir(0), mx(this), v(0) {}
	Node (int v) : p(0), l(0), r(0), pp(0), inv(0), sz(0), vir(0), mx(this), v(v) {}
};

int size (Node *t) {
	if (t)
		return t->sz;
	return 0;
} 

void update (Node *t) {
	if (t) {
		if (t->pp) t->pp->vir -= t->sz;
		t->sz = size(t->l) + size(t->r) + (1 - bool(t->v)) + t->vir;
		if (t->pp) t->pp->vir += t->sz;

		t->mx = t;
		if (t->l && t->l->mx->v > t->mx->v) t->mx = t->l->mx;
		if (t->r && t->r->mx->v > t->mx->v) t->mx = t->r->mx;
	}
}

void push (Node *t) {
	if (t && t->inv) {
		swap(t->l, t->r);
		if (t->l) t->l->inv ^= 1;
		if (t->r) t->r->inv ^= 1;
		t->inv = 0;
	}
}

void push_anc (Node *t) {
	stack<Node*> st;
	Node *aux = t;

	while (aux) {
		st.push(aux);
		aux = aux->p;
	}

	while (st.size()) {
		push(st.top());
		st.pop();
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

	if (t->pp) t->pp->vir += p->sz - t->sz;
	if (p->pp) p->pp->vir += t->sz - p->sz;

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
	push_anc(t);

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
		
		t->r->p = 0;
		t->r->pp = t;
		t->r = 0;
	}
	
	while (t->pp) {
		t->pp->vir -= t->sz;

		Node *p = t->pp;
		t->pp = 0;
		
		splay(p);
		if (p->r) {
			p->vir += p->r->sz;

			p->r->p = 0;
			p->r->pp = p;
		}

		p->r = t;
		t->p = p;
		rotate(t);
	}
}

void make_root (Node *t) {
	access(t);
	t->inv = 1;
}

Node * find_root (Node *t) {
	access(t);
	while (1) {
		push(t);
		if (!t->l) break;
		t = t->l;
	}
	splay(t);
	
	return t;
}

Node * lca (Node * a, Node * b) {
	access(a), access(b), splay(a);
	return a->pp ? a->pp : a;
}

void link (Node *a, Node *b) {
	access(a), make_root(b);
	a->r = b;
	b->p = a;
	update(a);
}

void cut (Node *a) {
	access(a);

	if (a->pp) {
		a->pp->vir -= a->sz;
		a->pp->vir += a->l->sz;
		update(a->pp);
	}

	a->l->p = 0;
	a->l->pp = a->pp;
	a->pp = 0;
	a->l = 0;

	update(a);
}

void cut (Node *a, Node *b) {
	if (lca(a, b) == a) cut(b);
	else cut(a);
}

Node * greatest (Node * a, Node * b) {
	Node * c = lca(a, b);
	Node * mx = c;

	access(c);
	
	if (a != c) {
		splay(a);
		if (a->l && a->l->mx->v > mx->v)
			mx = a->l->mx;	
	}

	if (b != c) {
		splay(b);
		if (b->l && b->l->mx->v > mx->v)
			mx = b->l->mx;
	}

	return mx;
}

const int MX = 100005;
int n, m, imp;
map<Node*, ii> mp;
set<pair<int, Node*>> res;
Node *st[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	imp = n;

	for (int i = 1; i <= n; i++)
		st[i] = new Node();

	while (m--) {
		int a, b, l, f = 0;
		cin >> a >> b >> l;

		if (find_root(st[a]) != find_root(st[b])) {
			splay(st[a]);
			splay(st[b]);

			if (st[a]->sz % 2) imp--;
			if (st[b]->sz % 2) imp--;
			if ((st[a]->sz + st[b]->sz) % 2) imp++;

			f = 1;
		} else {
			Node * mx = greatest(st[a], st[b]);

			if (mx->v > l) {
				ii p = mp[mx];
				cut(st[p.fi], mx);
				cut(st[p.se], mx);
				mp.erase(mx);
				res.erase({mx->v, mx});

				f = 1;
			}
		}

		if (f) {
			Node * e = new Node(l);
			link(st[a], e);
			link(st[b], e);
			mp[e] = ii(a, b);
			res.emplace(l, e);
		}

		while (!imp && res.size()) {
			auto it = res.end();
			it--;

			ii p = mp[it->se];
			cut(st[p.fi], it->se);

			make_root(st[p.fi]);
			make_root(st[p.se]);

			if (st[p.fi]->sz % 2 || st[p.se]->sz % 2) {
				link(st[p.fi], it->se);
				break;
			} else {
				cut(st[p.se], it->se);
				mp.erase(it->se);
				res.erase(it);
			}
		}

		if (!imp) {
			auto it = res.end();
			it--;
			cout << it->fi << endl;
		} else {
			cout << -1 << endl;
		}
	}

	return 0;
}