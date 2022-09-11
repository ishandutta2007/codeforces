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

int n,m;
vector<pair<int,char> > adj[MAXN];

bool done[MAXN];
int top[MAXN],ntop;

void dfstop(int at) {
	if(done[at]) return; else done[at]=true;
	REPSZ(i,adj[at]) { int to=adj[at][i].first; dfstop(to); }
	top[ntop++]=at;
}

int dp[MAXN][MAXN][26];

void run() {
	scanf("%d%d",&n,&m); REP(i,m) { int a,b; char c; scanf("%d%d %c",&a,&b,&c); --a,--b; adj[a].PB(MP(b,c)); }

	REP(i,n) done[i]=false; ntop=0;
	REP(i,n) if(!done[i]) dfstop(i);

	memset(dp,-1,sizeof(dp));
	REP(i,n) FOR(j,i,n) {
		int mn=top[i],mx=top[j];
		//printf("mn=%d,mx=%d\n",mn,mx);
		REP(k,26) {
			dp[mn][mx][k]=0;
			REPSZ(z,adj[mn]) {
				int nk=adj[mn][z].second-'a',to=adj[mn][z].first;
				if(nk>=k&&dp[mx][to][nk]==0) dp[mn][mx][k]=1;
			}
			//printf("%d %d %c = %s\n",mn+1,mx+1,'a'+k,dp[mn][mx][k]?"win":"lose");
			if(mn==mx) continue;
			dp[mx][mn][k]=0;
			REPSZ(z,adj[mx]) {
				int nk=adj[mx][z].second-'a',to=adj[mx][z].first;
				if(nk>=k&&dp[mn][to][nk]==0) dp[mx][mn][k]=1;
			}
			//printf("%d %d %c = %s\n",mx+1,mn+1,'a'+k,dp[mx][mn][k]?"win":"lose");
		}
	}
	REP(i,n) { REP(j,n) printf("%c",dp[i][j][0]==1?'A':'B'); puts(""); }
}

int main() {
	run();
	return 0;
}