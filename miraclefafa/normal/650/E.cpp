#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

#include <stack>
const int N=1501000;
struct node {
	node *s[2],*f,*minv;
	int val,d,id;
	bool rev;
	bool isr() { return !f||(f->s[0]!=this && f->s[1]!=this);}
	bool dir() { return f->s[1]==this;}
	void setc(node *c,int d) { s[d]=c;if (c) c->f=this;}
	void push() {
		if (rev) { swap(s[0],s[1]); rep(i,0,2) if (s[i]) s[i]->rev^=1;} rev=0;
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
const int inf=1<<30;
int n,Q,x[N],y[N];
map<PII,int> hs;

int main() {
	scanf("%d",&n);
//	n=500000;
	rep(i,1,n+1) pool[i].d=-1; cur=pool+n+1;
	rep(i,1,n) {
		scanf("%d%d",x+i+n,y+i+n);
		if (x[i+n]>y[i+n]) swap(x[i+n],y[i+n]);
	}
	rep(i,1,n) {
		scanf("%d%d",x+i,y+i);
		if (x[i]>y[i]) swap(x[i],y[i]);
		hs[mp(x[i],y[i])]=0;
	}
	int ret=n-1;
	rep(i,1,n) {
		node *w=cur++; w->d=inf; w->id=i+n;
		if (hs.count(mp(x[i+n],y[i+n]))) {
			hs[mp(x[i+n],y[i+n])]=1;
			w->d=0; --ret;
		}
//		printf("%d %d %d\n",x[i+n],y[i+n],w->d);
		link(w,pool+x[i+n]); link(w,pool+y[i+n]);
	}
	printf("%d\n",ret);
	rep(i,1,n) if (hs[mp(x[i],y[i])]==0) {
		node *u=pool+x[i],*v=pool+y[i];
		expose(u,v);
		node *w=u->minv;
		expose(w,w);
		printf("%d %d %d %d\n",x[w->id],y[w->id],x[i],y[i]);
		cut(pool+x[w->id],w);
		cut(pool+y[w->id],w);
		w=cur++;
		w->d=0;
		w->id=i;
		link(w,pool+x[i]);
		link(w,pool+y[i]);
	}
}