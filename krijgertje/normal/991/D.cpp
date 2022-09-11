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

const int MAXN=100;

int n;
char s[2][MAXN+1];

int dp[MAXN+1][4]; // dp[i][mask] = max chesswocks using the first i columns where mask indicates free spaces in last column

void upd(int &a,int b) { if(b>a) a=b; }
void run() {
	scanf("%s%s",s[0],s[1]); n=strlen(s[0]); assert(strlen(s[1])==n);

	REPE(i,n) REP(mask,4) dp[i][mask]=INT_MIN; dp[0][0]=0;
	REP(i,n) REP(mask,4) if(dp[i][mask]!=INT_MIN) {
		int nmask=(s[0][i]=='0'?1:0)+(s[1][i]=='0'?2:0);
		upd(dp[i+1][nmask],dp[i][mask]);
		if((nmask&3)==3&&(mask&1)==1) upd(dp[i+1][nmask^3],dp[i][mask]+1);
		if((nmask&3)==3&&(mask&2)==2) upd(dp[i+1][nmask^3],dp[i][mask]+1);
		if((mask&3)==3&&(nmask&1)==1) upd(dp[i+1][nmask^1],dp[i][mask]+1);
		if((mask&3)==3&&(nmask&2)==2) upd(dp[i+1][nmask^2],dp[i][mask]+1);
	}
	int ret=INT_MIN; REP(mask,4) upd(ret,dp[n][mask]); printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}