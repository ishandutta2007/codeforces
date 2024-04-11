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
typedef struct P { double x,y; P() {} P(double x,double y):x(x),y(y) {} } P;

const P operator+(const P &a,const P &b) { return P(a.x+b.x,a.y+b.y); }
const P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
const P operator*(const double &a,const P &b) { return P(a*b.x,a*b.y); }
const double operator^(const P &a,const P &b) { return a.x*b.y-a.y*b.x; }
const double operator*(const P &a,const P &b) { return a.x*b.x+a.y*b.y; }
double dist(const P &a,const P &b) { return sqrt((b-a)*(b-a)); }
P invert(const P &a,const P &c,const double &r) { double d=dist(a,c); return c+(r*r/d/d)*(a-c); }
P perp(const P &a) { return P(a.y,-a.x); }


P intersect(const P &a,const P &adir,const P &b,const P &bdir) {
	double num1=(bdir)^(b-a);
	double num2=(adir)^(b-a);
	double den=(bdir)^(adir);
	return a+(num1/den)*adir;
}

pair<double,double> calcrange(const P &a,const P &b,const P &c,const double &r) {
	double d=dist(a,c);
	double e=sqrt(d*d-r*r);
	P bb=invert(b,a,e);
	double dd=dist(bb,c);
	double z=r*r/dd;
	P pp=c+z/dd*(bb-c)+sqrt(r*r-z*z)/dd*perp(bb-c);
	P qq=c+z/dd*(bb-c)-sqrt(r*r-z*z)/dd*perp(bb-c);
	P p=invert(pp,a,e);
	P q=invert(qq,a,e);
	P abmid=a+0.5*(b-a),abdir=1/dist(a,b)*perp(b-a);
	P lp=intersect(abmid,abdir,a+0.5*(p-a),perp(p-a));
	P lq=intersect(abmid,abdir,a+0.5*(q-a),perp(q-a));
	double ppos=(lp-abmid)*abdir,qpos=(lq-abmid)*abdir;
	//printf("d=%lf e=%lf bb=(%lf,%lf) dd=%lf z=%lf\n",d,e,bb.x,bb.y,dd,z);
	//printf("pp=(%lf,%lf) qq=(%lf,%lf) [%lf (%lf,%lf)]\n",pp.x,pp.y,qq.x,qq.y,sqrt(r*r-z*z),perp(bb-c).x,perp(bb-c).y);
	//printf("p=(%lf,%lf) q=(%lf,%lf)\n",p.x,p.y,q.x,q.y);
	//printf("lp=(%lf,%lf) lq=(%lf,%lf)\n",lp.x,lp.y,lq.x,lq.y);
	//printf("%lf..%lf\n",ppos,qpos);
	if(ppos>qpos) swap(ppos,qpos);
	return MP(ppos,qpos);
}

P a,b;
int n;
P c[MAXN]; double r[MAXN];

pair<double,int> e[2*MAXN]; int ne;

void run() {
	scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
	scanf("%d",&n); REP(i,n) scanf("%lf%lf%lf",&c[i].x,&c[i].y,&r[i]);
	ne=0;
	REP(i,n) {
		pair<double,double> cur=calcrange(a,b,c[i],r[i]);
		//printf("%d: %lf..%lf\n",i,cur.first,cur.second);
		e[ne++]=MP(cur.first,-1); e[ne++]=MP(cur.second,+1);
	}
	sort(e,e+ne);
	double best=ne==0?0:e[0].first; int cur=0;
	REP(i,ne) {
		if(cur==0&&e[i].first>=0&&(i==0||e[i-1].first<=0)) best=0;
		if(cur==0&&fabs(e[i].first)<fabs(best)) best=e[i].first;
		cur-=e[i].second;
		if(cur==0&&fabs(e[i].first)<fabs(best)) best=e[i].first;
		if(cur==0&&e[i].first<=0&&(i+1>=ne||e[i+1].first>=0)) best=0;
	}
	P abmid=a+0.5*(b-a),abdir=1/dist(a,b)*perp(b-a);
	P cbest=abmid+best*abdir;
	double ret=dist(cbest,a);
	printf("%.15lf\n",ret);
}

int main() {
	run();
	return 0;
}