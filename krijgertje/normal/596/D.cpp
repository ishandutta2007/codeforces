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

const int MAXN=2000;

int n,h; double plft;
int x[MAXN];
int fst[MAXN],lst[MAXN];

double dp[MAXN][MAXN][2][2]; // dp[a][b][lft][rgt] is the expected extra area covered by trees a..b when the tree left of a and the tree right of b fall inside iff lft/rgt==1


void run() {
	scanf("%d%d%lf",&n,&h,&plft); REP(i,n) scanf("%d",&x[i]); sort(x,x+n);
	REP(i,n) if(i==0||x[i]-x[i-1]>=h) fst[i]=i; else fst[i]=fst[i-1];
	for(int i=n-1;i>=0;--i) if(i==n-1||x[i+1]-x[i]>=h) lst[i]=i; else lst[i]=lst[i+1];

	memset(dp,0,sizeof(dp));
	FOR(d,0,n) REP(a,n-d) REP(lft,2) REP(rgt,2) REP(side,2) REP(dir,2) {
		int b=a+d,c=side==0?a:b,cc=max(a,min(b,dir==0?fst[c]:lst[c]));
		int cur=abs(x[c]-x[cc])+(cc==0&&dir==0||cc==n-1&&dir==1?h:max(0,min(h,abs(x[cc]-x[cc+(dir==0?-1:+1)])-(cc==a&&dir==0&&lft||cc==b&&dir==1&&rgt?h:0))));
		double nxt=side==0&&cc==b||side==1&&cc==a?0:dp[side==0?cc+1:a][side==1?cc-1:b][side==0?dir:lft][side==1?1-dir:rgt];
		double pdir=dir==0?plft:1-plft;
		dp[a][b][lft][rgt]+=.5*pdir*(cur+nxt);
		//printf("\t%d..%d [%d,%d] {%d,%d} -> += 1/2*%lf*(%d+%lf) <%d>\n",a,b,lft,rgt,side,dir,pdir,cur,nxt,cc);
	}
	//FOR(d,0,n) REP(a,n-d) REP(lft,2) REP(rgt,2) printf("%d..%d [%d,%d] = %lf\n",a,a+d,lft,rgt,dp[a][a+d][lft][rgt]);
	printf("%.9lf\n",dp[0][n-1][0][0]);
}

int main() {
	run();
	return 0;
}