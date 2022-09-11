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

const int MAXN=22;

int n,m;
int adjmask[MAXN];

int dp[1<<MAXN],prv[1<<MAXN],prvact[1<<MAXN];

int ret[MAXN],nret;

void run() {
	scanf("%d%d",&n,&m); REP(i,n) adjmask[i]=1<<i; REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adjmask[a]|=1<<b; adjmask[b]|=1<<a; }
	//n=MAXN; REP(i,n) adjmask[i]=1<<i; REP(i,n) { if(i!=0) adjmask[i]|=1<<(i-1); if(i+1<n) adjmask[i]|=1<<(i+1); }
	
	bool all=true; REP(i,n) REP(j,n) if((adjmask[i]&(1<<j))==0) all=false; if(all) { printf("0\n\n"); return; }

	memset(dp,-1,sizeof(dp)); REP(i,n) dp[adjmask[i]]=1,prv[adjmask[i]]=-1,prvact[adjmask[i]]=i;
	REP(i,1<<n) if(dp[i]!=-1) {
		REP(j,n) if(i&(1<<j)) {
			int ni=i|adjmask[j];
			if(dp[ni]==-1||dp[i]+1<dp[ni]) dp[ni]=dp[i]+1,prv[ni]=i,prvact[ni]=j;
		}
	}
	assert(dp[(1<<n)-1]!=-1);
	nret=0; for(int at=(1<<n)-1;at!=-1;at=prv[at]) ret[nret++]=prvact[at]; reverse(ret,ret+nret);
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}