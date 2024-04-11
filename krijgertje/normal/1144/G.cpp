#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;

int n;
int a[MAXN];
int ans[MAXN];

int dp[2][MAXN]; // dp[kind][idx] = best extremum value of other sequence, assuming last value is increasing if kind==0 or decreasing otherwise
int act[2][MAXN]; // 0 if previous was inc, 1 if previous was dec

void upd(int kind,int idx,int val,int pkind) {
	if(kind==0) {
		if(val>dp[kind][idx]) dp[kind][idx]=val,act[kind][idx]=pkind;
	} else {
		if(val<dp[kind][idx]) dp[kind][idx]=val,act[kind][idx]=pkind;
	}
}

bool solve() {
	REP(kind,2) REP(i,n) dp[kind][i]=kind==0?INT_MIN:INT_MAX;
	dp[0][0]=INT_MAX; dp[1][0]=INT_MIN;

	FOR(i,1,n) REP(kind,2) REP(pkind,2) {
		if(kind==pkind) {
			if(kind==0&&a[i]<=a[i-1]) continue;
			if(kind==1&&a[i]>=a[i-1]) continue;
			upd(kind,i,dp[pkind][i-1],pkind);
		} else {
			if(kind==0&&a[i]<=dp[pkind][i-1]) continue;
			if(kind==1&&a[i]>=dp[pkind][i-1]) continue;
			upd(kind,i,a[i-1],pkind);
		}
	}
	//REP(i,n) printf("%d / %d\n",dp[0][i],dp[1][i]);
	{
		int kind=-1,idx=n-1;
		if(kind==-1&&dp[0][idx]!=INT_MIN) kind=0;
		if(kind==-1&&dp[1][idx]!=INT_MAX) kind=1;
		if(kind==-1) return false;
		while(idx>=0) {
			ans[idx]=kind;
			kind=act[kind][idx];
			--idx;
		}
	}
	return true;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}