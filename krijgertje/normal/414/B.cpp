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

int maxval,len;
int dp[2001][2001];


void run() {
	scanf("%d%d",&maxval,&len); // <=2000
	memset(dp,0,sizeof(dp));
	dp[0][1]=1;
	REP(i,len) FORE(j,1,maxval) if(dp[i][j]!=0) {
		for(int nj=j;nj<=maxval;nj+=j) {
			dp[i+1][nj]+=dp[i][j];
			if(dp[i+1][nj]>=MOD) dp[i+1][nj]-=MOD;
		}
	}
	int ret=0;
	FORE(j,1,maxval) {
		ret+=dp[len][j];
		if(ret>=MOD) ret-=MOD;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}