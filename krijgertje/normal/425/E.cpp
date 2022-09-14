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

const int MOD=1000000007;

int n,want;

ll p[250001];
ll dp[501][501];

void run() {
	scanf("%d%d",&n,&want);
	p[0]=1; FORE(i,1,n*n) p[i]=p[i-1]*2%MOD;
	memset(dp,0,sizeof(dp));
	REPE(j,n) dp[0][j]=1;
	FORE(i,1,want) FORE(j,1,n) {
		ll cur=0;
		REP(k,j) if(dp[i-1][j-k-1]!=0) {
			ll times=p[(k+1)*(j-k)]-p[(k+1)*(j-k-1)]; if(times<0) times+=MOD;
			cur+=times*dp[i-1][j-k-1];
			if(cur>=8000000000000000000LL) cur%=MOD;
		}
		dp[i][j]=cur%MOD;
	}
	cout<<dp[want][n]<<endl;
}

int main() {
	run();
	return 0;
}