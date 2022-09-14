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

const int MOD=1000000007;

int n;
char s[1000003];
int dp[1000001][2]; //0:NN,1:Y?

void run() {
	gets(s); n=strlen(s);
	memset(dp,0,sizeof(dp));
	if(s[0]=='0'||s[0]=='?') ++dp[1][0];
	if((s[0]=='1'||s[0]=='?')&&1<n&&(s[1]=='*'||s[1]=='?')) ++dp[2][1];
	if(s[0]=='*'||s[0]=='?') ++dp[1][1];
	FOR(i,1,n) REP(j,2) if(dp[i][j]!=0) {
#define INC(x) { x+=dp[i][j]; if(x>=MOD) x-=MOD; }
		if((s[i]=='0'||s[i]=='?')&&j==0) INC(dp[i+1][0]);
		if((s[i]=='1'||s[i]=='?')&&j==0&&i+1<n&&(s[i+1]=='*'||s[i+1]=='?')) INC(dp[i+2][1]);
		if((s[i]=='1'||s[i]=='?')&&j==1) INC(dp[i+1][0]);
		if((s[i]=='2'||s[i]=='?')&&j==1&&i+1<n&&(s[i+1]=='*'||s[i+1]=='?')) INC(dp[i+2][1]);
		if((s[i]=='*'||s[i]=='?')&&j==1) INC(dp[i+1][1]);
	}
	printf("%d\n",(dp[n][0]+dp[n][1])%MOD);
}

int main() {
	run();
	return 0;
}