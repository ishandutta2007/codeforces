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

const int MAXN=100;

int n; int x[MAXN];
int dp[MAXN+1][3];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);
	REPE(i,n) REP(j,3) dp[i][j]=INT_MAX;
	dp[0][0]=0;
	REP(i,n) REP(j,3) if(dp[i][j]!=INT_MAX) REP(nj,3) {
		if(j!=0&&j==nj) continue;
		if(nj!=0&&(x[i]&nj)==0) continue;
		int nval=dp[i][j]+(nj==0?1:0);
		if(nval<dp[i+1][nj]) {
			//printf("%d %d = %d (from %d %d)\n",i+1,nj,nval,i,j);
			dp[i+1][nj]=nval;
		}
	}
	int ret=INT_MAX; REP(j,3) if(dp[n][j]<ret) ret=dp[n][j]; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}