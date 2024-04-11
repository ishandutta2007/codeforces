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

const int MAXN=1000000;
const int SZ=1000;

typedef struct P { int x,y,idx; } P;
bool cmpx(const P &a,const P &b) { return a.x<b.x; }
bool cmpy(const P &a,const P &b) { return a.y<b.y; }

int n;
P p[MAXN];


void run() {
	scanf("%d",&n);	REP(i,n) { p[i].idx=i+1; scanf("%d%d",&p[i].x,&p[i].y); }

	//n=MAXN; REP(i,n) p[i].idx=i+1,p[i].x=(rand()*RAND_MAX+rand())%(MAXN+1),p[i].y=(rand()*RAND_MAX+rand())%(MAXN+1); printf("start\n"); fflush(stdout);

	sort(p,p+n,cmpx);
	for(int i=0;i<n;i+=SZ) { sort(p+i,p+min(i+SZ,n),cmpy); if((i/SZ)&1) reverse(p+i,p+min(i+SZ,n)); }

	//ll test=0; FOR(i,1,n) test+=abs(p[i].x-p[i-1].x)+abs(p[i].y-p[i-1].y);
	//fprintf(stderr,"%lld (%lf)\n",test,1.0*test/2500000000LL);

	REP(i,n) { if(i!=0) printf(" "); printf("%d",p[i].idx); } puts("");
}

int main() {
	run();
	return 0;
}