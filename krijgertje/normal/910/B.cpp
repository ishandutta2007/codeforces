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

int len,four,two;

int dp[5][3];

void run() {
	scanf("%d%d%d",&len,&four,&two);

	memset(dp,-1,sizeof(dp)); dp[0][0]=0;
	REPE(i,4) REPE(j,2) if(dp[i][j]!=-1) {
		REPE(di,4-i) REPE(dj,2-j) if((di!=0||dj!=0)&&di*four+dj*two<=len&&(dp[i+di][j+dj]==-1||dp[i][j]+1<dp[i+di][j+dj])) dp[i+di][j+dj]=dp[i][j]+1;
	}
	printf("%d\n",dp[4][2]);
}

int main() {
	run();
	return 0;
}