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

int x1,yy1,x2,y2;
int sz;
int x3,y3,x4,y4;

void run() {
	scanf("%d%d%d%d",&x1,&yy1,&x2,&y2);
	if(x1==x2) { sz=abs(yy1-y2); x3=x4=x1+sz; y3=yy1; y4=y2; }
	else if(yy1==y2) { sz=abs(x1-x2); y3=y4=yy1+sz; x3=x1; x4=x2; }
	else {
		sz=abs(x1-x2); if(abs(yy1-y2)!=sz) { printf("-1\n"); return; } 
		x3=x1,y3=y2,x4=x2,y4=yy1;
	}
	printf("%d %d %d %d\n",x3,y3,x4,y4);
}

int main() {
	run();
	return 0;
}