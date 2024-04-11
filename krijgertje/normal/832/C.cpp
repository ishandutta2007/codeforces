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
const int MAXX=1000000;
const int MAXV=1000000;
typedef struct P { int x,v,dir; } P;
bool operator<(const P &a,const P &b) { return a.x<b.x; }

typedef struct E { int x; int kind,by; } E;
bool operator<(const E &a,const E &b) { if(a.x!=b.x) return a.x<b.x; return a.by>b.by; }


int n,v;
P p[MAXN];
E e[4*MAXN+4]; int ne;

void addevent(double l,double r,int kind) { e[ne].x=l,e[ne].kind=kind,e[ne].by=+1,++ne; e[ne].x=r,e[ne].kind=kind,e[ne].by=-1,++ne; }
bool ok(double t) {
	bool alwayslft=false; REP(i,n) if(p[i].dir==1&&p[i].x-p[i].v*t<=0   ) alwayslft=true;
	bool alwaysrgt=false; REP(i,n) if(p[i].dir==2&&p[i].x+p[i].v*t>=MAXX) alwaysrgt=true;
	//printf("%s %s\n",alwayslft?"alwayslft":"not",alwayslft?"alwaysrgt":"not");

	ne=0;
	if(alwayslft) addevent(0,MAXX,0);
	if(alwaysrgt) addevent(0,MAXX,1);

	REP(i,n) if(p[i].dir==1) {
		int px=p[i].x,pv=p[i].v;
		int cur=(int)floor(min(1.0*MAXX,(t*v*v-t*pv*pv+1.0*px*pv)/v));
		if(cur>=px) addevent(px,cur,0);
		//printf("lft %d: [%d..%d]\n",i,px,cur);
	}
	REP(i,n) if(p[i].dir==2) {
		int px=MAXX-p[i].x,pv=p[i].v;
		int cur=MAXX-(int)floor(min(1.0*MAXX,(t*v*v-t*pv*pv+1.0*px*pv)/v));
		if(cur<=p[i].x) addevent(cur,p[i].x,1);
		//printf("rgt %d: [%d..%d]\n",i,cur,p[i].x);
	}
	sort(e,e+ne);
	int nlft=0,nrgt=0;
	REP(i,ne) {
		if(e[i].kind==0) nlft+=e[i].by; else nrgt+=e[i].by;
		if(nlft>0&&nrgt>0) return true;
	}
	return false;	
}

void run() {
	scanf("%d%d",&n,&v); REP(i,n) scanf("%d%d%d",&p[i].x,&p[i].v,&p[i].dir);
	sort(p,p+n);

	double l=0,h=MAXX;
	REP(i,100) {
		double m=l+(h-l)/2;
		if(ok(m)) h=m; else l=m;
	}
	printf("%.9lf\n",(l+h)/2);
}

int main() {
	run();
	return 0;
}