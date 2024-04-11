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

const int MAXN=50;

int n,nshelf;
ll a[MAXN];
ll asum[MAXN+1];

bool dp[MAXN+1][MAXN+1];

bool can(ll want) {
	memset(dp,false,sizeof(dp)); dp[0][0]=true;
	REP(i,n) REP(j,nshelf) if(dp[i][j]) FORE(ii,i+1,n) {
		ll cur=asum[ii]-asum[i];
		if((cur&want)==want) dp[ii][j+1]=true;
	}
	return dp[n][nshelf];
}

ll solve() {
	asum[0]=0; REP(i,n) asum[i+1]=asum[i]+a[i];
	ll ret=0;
	for(int bit=60;bit>=0;--bit) {
		ll cur=ret|(1LL<<bit);
		if(can(cur)) ret=cur;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&nshelf); REP(i,n) scanf("%lld",&a[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}