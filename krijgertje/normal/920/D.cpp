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
const int MAXSZ=5000;

int n,sz,want;
int a[MAXN];
int b[MAXN];

int dp[MAXN+1][MAXSZ];
int act[MAXN+1][MAXSZ];

int use[MAXN],nuse;
bool isused[MAXN];

int ret[MAXN+5][3],nret;

bool solve() {
	REP(i,n) b[i]=a[i]%sz;
	memset(dp,-1,sizeof(dp)); memset(act,0,sizeof(act)); dp[0][0]=0;
	REP(i,n) {
		//printf("dp%d:",i); REP(j,sz) printf(" %d",dp[i][j]); puts("");
		REP(j,sz) dp[i+1][j]=dp[i][j];
		REP(j,sz) if(dp[i][j]!=-1) {
			int nj=(j+b[i])%sz,nval=dp[i][j]+a[i];
			if(dp[i+1][nj]==-1||nval<dp[i+1][nj]) dp[i+1][nj]=nval,act[i+1][nj]=1;
		}
	}
	//printf("dp:"); REP(j,sz) printf(" %d",dp[n][j]); puts("");
	int bwant=want%sz;
	if(dp[n][bwant]==-1) return false;

	nuse=0;
	for(int i=n,j=bwant;i!=0;j=(j+sz-(act[i][j]==1?b[i-1]:0))%sz,--i) if(act[i][j]==1) use[nuse++]=i-1;
	REP(i,n) isused[i]=false; REP(i,nuse) isused[use[i]]=true;
	//printf("use:"); REP(i,nuse) printf(" %d",use[i]); puts("");
	
	// put all use on one pile, put everything else on other pile, do correction
	int idx=nuse==0?0:use[0],oidx=-1; REP(i,n) if(i!=idx&&!isused[i]) { oidx=i; break; } if(oidx==-1) oidx=idx==0?1:0;
	int idxsum=0,oidxsum=0;
	nret=0;
	//printf("idx=%d oidx=%d\n",idx+1,oidx+1);
	REP(i,n) {
		if(a[i]==0) continue;
		if(i==idx) {
			if(isused[i]) {
				idxsum+=a[i];
			} else {
				oidxsum+=a[i];
				ret[nret][0]=(a[i]+sz-1)/sz,ret[nret][1]=i,ret[nret][2]=oidx,++nret;
			}
		} else if(i==oidx) {
			if(isused[i]) {
				idxsum+=a[i];
				ret[nret][0]=(a[i]+sz-1)/sz,ret[nret][1]=i,ret[nret][2]=idx,++nret;
			} else {
				oidxsum+=a[i];
			}
		} else {
			if(isused[i]) {
				idxsum+=a[i];
				ret[nret][0]=(a[i]+sz-1)/sz,ret[nret][1]=i,ret[nret][2]=idx,++nret;
			} else {
				oidxsum+=a[i];
				ret[nret][0]=(a[i]+sz-1)/sz,ret[nret][1]=i,ret[nret][2]=oidx,++nret;
			}
		}
	}
	//printf("idxsum=%d\n",idxsum);
	assert(idxsum%sz==bwant);
	if(idxsum<want) {
		int t=(want-idxsum)/sz;
		if(oidxsum<t*sz) return false;
		ret[nret][0]=t,ret[nret][1]=oidx,ret[nret][2]=idx,++nret;
	}
	if(idxsum>want) {
		int t=(idxsum-want)/sz;
		ret[nret][0]=t,ret[nret][1]=idx,ret[nret][2]=oidx,++nret;
	}
	return true;
}

void run() {
	scanf("%d%d%d",&n,&sz,&want); REP(i,n) scanf("%d",&a[i]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i,nret) printf("%d %d %d\n",ret[i][0],ret[i][1]+1,ret[i][2]+1);
}

int main() {
	run();
	return 0;
}