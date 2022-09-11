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

const int MAXK=400;
const int MOD=1000000007;

int C[MAXK+1][MAXK+1];
int dp[MAXK+1][MAXK+1]; // dp[k][i] = #ways to make i paths in a tree of depth k

int K;
void inc(int &x,ll by) { /*printf("%lld\n",by);*/ x=(x+by)%MOD; }


void run() {
	scanf("%d",&K);
	memset(C,0,sizeof(C)); REPE(i,K) { C[i][0]=C[i][i]=1; FOR(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD; }
	memset(dp,0,sizeof(dp));
	dp[1][0]=1; dp[1][1]=1;
	FORE(k,2,K) {
		int mx=K-k+1; dp[k][0]=1;
		FORE(i,1,mx) {
			//printf("k=%d i=%d\n",k,i);
			// do not use root
			REPE(ii,i) inc(dp[k][i],(ll)dp[k-1][ii]*dp[k-1][i-ii]%MOD*C[i][ii]);
			// single root
			REPE(ii,i-1) inc(dp[k][i],(ll)dp[k-1][ii]*dp[k-1][i-ii-1]%MOD*C[i-1][ii]%MOD*(i));
			// use root on end of one side
			REPE(ii,i) inc(dp[k][i],(ll)dp[k-1][ii]*dp[k-1][i-ii]%MOD*C[i][ii]%MOD*(i*2));
			// use root in the middle
			REPE(ii,i+1) inc(dp[k][i],(ll)dp[k-1][ii]*dp[k-1][i-ii+1]%MOD*C[i+1][ii]%MOD*(i));
		}
	}
	printf("%d\n",dp[K][1]);
}

int main() {
	run();
	return 0;
}