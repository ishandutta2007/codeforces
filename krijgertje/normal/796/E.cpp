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
#include <random>
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

const int MAXN=1000;
const int MAXT=1000;
const int MAXSEE=50;

int n,tmx,nsee;
int nhave[2]; bool have[2][MAXN];
int sum[MAXN+1];

int dp[2][MAXN+1][MAXSEE+1][2]; // dp[x][i][j][k] = number of questions we can have correct if we are at position i and we can see the next j answers of genius k

void upd(int &x,int y) { if(y>x) x=y; }
void run() {
	scanf("%d%d%d",&n,&tmx,&nsee);
	REP(k,2) { scanf("%d",&nhave[k]); REP(i,n) have[k][i]=false; REP(i,nhave[k]) { int x; scanf("%d",&x); --x; have[k][x]=true; } }
	sum[0]=0; REP(i,n) sum[i+1]=sum[i]+(have[0][i]||have[1][i]?1:0);
	//REP(k,2) { REP(i,n) printf("%c",have[k][i]?'V':'.'); puts(""); }

	int at=0; memset(dp[at],-1,sizeof(dp[at])); dp[at][0][0][0]=0;
	REPE(t,tmx) {
		memset(dp[1-at],-1,sizeof(dp[1-at]));
		REP(i,n) REPE(j,nsee) REP(k,2) if(dp[at][i][j][k]!=-1) {
			// do nothing here
			upd(dp[at][i+1][max(0,j-1)][k],dp[at][i][j][k]+(j>0&&have[k][i]?1:0));
			// look at current genius
			if(t<tmx) {
				int csee=min(nsee,n-i);
				upd(dp[1-at][i][csee][k],dp[at][i][j][k]);
			}
			// look at other genius
			if(t<tmx) {
				int nboth=min(j,n-i),csee=min(nsee-nboth,n-i-nboth);
				upd(dp[1-at][i+nboth][csee][1-k],dp[at][i][j][k]+sum[i+nboth]-sum[i]);
			}
		}
		//REPE(i,n) REPE(j,nsee) REP(k,2) if(dp[at][i][j][k]!=-1) printf("after %d peeks, being at %d, seeing %d of %d -> %d\n",t,i,j,k,dp[at][i][j][k]);
		if(t<tmx) at=1-at;
	}
	printf("%d\n",max(dp[at][n][0][0],dp[at][n][0][1]));
}

int main() {
	run();
	return 0;
}