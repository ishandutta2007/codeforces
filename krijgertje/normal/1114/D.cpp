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
#include <bitset>
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

const int MAXN=5000;

int a[MAXN],na;

int b[MAXN],nb;
int dp[MAXN][MAXN];

int solve() {
	nb=0; for(int l=0,r=l;l<na;l=r) { while(r<na&&a[l]==a[r]) ++r; b[nb++]=a[l]; }
	//printf("b:"); REP(i,nb) printf(" %d",b[i]); puts("");

	REP(i,nb) REP(j,nb) dp[i][j]=INT_MAX;
	REP(i,nb) dp[i][i]=0;
	FOR(len,1,nb) REPE(i,nb-len) {
		int j=i+len-1;
		if(i-1>=0) dp[i-1][j]=min(dp[i-1][j],dp[i][j]+1);
		if(j+1<nb) dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1);
		if(i-1>=0&&j+1<nb&&b[i-1]==b[j+1]) dp[i-1][j+1]=min(dp[i-1][j+1],dp[i][j]+1);
	}
	return dp[0][nb-1];
}

void run() {
	scanf("%d",&na);
	REP(i,na) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}