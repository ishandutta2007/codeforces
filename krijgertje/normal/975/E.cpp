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

const int MAXN=10000;
struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} };
P operator+(const P &a,const P &b) { return P(a.x+b.x,a.y+b.y); }
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }
struct PF { long double x,y; PF() {} PF(long double x,long double y):x(x),y(y) {} PF(const P &p):x(p.x),y(p.y) {} };
PF operator-(const PF &a,const PF &b) { return PF(a.x-b.x,a.y-b.y); }
PF operator+(const PF &a,const PF &b) { return PF(a.x+b.x,a.y+b.y); }
PF operator*(const long double &a,const PF &b) { return PF(a*b.x,a*b.y); }
long double operator^(const PF &a,const PF &b) { return a.x*b.y-a.y*b.x; }
long double operator*(const PF &a,const PF &b) { return a.x*b.x+a.y*b.y; }


int n,nq;
P p[2*MAXN+1];

PF opp[MAXN];
PF dn[MAXN],rt[MAXN];
long double xdn[MAXN],xrt[MAXN],ydn[MAXN],yrt[MAXN];
 
long double area(const P &a,const P &b,const P &c) {
	return 0.5*abs((b-a)^(c-a));
}
long double area(const PF &a,const PF &b,const PF &c) {
	return 0.5*fabs((b-a)^(c-a));
}

P ca[MAXN-2]; long double wa[MAXN-2];
PF c;

void calcopposites() {
	REP(i,n-2) ca[i]=p[0]+p[i+1]+p[i+2],wa[i]=area(p[0],p[i+1],p[i+2]);
	double den=0; REP(i,n-2) den+=wa[i]; den*=3;
	c=PF(0,0); REP(i,n-2) c=c+(wa[i]/den)*PF(ca[i]);
	//printf("centroid=(%.15lf,%.15lf)\n",c.x,c.y);

	/*long double totarea=0; FOR(i,2,n) totarea+=area(p[0],p[i-1],p[i]);
	//printf("totarea=%lf\n",totarea);

	int l=0,r=0; long double curarea=0;
	while(l<n) {
		if(r==l) ++r;
		while(true) { long double cur=area(p[l],p[r],p[r+1]); if(curarea+cur>0.5*totarea) break; curarea+=cur; ++r; }
		PF a(p[l]),b(p[r]),cl(p[r]),cr(p[r+1]);
		REP(rep,100) {
			PF cm((cl.x+cr.x)/2,(cl.y+cr.y)/2);
			long double cur=area(a,b,cm);
			//if(l==0) printf("\t%d: (%.15lf,%.15lf) -> %.15lf\n",rep,cm.x,cm.y,curarea+cur);
			if(curarea+cur>0.5*totarea) cr=cm; else cl=cm;
		}
		opp[l]=PF((cl.x+cr.x)/2,(cl.y+cr.y)/2);
		//printf("curarea+cur=%lf [%lf,%lf]\n",curarea+area(a,b,opp[l]),curarea,curarea+area(p[l],p[r],p[r+1]));
		curarea-=area(p[l],p[l+1],p[r]); ++l;
	}*/
	REP(i,n) {
		long double dx=c.x-p[i].x,dy=c.y-p[i].y,len=sqrtl(dx*dx+dy*dy); dx/=len,dy/=len;
		dn[i]=PF(dx,dy),rt[i]=PF(-dy,dx);
		xdn[i]=PF(1,0)*dn[i],xrt[i]=PF(1,0)*rt[i],ydn[i]=PF(0,1)*dn[i],yrt[i]=PF(0,1)*rt[i];
		//printf("(%d,%d): opp=(%lf,%lf) dn=(%lf,%lf) rt=(%lf,%lf)\n",p[i].x,p[i].y,opp[i].x,opp[i].y,dn[i].x,dn[i].y,rt[i].x,rt[i].y);
		//printf("x=(%lf,%lf) y=(%lf,%lf)\n",xdn[i],xrt[i],ydn[i],yrt[i]);
	}
}

int pin1,pin2;
int topidx; PF top;
PF get(int idx) {
	if(topidx==-1) return PF(p[idx]);
	P d=p[idx]-p[topidx];
	//printf("get(%d): dx=%d dy=%d\n",idx,d.x,d.y);
	return top+d.x*PF(xrt[topidx],-xdn[topidx])+d.y*PF(yrt[topidx],-ydn[topidx]);
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
	FORE(i,n,2*n) p[i]=p[i-n];

	//offset=p[0]; REPE(i,2*n) p[i]=p[i]-offset;

	calcopposites();
	pin1=0,pin2=1,topidx=-1;
	REP(qi,nq) {
		int kind; scanf("%d",&kind);
		if(kind==1) {
			int rempin,addpin; scanf("%d%d",&rempin,&addpin); --rempin,--addpin;
			assert(rempin==pin1||rempin==pin2); if(rempin==pin1) swap(pin1,pin2);
			top=get(pin1); topidx=pin1; pin2=addpin;
			//printf("ntop: %d at (%lf,%lf)\n",topidx,top.x,top.y);
		}
		if(kind==2) {
			int idx; scanf("%d",&idx); --idx;
			PF ans=get(idx);
			printf("%.15lf %.15lf\n",(double)ans.x,(double)ans.y);
		}
	}
}

int main() {
	run();
	return 0;
}