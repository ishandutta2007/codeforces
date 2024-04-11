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

const int MOD=1000000007;
const int MAXLEN=100000;
const int MAXDIFF=2000;

int have,want,diff;
char s[MAXLEN+1];

int dp[MAXDIFF+1][MAXDIFF+1]; // dp[i][j]=#strings of length i with j opened brackets

void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void run() {
	scanf("%d%d%s",&want,&have,s); diff=want-have;
	int needopen=0,needclose=0;
	REP(i,have) {
		if(s[i]=='(') ++needclose;
		if(s[i]==')') if(needclose>0) --needclose; else ++needopen;
	}

	memset(dp,0,sizeof(dp)); dp[0][0]=1;
	REP(i,diff) REPE(j,i) if(dp[i][j]) {
		inc(dp[i+1][j+1],dp[i][j]);
		if(j>0) inc(dp[i+1][j-1],dp[i][j]);
	}

	int ret=0;
	REPE(a,diff) {
		int b=diff-a;
		FORE(nopen,needopen,a) {
			int nclose=nopen-needopen+needclose; if(nclose>b) continue;
			int cur=(ll)dp[a][nopen]*dp[b][nclose]%MOD;
			inc(ret,cur);
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}