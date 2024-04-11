
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

const int MAXN=200000;

int n,xfin,drun,djmp;
int x[MAXN];

int ret[2*MAXN+1],nret;

void run() {
	scanf("%d%d%d%d",&n,&xfin,&drun,&djmp);
	REP(i,n) scanf("%d",&x[i]); sort(x,x+n);
	while(n>=0&&x[n-1]>xfin) --n;

	nret=0; int xat=0,at=0;
	while(xat<xfin) {
		//printf("%d %d\n",at,xat);
		if(at>=n) { int crun=xfin-xat; ret[nret++]=crun; xat+=crun; continue; }
		int crun=x[at]-xat-1; if(crun<drun) { printf("IMPOSSIBLE\n"); return; } ret[nret++]=crun; xat+=crun;
		while(at+1<n&&x[at+1]-x[at]-2<drun) ++at;
		int cjmp=x[at]-xat+1; if(cjmp>djmp) { printf("IMPOSSIBLE\n"); return; } ret[nret++]=cjmp; xat+=cjmp; ++at;
	}
	REP(i,nret) printf("%s %d\n",i%2==0?"RUN":"JUMP",ret[i]);
}

int main() {
	run();
	return 0;
}