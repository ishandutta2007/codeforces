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

const int MAXLEN=1000;
const int MAXWANT=10;

int alen,blen,want;
char a[MAXLEN+1],b[MAXLEN+1];

int match[MAXLEN+1][MAXLEN+1];
int dp[MAXLEN+1][MAXLEN+1][MAXWANT+1];

void run() {
	scanf("%d%d%d%s%s",&alen,&blen,&want,a,b);
	for(int i=alen;i>=0;--i) for(int j=blen;j>=0;--j) {
		match[i][j]=0;
		if(i<alen&&j<blen&&a[i]==b[j]) match[i][j]=1+match[i+1][j+1];
	}
	memset(dp,0,sizeof(dp));
	int ret=0;
	REPE(k,want) REPE(i,alen) REPE(j,blen) {
		int z=match[i][j],nval=dp[i][j][k]+z;
		if(dp[i][j][k]>ret) ret=dp[i][j][k];
		if(k<want&&nval>dp[i+z][j+z][k+1]) dp[i+z][j+z][k+1]=nval;
		if(i<alen&&dp[i][j][k]>dp[i+1][j][k]) dp[i+1][j][k]=dp[i][j][k];
		if(j<blen&&dp[i][j][k]>dp[i][j+1][k]) dp[i][j+1][k]=dp[i][j][k];
		//printf("%d %d %d = %d\n",i,j,k,dp[i][j][k]);
	}
	printf("%d\n",ret);
}
//13 9 1 oaflomxegekyv bgwwqizfo
int main() {
	run();
	return 0;
}