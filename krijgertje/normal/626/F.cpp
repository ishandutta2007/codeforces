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

const int MAXN=200;
const int MAXK=1000;
const int MOD=1000000007;

int n,kmax;
int x[MAXN];
int dp[2][MAXN+1][MAXK+1]; // dp[i%2][j][k] is the number of ways to divide students [0..i) into groups, such that there are j 'open' and if all would close at x[i-1] the total imbalance is k

void inc(int &a,int times,int b) { a=(a+(ll)times*b)%MOD; }

void run() {
	scanf("%d%d",&n,&kmax); REP(i,n) scanf("%d",&x[i]); sort(x,x+n);
	
	int at=0; memset(dp,0,sizeof(dp)); dp[at][0][0]=1;
	REP(i,n) {
		int dx=i==0?0:x[i]-x[i-1];
		memset(dp[1-at],0,sizeof(dp[1-at]));
		REPE(j,i) REPE(k,kmax-j*dx) if(dp[at][j][k]!=0) {
			inc(dp[1-at][j+1][k+j*dx],1,dp[at][j][k]);
			inc(dp[1-at][j][k+j*dx],j+1,dp[at][j][k]);
			if(j>0) inc(dp[1-at][j-1][k+j*dx],j,dp[at][j][k]);
		}
		at=1-at;
	}
	int ret=0; REPE(k,kmax) inc(ret,1,dp[at][0][k]);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}