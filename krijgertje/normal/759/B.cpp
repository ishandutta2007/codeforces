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
const int C1=20;
const int C90m=50;
const int C1440m=120;

int n;
int t[MAXN];

int dp[MAXN+1]; // dp[i]=minimum cost to visit [0..i)


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&t[i]);
	dp[0]=0;
	int at90m=0,at1440m=0;
	REP(i,n) {
		dp[i+1]=dp[i]+C1;
		while(t[i]-t[at90m]>=90) ++at90m; dp[i+1]=min(dp[i+1],dp[at90m]+C90m);
		while(t[i]-t[at1440m]>=1440) ++at1440m; dp[i+1]=min(dp[i+1],dp[at1440m]+C1440m);
		printf("%d\n",dp[i+1]-dp[i]);
	}
}

int main() {
	run();
	return 0;
}