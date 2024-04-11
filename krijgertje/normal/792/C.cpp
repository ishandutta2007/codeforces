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

const int MAXLEN=100000;

char s[MAXLEN+1]; int slen;

int dp[MAXLEN+1][3][2]; // dp[i][j][k]=maximum length substring in [i..n) with modulo j and with leading zero iff k=1
bool use[MAXLEN][3][2]; // whether to use s[i] for dp[i][j][k]

char ret[MAXLEN+1]; int retlen;

void run() {
	scanf("%s",s); slen=strlen(s);
	memset(dp,-1,sizeof(dp));

	dp[slen][0][0]=0;
	for(int i=slen-1;i>=0;--i) {
		int x=(s[i]-'0')%3;
		REP(j,3) REP(k,2) dp[i][j][k]=dp[i+1][j][k],use[i][j][k]=false;
		{ int k=s[i]=='0'; REP(j,3) { int jj=(j-x+3)%3; REP(kk,2) if(dp[i+1][jj][kk]!=-1&&dp[i+1][jj][kk]+1>dp[i][j][k]) dp[i][j][k]=dp[i+1][jj][kk]+1,use[i][j][k]=true; } }
	}

	retlen=0;
	if(dp[0][0][0]>=1) {
		int i=0,j=0,k=0;
		while(i<slen) {
			//printf("%d %d %d\n",i,j,k);
			if(!use[i][j][k]) { ++i; continue; }
			int x=(s[i]-'0')%3; int jj=(j-x+3)%3,kk=-1; REP(kkk,2) if(dp[i+1][jj][kkk]!=-1&&dp[i][j][k]==dp[i+1][jj][kkk]+1) kk=kkk; assert(kk!=-1);
			ret[retlen++]=s[i]; ++i,j=jj,k=kk;
		}
		ret[retlen]='\0';
	} else {
		sprintf(ret,"-1");
		REP(i,slen) if(s[i]=='0') { sprintf(ret,"0"); break; }
	}
	printf("%s\n",ret);
}

int main() {
	run();
	return 0;
}