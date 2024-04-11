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

char s[MAXN+1]; int n;

int dp[MAXN+1][3];

void run() {
	scanf("%s",s); n=strlen(s);
	memset(dp,0,sizeof(dp));
	REPE(i,n) REP(j,3) {
		if(i>0) dp[i][j]=max(dp[i][j],dp[i-1][j]);
		if(j>0) dp[i][j]=max(dp[i][j],dp[i][j-1]);
		if(i<n&&s[i]=="aba"[j]) dp[i+1][j]=max(dp[i+1][j],dp[i][j]+1);
	}
	printf("%d\n",dp[n][2]);
}

int main() {
	run();
	return 0;
}