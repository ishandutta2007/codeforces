#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

typedef struct G { ll a,b,g; G(ll a,ll b,ll g):a(a),b(b),g(g) {} } G;
G egcd(ll p,ll q) {
	if(q==0) return G(1,0,p);
	G cur=egcd(q,p%q);
	return G(cur.b,cur.a-cur.b*(p/q),cur.g);
}

// T = a*p1+x1 = b*p2+x2
ll first(ll p1,ll x1,ll p2,ll x2) {
	//printf("T = a*%lld+%lld = b*%lld+%lld\n",p1,x1,p2,x2);
	// a*p1 = x2-x1 mod p2
	G cur=egcd(p1,p2);
	ll want=((x2-x1)%p2+p2)%p2;
	//printf("\t%lld %lld %lld %lld\n",cur.a,cur.b,cur.g,want);
	if(want%cur.g!=0) return LLONG_MAX;
	want/=cur.g; p1/=cur.g; p2/=cur.g;
	ll a=(cur.a%p2+p2)%p2; a=a*want%p2;
	//printf("\t=> %lld\n",a*p1*cur.g*want+x1);
	return a*p1*cur.g+x1;
}

// 
ll go2(ll MOD,ll a,ll l,ll r) {
	a%=MOD;
	if(2*a>MOD) return go2(MOD,MOD-a,MOD-r,MOD-l);
	ll m=l/a;
	if(l==m*a) return m;
	if((m+1)*a<=r) return m+1;
	ll k=go2(a,a-MOD%a,l%a,r%a);
	m=(k*MOD+l+a-1)/a;
	return m;
}

// l<=?*a<=r (mod MOD)
ll go(ll MOD,ll a,ll l,ll r) {
	ll g=gcd(MOD,a);
	if((l+g-1)/g>r/g) return LLONG_MAX;
	return go2(MOD,a,l,r);
}

// T = a*p1+x1+? = b*p2+x2+lim-?, 0<=?<=lim, p1 and p2 are even
ll first(ll p1,ll x1,ll p2,ll x2,ll lim) {
	//printf("T = a*%lld+%lld+? = b*%lld+%lld-?, 0<=?<=%lld\n",p1,x1,p2,x2+lim,lim);
	// b*p2+x2-x1-lim <= a*p1 <= b*p2+x2-x1+lim
	ll l=((x2-x1-lim)%p2+p2)%p2,h=((x2-x1+lim)%p2+p2)%p2;
	if(l%2!=0||h%2!=0) return LLONG_MAX;
	if(l==0||l>h||2*lim==p2) {
		//printf("->%lld -> %lld\n",0LL,x2+h/2);
		return x1+h/2;
	}
	ll a=go(p2,p1,l,h); if(a==LLONG_MAX) return LLONG_MAX;
	ll ret=a*p1+x1+lim-(a*p1%p2-l)/2;
	//printf("->%lld -> %lld\n",a,ret);
	return ret;
}

const int MAXN=200000;
const int MAXE=MAXN-1;
int n,nq;
int fst[MAXN];
int nxt[2*MAXE];
int to[2*MAXE];
int h[MAXN];
int par[MAXN][20];

int q[MAXN],qhead,qtail;
void init() {
	REP(i,n) h[i]=par[i][0]=-1;
	qhead=qtail=0; q[qhead++]=0; h[0]=0; par[0][0]=0;
	while(qtail<qhead) {
		int at=q[qtail++];
		for(int x=fst[at];x!=-1;x=nxt[x]) if(h[to[x]]==-1) {
			h[to[x]]=h[at]+1; par[to[x]][0]=at; q[qhead++]=to[x];
		}
	}
	//REP(i,n) printf("%d: h=%d, par=%d\n",i,h[i],par[i][0]);
	REP(k,19) REP(j,n) par[j][k+1]=par[par[j][k]][k];
}

int lca(int u,int v) {
	if(h[u]<h[v]) swap(u,v);
	//printf("lca(%d,%d) [%d,%d]\n",u,v,h[u],h[v]);
	for(int k=19;k>=0;--k) if(h[par[u][k]]>=h[v]) { u=par[u][k];  }
	if(u==v) return u;
	for(int k=19;k>=0;--k) if(par[u][k]!=par[v][k]) { u=par[u][k],v=par[v][k]; }
	return par[u][0];
}

