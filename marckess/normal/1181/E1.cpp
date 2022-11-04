#include <bits/stdc++.h>
 
//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
//typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;

struct List {
	List *nex, *pre;
	int i;
	List(int i) : nex(0), pre(0), i(i) {}
};

int n, a[MX], b[MX], c[MX], d[MX], q[MX];
List *la[MX], *lb[MX], *lc[MX], *ld[MX];

List *makeList (List *l[MX]) {
	List *r = new List(-1), *ant = r;
	forn(i, n) {
		List *act = new List(q[i]);
		ant->nex = act;
		act->pre = ant;
		ant = act;
		l[q[i]] = act;
	}
	return r;
}

vi makeSmall (List *r, List *t) {
	vi v;
	r = r->nex;
	while (r != t) {
		v.pb(r->i);
		r = r->nex;
	}
	return v;
}

bool go (List *ra, List *rb, List *rc, List *rd, int n);

void reloc (List *l[MX], List *nl, int x) {
	List *elem = l[x];
	List *pre = elem->pre;
	List *nex = elem->nex;
	pre->nex = nex;
	if (nex) nex->pre = pre;
	elem->pre = nl;
	elem->nex = 0;
	nl->nex = elem;
}

bool trans (List *ra, List *rb, List *rc, List *rd, int n, vi &v) {
	List *na = new List(-1), *ta = na;
	List *nb = new List(-1), *tb = nb;
	List *nc = new List(-1), *tc = nc;
	List *nd = new List(-1), *td = nd;

	sort(all(v), [&] (int i, int j) { return a[i] < a[j]; } );
	for (int x : v) { reloc(la, ta, x); ta = ta->nex; }

	sort(all(v), [&] (int i, int j) { return b[i] < b[j]; } );
	for (int x : v) { reloc(lb, tb, x); tb = tb->nex; }

	sort(all(v), [&] (int i, int j) { return c[i] > c[j]; } );
	for (int x : v) { reloc(lc, tc, x); tc = tc->nex; }

	sort(all(v), [&] (int i, int j) { return d[i] > d[j]; } );
	for (int x : v) { reloc(ld, td, x); td = td->nex; }

	return go(na, nb, nc, nd, v.size()) && go(ra, rb, rc, rd, n - v.size());
}

bool go (List *ra, List *rb, List *rc, List *rd, int n) {
	if (n < 2) return 1;

	List *ta = ra->nex; int ma = 0;
	List *tb = rb->nex; int mb = 0;
	List *tc = rc->nex; int mc = 1e9;
	List *td = rd->nex; int md = 1e9;

	forn(i, n) {
		if (i && ma <= a[ta->i]) {
			vi v = makeSmall(ra, ta);
			return trans(ra, rb, rc, rd, n, v);
		}
		if (i && mb <= b[tb->i]) {
			vi v = makeSmall(rb, tb);
			return trans(ra, rb, rc, rd, n, v);
		}
		if (i && mc >= c[tc->i]) {
			vi v = makeSmall(rc, tc);
			return trans(ra, rb, rc, rd, n, v);
		}
		if (i && md >= d[td->i]) {
			vi v = makeSmall(rd, td);
			return trans(ra, rb, rc, rd, n, v);
		}

		ma = max(ma, c[ta->i]); ta = ta->nex;
		mb = max(mb, d[tb->i]); tb = tb->nex;
		mc = min(mc, a[tc->i]); tc = tc->nex;
		md = min(md, b[td->i]); td = td->nex;
	}

	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n;
	forn(i, n) cin >> a[i] >> b[i] >> c[i] >> d[i];
	iota(q, q+n, 0);

	sort(q, q+n, [&] (int i, int j) { return a[i] < a[j]; });
	List *ra = makeList(la);

	sort(q, q+n, [&] (int i, int j) { return b[i] < b[j]; });
	List *rb = makeList(lb);

	sort(q, q+n, [&] (int i, int j) { return c[i] > c[j]; });
	List *rc = makeList(lc);

	sort(q, q+n, [&] (int i, int j) { return d[i] > d[j]; });
	List *rd = makeList(ld);

	if (go(ra, rb, rc, rd, n)) cout << "YES" << endl;
	else cout << "NO" << endl;
 
	return 0;
}