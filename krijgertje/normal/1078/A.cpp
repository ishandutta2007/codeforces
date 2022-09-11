#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

struct P { double x,y; P(double x,double y):x(x),y(y) {} };

int a,b,c;
int sx,sy,tx,ty;

vector<P> p;
vector<double> d;

double dst(const P &a,const P &b) { double dx=b.x-a.x,dy=b.y-a.y; return sqrt(dx*dx+dy*dy); }

double solve() {
	if(sx>tx) a=-a,sx=-sx,tx=-tx;
	if(sy>ty) b=-b,sy=-sy,ty=-ty;

	p.clear();
	p.PB(P(sx,sy)); p.PB(P(sx,ty)); p.PB(P(tx,sy)); p.PB(P(tx,ty));
	if(b!=0) p.PB(P(sx,(-1.0*a*sx-c)/b)),p.PB(P(tx,(-1.0*a*tx-c)/b));
	if(a!=0) p.PB(P((-1.0*b*sy-c)/a,sy)),p.PB(P((-1.0*b*ty-c)/a,ty));
	int n=SZ(p);
	d=vector<double>(n,1e200); d[0]=0;
	REP(rep,100) {
		bool change=false;
		REP(i,n) REP(j,n) {
			if((i<4||j<4)&&(p[i].x!=p[j].x&&p[i].y!=p[j].y)) continue;
			double nval=d[i]+dst(p[i],p[j]);
			if(nval+1e-9<d[j]) d[j]=nval,change=true;
		}
		if(!change) break;
	}
	return d[3];
}

void run() {
	scanf("%d%d%d",&a,&b,&c);
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	printf("%.15lf\n",solve());
}

int main() {
	run();
	return 0;
}