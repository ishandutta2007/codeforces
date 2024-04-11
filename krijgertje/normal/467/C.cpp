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
typedef long double ld;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int n,len,need;
int x[5000];
ll xsum[5001];
ll dp[5001];

void run() {
	scanf("%d%d%d",&n,&len,&need);
	REP(i,n) scanf("%d",&x[i]);
	xsum[0]=0; REP(i,n) xsum[i+1]=xsum[i]+x[i];
	REPE(j,n) dp[j]=0;
	REP(i,need) {
		for(int j=n;j>=0;--j) if(j<len||dp[j-len]==-1) dp[j]=-1; else dp[j]=dp[j-len]+xsum[j]-xsum[j-len];
		FORE(j,1,n) if(dp[j-1]!=-1&&(dp[j]==-1||dp[j-1]>dp[j])) dp[j]=dp[j-1];
	}
	cout<<dp[n]<<endl;
}

int main() {
	run();
	return 0;
}