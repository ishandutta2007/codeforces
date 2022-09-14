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

int n,s,e;
int x[MAXN],a[MAXN],b[MAXN],c[MAXN],d[MAXN];

ll dp[MAXN][MAXN]; // dp[i][j] = minimum cost for positions <=i when there are j paths flying right from i (and the appropriate number of paths left to i)

void run() {
	scanf("%d%d%d",&n,&s,&e); --s,--e;
	REP(i,n) scanf("%d",&x[i]); REP(i,n) scanf("%d",&a[i]); REP(i,n) scanf("%d",&b[i]); REP(i,n) scanf("%d",&c[i]); REP(i,n) scanf("%d",&d[i]);
	//if(s>e) { swap(s,e); REP(i,n) swap(b[i],d[i]),swap(a[i],c[i]); }

	memset(dp,-1,sizeof(dp));
	if(s==0) dp[0][1]=d[0]; else if(e==0) dp[0][0]=b[0]; else dp[0][1]=b[0]+d[0];
	REP(i,n-1) REP(j,n) if(dp[i][j]!=-1) {
		int k=j-(e>i?1:0)+(s>i?1:0);
		if(i+1!=s&&i+1!=e) REP(inlft,2) REP(outlft,2) {
			if(j==0&&inlft||k==0&&outlft) continue;
			int nj=j-inlft+(1-outlft),nk=k-outlft+(1-inlft);
			if(i+1!=n-1&&nj+nk==0) continue;
			ll cur=dp[i][j]+(inlft?a[i+1]:b[i+1])+(outlft?c[i+1]:d[i+1])+(ll)(j+k)*(x[i+1]-x[i]);
			if(dp[i+1][nj]==-1||cur<dp[i+1][nj]) dp[i+1][nj]=cur;
		}
		if(i+1==s) REP(outlft,2) {
			if(k==0) continue;
			int nj=j+(1-outlft),nk=k-outlft;
			if(i+1!=n-1&&nj+nk==0) continue;
			ll cur=dp[i][j]+(outlft?c[i+1]:d[i+1])+(ll)(j+k)*(x[i+1]-x[i]);
			if(dp[i+1][nj]==-1||cur<dp[i+1][nj]) dp[i+1][nj]=cur;
		}
		if(i+1==e) REP(inlft,2) {
			if(j==0) continue;
			int nj=j-inlft,nk=k+(1-inlft);
			if(i+1!=n-1&&nj+nk==0) continue;
			ll cur=dp[i][j]+(inlft?a[i+1]:b[i+1])+(ll)(j+k)*(x[i+1]-x[i]);
			if(dp[i+1][nj]==-1||cur<dp[i+1][nj]) dp[i+1][nj]=cur;
		}
	}
	printf("%lld\n",dp[n-1][0]);
}

int main() {
	run();
	return 0;
}