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

const int MAXN=300000;
const int MAXHP=2*MAXN+4;
typedef struct P { int x,y,id; P() {} P(int x,int y):x(x),y(y) {} } P;
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }
bool operator<(const P &a,const P &b) {
	bool apos=a.y>0||a.y==0&&a.x>0;
	bool bpos=b.y>0||b.y==0&&b.x>0;
	if(apos!=bpos) return apos;
	return (a^b)>0;
}
typedef struct HP {
	ll a,b,c; int id;
	HP() {}
	HP(ll a,ll b,ll c):a(a),b(b),c(c) {}
	HP(P u,P v):a(v.y-u.y),b(u.x-v.x),c((ll)u.x*v.y-(ll)u.y*v.x),id(100*u.id+v.id) {}
} HP;

// basic algorithm:
// 1) sort halfplanes
// 2) while there is a redundant halfplane, remove it
// 2a)   middle of three consecutive halfplanes is redundant iff outher two go 'toward' eachother and intersection point satisfies middle OR impossible opposite
// 2b)   halfplane is redundant if next has same orientation and is more restrictive
// 3) test empty (two impossible opposite halfplanes OR three such that intersection of two does not satisfy third)
// 4) test unbounded (one halfplane left OR two consecutive halfplanes do not go 'toward' eachother)
typedef struct HPIntersection {
	HP hp[MAXHP]; int nhp;
	HP res[MAXHP]; int head,tail;
	pair<double,double> p[MAXHP];
	double area;
	HPIntersection() {}
	static int quadrant(const HP &f) {
		if(f.b==0) return f.a>0?0:2; else return f.b>0?1:3;
	}
	static int cmpslope(const HP &f,const HP &g) {
		int qf=quadrant(f),qg=quadrant(g);
		if(qf!=qg) return qf<qg?-1:+1;
		if(qf==1) { ll x=f.a*g.b-f.b*g.a; if(x!=0) return x>0?-1:+1; }
		if(qf==3) { ll x=f.a*g.b-f.b*g.a; if(x!=0) return x>0?-1:+1; }
		return 0;
	}
	struct cmp { bool operator() (const HP &f,const HP &g) {
		int c=cmpslope(f,g); if(c!=0) return c<0;
		if(f.b==0&&f.a>0) { ll x=f.c*g.a-f.a*g.c; return x>0; }
		if(f.b==0&&f.a<0) { ll x=f.c*g.a-f.a*g.c; return x<0; }
		if(f.b>0) { ll x=f.c*g.b-f.b*g.c; return x>0; }
		if(f.b<0) { ll x=f.c*g.b-f.b*g.c; return x<0; }
		assert(false); return false;
	} };
	bool redundant(const HP &f,const HP &g) {
		if(cmpslope(f,g)!=0) return false;
		if(f.b==0&&f.a>0) { ll x=f.c*g.a-f.a*g.c; assert(x>=0); return true; }
		if(f.b==0&&f.a<0) { ll x=f.c*g.a-f.a*g.c; assert(x<=0); return true; }
		if(f.b>0) { ll x=f.c*g.b-f.b*g.c; assert(x>=0); return true; }
		if(f.b<0) { ll x=f.c*g.b-f.b*g.c; assert(x<=0); return true; }
		assert(false); return false;
	}
	bool impossible(const HP &f,const HP &g) {
		int qf=quadrant(f),qg=quadrant(g);
		if(qf==0||qg==2) return qf==0&&qg==2&&f.a*g.c<f.c*g.a;
		if(qf==2||qg==0) return qf==2&&qg==0&&f.a*g.c>f.c*g.a;
		if(f.a*g.b-f.b*g.a!=0) return false;
		if(qf==1||qg==3) return qf==1&&qg==3&&f.b*g.c<f.c*g.b;
		if(qf==3||qg==1) return qf==3&&qg==1&&f.b*g.c>f.c*g.b;
		assert(false); return false;
	}
	bool towards(const HP &f,const HP &g) {
		int qf=quadrant(f),qg=quadrant(g),c=cmpslope(f,g);
		if(qf==0) return qg==1;
		if(qf==1) return qg==1&&c<0||qg==2||qg==3&&f.a*g.b>f.b*g.a;
		if(qf==2) return qg==3;
		if(qf==3) return qg==3&&c<0||qg==0||qg==1&&f.a*g.b>f.b*g.a;
		assert(false); return false;
	}
	bool satisfies(const HP &f,const HP &g,const HP &h) {
		if(!towards(g,h)) return false;
		ll xnum=g.c*h.b-g.b*h.c;
		ll ynum=g.a*h.c-g.c*h.a;
		ll den=g.a*h.b-g.b*h.a; assert(den!=0); assert(den>0);
		return 1.0*f.a*xnum+1.0*f.b*ynum<=1.0*f.c*den;
	}
	pair<double,double> intersect(const HP &g,const HP &h) {
		ll xnum=g.c*h.b-g.b*h.c;
		ll ynum=g.a*h.c-g.c*h.a;
		ll den=g.a*h.b-g.b*h.a; assert(den!=0); assert(den>0);
		return MP(1.0*xnum/den,1.0*ynum/den);
	}
	bool redundant(const HP &f,const HP &g,const HP &h) {
		return impossible(g,h)||satisfies(f,g,h);
	}
	bool solve() {
		//REP(i,nhp) printf("%lld*x+%lld*y<=%lld (%d)\n",hp[i].a,hp[i].b,hp[i].c,hp[i].id); puts("");
		sort(hp,hp+nhp,cmp());
		//REP(i,nhp) printf("%lld*x+%lld*y<=%lld (%d)\n",hp[i].a,hp[i].b,hp[i].c,hp[i].id); puts("");
		head=tail=0;
		REP(i,nhp) {
			while(head-tail>=1&&redundant(res[head-1],hp[i])) --head;
			while(head-tail>=2&&redundant(res[head-1],res[head-2],hp[i])) --head;
			res[head++]=hp[i];
		}
		while(head-tail>=3&&redundant(res[head-1],res[head-2],res[tail])) --head;
		while(true) {
			if(head-tail>=3&&redundant(res[tail],res[head-1],res[tail+1])) { ++tail; continue; }
			if(head-tail>=3&&redundant(res[head-1],res[head-2],res[tail])) { --head; continue; }
			break;
		}
		if(head-tail==2&&impossible(res[tail],res[tail+1])) return false;
		if(head-tail==3&&!satisfies(res[tail],res[tail+1],res[tail+2])) return false;
		FOR(i,tail,head) if(!towards(res[i],res[i+1>=head?tail:i+1])) { printf("unbounded\n"); exit(0); }
		FOR(i,tail,head) { int j=i+1>=head?tail:i+1; p[i]=intersect(res[i],res[j]); }
		area=0; FOR(i,tail,head) { int j=i+1>=head?tail:i+1; area+=p[i].first*p[j].second-p[i].second*p[j].first; } area/=2;
		return true;
	}
} HPIntersection;

