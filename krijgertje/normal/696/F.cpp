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

const int MAXN=300;
const double eps=1e-9;
typedef struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} } P;
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }
typedef struct L { double a,b,c; L() {} L(const P &p,const P &q):a(p.y-q.y),b(q.x-p.x),c(p^q) {} L(double a,double b,double c):a(a),b(b),c(c) {} } L;
L bisect(const L &u,const L &v) { double uu=sqrt(u.a*u.a+u.b*u.b),vv=sqrt(v.a*v.a+v.b*v.b); return L(u.a*vv-v.a*uu,u.b*vv-v.b*uu,u.c*vv-v.c*uu); }
typedef struct PD { double x,y; } PD;

int n;
P p[2*MAXN+1];

bool ok(int a,int b) {
	P da=p[a+1]-p[a],db=p[b+1]-p[b];
	bool ret=(da^db)>=0;
	//printf("%d %d = %c\n",a,b,ret?'V':'x');
	return ret;
}
bool intersect(int a,int b,int c,PD &ret) {
	
	if(a==b) { assert(c==a); ret.x=p[a].x; ret.y=p[a].y; return true; }
	L s(p[a],p[a+1]),t(p[b],p[b+1]),u=bisect(s,t),v(p[c],p[c+1]);
	//printf("\t[%d,%d,%d] (%.2lf)x+(%.2lf)y+(%.2lf)=0 (%.2lf)x+(%.2lf)y+(%.2lf)=0\n",a,b,c,s.a,s.b,s.c,t.a,t.b,t.c);
	double den=u.a*v.b-u.b*v.a;
	if(fabs(den)<eps) {
		//printf("\t%d %d %d: parallel\n",a,b,c);
		return false;
	}
	ret.x=(u.b*v.c-u.c*v.b)/den;
	ret.y=(v.a*u.c-v.c*u.a)/den;
	//printf("\t%d %d %d: (%lf,%lf)\n",a,b,c,ret.x,ret.y);

	int lx=min(p[c].x,p[c+1].x),hx=max(p[c].x,p[c+1].x);
	int ly=min(p[c].y,p[c+1].y),hy=max(p[c].y,p[c+1].y);
	return lx-eps<=ret.x&&ret.x<=hx+eps&&ly-eps<=ret.y&&ret.y<=hy+eps;
}
double dist(int a,PD b) {
	L s(p[a],p[a+1]);
	double den=sqrt(s.a*s.a+s.b*s.b);
	return fabs(s.a*b.x+s.b*b.y+s.c)/den;
}


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
	REPE(i,n) p[i+n]=p[i];


	// a..a+1 is first line covered by person 1
	// b..b+1 is first line covered by person 1
	// c..c+1 is segment intersecting angular bisector of a..a+1 and b-1..b
	// d..d+1 is segment intersecting angular bisector of b..b+1 and a-1..a
	int a=0,b=1,c=0,d=1;
	double ret=1e200; PD retu,retv;
	while(a<n) {
		if(b<=a) b=a+1; while(!ok(b,a+n-1)) ++b;
		while(ok(a,b-1)) {
			PD u,v;
			if(c<a) c=a; while(!intersect(a,b-1,c,u)) ++c;
			if(d<b) d=b; while(!intersect(b,a+n-1,d,v)) ++d;
			double du=dist(a,u);
			double dv=dist(b,v);
			//printf("%d..%d -> (%.2lf,%.2lf) = %lf | %d..%d -> (%.2lf,%.2lf) = %lf\n",a,b-1,u.x,u.y,du,b,a+n-1,v.x,v.y,dv);
			double cur=max(du,dv);
			if(cur<ret) { ret=cur; retu=u; retv=v; }
			++b;
		}
		++a,--b;
	}
	printf("%.10lf\n",ret); printf("%.10lf %.10lf\n",retu.x,retu.y); printf("%.10lf %.10lf\n",retv.x,retv.y);
}

int main() {
	run();
	return 0;
}