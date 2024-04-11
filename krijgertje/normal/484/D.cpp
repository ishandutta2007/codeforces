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

int n;
int a[1000000];
ll dp[1000000][3]; // 0=down, 1=same, 2=up

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);

	memset(dp,-1,sizeof(dp)); dp[0][1]=0;
	REP(i,n-1) REP(j,3) if(dp[i][j]!=-1) {
		if(dp[i][j]>dp[i+1][1]) dp[i+1][1]=dp[i][j];
		int nj=a[i]>a[i+1]?0:a[i]<a[i+1]?2:1;
		if(j==0&&nj==2||j==2&&nj==0||nj==1) continue;
		ll nval=dp[i][j]+abs(a[i]-a[i+1]);
		if(nval>dp[i+1][nj]) dp[i+1][nj]=nval;
	}
	//REP(i,n) REP(j,3) printf("%d %d: %lld\n",i,j,dp[i][j]);
	ll ret=0; REP(j,3) if(dp[n-1][j]>ret) ret=dp[n-1][j];
	cout<<ret<<endl;

}

int main() {
	run();
	return 0;
}