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

int dp[2001][2001]; // dp[i][j] = # of 'non-increasing' caves height at most i and width j

void run(int casenr) {
	int h,w; scanf("%d%d",&h,&w);
	
	memset(dp,0,sizeof(dp));
	FORE(i,1,h) {
		ll sum=0;
		FORE(j,2,w) {
			sum+=dp[i-1][j]; if(sum>=MOD) sum-=MOD;
			dp[i][j]+=dp[i][j-1]; if(dp[i][j]>=MOD) dp[i][j]-=MOD;
			dp[i][j]+=sum; if(dp[i][j]>=MOD) dp[i][j]-=MOD;
		}
		FORE(j,2,w) {
			++dp[i][j]; if(dp[i][j]>=MOD) dp[i][j]-=MOD;
		}
	}
	
	ll ret=0;
	REP(ii,h) FORE(j,2,w) { // ii=first row with maximum width
		ll cur=w-j+1;
		if(ii!=0) {
			ll tmp=dp[ii+1][j]-dp[ii][j]; if(tmp<0) tmp+=MOD;
			cur=cur*tmp%MOD;
		}
		cur=cur*dp[h-ii][j]%MOD;
		ret+=cur; if(ret>=MOD) ret-=MOD;
	}
	cout<<ret<<endl;
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}