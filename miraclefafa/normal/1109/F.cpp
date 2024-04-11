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

const int N=210000;
struct node {
	node *s[2],*f;
	bool rev;
	bool isr() { return !f||(f->s[0]!=this && f->s[1]!=this);}
	bool dir() { return f->s[1]==this;}
	void setc(node *c,int d) { s[d]=c;if (c) c->f=this;}
	void upd() {

	}
	void push() {
		if (rev) { swap(s[0],s[1]); rep(i,0,2) if (s[i]) s[i]->rev^=1;} rev=0;
	}
}nd[N],*cur;
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
node *findr(node *x) {
	node *q=expose(x);
	while (q->s[0]) q=q->s[0];
	splay(q);
	return q;
}

void evert(node *x) { expose(x); splay(x); x->rev^=1; x->push();}
void expose(node *x,node *y) { evert(x); expose(y); splay(x);}
void link(node *x,node *y) {
//	printf("link %d %d\n",x-nd,y-nd);
	evert(x); evert(y); x->setc(y,1);}
void cut(node *x,node *y) {
//	printf("cut %d %d\n",x-nd,y-nd);
	expose(x,y); x->s[1]=y->f=NULL;}

namespace segt {
struct node {
	int fg;
	PII s;
}nd[4*N];
PII operator + (const PII &a, const PII &b) {
	PII c(0,0); c.fi=min(a.fi,b.fi);
	if (a.fi==c.fi) c.se+=a.se;
	if (b.fi==c.fi) c.se+=b.se;
	return c;
}
void upd(int p) {
	nd[p].s=nd[p+p].s+nd[p+p+1].s;
}
void setf(int p,int v) {
	nd[p].fg+=v;
	nd[p].s.fi+=v;
}
void push(int p) {
	if (nd[p].fg) {
		setf(p+p,nd[p].fg);
		setf(p+p+1,nd[p].fg);
		nd[p].fg=0;
	}
}
void build(int p,int l,int r) {
	nd[p].fg=0;
	if (l==r) {
		nd[p].s=mp(0,1);
	} else {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
		upd(p);
	}
}
PII query(int p,int l,int r,int tl,int tr) {
	if (tl==l&&tr==r) return nd[p].s;
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) return query(p+p,l,md,tl,tr);
		else if (tl>md) return query(p+p+1,md+1,r,tl,tr);
		else return query(p+p,l,md,tl,md)+query(p+p+1,md+1,r,md+1,tr);
	}
}
void modify(int p,int l,int r,int tl,int tr,int v) {
	if (tl>tr) return;
	if (tl==l&&tr==r) return setf(p,v);
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) modify(p+p,l,md,tl,tr,v);
		else if (tl>md) modify(p+p+1,md+1,r,tl,tr,v);
		else modify(p+p,l,md,tl,md,v),modify(p+p+1,md+1,r,md+1,tr,v);
		upd(p);
	}
}
}

const int M=1010;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int r,c,f[M][M],n;
PII pos[N];
VI eg[N];

int main() {
	scanf("%d%d",&r,&c);
	n=r*c;
	ll ans=0;
	rep(i,1,r+1) rep(j,1,c+1) {
		scanf("%d",&f[i][j]);
		pos[f[i][j]]=mp(i,j);
	}
	int pr=0;
	segt::build(1,1,n);
	rep(i,1,r*c+1) {
		if (pr<i) {
			pr=i;
			segt::modify(1,1,n,i,n,1);
		}
		while (pr<n) {
			int z=pr+1;
			int x=pos[z].fi,y=pos[z].se;
			VI ta;
			vector<node*> cc;
			rep(k,0,4) {
				int nx=x+dx[k],ny=y+dy[k];
				if (nx>=1&&nx<=r&&ny>=1&&ny<=c&&f[nx][ny]>=i&&f[nx][ny]<z) {
					ta.pb(f[nx][ny]);
					cc.pb(findr(nd+f[nx][ny]));
				}
			}
			bool succ=1;
			rep(k,0,SZ(cc)) rep(j,k+1,SZ(cc)) if (cc[k]==cc[j]) {
				succ=0;
				break;
			}
			if (succ) {
				++pr;
				segt::modify(1,1,n,pr,n,1);
				rep(k,0,SZ(ta)) {
					link(nd+pr,nd+ta[k]);
					eg[ta[k]].pb(pr);
					segt::modify(1,1,n,pr,n,-1);
				}
			} else break;
		}
		PII cc=segt::query(1,1,n,i,pr);
//		printf("gg %d %d\n",i,pr);
//		printf("cc %d %d\n",cc.fi,cc.se);
		if (cc.fi==1) ans+=cc.se;
		segt::modify(1,1,n,i,n,-1);
		for (auto v:eg[i]) {
			segt::modify(1,1,n,v,n,1);
			cut(nd+i,nd+v);
		}
	}
	printf("%lld\n",ans);
}