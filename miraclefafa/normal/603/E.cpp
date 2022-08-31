#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define mp make_pair
#define SZ(x) (int(x.size()))
#define fi first
#define se second
const int N=501000,M=1010000;
struct node {
	node *s[2],*f,*minv;
	int val,d,id;
	bool rev,col,inv;
	bool isr() { return !f||(f->s[0]!=this && f->s[1]!=this);}
	bool dir() { return f->s[1]==this;}
	void setc(node *c,int d) { s[d]=c;if (c) c->f=this;}
	void push() {
		if (rev) { swap(s[0],s[1]); rep(i,0,2) if (s[i]) s[i]->rev^=1;} rev=0;
		if (inv) { col^=1; rep(i,0,2) if (s[i]) s[i]->inv^=1; } inv=0;
	}
	void upd() {
		minv=this; val=d;
		rep(i,0,2) if (s[i]&&s[i]->val>val) val=s[i]->val,minv=s[i]->minv;

	}
}pool[N],*cur;
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
		else if (x->isr()==x->f->isr()) rot(x->f),rot(x);
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
struct edge { int x,y,w;}e[M],q[N];
const bool cmp(const edge &a,const edge &b) { return a.w<b.w;}
const int inf=1<<30;
int n,Q,x[N],y[N],ww[N];
node *vt[N];
#include <set>
set<pair<int,int> > eg;

int main() {
	scanf("%d%d",&n,&Q);
	rep(i,1,n+1) pool[i].d=-1; cur=pool+n+1;
	rep(i,1,n) {
		node *w=cur++; w->d=inf;
		w->col=i%2; w->id=i+Q; x[i+Q]=i; y[i+Q]=i+1;
		link(w,pool+i); link(w,pool+i+1); vt[i+Q]=w;
		eg.insert(mp(-inf,i+Q));
	}
	pair<int,int> ret=mp(-inf,0);
	rep(i,0,Q) {
		if (n%2==1) { printf("-1\n"); continue; }
		scanf("%d%d%d",x+i,y+i,ww+i); 
		node *u=pool+x[i],*v=pool+y[i];
		expose(u,v);
		if (ww[i]<u->val) {
			node *w=u->minv;
			expose(w,w);
			bool od=w->col;
			expose(u,v);
			if (od) u->inv^=1;
			eg.erase(mp(-w->d,w->id));
			cut(pool+x[w->id],w);
			cut(pool+y[w->id],w);
			w=cur++;
			w->d=ww[i];
			w->id=i; w->col=od; vt[i]=w;
			link(w,pool+x[i]);
			link(w,pool+y[i]);
			eg.insert(mp(-w->d,w->id));
		}
		ret.se--;
		while (1) {
			ret=*eg.upper_bound(ret);
			node *u=vt[ret.se];
			expose(u,u);
			if (u->col==1) {
				break;
			}
		}
		if (ret.fi==-inf) puts("-1"); else printf("%d\n",-ret.fi);
	}
}