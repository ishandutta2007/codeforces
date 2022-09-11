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
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int n,k;
int a[MAXN];

int ways[MAXN+1]; // ways[i] = factor to add when missing i bits
int dp[MAXN+1][MAXN+1]; // dp[i][j] = sum of all products of j-tuples out of first i items

void run() {
	scanf("%d%d",&n,&k); REP(i,n) scanf("%d",&a[i]);

	int minonedivn=(MOD-pw(n,MOD-2))%MOD,now=1;
	REPE(need,n) {
		ways[need]=now;
		now=(ll)now*(k+MOD-need)%MOD*minonedivn%MOD;
	}
	memset(dp,0,sizeof(dp)); dp[0][0]=1;
	REP(i,n) REPE(j,i) {
		dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
		dp[i+1][j+1]=(dp[i+1][j+1]+(ll)a[i]*dp[i][j])%MOD;
	}

	int before=1; REP(i,n) before=(ll)before*a[i]%MOD;
	int after=0; REPE(i,n) after=(after+(ll)dp[n][i]*ways[n-i])%MOD;
	int ret=(MOD+before-after)%MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}