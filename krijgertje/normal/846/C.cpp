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

int n;
int a[MAXN];
ll sum[MAXN+1];

ll dp[4][MAXN+1];
int act[4][MAXN+1];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]); sum[0]=0; REP(i,n) sum[i+1]=sum[i]+a[i];
	
	REPE(i,n) dp[3][i]=-(sum[n]-sum[i]),act[3][i]=-1;
	REPE(i,n) { dp[2][i]=LLONG_MIN,act[2][i]=-1; FORE(j,i,n) { ll cur=+(sum[j]-sum[i])+dp[3][j]; if(cur>dp[2][i]) dp[2][i]=cur,act[2][i]=j; } }
	REPE(i,n) { dp[1][i]=LLONG_MIN,act[1][i]=-1; FORE(j,i,n) { ll cur=-(sum[j]-sum[i])+dp[2][j]; if(cur>dp[1][i]) dp[1][i]=cur,act[1][i]=j; } }
	REPE(i,n) { dp[0][i]=LLONG_MIN,act[0][i]=-1; FORE(j,i,n) { ll cur=+(sum[j]-sum[i])+dp[1][j]; if(cur>dp[0][i]) dp[0][i]=cur,act[0][i]=j; } }
	//printf("%lld\n",dp[0][0]);
	int a=act[0][0],b=act[1][a],c=act[2][b];
	printf("%d %d %d\n",a,b,c);
}

int main() {
	run();
	return 0;
}