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

int n,sz;
int a[MAXN];
ll asum[MAXN+1];
ll dp[MAXN+1];

int q[MAXN],qhead,qtail;

void run() {
	scanf("%d%d",&n,&sz); REP(i,n) scanf("%d",&a[i]);
	
	asum[0]=0; REP(i,n) asum[i+1]=asum[i]+a[i];

	dp[0]=0; FORE(i,1,n) dp[i]=LLONG_MAX; qhead=qtail=0;
	REP(i,min(n,sz)) { while(qtail<qhead&&a[i]<=a[q[qhead-1]]) --qhead; q[qhead++]=i; }
	REP(i,n) {
		//printf("dp[%d]=%lld\n",i,dp[i]);
		dp[i+1]=min(dp[i+1],dp[i]+a[i]);
		while(qtail<qhead&&q[qtail]<i) ++qtail;
		if(qtail<qhead&&i+sz<=n) dp[i+sz]=min(dp[i+sz],dp[i]+asum[i+sz]-asum[i]-a[q[qtail]]);
		if(i+sz<n) { while(qtail<qhead&&a[i+sz]<a[q[qhead-1]]) --qhead; q[qhead++]=i+sz; }
	}
	printf("%lld\n",dp[n]);
}

int main() {
	run();
	return 0;
}