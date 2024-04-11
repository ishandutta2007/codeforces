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

const int MAXN=100;
const int MAXT=2000;
typedef struct Item { int need,lim,val,id; } Item;
bool operator<(const Item &a,const Item &b) { return a.lim<b.lim; }

int n;
Item a[MAXN];
int dp[MAXN+1][MAXT+1];
int prv[MAXN+1][MAXT+1];

int ret[MAXN],nret;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d%d",&a[i].need,&a[i].lim,&a[i].val),a[i].id=i; sort(a,a+n);
	memset(dp,0,sizeof(dp)); memset(prv,-1,sizeof(prv));
	REP(i,n) {
		REPE(t,MAXT) dp[i+1][t]=dp[i][t],prv[i+1][t]=prv[i][t];
		for(int t=a[i].lim-1;t>=a[i].need;--t) {
			int nval=dp[i][t-a[i].need]+a[i].val;
			if(nval>dp[i+1][t]) dp[i+1][t]=nval,prv[i+1][t]=i;
		}
	}
	int bt=0; REPE(t,MAXT) if(dp[n][t]>dp[n][bt]) bt=t;
	nret=0; for(int i=n,t=bt;prv[i][t]!=-1;) { int cur=prv[i][t]; ret[nret++]=a[cur].id+1; t-=a[cur].need; i=cur; }
	reverse(ret,ret+nret);
	printf("%d\n",dp[n][bt]);
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}