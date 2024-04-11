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
#include <chrono>
#include <random>
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
ull gcd(ull a, ull b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXTREE=50;
const int MOD=998244353;
const int INV6=166374059;
const int MINCOORD=-1000000000;
const int MAXCOORD=+1000000000;
struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} };
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
bool operator==(const P &a,const P &b) { return a.x==b.x&&a.y==b.y; }
struct Pol { vector<P> p; };

int ntree,tlast;
P t[MAXTREE];

void rotate(P &p) { p=P(-p.y,+p.x); }
void rotate(Pol &pol) { REPSZ(i,pol.p) rotate(pol.p[i]); }
void flip(P &p) { swap(p.x,p.y); }
void flip(Pol &pol) { REPSZ(i,pol.p) flip(pol.p[i]); reverse(pol.p.begin(),pol.p.end()); }

P infleftup(const P &p) { int t=min(p.x-MINCOORD,MAXCOORD-p.y); return P(p.x-t,p.y+t); }
P infleftdown(const P &p) { int t=min(p.x-MINCOORD,p.y-MINCOORD); return P(p.x-t,p.y-t); }
P infrightup(const P &p) { int t=min(MAXCOORD-p.x,MAXCOORD-p.y); return P(p.x+t,p.y+t); }
P infrightdown(const P &p) { int t=min(MAXCOORD-p.x,p.y-MINCOORD); return P(p.x+t,p.y-t); }

int getdelta(const P &a,const P &b) { P ba=b-a; assert(ba.y==0||abs(ba.y)==abs(ba.x)); return ba.y/ba.x; }
int getdir(const P &a,const P &b) {
	P ba=b-a; int mag=max(abs(ba.x),abs(ba.y)); assert(mag!=0&&ba.x%mag==0&&ba.y%mag==0); ba.x/=mag,ba.y/=mag;
	if(ba==P(1,1)) return 0; if(ba==P(1,0)) return 1; if(ba==P(1,-1)) return 2; if(ba==P(0,-1)) return 3; if(ba==P(-1,-1)) return 4; if(ba==P(-1,0)) return 5; if(ba==P(-1,1)) return 6; if(ba==P(0,1)) return 7; assert(false); return -1;
}

int gety(int x,const vector<P> &path) {
	int idx=0; while(idx+1<SZ(path)&&path[idx+1].x<=x) ++idx; assert(idx+1<SZ(path));
	int v=getdelta(path[idx],path[idx+1]);
	return path[idx].y+(x-path[idx].x)*v;
}

