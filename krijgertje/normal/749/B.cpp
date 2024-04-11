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
bool operator==(const P &a,const P &b) { return a.x==b.x&&a.y==b.y; }
P operator+(const P &a,const P &b) { return P(a.x+b.x,a.y+b.y); }
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }

P p[3];
P ret[3]; int nret;

void run() {
	REP(i,3) scanf("%d%d",&p[i].x,&p[i].y);
	nret=0;
	REP(i,3) {
		P a=p[0],d1=p[1]-p[0],d2=p[2]-p[0];
		if(i==1) d2=d2-d1; if(i==2) d1=d1-d2;
		P d=i==0?a+d1+d2:i==1?a+d2:a+d1;
		ret[nret++]=d;
	}
	sort(ret,ret+nret); nret=unique(ret,ret+nret)-ret;
	printf("%d\n",nret);
	REP(i,nret) printf("%d %d\n",ret[i].x,ret[i].y);
}

int main() {
	run();
	return 0;
}