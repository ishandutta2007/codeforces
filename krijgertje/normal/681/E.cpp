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
const double MYPI=acos(-1.0);
typedef struct E { double ang; int delta; } E;
bool operator<(const E &p,const E &q) { return p.ang<q.ang; }

ll sx,sy,v,tmx;
int n;
E e[2*MAXN]; int ne,e0; bool covered;

void addevent(double a,int delta) {
	if(a<eps) a+=2*MYPI,e0+=delta;
	if(a>2*MYPI+eps) a-=2*MYPI,e0-=delta;
	e[ne].ang=a,e[ne].delta=delta,++ne;
}


void run() {
	scanf("%lld%lld%lld%lld%d",&sx,&sy,&v,&tmx,&n); ne=0; covered=false; e0=0;
	REP(i,n) {
		ll x,y,r; scanf("%lld%lld%lld",&x,&y,&r);
		ll dx=x-sx,dy=y-sy; if(dx*dx+dy*dy<=r*r) { covered=true; continue; }
		if(dx*dx+dy*dy-r*r<=1.0*v*tmx*v*tmx) {
			double a=atan2(dy,dx),da=asin(r/sqrt(1.0*dx*dx+dy*dy));
			if(!(da>=-10&&da<=10)) printf("err %lld %lld %lld (%lld %lld %lld %lld)\n",x,y,r,sx,sy,v,tmx);
			addevent(a-da,+1),addevent(a+da,-1);
			//printf("a=%.9lf da=%.9lf\n",a,da);
		} else if(dx*dx+dy*dy<1.0*(r+v*tmx)*(r+v*tmx)) {
			// R*R-x*x=r*r-(d-x)*(d-x) -> x=(R*R-r*r+d*d)/(2*d)
			double z=0.5*(v*tmx*v*tmx-r*r+dx*dx+dy*dy)/sqrt(1.0*dx*dx+dy*dy);
			double a=atan2(dy,dx),da=acos(z/v/tmx);
			addevent(a-da,+1),addevent(a+da,-1);
			if(!(da>=-10&&da<=10)) printf("err %lld %lld %lld (%lld %lld %lld %lld)\n",x,y,r,sx,sy,v,tmx);
			//printf("a=%.9lf da=%.9lf\n",a,da);
			//printf("z=%.9lf den=%lld  (.5*%lld/%.9lf)\n",z,v*tmx,v*tmx*v*tmx-r*r+dx*dx+dy*dy,sqrt(1.0*dx*dx+dy*dy));
			//printf("\t%lf\n",(v*tmx*v*tmx-z*z)-(r*r-(sqrt(1.0*dx*dx+dy*dy)-z)*(sqrt(1.0*dx*dx+dy*dy)-z)));
		}
	}
	sort(e,e+ne);
	//REP(i,ne) printf("\t%.9lf: %d\n",e[i].ang,e[i].delta);
	int cur=e0; double ret=0;
	REPE(i,ne) {
		double pa=i==0?0:e[i-1].ang,na=i==ne?2*MYPI:e[i].ang;
		if(cur>0) ret+=na-pa; cur+=e[i].delta;
	}
	ret/=2*MYPI;
	printf("%.9lf\n",covered?1.0:ret);
}

int main() {
	run();
	return 0;
}