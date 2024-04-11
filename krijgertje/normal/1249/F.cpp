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
#include <chrono>
#include <chrono>
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

const int MAXN=200;
const int MAXBOUND=200;

int n,bound;
int val[MAXN];
vector<int> adj[MAXN];

int dp[MAXN][MAXBOUND+1];

void dfs(int at,int par) {
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		dfs(to,at);
	}
	REPE(z,bound) dp[at][z]=0;
	{
		int sum=val[at];
		REPSZ(i,adj[at]) {
			int to=adj[at][i]; if(to==par) continue;
			sum+=dp[to][bound];
		}
		dp[at][0]=max(dp[at][0],sum);
	}
	FORE(x,1,bound) {
		int y=max(x,bound-x+1);
		int sum=0,delta=0;
		REPSZ(i,adj[at]) {
			int to=adj[at][i]; if(to==par) continue;
			sum+=dp[to][y-1]; delta=max(delta,dp[to][x-1]-dp[to][y-1]);
		}
		//if(at+1==1) printf("(%d,%d) -> sum=%d delta=%d\n",x,y,sum,delta);
		REPE(z,x) dp[at][z]=max(dp[at][z],sum+delta);
	}
	//printf("%d:",at+1); REPE(z,bound) printf(" %d",dp[at][z]); puts("");
}

int solve() {
	dfs(0,-1);
	return dp[0][0];
}

void run() {
	scanf("%d%d",&n,&bound);
	REP(i,n) scanf("%d",&val[i]);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}