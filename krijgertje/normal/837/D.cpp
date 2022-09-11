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

const int MAXN=200;
const int MAXA=59;
const int MAXB=25;

int n,cnt;
ll x[MAXN];
int a[MAXN],b[MAXN];

int dp[MAXN+1][MAXN*MAXB+1];




void run() {
	scanf("%d%d",&n,&cnt); REP(i,n) scanf("%lld",&x[i]);
	REP(i,n) { ll z=x[i]; a[i]=0; while(z%2==0) ++a[i],z/=2; b[i]=0; while(z%5==0) ++b[i],z/=5; }

	memset(dp,-1,sizeof(dp)); dp[0][0]=0; int bmx=0;
	REP(i,n) {
		for(int j=i;j>=0;--j) REPE(k,bmx) if(dp[j][k]!=-1) {
			int jj=j+1,kk=k+b[i],nval=dp[j][k]+a[i];
			if(dp[jj][kk]==-1||nval>dp[jj][kk]) dp[jj][kk]=nval;
		}
		bmx+=b[i];
	}
	int ret=0; REPE(j,bmx) { int cur=min(j,dp[cnt][j]); if(cur>ret) ret=cur; } printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}