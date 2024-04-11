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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MOD=1000000007;
const int MAXN=2000;

int n,want;
int a[MAXN];

int dp[MAXN];

void run() {
	scanf("%d%d",&n,&want); REP(i,n) scanf("%d",&a[i]);
	REP(i,n) if(a[i]>want) { printf("0\n"); return; }

	REP(i,n) dp[i]=0;
	if(a[0]==want||a[0]==want-1) dp[0]=1;
	REP(i,n-1) {
		if(a[i+1]==a[i]-1) dp[i+1]=dp[i];
		if(a[i+1]==a[i]) dp[i+1]=(ll)dp[i]*(want-a[i]+1)%MOD;
		if(a[i+1]==a[i]+1) dp[i+1]=(ll)dp[i]*(want-a[i])%MOD;
	}
	int ret=0;
	if(a[n-1]==want||a[n-1]==want-1) ret=dp[n-1];
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}