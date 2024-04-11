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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

typedef struct P {
	int x,y;
} P;
bool operator<(const P &a,const P &b) {
	if(a.y==0&&b.y==0) return false;
	if(a.y==0) return true;
	if(b.y==0) return false;
	return a.x*b.y<b.x*a.y;
}
bool operator==(const P &a,const P &b) { return !(a<b)&&!(b<a); }

int n;
int sx,sy;
P p[1000];

void run() {
	scanf("%d",&n);
	scanf("%d%d",&sx,&sy);
	REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
	REP(i,n) p[i].x-=sx,p[i].y-=sy;
	REP(i,n) if(p[i].y<0) { p[i].y*=-1; p[i].x*=-1; } else if(p[i].y==0&&p[i].x<0) { p[i].x*=-1; }
	sort(p,p+n);
	//REP(i,n) printf("%d %d\n",p[i].x,p[i].y); puts("");

	int ret=0,at=0;
	while(at<n) {
		int to=at+1; while(to<n&&p[at]==p[to]) ++to;
		++ret; at=to;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}