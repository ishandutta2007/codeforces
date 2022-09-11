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

const int MAXN=100;
const int MOD=1000000007;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void sub(int &a,int b) { if((a-=b)<0) a+=MOD; }

int n;
vector<int> adj[MAXN];

int npw[MAXN+1];
int C[MAXN+1][MAXN+1];

int sz[MAXN];
int dp[MAXN][MAXN][MAXN+1]; // dp[i][j][k] = sum of prod(csz) over all choices of j edges from subtree of i such that the root component has size k (and is not included in product)
int cnt[MAXN]; // cnt[i] = sum of n^(ncomp-2)*prod(csz) when chosing i edges
int ans[MAXN];

void dfs(int at,int par) {
	sz[at]=1;
	dp[at][0][1]=1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		dfs(to,at);
		for(int j=sz[at]-1;j>=0;--j) for(int k=sz[at];k>=1;--k) if(dp[at][j][k]!=0) {
			int ways=dp[at][j][k]; dp[at][j][k]=0;
			REP(jj,sz[to]) FORE(kk,1,sz[to]) if(dp[to][jj][kk]!=0) {
				int nways=(ll)ways*dp[to][jj][kk]%MOD;
				// do not take edge
				inc(dp[at][j+jj][k],(ll)nways*kk%MOD);
				// take edge
				inc(dp[at][j+jj+1][k+kk],nways);
			}
		}
		sz[at]+=sz[to];
	}
}


void run() {
	scanf("%d",&n);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }

	memset(dp,0,sizeof(dp));
	dfs(0,-1);

	memset(cnt,0,sizeof(cnt));
	npw[0]=1; FORE(i,1,n) npw[i]=(ll)npw[i-1]*n%MOD;
	REP(j,n) FORE(k,1,n) if(dp[0][j][k]!=0) {
		int prod=(ll)dp[0][j][k]*k%MOD,ncomp=n-j;
		if(ncomp==1) inc(cnt[j],1); else inc(cnt[j],(ll)prod*npw[ncomp-2]%MOD);
	}
	//printf("cnt:"); REP(i,n) printf(" %d",cnt[i]); puts("");

	memset(ans,0,sizeof(ans));
	REPE(i,n) { C[i][0]=C[i][i]=1; FOR(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD; }
	REP(i,n) FOR(j,i,n) {
		int sgn=(j-i)%2==0?+1:-1;
		int val=(ll)cnt[j]*C[j][i]%MOD;
		if(sgn==+1) inc(ans[i],val); else sub(ans[i],val);
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}