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

int nholes,ncomp,nfix;
int l[100000],r[100000],c[100000];
ll dp[301][301]; // dp[i][j]=minimum cost to fix j holes out of [0..i)
int first[300],nxt[100000];

void run(int casenr) {
	scanf("%d%d%d",&nholes,&ncomp,&nfix);
	REP(i,ncomp) { scanf("%d%d%d",&l[i],&r[i],&c[i]); --l[i]; --r[i]; }
	
	memset(first,-1,sizeof(first)); REP(i,ncomp) { nxt[i]=first[l[i]]; first[l[i]]=i; }
	memset(dp,-1,sizeof(dp));
	REPE(i,nholes) dp[i][0]=0;
	REP(j,nholes) {
		REP(i,nholes) if(dp[i][j]!=-1) {
			int ii=i+1,jj=j; ll ncost=dp[i][j];
			if(dp[ii][jj]==-1||ncost<dp[ii][jj]) dp[ii][jj]=ncost;
		}
		REP(i,nholes) if(dp[i][j]!=-1) for(int x=first[i];x!=-1;x=nxt[x]) {
			int ii=r[x]+1,jj=j+r[x]-l[x]+1; ll ncost=dp[i][j]+c[x];
			if(dp[ii][jj]==-1||ncost<dp[ii][jj]) dp[ii][jj]=ncost;
		}
		for(int k=nholes;k>j;--k) REP(i,nholes) if(dp[i][k]!=-1) {
			int ii=i-1,jj=k-1; ll ncost=dp[i][k];
			if(dp[ii][jj]==-1||ncost<dp[ii][jj]) dp[ii][jj]=ncost;
		}
	}
//	REPE(i,nholes) REPE(j,nholes) if(dp[i][j]!=-1) printf("%d %d = %lld\n",i,j,dp[i][j]);
	ll ret=-1; FORE(j,nfix,nholes) if(dp[nholes][j]!=-1&&(ret==-1||dp[nholes][j]<ret)) ret=dp[nholes][j];
	cout<<ret<<endl;
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}