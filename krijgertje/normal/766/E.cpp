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

const int MAXN=100000;
const int MAXM=MAXN-1;
const int MAXBIT=19;

int n;
int val[MAXN];
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];

ll dp[MAXN][MAXBIT+1][2]; // dp[i][j][k] = # paths in subtree of i for which the number of times the jth bit is set is k (mod 2)

ll dfs(int at,int par) {
	ll ret=val[at];
	REPE(j,MAXBIT) dp[at][j][(val[at]>>j)&1]++;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		ret+=dfs(to,at);
		REPE(j,MAXBIT) REP(k,2) {
			ll times=dp[at][j][1-k]*dp[to][j][k];
			//if(j==0) printf("\t(%d,%d) with (%d,%d): %lld*%lld\n",at,1-k,to,k,dp[at][j][1-k],dp[to][j][k]);
			ret+=times<<j;
		}
		REPE(j,MAXBIT) REP(k,2) dp[at][j][(k+((val[at]>>j)&1))%2]+=dp[to][j][k];
	}
	//printf("dp[%d][0]: %lld / %lld\n",at+1,dp[at][0][0],dp[at][0][1]);
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&val[i]);
	REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}

	memset(dp,0,sizeof(dp));
	ll ret=dfs(0,-1);
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}