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

const int MAXN=1000;
const int MOD=998244353;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int n,k;
int a[MAXN];

int dp[MAXN+1][MAXN]; // dp[i][j] = #ways to select i items (i>0), the last one being <= j


int calcatleast(int lbound) {
	REP(j,n) dp[1][j]=j+1;
	FORE(i,2,k) {
		int upto=-1;
		REP(j,n) {
			while(a[j]-a[upto+1]>=lbound) ++upto;
			dp[i][j]=0;
			if(j-1>=0) inc(dp[i][j],dp[i][j-1]);
			if(upto>=0) inc(dp[i][j],dp[i-1][upto]);
		}
	}
	//printf("calcatleast(%d)=%d\n",lbound,dp[k][n-1]);
	return dp[k][n-1];
}

int solve() {
	sort(a,a+n);
	int mx=(a[n-1]-a[0])/(k-1);
	int ret=0;
	FORE(i,1,mx) {
		int cnt=calcatleast(i);
		inc(ret,cnt);
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}