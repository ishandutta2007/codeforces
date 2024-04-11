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

const int MAXN=1000000;
const int MOD=1000000007;

int n;
char s[MAXN+1];

int dp[MAXN+1];

void run() {
	scanf("%s",s); n=strlen(s);

	dp[0]=0; FORE(i,1,n) dp[i]=(1+(ll)2*dp[i-1])%MOD;
	int na=0;
	int ret=0;
	REP(i,n) {
		if(s[i]=='a') { ++na; continue; }
		if(s[i]=='b') ret=(ret+dp[na])%MOD;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}