vector<pair<P,P>> segmentsbeloworequal(P a,P b,const vector<P> &path) {
	bool swapab=false; if(a.x>b.x) swapab=true,swap(a,b);
	P ba=b-a; vector<pair<P,P>> ret;
	if(ba.x==0) {
		int x=a.x,py=gety(x,path); assert(!swapab);
		if(a.y<=py) ret.PB(MP(a,P(x,min(py,b.y)))); else if(b.y<=py) ret.PB(MP(P(x,py),b));
	} else {
		int x=a.x,y=a.y,u=getdelta(a,b),idx=0; P oth=a;
		while(true) {
			while(idx+1<SZ(path)&&path[idx+1].x<=x) ++idx; assert(idx+1<SZ(path));
			int v=getdelta(path[idx],path[idx+1]);
			int py=path[idx].y+(x-path[idx].x)*v;
			if(x==b.x) { if(y<=py) ret.PB(MP(oth,b)); break; }
			int dx=min(b.x-x,path[idx+1].x-x);
			if(y<=py) {
				if(u-v>=1) { int t=(py-y)/(u-v); if(t<dx) ret.PB(MP(oth,P(x+t,y+u*t))); }
			} else {
				if(v-u>=1) { int t=(y-py-1)/(v-u); if(t<dx) oth=P(x+t+1,y+u*(t+1)); }
			}
			x+=dx,y+=u*dx;
		}
	}
	if(swapab) { swapab=false,swap(a,b),reverse(ret.begin(),ret.end()); REPSZ(i,ret) swap(ret[i].first,ret[i].second); }
	//printf("\t\tsegments of (%d,%d)-(%d,%d) <= path:",a.x,a.y,b.x,b.y); REPSZ(i,ret) printf(" (%d,%d)..(%d,%d)",ret[i].first.x,ret[i].first.y,ret[i].second.x,ret[i].second.y); puts("");
	return ret;
}
bool isbeloworequal(const P &a,const vector<P> &path) {
	return a.y<=gety(a.x,path);
}
bool isinside(const P &p,const Pol &pol) {
	if(SZ(pol.p)==1) return pol.p[0]==p;
	bool ret=false;
	REPSZ(i,pol.p) {
		P a=pol.p[i],b=pol.p[(i+1)%SZ(pol.p)],c=pol.p[(i+2)%SZ(pol.p)],d=pol.p[(i+3)%SZ(pol.p)];
		int pdir=getdir(a,b),cdir=getdir(b,c),ndir=getdir(c,d); int sgn,delta; P l,r; bool includefirst,includelast;
		if(cdir<4) {
			includefirst=pdir<3||pdir>=cdir+4,includelast=cdir!=3&&ndir>=4&&ndir<=cdir+4;
			if(cdir==3) {
				sgn=includefirst?+1:0,delta=0,l=r=b; ++l.y,++r.y;
			} else {
				sgn=+1,delta=getdelta(b,c); l=b,r=c; ++l.y,++r.y; if(!includefirst) ++l.x,l.y+=delta; if(!includelast) --r.x,r.y-=delta;
			}
		} else {
			includefirst=pdir!=7&&pdir>=cdir-4,includelast=cdir!=7&&ndir<=cdir-4;
			if(cdir==7) {
				sgn=includefirst?-1:0,delta=0,l=r=b;
			} else {
				sgn=-1,delta=getdelta(c,b),l=c,r=b; if(!includefirst) --r.x,r.y-=delta; if(!includelast) ++l.x,l.y+=delta;
			}
		}
		//printf("\t\t\ttestinside (%d,%d): (%d,%d)-(%d,%d) -> (%d,%d)..(%d,%d)\n",p.x,p.y,b.x,b.y,c.x,c.y,l.x,l.y,r.x,r.y);
		if(sgn!=0&&l.x<=p.x&&p.x<=r.x&&p.y<l.y+(p.x-l.x)*delta) ret=!ret;
	}
	return ret;
}
void updatepol(Pol &pol,bool prvonpol,const P p,const vector<P> &path,const Pol &orig) {
	//printf("\t\t\tupdate pol with (%d,%d) [prvonpol=%s]\n",p.x,p.y,SZ(pol.p)==0?"unknown":prvonpol?"true":"false");
	if(SZ(pol.p)>=1&&p==pol.p[SZ(pol.p)-1]) return;
	if(!prvonpol&&SZ(pol.p)>=1) {
		P a=pol.p[SZ(pol.p)-1],b=p;
		//printf("\t\ttesting path vertexes between (%d,%d) and (%d,%d)\n",a.x,a.y,b.x,b.y);
		bool swapab=false; if(a.x>b.x) swapab=true,swap(a,b);
		int ay=gety(a.x,path),by=gety(b.x,path);
		//printf("\t\ttesting path vertexes between (%d,%d->%d) and (%d,%d->%d)\n",a.x,a.y,ay,b.x,b.y,by);
		if(ay!=a.y) { assert(ay==a.y+1); if(isinside(P(a.x,a.y+1),orig)) ++a.y; else ++a.x,--ay; }
		if(by!=b.y) { assert(by==b.y+1); if(isinside(P(b.x,b.y+1),orig)) ++b.y; else --b.x,--by; }
		//printf("\t\ttesting path vertexes between (%d,%d->%d) and (%d,%d->%d)\n",a.x,a.y,ay,b.x,b.y,by);
		vector<P> extra;
		if(!(a==pol.p[SZ(pol.p)-1])) extra.PB(a);
		REPSZ(i,path) if(a.x<path[i].x&&path[i].x<b.x) extra.PB(path[i]);
		if(!(b==p)&&!(b==a)) extra.PB(b);
		if(swapab)  reverse(extra.begin(),extra.end());
		REPSZ(i,extra) pol.p.PB(extra[i]);
		//printf("extra:"); REPSZ(i,extra) printf(" (%d,%d)",extra[i].x,extra[i].y); puts("");
	}
	if(SZ(pol.p)==0||!(p==pol.p[SZ(pol.p)-1])) pol.p.PB(p);
}

