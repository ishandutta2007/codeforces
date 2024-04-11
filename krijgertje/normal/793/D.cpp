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

const int MAXN=80;
const int MAXM=2000;

int n,want,m;
int ghead[MAXN],gnxt[MAXM],gto[MAXM],gcost[MAXM];

int dp[MAXN][MAXN][MAXN+1]; // dp[i][j][k] is minimum cost of visiting k offices in the range min(i,j)..max(i,j), starting at i

void run() {
	scanf("%d%d%d",&n,&want,&m);
	REP(i,n) ghead[i]=-1;
	REP(i,m) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; gcost[i]=c;
		gnxt[i]=ghead[a],ghead[a]=i,gto[i]=b;
		//gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a;
	}
	REP(i,n) REP(j,n) dp[i][j][1]=0;
	REP(i,n) REP(j,n) FORE(k,2,want) dp[i][j][k]=INT_MAX;
	FOR(len,1,n) REP(i,n) REP(dj,2) {
		int j=dj==0?i+len:i-len; if(j<0||j>=n) continue;
		FORE(k,2,min(want,len+1)) {
			for(int x=ghead[i];x!=-1;x=gnxt[x]) {
				int to=gto[x];
				if(j<i&&(to<j||to>=i)) continue;
				if(i<j&&(to<=i||to>j)) continue;
				int ni=j<i?i-1:i+1;
				//printf("\t(%d,%d,%d)=%d+%d\n",to,j,k-1,dp[to][j][k-1],gcost[x]);
				//printf("\t(%d,%d,%d)=%d+%d\n",to,ni,k-1,dp[to][ni][k-1],gcost[x]);
				if(dp[to][j][k-1]!=INT_MAX) { int cur=dp[to][j][k-1]+gcost[x]; if(cur<dp[i][j][k]) dp[i][j][k]=cur; }
				if(dp[to][ni][k-1]!=INT_MAX) { int cur=dp[to][ni][k-1]+gcost[x]; if(cur<dp[i][j][k]) dp[i][j][k]=cur; }
			}
			//printf("(%d,%d,%d)=%d\n",i,j,k,dp[i][j][k]);
		}
	}
	int ret=INT_MAX; REP(i,n) REP(j,n) ret=min(ret,dp[i][j][want]); printf("%d\n",ret==INT_MAX?-1:ret);
}

int main() {
	run();
	return 0;
}