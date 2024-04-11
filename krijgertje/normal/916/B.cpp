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

ll want; int n;

int ret[MAXN],nret;

void run() {
	scanf("%lld%d",&want,&n);
	nret=0; for(int i=0;(1LL<<i)<=want;++i) if(want&(1LL<<i)) ret[nret++]=i;
	if(nret>n) { printf("No\n"); return; }
	int mx=ret[--nret],mxcnt=1;
	while(nret+2*mxcnt<=n) {
		mxcnt*=2,--mx; if(nret>0&&ret[nret-1]==mx) --nret,++mxcnt;
	}
	REP(i,mxcnt) ret[nret++]=mx;
	while(nret<n) { --ret[0]; ret[nret++]=ret[0]; }
	sort(ret,ret+nret); reverse(ret,ret+nret);
	printf("Yes\n"); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}