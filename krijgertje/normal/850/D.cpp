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

const int MAXM=31;
const int MAXN=61;
const int MAXSUM=1830;

int m;
int a[MAXM];

int dp[MAXSUM+1][MAXM][MAXN+1];
int nxt[MAXSUM+1][MAXM][MAXN+1];

int n;
int want[MAXN];

int have[MAXN];
int g[MAXN][MAXN];

void run() {
	scanf("%d",&m); REP(i,m) scanf("%d",&a[i]); sort(a,a+m);
	memset(dp,-1,sizeof(dp));
	for(int sum=MAXSUM;sum>=0;--sum) REP(i,m) REPE(j,MAXN) {
		if(sum<j*(j-1)/2) continue;
		if(i==m-1&&sum==j*(j-1)/2) { dp[sum][i][j]=j; nxt[sum][i][j]=-1; continue; }
		if(sum+a[i]<=MAXSUM&&j+1<=MAXN&&dp[sum+a[i]][i][j+1]!=-1&&(dp[sum][i][j]==-1||dp[sum+a[i]][i][j+1]<=dp[sum][i][j])) { dp[sum][i][j]=dp[sum+a[i]][i][j+1]; nxt[sum][i][j]=i; }
		if(i+1<m&&sum+a[i+1]<=MAXSUM&&j+1<=MAXN&&dp[sum+a[i+1]][i+1][j+1]!=-1&&(dp[sum][i][j]==-1||dp[sum+a[i+1]][i+1][j+1]<=dp[sum][i][j])) { dp[sum][i][j]=dp[sum+a[i+1]][i+1][j+1]; nxt[sum][i][j]=i+1; }
	}
	//printf("n=%d\n",dp[a[0]][0][1]);
	
	if(dp[a[0]][0][1]==-1) { printf("=(\n"); return; }
	{ n=0; want[n++]=a[0]; int sum=a[0],i=0,j=1; while(nxt[sum][i][j]!=-1) { int cur=nxt[sum][i][j]; want[n++]=a[cur]; sum+=a[cur],i=max(i,cur),++j; } }
	sort(want,want+n);
	//printf("want:"); REP(i,n) printf(" %d",want[i]); puts("");

	REP(i,n) have[i]=i; REP(i,n) REP(j,n) g[i][j]=i>j?1:0;
	while(true) {
		int p=0; while(p<n&&have[p]==want[p]) ++p; if(p>=n) break; assert(have[p]<want[p]);
		while(p+1<n&&have[p+1]==have[p]) ++p;
		int q=p+1; while(q<n&&have[q]<=want[q]) ++q; assert(q<n);
		int r=-1; REP(i,n) if(i!=p&&i!=q&&g[q][i]&&g[i][p]) { r=i; break; } assert(r!=-1);
		g[q][r]=g[r][p]=0,g[p][r]=g[r][q]=1,++have[p],--have[q];
	}
	printf("%d\n",n); REP(i,n) { REP(j,n) printf("%d",g[i][j]); puts(""); }
}

int main() {
	//for(int n=1;;++n) { int a=n*30,b=n*(n-1)/2; printf("%d: %d vs %d\n",n,a,b); if(a<b) break; }
	run();
	return 0;
}