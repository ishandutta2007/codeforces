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

const int MOD=998244353;
const int MAXSZ=500;

int sz,lim;
int dp[MAXSZ+1][MAXSZ+1]; // dp[i][j]=ways to pick the first i columns with largest no larger than j
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

void run() {
	scanf("%d%d",&sz,&lim);

	memset(dp,0,sizeof(dp));
	FORE(j,1,sz) {
		dp[0][j]=1;
		int sum=0;
		FORE(i,1,sz) {
			inc(sum,dp[i-1][j]);
			dp[i][j]=sum;
			if(i-j>=0) inc(sum,MOD-dp[i-j][j]);
		}
		//printf("%d:",j); REPE(i,sz) printf(" %d",dp[i][j]); puts("");
	}

	int ret=0;
	FORE(a,1,sz) {
		int bmx=min(sz,(lim-1)/a);
		int cur=(ll)(dp[sz][a]+MOD-dp[sz][a-1])*dp[sz][bmx]%MOD;
		//printf("a=%d -> b<=%d -> %d\n",a,bmx,cur);
		inc(ret,cur);
	}
	ret=(ll)ret*2%MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}