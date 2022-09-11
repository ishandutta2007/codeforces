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


void run() {
	int r,x1,y1,x2,y2;
	scanf("%d%d%d%d%d",&r,&x1,&y1,&x2,&y2);
	int dx=x2-x1,dy=y2-y1;
	if((ll)dx*dx+(ll)dy*dy>=(ll)r*r) { printf("%d %d %d\n",x1,y1,r); return; }
	if(dx==0&&dy==0) { printf("%lf %lf %lf\n",x1+0.5*r,y1+0.0,0.5*r); return; }
	double ang=atan2(dy,dx),d=sqrt(1.0*dx*dx+1.0*dy*dy),dans=r+d,xans=x2-0.5*dans*cos(ang),yans=y2-0.5*dans*sin(ang);
	printf("%.15lf %.15lf %.15lf\n",xans,yans,0.5*dans);
}

int main() {
	run();
	return 0;
}