Pol cutabove(Pol pol,const vector<P> &path) {
	if(SZ(pol.p)==0) return pol;
	//printf("\tpath:"); REPSZ(i,path) printf(" (%d,%d)",path[i].x,path[i].y); puts("");
	//printf("\tpol:"); REPSZ(i,pol.p) printf(" (%d,%d)",pol.p[i].x,pol.p[i].y); puts("");
	Pol ret;
	if(SZ(pol.p)==1) return isbeloworequal(pol.p[0],path)?pol:ret;
	bool prvonpol=false;
	REPSZ(i,pol.p) {
		P a=pol.p[i],b=pol.p[(i+1)%SZ(pol.p)];
		vector<pair<P,P>> segments=segmentsbeloworequal(a,b,path);
		if(SZ(segments)==0||!(segments[0].first==a)) prvonpol=false;
		REPSZ(k,segments) {
			if(segments[k].first==b) {
				assert(segments[k].second==b); assert(k==SZ(segments)-1);
				prvonpol=false;
			} else {
				updatepol(ret,prvonpol,segments[k].first,path,pol);
				if(segments[k].first==segments[k].second) {
					prvonpol=false;
				} else if(segments[k].second==b) {
					prvonpol=true;
				} else {
					updatepol(ret,true,segments[k].second,path,pol);
					prvonpol=false;
				}
			}
		}
	}
	if(SZ(ret.p)>=1) {
		if(!(ret.p[0]==pol.p[0])) prvonpol=false;
		updatepol(ret,prvonpol,ret.p[0],path,pol);
		if(SZ(ret.p)>=2&&ret.p[SZ(ret.p)-1]==ret.p[0]) ret.p.pop_back();
	}
	//printf("\tret:"); REPSZ(i,ret.p) printf(" (%d,%d)",ret.p[i].x,ret.p[i].y); puts("");
	return ret;
}

Pol cut(Pol pol,P a,P b,bool winequal) {
	int nrot=0,nflip=0;
	while(b.y<=a.y||b.x<a.x) rotate(pol),rotate(a),rotate(b),++nrot;
	if(b.y-a.y<b.x-a.x) flip(pol),flip(a),flip(b),++nflip;
	P d=b-a; // d.y>=d.x>=0
	//printf("\ta=(%d,%d) b=(%d,%d) d=(%d,%d)\n",a.x,a.y,b.x,b.y,d.x,d.y);
	//printf("\tpol:"); REPSZ(k,pol.p) printf(" (%d,%d)",pol.p[k].x,pol.p[k].y); puts("");
	int between=d.y-1;
	int asteps=between/2,bsteps=between/2,turn=winequal?0:1; if(between%2==1) if(turn==0) ++asteps,turn=1; else ++bsteps,turn=0;
	vector<P> path; int y=a.y+asteps;
	if(d.x==d.y) {
		P m(a.x+asteps+(turn==0?1:0),y); path.PB(infleftup(m)); path.PB(infrightdown(m));
	} else if(d.x==0) {
		if(asteps<bsteps) { assert(turn==0); ++asteps,turn=1; } if(bsteps<asteps) { assert(turn==1); ++bsteps,turn=0; } assert(asteps==bsteps);
		P l(a.x-asteps,y),r(a.x+asteps,y); path.PB(turn==0?infleftup(l):infleftdown(l)); path.PB(l); if(l.x!=r.x||l.y!=r.y) path.PB(r); path.PB(turn==0?infrightup(r):infrightdown(r));
	} else {
		P l(a.x+d.x-bsteps-(turn==0?0:1),y),r(a.x+asteps+(turn==0?1:0),y); path.PB(infleftup(l)); path.PB(l); path.PB(r); path.PB(infrightdown(r));
	}
	pol=cutabove(pol,path);
	
	while(nflip%2!=0) flip(pol),flip(a),flip(b),++nflip;
	while(nrot%4!=0) rotate(pol),rotate(a),rotate(b),++nrot;
	return pol;
}

