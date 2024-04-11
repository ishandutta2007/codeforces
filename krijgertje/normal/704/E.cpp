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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MAXM=MAXN-1;
const int MAXS=100000;
const int MAXLOGN=16;
const int MAXL=MAXS*(2*MAXLOGN+1);
const int MAXE=2*MAXL;
typedef struct T { ll num; int den; T() { num=0,den=1; } T(ll n,ll d) { ll g=gcd(n,d); num=n/g,den=d/g; } T(ll a,ll b,ll c) { ll n=a*c+b,d=c,g=gcd(n,d); num=n/g,den=d/g; } double val() { return 1.0*num/den; } } T;
bool operator==(const T &a,const T &b) { return a.num==b.num&&a.den==b.den; }
T operator-(const T &a,const T &b) { return T(a.num*b.den-b.num*a.den,a.den*b.den); }
T operator/(const T &a,const T &b) { return T(a.num*b.den,a.den*b.num); }
T operator*(const T &a,const ll &b) { return T(a.num*b,a.den); }
T operator+(const ll &a,const T &b) { return T(a*b.den+b.num,b.den); }
bool operator<(const T &a,const T &b) { return a.num*b.den<b.num*a.den; }

int n,ns;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];
int q[MAXN],qhead,qtail;
int d[MAXN],par[MAXN],sz[MAXN],heavy[MAXN],hroot[MAXN],hidx[MAXN],nhidx;

int lca(int a,int b) {
	while(hroot[a]!=hroot[b]) {
		if(d[hroot[a]]>d[hroot[b]]) swap(a,b);
		b=par[hroot[b]];
	}
	if(d[a]>d[b]) swap(a,b);
	return a;
}

typedef struct L {
	int x1; T y1; int x2; T y2;
	T getx(T y) const {
		if(y1==y2) return T(x1,1);
		return x1+(y-y1)/(y2-y1)*(x2-x1);
	}
} L;

L l[MAXL]; int nl;

T scanliney;
typedef struct scanlinecmp {
	bool operator()(const int &aa,const int &bb) {
		T ax=l[aa].getx(scanliney),bx=l[bb].getx(scanliney);
		//L &a=l[aa]; L &b=l[bb]; printf("comp (%d,%.2lf)-(%d,%.2lf) and (%d,%.2lf)-(%d,%.2lf) -> (%.2lf,%.2lf) [%.2lf]\n",a.x1,a.y1.val(),a.x2,a.y2.val(),b.x1,b.y1.val(),b.x2,b.y2.val(),ax.val(),bx.val(),scanliney.val());
		return ax<bx;
	}
} scanlinecmp;

typedef struct ecmp {
	bool operator()(const int &aa,const int &bb) {
		int aidx=aa/2,atype=aa%2==0?+1:-1;
		int bidx=bb/2,btype=bb%2==0?+1:-1;

		T ay=atype==+1?l[aidx].y1:l[aidx].y2;
		T by=btype==+1?l[bidx].y1:l[bidx].y2;
		if(!(ay==by)) return ay<by;
		if(atype!=btype) return atype>btype;
		return aidx<bidx;
	}
} ecmp;

int e[MAXE]; int ne;

void addseg(int x1,T y1,int x2,T y2) {
	if(nl>MAXL) { printf("too many segs\n"); exit(0); }
	if(y2<y1) swap(x1,x2),swap(y1,y2);
	l[nl].x1=x1; l[nl].y1=y1; l[nl].x2=x2; l[nl].y2=y2; ++nl;
	//printf("%d=(%d,%lf)-(%d,%lf)\n",nl-1,x1,1.0*y1.num/y1.den,x2,1.0*y2.num/y2.den);
}

typedef struct P { double x,y; P(double x,double y):x(x),y(y) {} } P;
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
double operator^(const P &a,const P &b) { return a.x*b.y-a.y*b.x; }

double intersect(const P &a,const P &b,const P &c,const P &d) {
	double num=(d-c)^(c-a);
	double den=(d-c)^(b-a);
	double t=num/den;
	return a.y+t*(b.y-a.y);
}

void updateintersection(double &yfst,T &cy,int aa,int bb) {
	L &a=l[aa]; L &b=l[bb];
	//printf("%lf: check (%d,%.2lf)-(%d,%.2lf) and (%d,%.2lf)-(%d,%.2lf)\n",cy.val(),a.x1,a.y1.val(),a.x2,a.y2.val(),b.x1,b.y1.val(),b.x2,b.y2.val());
	T topy=a.y2<b.y2?a.y2:b.y2;
	T atopx=a.getx(topy),btopx=b.getx(topy);
	if(atopx<btopx) return;
	//printf("%d and %d intersect (%lf,%lf)\n",aa,bb,atopx.val(),btopx.val());
	double ycur=intersect(P(a.x1,a.y1.val()),P(a.x2,a.y2.val()),P(b.x1,b.y1.val()),P(b.x2,b.y2.val()));
	//printf("at %lf\n",ycur);
	if(ycur<yfst) yfst=ycur;
}

