#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <stack>
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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=301000,M=1010000;
struct node {
	node *s[2],*f,*minv;
	int val,d;
	PII id;
	bool rev;
	bool isr() { return !f||(f->s[0]!=this && f->s[1]!=this);}
	bool dir() { return f->s[1]==this;}
	void setc(node *c,int d) { s[d]=c;if (c) c->f=this;}
	void push() {
		if (rev) { swap(s[0],s[1]); rep(i,0,2) if (s[i]) s[i]->rev^=1;} rev=0;
	}
	void upd() {
		minv=this;val=d;
		rep(i,0,2) if (s[i]&&s[i]->val>val) val=s[i]->val,minv=s[i]->minv;
	}
}pool[M],*cur;
stack<node*> sta;
void rot(node *x) {
	node *p=x->f;bool d=x->dir();
	if (!p->isr()) p->f->setc(x,p->dir()); else x->f=p->f;
	p->setc(x->s[!d],d);x->setc(p,!d);
	p->upd();
}
void splay(node *x) {
	node *q=x;
	while (1) { sta.push(q);if (q->isr()) break; q=q->f; }
	while (!sta.empty()) sta.top()->push(),sta.pop();
	while (!x->isr()) {
		if (x->f->isr()) rot(x);
		else if (x->dir()==x->f->dir()) rot(x->f),rot(x);
		else rot(x),rot(x);
	}
	x->upd();
}
node *expose(node *x) {
	node *q=NULL;
	for (;x;x=x->f) splay(x),x->s[1]=q,(q=x)->upd();
	return q;
}
void evert(node *x) { expose(x); splay(x); x->rev^=1; x->push();}
void expose(node *x,node *y) { evert(x); expose(y); splay(x);}
void link(node *x,node *y) { evert(x); evert(y); x->setc(y,1);}
void cut(node *x,node *y) { expose(x,y); x->s[1]=y->f=NULL;}

int n,m,l,r,Q,ret[N];
VI e[N];
vector<PII> q[N];
int c[N];
void modify(int x,int s) {
	for (;x<=n+1;x+=x&-x) c[x]+=s;
}
int query(int x) {
	int s=0;
	for (;x;x-=x&-x) s+=c[x];
	return s;
}
int main() {
	scanf("%d%*d",&n);
	scanf("%d",&m);
	rep(i,0,m) {
		scanf("%d%d",&l,&r);
		if (l>r) swap(l,r);
		e[l].pb(r);
	}
	n++;
	scanf("%d",&Q);
	rep(i,0,Q) {
		scanf("%d%d",&l,&r);
		ret[i]=r-l+1;
		q[l].pb(mp(r,i));
	}
	rep(i,1,n+2) pool[i].d=-1;
	cur=pool+n+2;
	rep(i,1,n+1) {
		node *u=pool+i,*v=pool+n+1;
		node *x=cur++;
		x->d=n+1;
		x->id=mp(i,n+1);
		link(x,u); link(x,v);
		modify(n+1,1);
	}
	per(x,1,n+1) {
		for (auto y:e[x]) {
			node *u=pool+x,*v=pool+y;
			expose(u,v);
			if (y<u->val) {
				node *w=u->minv;
				cut(pool+w->id.fi,w);
				cut(pool+w->id.se,w);
				modify(w->d,-1);
				w=cur++;
				w->d=y;
				modify(w->d,1);
				w->id=mp(x,y);
				link(w,pool+x);
				link(w,pool+y);
			}
		}
		for (auto y:q[x]) {
			ret[y.se]-=query(y.fi);
		}
	}
	rep(i,0,Q) printf("%d\n",ret[i]);
}