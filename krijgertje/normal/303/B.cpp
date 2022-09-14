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

int X,Y,cx,cy,rx,ry;

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

void run(int casenr) {
	scanf("%d%d%d%d%d%d",&X,&Y,&cx,&cy,&rx,&ry);
	int g=gcd(rx,ry); rx/=g; ry/=g;
	int s=min(X/rx,Y/ry); rx*=s; ry*=s;
	int x=cx-(rx+1)/2,y=cy-(ry+1)/2;
	if(x<0) x=0; if(x+rx>X) x=X-rx;
	if(y<0) y=0; if(y+ry>Y) y=Y-ry;
	printf("%d %d %d %d\n",x,y,x+rx,y+ry);
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}