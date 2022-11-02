#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 0
	#define DEB printf
#else
	#define DEB(...)
#endif

typedef long long ll;
typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int mod = 1000000007;
const int MAXN = 1000006;

struct node {
	node *c[2], *p;
	int va, mva; node *mvw;
	bool rev; /// is reversed
	bool pa, invp; /// parity
	bool hasp() { return p && (p->c[0]==this || p->c[1]==this); }
	int dir(node *n) { return c[0] != n; }
	void upd() {
		mva = va; mvw = this; fru(i,2) if(c[i] && c[i]->mva > mva) { mva = c[i]->mva; mvw = c[i]->mvw; }
	}
	void push() {
		if(rev) { swap(c[0],c[1]); fru(i,2) if(c[i]) c[i]->rev ^= 1; } rev = 0;
		if(invp) { pa ^= 1; fru(i,2) if(c[i]) c[i]->invp ^= 1; } invp = 0;
	}
	void pull() { if(hasp()) p->pull(); push(); }
};

void rot(node *n, int d) {
	node *m = n->c[d];
	if((n->c[d] = m->c[!d])) n->c[d]->p = n;
	m->c[!d] = n;
	if(n->hasp()) n->p->c[n->p->dir(n)] = m;
	m->p = n->p;
	n->p = m;
	n->upd();
	m->upd();
}

void splay(node *n) {
	n->pull();
	while(n->hasp()) {
		node *p1 = n->p, *p2 = p1->p;
		if(!p1->hasp()) return rot(p1,p1->dir(n));
		int d1 = p1->dir(n), d2 = p2->dir(p1);
		if(d1 == d2) swap(p1,p2);
		rot(p1,d1);
		rot(p2,d2);
	}
}

void activate(node *n) {
	node *on = n, *m = NULL;
	for(; n; n = n->p) { splay(n); n->c[1] = m; n->upd(); m = n; }
	splay(on);
}

node* findroot(node *n) {
	activate(n);
	while(n->c[0]) n = n->c[0];
	splay(n);
	return n;
}

node * base;
// cut n from parent
void cut(node *n) {
	DEB("cut %d\n",n-base);
	activate(n);
	assert(n->c[0]); // n has parent
	n->c[0]->p = NULL;
	n->c[0] = NULL;
	n->upd();
}

// n must be root, m must be in different tree
void link(node *n, node *m) {
	DEB("link %d %d\n",n-base,m-base);
	splay(n);
	assert(!n->c[0]); // n is root
	activate(m);
	n->c[0] = m;
	m->p = n;
	n->upd();
}

node* aggregate_va(node *n) {
	activate(n);
	return n->mvw;
}

// make n root of its tree
void chgroot(node *n) {
	DEB("chgroot %d\n",n-base);
	activate(n);
	n->rev ^= 1;
}

struct cmp {
	bool operator() (node *a, node *b) {
		if(a->va != b->va) return a->va < b->va;
		return a<b;
	}
};

void solve() {
	int n,m;
	scanf("%d%d",&n,&m);
	if(n%2) { fru(j,m) puts("-1"); return; }
	vector<node> V(n+m+n-1); base = &V[0];
	fru(i,n) V[i].va = -1;
	vector<pii> E(m+n-1);
	set<node*, cmp> S;
	fru(i,n-1) {
		V[n+m+i].pa = (i+1)%2;
		V[n+m+i].va = inft;
		chgroot(&V[i]);
		chgroot(&V[i+1]);
		link(&V[i], &V[n+m+i]);
		link(&V[i+1], &V[n+m+i]);
		E[m+i] = pii(i,i+1);
		S.insert(&V[n+m+i]);
	}
	auto ait = S.end();
	fru(j,m) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c); a--; b--;
		node *A = &V[a], *B = &V[b], *C = &V[n+j];
		E[j] = pii(a,b);
		chgroot(A);
		node *D = aggregate_va(B);
		activate(D);
		C->va = c;
		C->pa = D->pa;
		DEB("replace (%d) with %d - %d (%d) par %d\n",D->va,a+1,b+1,c,D->pa);
		if(D->va > C->va) {
			chgroot(A);
			activate(B);
			B->invp ^= D->pa;
			chgroot(D);
			pii pr = E[D-&V[n]];
			cut(&V[pr.x]);
			cut(&V[pr.y]);
			chgroot(A);
			chgroot(B);
			link(A,C);
			link(B,C);
			if(ait != S.end() && *ait == D) ++ait;
			S.erase(D);
			S.insert(C);
		}
		fru(z,10) if(ait != S.end()) ++ait;
		if(ait == S.end()) --ait;
		while(1) {
			activate(*ait);
			DEB("size %d par %d\n",(*ait)->va,(*ait)->pa);
			if((*ait)->pa) break;
			if(ait == S.begin()) assert(0);
			--ait;
		}
		int ans = (*ait)->va;
		printf("%d\n", ans == inft ? -1 : ans);
	}
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}