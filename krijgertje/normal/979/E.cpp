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

const int MAXN=50;
const int MOD=1000000007;

int n,wantpar;
int fixedcol[MAXN]; // 0==black, 1==white

// dp[bevn][bodd][wevn][wodd] is # ways to color first n=bevn+bodd+wevn+wodd nodes and draw arrows between them such that
// bevn nodes of them are black and have an even number of alternating paths in them (bodd, wevn and wodd are defined similarly)
int dp[MAXN+1][MAXN+1][MAXN+1][MAXN+1];

int p2[MAXN+1];
int C[MAXN+1][MAXN+1];
int fac[MAXN+1];
int wayspar[MAXN+1][2];

void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void run() {
	scanf("%d%d",&n,&wantpar); REP(i,n) scanf("%d",&fixedcol[i]);

	p2[0]=1; FORE(i,1,n) p2[i]=(ll)p2[i-1]*2%MOD;
	REPE(i,n) { C[i][0]=C[i][i]=1; FOR(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD; }
	fac[0]=1; FORE(i,1,n) fac[i]=(ll)fac[i-1]*i%MOD;
	REPE(i,n) REPE(j,i) inc(wayspar[i][j%2],C[i][j]);

	int ret=0;
	memset(dp,0,sizeof(dp)); dp[0][0][0][0]=1;
	REPE(bevn,n) REPE(bodd,n) REPE(wevn,n) REPE(wodd,n) {
		int cways=dp[bevn][bodd][wevn][wodd],ccnt=bevn+bodd+wevn+wodd;
		if(ccnt==n&&(bodd+wodd)%2==wantpar) inc(ret,cways);
		if(cways==0||ccnt>=n) continue;
		REP(ncol,2) {
			if(fixedcol[ccnt]!=-1&&fixedcol[ccnt]!=ncol) continue;
			REP(npar,2) {
				int na=ncol==0?bevn+bodd+wevn:wevn+wodd+bevn,nb=ccnt-na;
				int nways=(ll)cways*p2[na]%MOD*wayspar[nb][1-npar]%MOD;
				inc(dp[bevn+(ncol==0&&npar==0?1:0)][bodd+(ncol==0&&npar==1?1:0)][wevn+(ncol==1&&npar==0?1:0)][wodd+(ncol==1&&npar==1?1:0)],nways);
			}
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}