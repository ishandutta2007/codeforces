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

const int MOD=1000000007;
const int MAXN=100000;
const int MAXM=MAXN-1;
int add(int a,int b) { int ret=a+b; if(ret>=MOD) ret-=MOD; return ret; }
int mlt(int a,int b) { return (ll)a*b%MOD; }

int n;
int par[MAXN];
int fst[MAXN],nxt[MAXM],to[MAXM];
int col[MAXN];

int dp[MAXN][2]; // dp[i][j] = # ways for subtree of i (i is connected to black node iff j==1)

void run() {
	scanf("%d",&n);
	par[0]=-1; FOR(i,1,n) scanf("%d",&par[i]);
	REP(i,n) fst[i]=-1; REP(i,n-1) { int a=par[i+1],b=i+1; nxt[i]=fst[a]; fst[a]=i; to[i]=b; }
	REP(i,n) scanf("%d",&col[i]);

	for(int i=n-1;i>=0;--i) {
		dp[i][0]=col[i]==0?1:0; dp[i][1]=col[i]==1?1:0;
		for(int x=fst[i];x!=-1;x=nxt[x]) {
			int j=to[x];
			int nj01=add(dp[j][0],dp[j][1]);
			int i0=mlt(dp[i][0],nj01);
			int i1=add(mlt(dp[i][0],dp[j][1]),mlt(dp[i][1],nj01));
			dp[i][0]=i0,dp[i][1]=i1;
		}
	}
	printf("%d\n",dp[0][1]);
}

int main() {
	run();
	return 0;
}