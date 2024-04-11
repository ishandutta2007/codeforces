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
const double eps=1e-9;

typedef struct  P {
	double x,y,z;
	P() {}
	P(double x,double y,double z):x(x),y(y),z(z) {}
	void print() const { printf("(%.1lf,%.1lf,%.1lf)",x,y,z); }
	bool iszero() { return fabs(x)<eps&&fabs(y)<eps&&fabs(z)<eps; }
} P;
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y,a.z-b.z); }
double operator*(const P&a,const P &b) { return a.x*b.x+a.y*b.y+a.z*b.z; }
P operator^(const P &a,const P &b) { return P(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x); }

typedef struct Pn {
	double a,b,c,d; // ax+by+cz+d=0
	P n() { return P(a,b,c); }
	void print() const { printf("%.2lfx+%.2lfy+%2.lfz+%.2lf=0",a,b,c,d); }
} Pn;
typedef struct Ln {
	P p,dir;
	Ln() {}
	Ln(P p,P dir):p(p),dir(dir) {}
	void print() const { p.print(); printf("+t"); dir.print(); }
} Ln;
int side(const P &p,const Pn &q) {
	double res=p.x*q.a+p.y*q.b+p.z*q.c+q.d;
	return res>=eps?1:0;
}
bool intersect(const Ln &a,const Ln &b,double &s,double &t) {
	P u=a.dir,v=b.dir,p=a.p,q=b.p,w=p-q;
	//a.print(); printf(" x "); b.print(); puts("");
	if(fabs(u.x*v.y-u.y*v.x)<eps) { swap(u.y,u.z); swap(v.y,v.z); swap(p.y,p.z); swap(q.y,q.z); swap(w.y,w.z); }
	if(fabs(u.x*v.y-u.y*v.x)<eps) { swap(u.x,u.z); swap(v.x,v.z); swap(p.x,p.z); swap(q.x,q.z); swap(w.x,w.z); }
	if(fabs(u.x*v.y-u.y*v.x)<eps) return false; // same line or parallel lines
	s=(v.y*w.x-v.x*w.y)/(v.x*u.y-v.y*u.x);
	t=(u.x*w.y-u.y*w.x)/(u.x*v.y-u.y*v.x);
	//printf("%lf %lf (%lf,%lf,%lf)\n",s,t,(p.x+s*u.x)-(q.x+t*v.x),(p.y+s*u.y)-(q.y+t*v.y),(p.z+s*u.z)-(q.z+t*v.z));
	return fabs((p.z+s*u.z)-(q.z+t*v.z))<eps;
}

int na,nb;
P pa[MAXN+1],pb[MAXN+1];


void run() {
	scanf("%d",&na); REP(i,na) scanf("%lf%lf%lf",&pa[i].x,&pa[i].y,&pa[i].z); pa[na]=pa[0];
	scanf("%d",&nb); REP(i,nb) scanf("%lf%lf%lf",&pb[i].x,&pb[i].y,&pb[i].z); pb[nb]=pb[0];

	// determine plane of a A
	Pn A; P an=(pa[1]-pa[0])^(pa[2]-pa[0]); A.a=an.x,A.b=an.y,A.c=an.z,A.d=-(an*pa[0]);
	//A.print(); puts("");

	// determine plane of b B
	Pn B; P bn=(pb[1]-pb[0])^(pb[2]-pb[0]); B.a=bn.x,B.b=bn.y,B.c=bn.z,B.d=-(bn*pb[0]);
	//B.print(); puts("");

	// determine line of intersection C
	Ln C; C.dir=A.n()^B.n();
	if(C.dir.iszero()) { printf("NO\n"); return; } // same plane or parallel planes
	if(fabs(C.dir.x)>fabs(C.dir.y)&&fabs(C.dir.x)>fabs(C.dir.z)) { fprintf(stderr,"swap xz\n"); REPE(i,na) swap(pa[i].x,pa[i].z); REPE(i,nb) swap(pb[i].x,pb[i].z); swap(A.a,A.c); swap(B.a,B.c); swap(C.dir.x,C.dir.z); }
	else if(fabs(C.dir.y)>fabs(C.dir.z)) { fprintf(stderr,"swap yz\n"); REPE(i,na) swap(pa[i].y,pa[i].z); REPE(i,nb) swap(pb[i].y,pb[i].z); swap(A.b,A.c); swap(B.b,B.c); swap(C.dir.y,C.dir.z); }
	C.p.x=(A.b*B.d-B.b*A.d)/(A.a*B.b-B.a*A.b),C.p.y=(B.a*A.d-A.a*B.d)/(A.a*B.b-B.a*A.b),C.p.z=0;
	//C.print(); puts("");

	// foreach line of a, determine where it crosses L
	vector<pair<double,int> > e;
	REP(i,na) {
		double s,t;
		int s0=side(pa[i],B),s1=side(pa[i+1],B);
		//printf("A%d: %d %d\n",i,s0,s1);
		if(s0==s1) continue;
		assert(intersect(C,Ln(pa[i],pa[i+1]-pa[i]),s,t));
		e.PB(MP(s,0));
		//printf("%lf\n",s);
	}

	// foreach line of b, determine where it crosses L and from which side
	REP(i,nb) {
		double s,t;
		int s0=side(pb[i],A),s1=side(pb[i+1],A);
		//printf("B%d: %d %d\n",i,s0,s1);
		if(s0==s1) continue;
		assert(intersect(C,Ln(pb[i],pb[i+1]-pb[i]),s,t));
		//printf("%lf %d\n",s,s1-s0);
		e.PB(MP(s,s1-s0));
	}

	sort(e.begin(),e.end());
	bool inside=false; int sum=0;
	REPSZ(i,e) {
		if(e[i].second==0) inside=!inside; else if(inside) sum+=e[i].second;
	}
	printf("%s\n",sum==0?"NO":"YES");
}

int main() {
	run();
	return 0;
}