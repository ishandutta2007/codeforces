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

const int MAXN=5000;
const int MOD=1000000007;

int n;
char s[MAXN];

int dp[MAXN+1][MAXN+1];
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

void run() {
	scanf("%d",&n); REP(i,n) scanf(" %c",&s[i]);
	
	memset(dp,0,sizeof(dp)); dp[0][0]=1;
	REP(i,n) {
		if(s[i]=='f') {
			REPE(j,n) if(dp[i][j]!=0) inc(dp[i+1][j+1],dp[i][j]);
		}
		if(s[i]=='s') {
			int sum=0;
			for(int j=n;j>=0;--j) {
				inc(sum,dp[i][j]);
				inc(dp[i+1][j],sum);
			}
		}
	}
	printf("%d\n",dp[n][0]);
}

int main() {
	run();
	return 0;
}