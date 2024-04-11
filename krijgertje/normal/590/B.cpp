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

int sx,sy,tx,ty;
int vmax,tchange;
int vx,vy,wx,wy;

bool can(double t) {
	double tv=min(t,1.0*tchange),tw=t-tv;
	double dx=sx+tv*vx+tw*wx-tx,dy=sy+tv*vy+tw*wy-ty;
	return sqrt(dx*dx+dy*dy)/vmax<=t;
}

void run() {
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	scanf("%d%d",&vmax,&tchange);
	scanf("%d%d%d%d",&vx,&vy,&wx,&wy);

	double l=0,h=1;
	while(!can(h)) l=h,h+=h;
	REP(i,100) { double m=l+(h-l)/2; if(!can(m)) l=m; else h=m; }
	printf("%.9lf\n",l+(h-l)/2);
}

int main() {
	run();
	return 0;
}