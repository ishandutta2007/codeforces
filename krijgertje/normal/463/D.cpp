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

int n,np;
int p[5][1000];
int r[5][1000];

int dp[1000];

void run() {
	scanf("%d%d",&n,&np);
	REP(i,np) REP(j,n) { scanf("%d",&p[i][j]); --p[i][j]; }
	REP(i,np) REP(j,n) r[i][p[i][j]]=j;

	REP(i,n) {
		int a=p[0][i]; dp[a]=1;
		REP(j,i) {
			int b=p[0][j]; bool ok=true;
			REP(k,np) if(r[k][b]>=r[k][a]) ok=false;
			if(!ok) continue;
			if(dp[b]+1>dp[a]) dp[a]=dp[b]+1;
		}
	}
	int ret=dp[0]; FOR(i,1,n) if(dp[i]>ret) ret=dp[i]; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}