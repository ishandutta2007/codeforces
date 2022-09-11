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

int n;
vector<int> adj[MAXN];

int mem[MAXN][4];

int dfs(int at,int par,int k) {
	if(mem[at][k]!=-1) return mem[at][k];
	int none=0,me=1,ch=1,chextra=INT_MAX;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		none+=dfs(to,at,min(3,k+1));
		me+=dfs(to,at,min(2,k+1));
		ch+=dfs(to,at,min(3,k+1));
		chextra=min(chextra,dfs(to,at,1)-dfs(to,at,min(3,k+1)));
	}
	int ret=INT_MAX;
	if(k<=2) ret=min(ret,none);
	ret=min(ret,me);
	if(chextra!=INT_MAX) ret=min(ret,ch+chextra);
	//printf("dp[%d][%d]=%d (%d,%d,%d+%d)\n",at+1,k,ret,none,me,ch,chextra);
	return mem[at][k]=ret;
}

void run() {
	scanf("%d",&n); REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }

	memset(mem,-1,sizeof(mem));
	int ans=dfs(0,-1,0);
	printf("%d\n",ans);
}

int main() {
	run();
	return 0;
}