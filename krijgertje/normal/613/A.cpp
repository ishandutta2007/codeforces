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
typedef struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} } P;
const P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
const ll operator*(const P &a,const P &b) { return (ll)a.x*b.x+(ll)a.y*b.y; }

int n;
P o;
P p[MAXN+1];

void run() {
	scanf("%d%d%d",&n,&o.x,&o.y); REP(i,n) scanf("%d%d",&p[i].x,&p[i].y); p[n]=p[0];

	double rmin=1e200,rmax=0;
	REP(i,n) { int dx=p[i].x-o.x,dy=p[i].y-o.y; double r=sqrt((double)dx*dx+(double)dy*dy); if(r<rmin) rmin=r; if(r>rmax) rmax=r; }
	REP(i,n) {
		ll num=(o-p[i])*(p[i+1]-p[i]),den=(p[i+1]-p[i])*(p[i+1]-p[i]);
		//printf("%d -> %lf\n",i,1.0*num/den);
		if(num<=0||num>=den) continue;
		double x=p[i].x+1.0*num/den*(p[i+1].x-p[i].x);
		double y=p[i].y+1.0*num/den*(p[i+1].y-p[i].y);
		double dx=x-o.x,dy=y-o.y,r=sqrt(dx*dx+dy*dy); if(r<rmin) rmin=r; if(r>rmax) rmax=r;
	}
	printf("%.9lf\n",(rmax*rmax-rmin*rmin)*acos(-1));
}

int main() {
	run();
	return 0;
}