ll calc(int u,int v,int x,int y) {
	//printf("calc(%d,%d,%d,%d)\n",u,v,x,y);
	int uv=lca(u,v),xy=lca(x,y),ux=lca(u,x),uy=lca(u,y),vx=lca(v,x),vy=lca(v,y);
	//printf("lca: %d,%d,%d,%d,%d,%d\n",uv,xy,ux,uy,vx,vy);
	int du=0,dv=0,dx=0,dy=0;
	if(min(min(h[ux],h[uy]),min(h[vx],h[vy]))>=max(h[uv],h[xy])) {
		if(h[ux]>=h[uy]) { du=h[u]-h[ux]; dx=h[x]-h[ux]; } else { du=h[u]-h[uy]; dx=h[x]+h[uy]-2*h[ux]; }
		if(h[vx]>=h[vy]) { dv=h[v]-h[vx]; dy=h[y]+h[vx]-2*h[vy]; } else { dv=h[v]-h[vy]; dy=h[y]-h[vy]; }
	} else if(min(h[ux],h[uy])>=max(h[uv],h[xy])) {
		dv=h[v]+h[xy]-2*h[uv]; dy=h[y]-h[xy];
		if(h[ux]>=h[uy]) { du=h[u]-h[ux]; dx=h[x]-h[ux]; } else { du=h[u]-h[uy]; dx=h[x]+h[uy]-2*h[xy]; }
	} else if(min(h[vx],h[vy])>=max(h[uv],h[xy])) {
		du=h[u]+h[xy]-2*h[uv]; dx=h[x]-h[xy];
		if(h[vx]>=h[vy]) { dv=h[v]-h[vx]; dy=h[y]+h[vx]-2*h[xy]; } else { dv=h[v]-h[vy]; dy=h[y]-h[vy]; }
	} else {
		swap(u,x); swap(v,y); swap(uv,xy); swap(uy,vx);
		if(min(h[ux],h[uy])>=max(h[uv],h[xy])) {
			dv=h[v]+h[xy]-2*h[uv]; dy=h[y]-h[xy];
			if(h[ux]>=h[uy]) { du=h[u]-h[ux]; dx=h[x]-h[ux]; } else { du=h[u]-h[uy]; dx=h[x]+h[uy]-2*h[xy]; }
		} else if(min(h[vx],h[vy])>=max(h[uv],h[xy])) {
			du=h[u]+h[xy]-2*h[uv]; dx=h[x]-h[xy];
			if(h[vx]>=h[vy]) { dv=h[v]-h[vx]; dy=h[y]+h[vx]-2*h[xy]; } else { dv=h[v]-h[vy]; dy=h[y]-h[vy]; }
		} else {
			return -1;
		}
	}
	//printf("calc(%d,%d,%d,%d)\n",u,v,x,y);
	int duv=h[u]+h[v]-2*h[uv],dxy=h[x]+h[y]-2*h[xy],d=duv-du-dv;
	//printf("du=%d dv=%d dx=%d dy=%d duv=%d dxy=%d d=%d\n",du,dv,dx,dy,duv,dxy,d);
	dv+=duv; if(dx+dy<=dxy) { dy+=dxy; } else { dx=2*dxy-dx; dy=dxy-dy; } 
	//printf("du=%d dv=%d dx=%d dy=%d duv=%d dxy=%d d=%d\n",du,dv,dx,dy,duv,dxy,d);
	ll cur1=first(2*duv,du,2*dxy,dx);
	ll cur2=first(2*duv,dv,2*dxy,dy);
	ll cur3=first(2*duv,du,2*dxy,dy,d);
	ll cur4=first(2*duv,dv,2*dxy,dx,d);
	ll ret=min(min(cur1,cur2),min(cur3,cur4));
	return ret==LLONG_MAX?-1:ret;
}



void run() {
	scanf("%d",&n);
	REP(i,n) fst[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}
	init();
	scanf("%d",&nq);
	REP(qi,nq) {
		int u,v,x,y; scanf("%d%d%d%d",&u,&v,&x,&y); --u,--v,--x,--y;
		ll ret=calc(u,v,x,y);
		cout<<ret<<endl;
	}
}

int main() {
	run();
	return 0;
}