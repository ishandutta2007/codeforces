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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXN=100000;
const int MOD=1000000007;

char s[MAXN+1]; int n;

int dp[MAXN+1];

int solve() {
	dp[1]=1; dp[2]=2; FORE(i,3,n) dp[i]=(dp[i-2]+dp[i-1])%MOD;
	int ret=1;
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&s[r]==s[l]) ++r;
		int cnt=r-l;
		if(s[l]=='w'||s[l]=='m') return 0;
		if(s[l]=='u'||s[l]=='n') ret=(ll)ret*dp[cnt]%MOD;
	}
	return ret;
}

void run() {
	scanf("%s",s); n=strlen(s);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}