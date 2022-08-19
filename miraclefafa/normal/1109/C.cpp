#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

struct node {
	node *s[2],*f;
	ll len;
	int key,rt;
	ll ss=0,ms=0;
	void clear() { s[0]=s[1]=f=0;}
	bool dir() { return f->s[1]==this;}
	void setc(node *p,int d) { if (p) p->f=this; s[d]=p;}
	void push() {
	}
	void upd() {
		ss=len; rep(i,0,2) if (s[i]) ss+=s[i]->ss;
		ms=s[1]?s[1]->ms:0;
		ms=len+min(ms,0ll);
		ms=(s[0]?s[0]->ss:0ll)+min(ms,0ll);
		ms=min(ms,s[0]?s[0]->ms:0ll);
	}
};
const int N=501000;
node pool[N],*cur=pool;
stack<node*> tra;
node *newnode(int ts,int rt,int s) {
	node *p=cur++;
	p->key=ts; p->rt=rt;
	p->len=1ll*rt*s;
	p->upd();
	return p;
}
void dispose(node *x) { x->clear();tra.push(x);}

VI vv;
struct Splaytree {
	node *rt;
	void dfs_init(node *x) { if (x) { dfs_init(x->s[0]),dfs_init(x->s[1]);dispose(x);} }
	void init() { dfs_init(rt); rt=0;}
	void rot(node *x) {
		node *p=x->f;
		bool d=x->dir();
		if (p->f) p->f->setc(x,p->dir()); else x->f=p->f;
		p->setc(x->s[!d],d); x->setc(p,!d);
		if (p==rt) rt=x;
		p->upd();
	}
	void splay(node *x,node *f=NULL) {
		node *q=x; stack<node*> sta;
		while (1) { sta.push(q);if (!q->f) break; q=q->f; }
		while (!sta.empty()) sta.top()->push(),sta.pop();
		while (x->f!=f) {
			if (x->f->f==f) rot(x);
			else if (x->dir()==x->f->dir()) rot(x->f),rot(x);
			else rot(x),rot(x);
		}
		x->upd();
	}
	node *prev(node *x) {
		assert(x);
		splay(x);
		node *p=x->s[0];
		if (!p) return 0;
		while (p->s[1]) p=p->s[1];
		return p;
	}
	node *succ(node *x) {
		assert(x);
		splay(x);
		node *p=x->s[1];
		if (!p) return 0;
		while (p->s[0]) p=p->s[0];
		return p;
	}
	void insert(node *x,node *p) {
		splay(x);
		if (!x->s[1]) { x->setc(p,1);x->upd();}
		else {
			splay(succ(x),x);
			x->s[1]->setc(p,0);
			x->s[1]->upd(); x->upd();
		}
	}
	void insert(node *x) {
		if (!rt) rt=x;
		else { node *p=rt; while (p->s[1]) p=p->s[1]; p->setc(x,1);}
		splay(x);
	}
	node* extract(node *l,node *r) {
		node *pl=prev(l),*pr=succ(r);
		assert(pl); assert(pr);
		splay(pl);splay(pr,pl);
		node *p=pr->s[0];
		return p;
	}

	node* extract(node *l) {
		node *pl=prev(l);
		assert(pl);
		splay(pl);
		node *p=pl->s[1];
		return p;
	}

	node* split(node *l,node *r) {
		node *p=extract(l,r);
		p->f->s[p->dir()]=0;
		p->f->upd();
		p->f=0;
		return p;
	}
	void erase(node *p) { split(p,p);dispose(p);}
	void dfs_debug(node *x) {
		if (x->s[0]) dfs_debug(x->s[0]);
//		printf("%d,%d,%lld ",x->key,x->rt,x->len);
		if (x->key>=0) vv.pb(x->key),printf("%d ",x->key);
		if (x->s[1]) dfs_debug(x->s[1]);
	}
	void print() { vv.clear(); puts("DEBUG");dfs_debug(rt); puts("");}
	node* lower_bound(int key) {
		node *p=rt,*q=NULL;
		while (p) {
			if (p->key>=key) q=p,p=p->s[0];
			else p=p->s[1];
		}
		return q;
	}
	void add(node *x) {
		node *q=lower_bound(x->key);
		q=prev(q);
		assert(q);
		insert(q,x);
	}
}T;

int q,ty,t,s,l,r;
ll v;
map<int,int> evt;

int main() {
	scanf("%d",&q);
	evt[0]=0;
	evt[1<<30]=0;
	T.insert(newnode(-1,0,1));
	T.insert(newnode(0,0,1<<30));
	T.insert(newnode(1<<30,0,1));
	rep(i,0,q) {
		scanf("%d",&ty);
		if (ty==1) {
			scanf("%d%d",&t,&s);
			auto it=evt.lower_bound(t),nit=it;
			--it;
			auto c=T.lower_bound(it->fi);
			T.erase(c);
			T.add(newnode(it->fi,it->se,t-it->fi));
			T.add(newnode(t,s,nit->fi-t));
			evt[t]=s;
/*			T.print();
			VI ww;
			for (auto p:evt) ww.pb(p.fi);
			assert(ww==vv);*/
		} else if (ty==2) {
			scanf("%d",&t);
			auto it=evt.lower_bound(t),pit=it,nit=it;
			--pit; ++nit;
			auto c=T.lower_bound(t); T.erase(c);
			c=T.lower_bound(pit->fi); T.erase(c);
			T.add(newnode(pit->fi,pit->se,nit->fi-pit->fi));
			evt.erase(t);
//			T.print();
		} else {
			scanf("%d%d%lld",&l,&r,&v);
			if (v==0) {
				printf("%d\n",l);
				continue;
			}
			auto c=T.lower_bound(l); c=T.extract(c);
			if (v+c->ms>0) {
				puts("-1");
				continue;
			}
			while (1) {
				if (c->s[0]&&v+c->s[0]->ms<=0) {
					c=c->s[0];
					continue;
				}
				v+=c->s[0]?c->s[0]->ss:0;
				if (v+c->len<=0) {
					if (v<=(ll)(r-c->key)*(-c->rt)) {
						printf("%.10f\n",c->key-(double)v/c->rt);
					} else {
						puts("-1");
					}
					T.splay(c);
					break;
				}
				v+=c->len;
				c=c->s[1];
			}
		}
	}
}