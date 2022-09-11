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

const int MAXV=10;
const int MAXP=100000;
const int MAXQ=100000;
typedef struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} } P;
P operator+(const P &a,const P &b) { return P(a.x+b.x,a.y+b.y); }
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.y<b.y; }
ll side(const P &a,const P &b,const P &c) { return (b-a)^(c-a); }
typedef struct R { ll x; ll val; int mlt,idx; R() {} R(ll x,ll val,int mlt,int idx):x(x),val(val),mlt(mlt),idx(idx) {} } R;
bool operator<(const R &a,const R &b) { return a.x<b.x; }

vector<P> calchull(vector<P> p) {
	sort(p.begin(),p.end());
	vector<P> ret; ret.PB(p[0]); int nret;
	nret=SZ(ret); REPSZ(i,p) { while(SZ(ret)-nret>0&&side(ret[SZ(ret)-2],ret[SZ(ret)-1],p[i])<=0) ret.pop_back(); ret.PB(p[i]); }
	nret=SZ(ret); for(int i=SZ(p)-1;i>=0;--i) { while(SZ(ret)-nret>0&&side(ret[SZ(ret)-2],ret[SZ(ret)-1],p[i])<=0) ret.pop_back(); ret.PB(p[i]); }
	ret.pop_back(); return ret;
}

int nv,np,nq;
P v[MAXV];
P p[MAXP]; int pcnt[MAXP];
P q[MAXQ]; int qt[MAXQ];

R a[MAXP]; int na;
R b[2*MAXQ]; int nb;
ll c[MAXP]; int nc;
ll ans[MAXQ];

ll bt[MAXP+1];
void bmod(int idx,int by) { ++idx; while(idx<=nc) { bt[idx]+=by; idx+=idx&-idx; } }
ll bget(int idx) { ll ret=0; ++idx; while(idx>0) { ret+=bt[idx]; idx-=idx&-idx; } return ret; }

void solve(int it) {
	//REP(i,na) printf("a%d: x=%lld val=%lld cnt=%d\n",a[i].idx,a[i].x,a[i].val,a[i].mlt);
	//REP(i,nb) printf("b%d: x=%lld val=%lld mlt=%d\n",b[i].idx,b[i].x,b[i].val,b[i].mlt);

	nc=0; REP(i,na) c[nc++]=a[i].val; sort(c,c+nc); nc=unique(c,c+nc)-c;
	REPE(i,nc) bt[i]=0;
	sort(a,a+na); sort(b,b+nb); int ai=0;
	REP(bi,nb) {
		while(ai<na&&a[ai].x<=b[bi].x) {
			int aidx=lower_bound(c,c+nc,a[ai].val)-c;
			//if(it==3) printf("bmod(%d,%d)\n",aidx,a[ai].mlt);
			bmod(aidx,a[ai].mlt);
			++ai;
		}
		int bidx=lower_bound(c,c+nc,b[bi].val)-c; if(bidx==nc||c[bidx]>b[bi].val) --bidx;
		ll cur=bget(bidx);
		//if(it==3) printf("bget(%d)=%lld\n",bidx,cur);
		ans[b[bi].idx]+=cur*b[bi].mlt;
		//if(cur!=0) printf("\t%d + %lld * %d\n",b[bi].idx,cur,b[bi].mlt);
	}
}

void run() {
	scanf("%d%d%d",&nv,&np,&nq);
	REP(i,nv) scanf("%d%d",&v[i].x,&v[i].y);
	REP(i,np) scanf("%d%d%d",&p[i].x,&p[i].y,&pcnt[i]);
	REP(i,nq) scanf("%d%d%d",&q[i].x,&q[i].y,&qt[i]);

	vector<P> hull; hull.PB(P(0,0));
	REP(i,nv) {
		vector<P> nhull; REPSZ(j,hull) nhull.PB(hull[j]+v[i]),nhull.PB(hull[j]-v[i]);
		hull=calchull(nhull);
	}
	//printf("hull:"); REPSZ(i,hull) printf(" (%d,%d)",hull[i].x,hull[i].y); puts("");

	int xmx=hull[0].x; FORSZ(i,1,hull) xmx=max(xmx,hull[i].x);
	REP(i,nq) ans[i]=0;
	REPSZ(it,hull) {
		P A=hull[it],B=hull[(it+1)%SZ(hull)];
		int lx=A.x,ly=A.y,rx=B.x,ry=B.y; bool swapped=false;
		if(lx==rx) continue; if(lx>rx) swap(lx,rx),swap(ly,ry),swapped=true;
		int dx=rx-lx,dy=ry-ly;
		//printf("(%d,%d)-(%d,%d)%s\n",lx,ly,rx,ry,swapped?"swapped":"");
		// (qx+t*lx,qy+t*ly)-(qx+t*rx,qy+t*ry)    QY=qy+t*ly, QX=qx+t*lx    -> y*dx-x*dy<=QY*dx-QX*dy
		na=nb=0;
		REP(i,np) {
			int x=p[i].x,y=p[i].y;
			a[na++]=R(x,(ll)y*dx-(ll)x*dy,pcnt[i],i);
		}
		REP(i,nq) {
			ll lqx=q[i].x+(ll)qt[i]*lx,lqy=q[i].y+(ll)qt[i]*ly,rqx=q[i].x+(ll)qt[i]*rx;
			b[nb++]=R(rx==xmx?rqx:rqx-1,lqy*dx-lqx*dy+(!swapped?-1:0),!swapped?-1:+1,i);
			b[nb++]=R(lqx-1,lqy*dx-lqx*dy+(!swapped?-1:0),!swapped?+1:-1,i);
		}
		solve(it);
	}
	REP(i,nq) printf("%lld\n",ans[i]);
}

int main() {
	run();
	return 0;
}