int sum(int a,int b) { return (ll)(a+b)*(b-a+1)/2%MOD; }
int sumsq(int a,int b) { return ((ll)2*a*a+(ll)2*b*b+(ll)2*a*b+b-a)%MOD*(b-a+1)%MOD*INV6%MOD; }

int calcsum(const P &l,const P &r,int delta) {
	int y=l.y%MOD; if(y<0) y+=MOD; int x=l.x%MOD; if(x<0) x+=MOD;
	if(delta==0) { // sum(x=lx..rx,x*ly)
		return (ll)sum(l.x,r.x)*y%MOD;
	} else if(delta==1) { // sum(x=lx..rx,x*(ly+x-lx))=sum(x=lx..rx,x)*(ly-lx)+sum(x=lx..rx,x*x)
		return ((ll)sum(l.x,r.x)*(y+MOD-x)+sumsq(l.x,r.x))%MOD;
	} else if(delta==-1) { // sum(x=lx..rx,x*(ly+lx-x))=sum(x=lx..rx,x)*(ly+lx)-sum(x=lx..rx,x*x)
		return ((ll)sum(l.x,r.x)*(y+x)+MOD-sumsq(l.x,r.x))%MOD;
	} else {
		assert(false);
	}
}

int xcalc(Pol pol) {
	int ret=0;
	//printf("xcalc:"); REPSZ(i,pol.p) printf(" (%d,%d)",pol.p[i].x,pol.p[i].y); puts("");
	if(SZ(pol.p)>=2) REPSZ(i,pol.p) {
		P a=pol.p[i],b=pol.p[(i+1)%SZ(pol.p)],c=pol.p[(i+2)%SZ(pol.p)],d=pol.p[(i+3)%SZ(pol.p)];
		int pdir=getdir(a,b),cdir=getdir(b,c),ndir=getdir(c,d); int sgn,delta; P l,r; bool includefirst,includelast;
		if(cdir<4) {
			includefirst=pdir<3||pdir>=cdir+4,includelast=cdir!=3&&ndir>=4&&ndir<=cdir+4;
			if(cdir==3) {
				sgn=includefirst?+1:0,delta=0,l=r=b; ++l.y,++r.y;
			} else {
				sgn=+1,delta=getdelta(b,c); l=b,r=c; ++l.y,++r.y; if(!includefirst) ++l.x,l.y+=delta; if(!includelast) --r.x,r.y-=delta;
			}
		} else {
			includefirst=pdir!=7&&pdir>=cdir-4,includelast=cdir!=7&&ndir<=cdir-4;
			if(cdir==7) {
				sgn=includefirst?-1:0,delta=0,l=r=b;
			} else {
				sgn=-1,delta=getdelta(c,b),l=c,r=b; if(!includefirst) --r.x,r.y-=delta; if(!includelast) ++l.x,l.y+=delta;
			}
		}
		int cur=sgn!=0&&l.x<=r.x?calcsum(l,r,delta):0;
		//printf("\t\tcur=%d sgn=%d l=(%d,%d) r=(%d,%d) delta=%d dir=(%d,%d,%d)\n",cur,sgn,l.x,l.y,r.x,r.y,delta,pdir,cdir,ndir);
		if(sgn==+1) ret=(ret+cur)%MOD; else ret=(ret+MOD-cur)%MOD;
	}
	if(SZ(pol.p)==1) ret=(ret+pol.p[0].x)%MOD;
	//printf("xcalc:"); REPSZ(i,pol.p) printf(" (%d,%d)",pol.p[i].x,pol.p[i].y); printf(" = %d\n",ret);
	return ret;
}

