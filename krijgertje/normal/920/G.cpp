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

const int MAXA=7;
const int MAXVAL=1000000;

int a[MAXA],na;
int pmn[MAXVAL+1];

void calca(int x) {
	na=0; while(x!=1) { int p=pmn[x]; a[na++]=p; while(x!=1&&pmn[x]==p) x/=p; }
}

int calc(int bound) {
	int ret=0;
	REP(i,1<<na) {
		int prod=1,cnt=0; REP(j,na) if(i&(1<<j)) prod*=a[j],++cnt;
		if(cnt%2==0) ret+=bound/prod; else ret-=bound/prod;
	}
	//printf("calc(%d) -> %d\n",bound,ret);
	return ret;
}

void run() {
	int bound,p,idx; scanf("%d%d%d",&bound,&p,&idx); --idx;
	calca(p);
	idx+=calc(bound);
	int l=1,h=2; while(idx>=calc(h)) l=h,h+=h; while(l+1<h) { int m=l+(h-l)/2; if(idx>=calc(m)) l=m; else h=m; } printf("%d\n",h);
}

void precalc() {
	memset(pmn,-1,sizeof(pmn)); FORE(i,2,MAXVAL) if(pmn[i]==-1) for(int j=i;j<=MAXVAL;j+=i) if(pmn[j]==-1) pmn[j]=i;
}

int main() {
	precalc();
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}