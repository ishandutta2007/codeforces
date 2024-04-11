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

const int MAXN=5000;
const int MAXM=5000;

int n,m,tmax;
int ghead[MAXN],gnxt[MAXM],gto[MAXM],glen[MAXM];
int indeg[MAXN];
int q[MAXN],qhead,qtail;

int dp[MAXN][MAXN+1];
int prv[MAXN][MAXN+1];
int ret[MAXN],nret;

void run() {
	scanf("%d%d%d",&n,&m,&tmax);
	REP(i,n) ghead[i]=-1,indeg[i]=0;
	REP(i,m) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b;
		gnxt[i]=ghead[a]; ghead[a]=i; gto[i]=b; glen[i]=c; ++indeg[b];
	}
	memset(dp,-1,sizeof(dp)); dp[0][1]=0;
	qhead=qtail=0; REP(i,n) if(indeg[i]==0) q[qhead++]=i;
	while(qtail<qhead) {
		int at=q[qtail++]; //printf("at %d\n",at);
		REPE(cnt,n) if(dp[at][cnt]!=-1) for(int x=ghead[at];x!=-1;x=gnxt[x]) {
			int nval=dp[at][cnt]+glen[x]; if(nval>tmax) continue;
			int to=gto[x]; if(dp[to][cnt+1]!=-1&&dp[to][cnt+1]<nval) continue;
			dp[to][cnt+1]=nval,prv[to][cnt+1]=at;
			//printf("%d %d = %d (%d)\n",to,cnt+1,nval,at);
		}
		for(int x=ghead[at];x!=-1;x=gnxt[x]) if(--indeg[gto[x]]==0) q[qhead++]=gto[x];
	}
	int mx=-1; REPE(cnt,n) if(dp[n-1][cnt]!=-1) mx=cnt; nret=0;
	for(int at=n-1;at!=0;at=prv[at][mx],--mx) ret[nret++]=at; ret[nret++]=0;
	reverse(ret,ret+nret);
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}


int main() {
	run();
	return 0;
}