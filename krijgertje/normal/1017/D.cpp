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

const int MAXLEN=12;
const int MAXZ=(2<<12)-1;
const int MAXVAL=100;
struct Z { int c[2]; int cnt; };

int len,n,nq;
int w[MAXLEN];
Z z[MAXZ]; int nz,zroot;

vector<vector<int>> dp[MAXZ]; // dp[at][mask][sum] = # ways to make exactly sum from node at with the given mask


int makez() { assert(nz<MAXZ); int ret=nz++; z[ret].c[0]=z[ret].c[1]=-1,z[ret].cnt=0; return ret; }

void dfs(int at,int dep) {
	dp[at]=vector<vector<int>>(1<<(len-dep),vector<int>(MAXVAL+1,0));
	REPSZ(mask,dp[at]) dp[at][mask][0]+=z[at].cnt;
	REP(x,2) {
		int to=z[at].c[x]; if(to==-1) continue;
		dfs(to,dep+1);
		REPSZ(mask,dp[at]) REPE(i,MAXVAL) {
			int ni=i-((mask&1)==x?w[dep]:0);
			if(ni>=0) dp[at][mask][i]+=dp[to][mask>>1][ni];
		}
	}
	//REPSZ(mask,dp[at]) { printf("%d:\t",at); REP(i,len-dep) printf("%d",(mask>>i)&1); printf(":"); REPE(i,MAXVAL) if(dp[at][mask][i]!=0) printf(" %d=%d",i,dp[at][mask][i]); puts(""); }
}

void run() {
	scanf("%d%d%d",&len,&n,&nq);
	REP(i,len) scanf("%d",&w[i]);
	nz=0; zroot=makez(); REP(i,n) { char s[MAXLEN+1]; scanf("%s",s); int at=zroot; REP(j,len) { int x=s[j]-'0'; if(z[at].c[x]==-1) z[at].c[x]=makez(); at=z[at].c[x]; } ++z[at].cnt; }

	dfs(zroot,0);
	REP(at,nz) REPSZ(mask,dp[at]) REP(i,MAXVAL) dp[at][mask][i+1]+=dp[at][mask][i];
	REP(i,nq) {
		char s[MAXLEN+1]; int lim; scanf("%s%d",s,&lim); int mask=0; REP(j,len) if(s[j]=='1') mask|=1<<j;
		printf("%d\n",dp[zroot][mask][lim]);
	}
}

int main() {
	run();
	return 0;
}