void solve() {
	scanlinecmp cmp;
	set<int,scanlinecmp> scanline(cmp);

	ne=0; REP(i,nl) { e[ne++]=2*i+0; e[ne++]=2*i+1;  }
	sort(e,e+ne,ecmp());

	double yfst=1e200;
	REP(i,ne) {
		//const L& cur=l[e[i].idx]; printf("%+d (%d,%lf)-(%d,%lf)\n",e[i].type,cur.x1,1.0*cur.y1.num/cur.y1.den,cur.x2,1.0*cur.y2.num/cur.y2.den);
		int eidx=e[i]/2,etype=e[i]%2==0?+1:-1;
		T y=etype==+1?l[eidx].y1:l[eidx].y2;
		scanliney=y;
		if(y.val()+1e-9>yfst) {
			printf("%.9lf\n",yfst);
			return;
		}
		if(etype==+1) {
			set<int,scanlinecmp>::iterator at=scanline.lower_bound(eidx);
			if(at!=scanline.end()&&l[*at].getx(y)==T(l[eidx].x1,1)) {
				printf("%.9lf\n",1.0*y.num/y.den);
				return;
			}
			if(at!=scanline.end()) updateintersection(yfst,y,eidx,*at);
			if(at!=scanline.begin()) { set<int,scanlinecmp>::iterator prv=at; --prv; updateintersection(yfst,y,*prv,eidx); }
			scanline.insert(eidx);
		}
		if(etype==-1) {
			set<int,scanlinecmp>::iterator at=scanline.lower_bound(eidx);
			assert(at!=scanline.end()&&*at==eidx);
			set<int,scanlinecmp>::iterator nxt=at; ++nxt;
			if(at!=scanline.begin()&&nxt!=scanline.end()) { set<int,scanlinecmp>::iterator prv=at; --prv; updateintersection(yfst,y,*prv,*nxt); }
			scanline.erase(at);
		}
	}
	printf("-1\n");
}



void run() {
	scanf("%d%d",&n,&ns);
	REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}

	qhead=qtail=0; memset(par,-1,sizeof(par)); d[0]=0; q[qhead++]=0;
	while(qtail<qhead) { int at=q[qtail++]; for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(to==par[at]) continue; par[to]=at; d[to]=d[at]+1; q[qhead++]=to; } }
	REP(i,n) sz[i]=1; for(int i=n-1;i>=0;--i) sz[par[q[i]]]+=sz[q[i]];
	REP(i,n) heavy[i]=-1; REP(i,n) if(par[i]!=-1&&(heavy[par[i]]==-1||sz[i]>sz[heavy[par[i]]])) heavy[par[i]]=i;
	nhidx=0; REP(i,n) hidx[i]=-1; REP(i,n) if(hidx[q[i]]==-1) for(int at=q[i];at!=-1;at=heavy[at]) hidx[at]=nhidx++,hroot[at]=q[i];
	//REP(i,n) printf("%d: d=%d par=%d sz=%d heavy=%d hroot=%d hidx=%d\n",i,d[i],par[i],sz[i],heavy[i],hroot[i],hidx[i]);

	nl=0;
	REP(i,ns) {
		int t,v,a,b; scanf("%d%d%d%d",&t,&v,&a,&b); --a,--b;
		int c=lca(a,b),dst=d[a]+d[b]-2*d[c];
		int aa=a; while(hroot[aa]!=hroot[c]) {
			addseg(hidx[hroot[aa]],T(t,d[a]-d[hroot[aa]],v),hidx[aa],T(t,d[a]-d[aa],v)); aa=hroot[aa];
			addseg(n+2*aa,T(t,d[a]-d[aa],v),n+2*aa+1,T(t,d[a]-d[par[aa]],v)); aa=par[aa];
		}
		int bb=b; while(hroot[bb]!=hroot[c]) {
			addseg(hidx[hroot[bb]],T(t,dst-d[b]+d[hroot[bb]],v),hidx[bb],T(t,dst-d[b]+d[bb],v)); bb=hroot[bb];
			addseg(n+2*bb,T(t,dst-d[b]+d[bb],v),n+2*bb+1,T(t,dst-d[b]+d[par[bb]],v)); bb=par[bb];
		}
		addseg(hidx[aa],T(t,d[a]-d[aa],v),hidx[bb],T(t,dst-d[b]+d[bb],v));
	}
	solve();
}

int main() {
	run();
	return 0;
}