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

const int MAXLEN=701;
const int MOD=1000000007;
const int INV9=111111112;

char s[MAXLEN+1]; int n;

int ones[MAXLEN+1];

int dp[MAXLEN+1][MAXLEN+1][2]; // dp[i][j][eq] = #ways for there being exactly j numbers >=k among the first i digits

void inc(int &a,ll b) { a=(a+b)%MOD; }
void run() {
	scanf("%s",s); n=strlen(s);
	//n=MAXLEN/2; REP(i,n) s[i]=i==0?'1':'0'; s[n]='\0';
	ones[0]=0; FORE(i,1,n) ones[i]=((ll)10*ones[i-1]+1)%MOD;

	int ret=0;
	FORE(k,1,9) {
		memset(dp,0,sizeof(dp));
		dp[0][0][1]=1;
		REP(i,n) REPE(j,i) {
			inc(dp[i+1][j][0],(ll)k*dp[i][j][0]);
			inc(dp[i+1][j+1][0],(ll)(10-k)*dp[i][j][0]);
			inc(dp[i+1][j][0],(ll)min(k,s[i]-'0')*dp[i][j][1]);
			inc(dp[i+1][j+1][0],(ll)max(0,s[i]-'0'-k)*dp[i][j][1]);
			inc(dp[i+1][j+(s[i]-'0'>=k?1:0)][1],dp[i][j][1]);
		}
		//printf("%d:\n",k); REPE(i,n) { REPE(j,i) printf("(%d,%d)",dp[i][j][0],dp[i][j][1]); puts(""); }
		REPE(j,n) REP(eq,2) inc(ret,(ll)dp[n][j][eq]*ones[j]);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}