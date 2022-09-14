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
#include <random>
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

const int MAXN=5000;

typedef struct Knap {
	int opt[MAXN],nopt;
	bool dp[MAXN+1];
	void clear() { nopt=0; }
	void add(int x) { opt[nopt++]=x; }
	bool can(int want) {
		//REP(i,nopt) printf(" %d",opt[i]); printf(" -> %d\n",want);
		REPE(j,want) dp[j]=false; dp[0]=true;
		REP(i,nopt) for(int j=want;j>=opt[i];--j) if(dp[j-opt[i]]) dp[j]=true;
		//printf("-> %s\n",dp[want]?"ok":"err");
		return dp[want];
	}
} Knap;
Knap knap;

int n;
int A,B,C,D;
int par[MAXN];

int chead[MAXN],cnxt[MAXN];
int sz[MAXN]; int mask[MAXN];

void dfs(int at) {
	sz[at]=chead[at]==-1?1:0; mask[at]=0; if(at==A) mask[at]|=1; if(at==B) mask[at]|=2; if(at==C) mask[at]|=4; if(at==D) mask[at]|=8;
	for(int to=chead[at];to!=-1;to=cnxt[to]) { dfs(to); sz[at]+=sz[to]; mask[at]|=mask[to]; }
}



void run() {
	scanf("%d",&n); scanf("%d%d%d%d",&A,&B,&C,&D); --A,--B,--C,--D; par[0]=-1; FOR(i,1,n) { scanf("%d",&par[i]); --par[i]; }
	REP(i,n) chead[i]=-1; FOR(i,1,n) cnxt[i]=chead[par[i]],chead[par[i]]=i;
	dfs(0);
	//REP(i,n) printf("%d: par=%d sz=%d mask=%d\n",i+1,par[i]==-1?-1:par[i]+1,sz[i],mask[i]);
	int nleaf=0; REP(i,n) if(chead[i]==-1) ++nleaf;
	if(nleaf%2==1) { printf("NO\n"); return; }
	REP(x,2) {
		knap.clear(); 
		int want=nleaf/2-1;
		FOR(i,1,n) if(par[i]==0&&mask[i]==0) knap.add(sz[i]);
		FOR(i,1,n) if(mask[i]==0&&(mask[par[i]]==(1<<(0+2*x))||mask[par[i]]==(1<<(1+2*x)))) knap.add(sz[i]);
		FOR(i,1,n) if(par[i]==0&&mask[i]==(1<<(2-x))) want-=sz[i];
		if(!knap.can(want)) { printf("NO\n"); return; }
	}
	printf("YES\n");
}

int main() {
	run();
	return 0;
}