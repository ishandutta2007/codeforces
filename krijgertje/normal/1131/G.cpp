#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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

const int MAXN=10000000;
const int MAXKIND=250000;
const int MAXSUMKINDLEN=250000;
const int MAXINST=250000;

int nkind,n;
int kindoff[MAXKIND],kindlen[MAXKIND];
int tplheight[MAXSUMKINDLEN],tplcost[MAXSUMKINDLEN];
int ninst;
int instkind[MAXINST],instmult[MAXINST];

int height[MAXN]; ll cost[MAXN];

int fst[MAXN]; // fst[i] = leftmost domino that falls when pushing domino i to the left
int lst[MAXN]; // lst[i] = rightmost domino that falls when pushing domino i to the right

ll dp[MAXN+1]; // dp[i] = cost to make first i dominoes fall

int a[MAXN]; int na; // stack with decreasing fst[a[i]] as we move down the stack
int b[MAXN]; int nb; // stack with increasing lst[b[i]] and increasing dp[b[i]]+cost[b[i]] as we move down the stack

ll solve() {
	{ int at=0; REP(i,ninst) { int z=instkind[i]; REP(j,kindlen[z]) height[at]=tplheight[kindoff[z]+j]-1,cost[at]=(ll)instmult[i]*tplcost[kindoff[z]+j],++at; } assert(at==n); }
	//printf("height:"); REP(i,n) printf(" %d",height[i]); puts("");
	//printf("cost:"); REP(i,n) printf(" %lld",cost[i]); puts("");

	nb=0;
	for(int i=n-1;i>=0;--i) {
		lst[i]=i;
		while(nb>0&&i+height[i]>=b[nb-1]) lst[i]=lst[b[nb-1]],--nb;
		b[nb++]=i;
	}

	dp[0]=0; na=0; nb=0;
	REP(i,n) {
		fst[i]=i;
		while(na>0&&i-height[i]<=a[na-1]) fst[i]=fst[a[na-1]],--na;
		a[na++]=i;
		while(nb>0&&lst[b[nb-1]]<i) --nb;
		if(nb==0) b[nb++]=i; else { assert(lst[b[nb-1]]>=lst[i]); if(dp[i]+cost[i]<dp[b[nb-1]]+cost[b[nb-1]]) { if(lst[b[nb-1]]==lst[i]) --nb; b[nb++]=i; } }

		// fall to left -> cost[i]+dp[fst[i]]
		ll leftcost=dp[fst[i]]+cost[i];
		// fall to right -> use some domino j (j<=i) such that j+height[j] >= i with minimum dp[j]+cost[j]
		ll rightcost=dp[b[nb-1]]+cost[b[nb-1]];

		dp[i+1]=min(leftcost,rightcost);
	}
	//printf("fst:"); REP(i,n) printf(" %d",fst[i]); puts("");
	//printf("dp:"); REPE(i,n) printf(" %lld",dp[i]); puts("");

	return dp[n];
}

void run() {
	scanf("%d%d",&nkind,&n);
	REP(i,nkind) { kindoff[i]=i==0?0:kindoff[i-1]+kindlen[i-1]; scanf("%d",&kindlen[i]); REP(j,kindlen[i]) scanf("%d",&tplheight[kindoff[i]+j]); REP(j,kindlen[i]) scanf("%d",&tplcost[kindoff[i]+j]); }
	scanf("%d",&ninst);
	REP(i,ninst) scanf("%d%d",&instkind[i],&instmult[i]),--instkind[i];
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}