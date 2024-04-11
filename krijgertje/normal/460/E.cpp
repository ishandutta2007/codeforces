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

typedef struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} } P;
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.y<b.y; }
const P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
const int operator^(const P &a,const P &b) { return a.x*b.y-a.y*b.x; }
int side(const P &a,const P &b,const P &c) { int ret=(b-a)^(c-a); return ret<0?-1:ret>0?+1:0; }

int n,r;
P p[61*61]; int np;

P h[61*61]; int nh;

void calchull() {
	sort(p,p+np);
	REP(i,np) {
		while(nh>=2&&side(h[nh-2],h[nh-1],p[i])<=0) --nh;
		h[nh++]=p[i];
	}
	for(int i=np-2;i>=0;--i) {
		while(nh>=2&&side(h[nh-2],h[nh-1],p[i])<=0) --nh;
		h[nh++]=p[i];
	}
	--nh;
	//printf("%d\n",nh); REP(i,nh) printf("(%d,%d)",h[i].x,h[i].y); puts("");
}

P cur[8]; int ncur;
P ret[8]; int nret; int retval;

void go(int at,int sx,int sxx,int sy,int syy,int curval) {
	if(ncur>=n) { 
		if(curval>retval) { nret=ncur; retval=curval; REP(i,ncur) ret[i]=cur[i]; }
		return;
	}
	FOR(i,at,nh) {
		cur[ncur++]=h[i];
		int x=h[i].x,y=h[i].y;
		go(i,sx+x,sxx+x*x,sy+y,syy+y*y,curval+(x*x+y*y)*(ncur-1)-2*x*sx-2*y*sy+sxx+syy);
		--ncur;
	}
}

void run() {
	scanf("%d%d",&n,&r);
	np=0; FORE(x,-r,+r) FORE(y,-r,+r) if(x*x+y*y<=r*r) p[np].x=x,p[np].y=y,++np;
	//printf("%d\n",np);
	calchull();
	go(0,0,0,0,0,0);
	printf("%d\n",retval); REP(i,nret) printf("%d %d\n",ret[i].x,ret[i].y);
	
}

int main() {
	run();
	return 0;
}