int n;
P p[MAXN];
P r[4];
HPIntersection inter;

void run(int casenr) {
	//puts("");
	scanf("%d",&n); REP(i,n) scanf("%d%d",&p[i].x,&p[i].y); r[0]=P(-1000000,-1000000); r[1]=P(+1000000,-1000000); r[2]=P(+1000000,+1000000); r[3]=P(-1000000,+1000000);
	//if(casenr!=2) return;
	P O=p[0]; FORE(i,1,n) p[i]=p[i]-p[0]; REP(i,4) r[i]=r[i]-p[0]; REP(i,n-1) p[i]=p[i+1]; --n;
	REP(i,n) p[i].id=i; REP(i,4) r[i].id=n+i;
	sort(p,p+n);
	//REP(i,n) printf("%d %d (%d)\n",O.x+p[i].x,O.y+p[i].y,p[i].id); puts("");
	//REP(i,4) printf("[%d %d]\n",r[i].x,r[i].y);

	REP(i,n-1) if(!(p[i]<p[i+1])) { printf("0.0\n"); return; }

	inter.nhp=0;
	REP(i,n) inter.hp[inter.nhp++]=HP(p[i],p[(i+1)%n]);
	REP(i,4) inter.hp[inter.nhp++]=HP(r[i],r[(i+1)%4]);

	for(int at=0,to=0;at<n;++at) {
		if(at==to) to=(to+1)%n;
		while(to!=at&&(p[at]^p[to])>0) to=(to+1)%n;
		if(at==to) continue;
		if((p[at]^p[to])==0) { printf("0.0\n"); return; }
		inter.hp[inter.nhp++]=HP(p[to],p[at]);
		//printf("left of (%d,%d)-(%d,%d)\n",p[to].x,p[to].y,p[at].x,p[at].y);
	}
	REP(i,inter.nhp) if(inter.hp[i].c<0) inter.hp[i].a*=-1,inter.hp[i].b*=-1,inter.hp[i].c*=-1;


	if(!inter.solve()) { printf("empty\n"); return; }
	//FOR(i,inter.tail,inter.head) printf("%lld*x+%lld*y<=%lld (%d)\n",inter.res[i].a,inter.res[i].b,inter.res[i].c,inter.res[i].id); puts("");
	//FOR(i,inter.tail,inter.head) printf("(%.0lf,%.0lf)\n",O.x+inter.p[i].first,O.y+inter.p[i].second); puts("");

	printf("%.9lf\n",inter.area);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	//scanf("%d",&n); inter.nhp=n; REP(i,n) { P a,b; scanf("%d%d%d%d",&a.x,&a.y,&b.x,&b.y); inter.hp[i]=HP(a,b); } if(!inter.solve()) printf("empty\n"); else FOR(i,inter.tail,inter.head) printf("%lld*x+%lld*y<=%lld\n",inter.res[i].a,inter.res[i].b,inter.res[i].c);
	return 0;
}