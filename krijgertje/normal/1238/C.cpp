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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXN=200000;

int h,n;
int x[MAXN];

int dp[MAXN];

int solve() {
	int ret=INT_MAX;
	REP(i,n) dp[i]=INT_MAX; dp[0]=0;
	REP(i,n) if(dp[i]!=INT_MAX) {
		if(i+1<n) dp[i+1]=min(dp[i+1],dp[i]+1);
		if(i+2<n&&x[i+2]==x[i+1]-1) dp[i+2]=min(dp[i+2],dp[i]);
		if(i+1>=n) ret=min(ret,dp[i]);
		if(i+1<n&&i+2>=n&&x[i+1]==1) ret=min(ret,dp[i]);
	}
	return ret;
}

void run() {
	scanf("%d%d",&h,&n);
	REP(i,n) scanf("%d",&x[i]);
	printf("%d\n",solve());
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}