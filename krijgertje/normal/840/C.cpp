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

const int MAXN=300;
const int MOD=1000000007;

int n;
int a[MAXN];

int fac[MAXN+1];
int C[MAXN+1][MAXN+1];
int dp[2][MAXN+1]; // dp[][i] = ways to have i pairs to break up

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	REP(i,n) for(int x=2;x*x<=a[i];++x) while(a[i]%(x*x)==0) a[i]/=x*x;
	REPE(i,n) { C[i][0]=C[i][i]=1; FOR(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD; }
	fac[0]=1; FORE(i,1,n) fac[i]=(ll)fac[i-1]*i%MOD;
	//REP(i,n) { if(i!=0) printf(" "); printf("%d",a[i]); } puts("");

	sort(a,a+n);
	int z=0; memset(dp[z],0,sizeof(dp[z])); dp[z][0]=1; int sum=0;
	for(int at=0,to=at;at<n;at=to) {
		while(to<n&&a[at]==a[to]) ++to;
		int cnt=to-at;
		memset(dp[1-z],0,sizeof(dp[1-z]));
		REPE(i,n) if(dp[z][i]!=0) FORE(ngrp,1,cnt) REPE(di,min(i,ngrp)) {
			if(ngrp-di>sum+1-i) continue;
			int x1=C[cnt-ngrp+ngrp-1][ngrp-1];
			int x2=C[i][di];
			int x3=C[sum+1-i][ngrp-di];
			int x4=fac[cnt];
			int ni=i-di+cnt-ngrp;
			dp[1-z][ni]=(dp[1-z][ni]+(ll)dp[z][i]*x1%MOD*x2%MOD*x3%MOD*x4)%MOD;
		}
		sum+=cnt; z=1-z;
		//printf("after %d (%d):",a[at],cnt); REPE(i,n) if(dp[z][i]>0) printf(" %d=%d",i,dp[z][i]); puts("");
	}
	printf("%d\n",dp[z][0]);
}

int main() {
	run();
	return 0;
}