Pol cutbelow(Pol pol,vector<P> path) {
	REP(rep,2) { rotate(pol); REPSZ(i,path) rotate(path[i]); } reverse(path.begin(),path.end()); 
	pol=cutabove(pol,path);
	REP(rep,2) { rotate(pol); REPSZ(i,path) rotate(path[i]); } reverse(path.begin(),path.end()); 
	return pol;
}

int calc(Pol pol) {
	//printf("\tcalc:"); REPSZ(i,pol.p) printf(" (%d,%d)",pol.p[i].x,pol.p[i].y); puts("");
	int ret=0;
	REP(rep,4) {
		vector<P> upath; upath.PB(infleftdown(P(0,0))); upath.PB(infrightup(P(0,0)));
		vector<P> lpath; lpath.PB(P(MINCOORD,0)); lpath.PB(P(1,0)); lpath.PB(infrightdown(P(1,0)));
		Pol cpol=cutbelow(cutabove(pol,upath),lpath);
		ret=(ret+xcalc(cpol))%MOD;
		rotate(pol);
	}
	return ret;
}

int solve() {
	if(tlast==0) return 0;
	int ret=0;
	REP(i,ntree) {
		//printf("processing %d\n",i);
		Pol pol;
		pol.p.PB(P(t[i].x-tlast,t[i].y+tlast));
		pol.p.PB(P(t[i].x+tlast,t[i].y+tlast));
		pol.p.PB(P(t[i].x+tlast,t[i].y-tlast));
		pol.p.PB(P(t[i].x-tlast,t[i].y-tlast));
		//printf("\tpol:"); REPSZ(k,pol.p) printf(" (%d,%d)",pol.p[k].x,pol.p[k].y); puts("");
		REP(j,ntree) if(j!=i) {
			pol=cut(pol,t[i],t[j],i<j);
			//printf("\tpol:"); REPSZ(k,pol.p) printf(" (%d,%d)",pol.p[k].x,pol.p[k].y); puts("");
		}
		//printf("\tpol:"); REPSZ(k,pol.p) printf(" (%d,%d)",pol.p[k].x,pol.p[k].y); puts("");
		REPSZ(k,pol.p) pol.p[k]=pol.p[k]-t[i];
		ret=(ret+calc(pol))%MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d",&ntree,&tlast);
	REP(i,ntree) scanf("%d%d",&t[i].x,&t[i].y);
	printf("%d\n",solve());
}

int solvestupid() {
	int lx=INT_MAX,hx=INT_MIN,ly=INT_MAX,hy=INT_MIN;
	REP(i,ntree) lx=min(lx,t[i].x-tlast),hx=max(hx,t[i].x+tlast),ly=min(ly,t[i].y-tlast),hy=max(hy,t[i].y+tlast);
	vector<vector<int>> d(hx-lx+1,vector<int>(hy-ly+1,INT_MAX));
	REP(i,ntree) FORE(x,t[i].x-tlast,t[i].x+tlast) FORE(y,t[i].y-tlast,t[i].y+tlast) { int &v=d[x-lx][y-ly]; v=min(v,max(abs(x-t[i].x),abs(y-t[i].y))); }
	int ret=0; FORE(x,lx,hx) FORE(y,ly,hy) { int v=d[x-lx][y-ly]; if(v!=INT_MAX) ret+=v; } return ret;
}

void stress() {
	mt19937 rnd(12344);
	int mxn=100,mxt=100,mncoord=0,mxcoord=100;
	REP(rep,100000) {
		ntree=rnd()%mxn+1; tlast=rnd()%(mxt+1);
		set<pair<int,int>> seen; REP(i,ntree) while(true) { t[i].x=rnd()%(mxcoord-mncoord+1)+mncoord,t[i].y=rnd()%(mxcoord-mncoord+1)+mncoord; if(seen.count(MP(t[i].x,t[i].y))) continue; seen.insert(MP(t[i].x,t[i].y)); break; }
		int have=solve();
		int want=solvestupid();
		if(have==want) { if(rep%100==99) printf("."); continue; }
		puts(""); printf("%d %d\n",ntree,tlast); REP(i,ntree) printf("%d %d\n",t[i].x,t[i].y);
		printf("err have=%d want=%d\n",have,want);
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}