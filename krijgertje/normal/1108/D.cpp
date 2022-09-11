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

const int MAXN=200000;
const char CH[3]={'B','G','R'};

int n;
char s[MAXN+1];
char ans[MAXN+1];


int dp[MAXN][3];
int prv[MAXN][3];

int solve() {
	REP(j,3) dp[0][j]=s[0]==CH[j]?0:1,prv[0][j]=-1;
	FOR(i,1,n) REP(j,3) { dp[i][j]=INT_MAX; REP(pj,3) if(pj!=j) { int cur=dp[i-1][pj]+(s[i]==CH[j]?0:1); if(cur<dp[i][j]) dp[i][j]=cur,prv[i][j]=pj; } }
	int cj=0; REP(j,3) if(dp[n-1][j]<dp[n-1][cj]) cj=j;
	int ret=dp[n-1][cj];
	ans[n]='\0'; for(int ci=n-1;ci>=0;--ci) { ans[ci]=CH[cj]; cj=prv[ci][cj]; }
	return ret;
}

void run() {
	scanf("%d",&n);
	scanf("%s",s);
	printf("%d\n",solve());
	printf("%s\n",ans);
}

int main() {
	run();
	return 0;
}