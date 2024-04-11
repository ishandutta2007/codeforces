#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
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

const int MAXLEN=200000;

char s[MAXLEN+1]; int slen;

int dp[MAXLEN+1][3];

void upd(int &a,int b) { a=max(a,b); }
void run() {
	scanf("%s",s); slen=strlen(s);
	
	memset(dp,-1,sizeof(dp)); dp[0][0]=0;
	REP(i,slen) REP(j,3) if(dp[i][j]!=-1) {
		int x=(s[i]-'0')%3;
		int nj=(j+x)%3;
		upd(dp[i+1][nj],dp[i][j]);
		upd(dp[i+1][0],dp[i][j]+(nj==0?1:0));
	}
	//REPE(i,slen) REP(j,3) printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
	int ret=0; REP(j,3) upd(ret,dp[slen][0]);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}