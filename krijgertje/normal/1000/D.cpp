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

const int MAXN=1000;
const int MOD=998244353;

int n;
int a[MAXN];

int dp[MAXN+1][MAXN+1];

void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	memset(dp,0,sizeof(dp));
	dp[n][0]=1;
	for(int i=n-1;i>=0;--i) REPE(j,n-i) {
		dp[i][j]=dp[i+1][j];
		if(j>0) inc(dp[i][j],dp[i+1][j-1]);
		if(j==0&&a[i]>0&&i+1+a[i]<=n) inc(dp[i][j],dp[i+1][a[i]]);
	}
	printf("%d\n",(dp[0][0]+MOD-1)%MOD);
}

int main() {
	run();
	return 0;
}