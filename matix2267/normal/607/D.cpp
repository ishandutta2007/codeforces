#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
	#define DEB printf
#else
	#define DEB(...)
#endif

typedef long long ll;
typedef long long LL;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int mod = 1000000007;
const int MAXN = 1000006;

struct node {
	node *c[2], *p;
	int val, val2, mnoz, mn, ans, anss;
	bool hasp() { return p && (p->c[0]==this || p->c[1]==this); }
	int dir(node *n) { return c[0] != n; }
	void upd() {
		int ansl = c[0] ? c[0]->ans : 0;
		int ansr = c[1] ? c[1]->ans : 0;
		int mnl = c[0] ? c[0]->mn : 1;
		int mnr = c[1] ? c[1]->mn : 1;
		mn = 1LL*mnoz*mnl%mod*mnr%mod;
		anss = (1LL*(0LL+val+val2+ansr)*mnoz) % mod;
		ans = (ansl + (1LL*(0LL+val+val2+ansr)*mnoz%mod*mnl)) % mod;
	}
	void push() {}
	void pull() {}
//	void pull() { if(hasp()) p->pull(); push(); }
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
	for(; n; n = n->p) {
		splay(n);
		if(n->c[1]) n->val2 = (n->val2 + n->c[1]->ans) % mod;
		n->c[1] = m;
		if(n->c[1]) n->val2 = (n->val2 - n->c[1]->ans + mod) % mod;
		n->upd();
		m = n;
	}
	splay(on);
}

// n must be root, m must be in different tree
void link(node *n, node *m) {
	splay(n);
	assert(!n->c[0]); // n is root
	activate(m);
	n->c[0] = m;
	m->p = n;
	m->mnoz++;
	m->upd();
	n->upd();
}

node MEM[210000];

void solve() {
	int v0,q,next=1;
	scanf("%d%d",&v0,&q);
	MEM[0].val = v0;
	MEM[0].mnoz = 1;
	MEM[0].upd();
	fru(qq,q) {
		int tt;
		scanf("%d",&tt);
		if(tt==1) {
			int p,v;
			scanf("%d%d",&p,&v);
			p--;
			MEM[next].val = v;
			MEM[next].mnoz = 1;
			link(&MEM[next], &MEM[p]);
			next++;
		}
		if(tt==2) {
			int p;
			scanf("%d",&p);
			p--;
			activate(&MEM[p]);
			printf("%d\n",MEM[p].anss);
		}
	}
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}