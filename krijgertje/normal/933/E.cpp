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

const int MAXN=300000;

int n;
int a[MAXN];
ll dp[MAXN]; // dp[i] is mincost to have no two consecutive positive integers in [0..i] in which the last element is allowed be positive
int act[MAXN];

bool canpos[MAXN];
int b[MAXN];
int ret[MAXN-1],nret;



void solve() {
	nret=0;
	if(n==1) return;
	REP(i,n) dp[i]=LLONG_MAX,act[i]=-1; dp[0]=0,act[0]=0; dp[1]=a[0],act[1]=1;
	REP(i,n) {
		//printf("%d: %lld\n",i,dp[i]);
		if(i+2<n) { ll val=dp[i]+a[i+1]; if(val<dp[i+2]) dp[i+2]=val,act[i+2]=1; }
		if(i+3<n) { ll val=dp[i]+max(a[i+1],a[i+2]); if(val<dp[i+3]) dp[i+3]=val,act[i+3]=2; }
	}
	int lst=n-1; ll cost=dp[n-1]; if(dp[n-2]+a[n-1]<cost) lst=n-2,cost=dp[n-2]+a[n-1];
	//printf("cost=%lld\n",cost);
	REP(i,n) canpos[i]=false; for(int i=lst;i>=0;i-=act[i]+1) canpos[i]=true;
	//printf("canpos:"); REP(i,n) printf("%c",canpos[i]?'*':'0'); puts("");
	REP(i,n) b[i]=a[i];
	REP(i,n) if(!canpos[i]&&b[i]>0) {
		if(i+1<n&&!canpos[i+1]&&b[i+1]>0) {
			ret[nret++]=i;
			int cur=min(b[i],b[i+1]); b[i]-=cur; b[i+1]-=cur;
			if(b[i]>0&&i-1>=0&&b[i-1]>0) { ret[nret++]=i-1; int oth=min(b[i-1],b[i]); b[i-1]-=oth; b[i]-=oth; }
			if(b[i+1]>0&&i+2<n&&b[i+2]>0) { ret[nret++]=i+1; int oth=min(b[i+1],b[i+2]); b[i+1]-=oth; b[i+2]-=oth; }
		} else {
			if(b[i]>0&&i-1>=0&&b[i-1]>0) { ret[nret++]=i-1; int oth=min(b[i-1],b[i]); b[i-1]-=oth; b[i]-=oth; }
			if(b[i]>0&&i+1<n&&b[i+1]>0) { ret[nret++]=i; int oth=min(b[i],b[i+1]); b[i]-=oth; b[i+1]-=oth; }
		}
	}
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	solve();
	printf("%d\n",nret); REP(i,nret) printf("%d\n",ret[i]+1);
}

int main() {
	run();
	return 0;
}