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

const int MAXN=1000000;

int n,lim;
int par[MAXN];

vector<int> ch[MAXN];
int dleaf[MAXN];
int dp[MAXN]; // max nr of leafs visited when needing to return

void dfsinit(int at) {
	dleaf[at]=SZ(ch[at])==0?0:INT_MAX;
	dp[at]=SZ(ch[at])==0?1:0;
	REPSZ(i,ch[at]) {
		int to=ch[at][i];
		dfsinit(to);
		dleaf[at]=min(dleaf[at],1+dleaf[to]);
		if(dleaf[to]<=lim-1) dp[at]+=dp[to];
	}
}
int dfsans(int at) {
	int ret=dp[at];
	REPSZ(i,ch[at]) {
		int to=ch[at][i];
		int cur=dp[at]+dfsans(to)-(dleaf[to]<=lim-1?dp[to]:0);
		ret=max(ret,cur);
	}
	//printf("%d: dleaf=%d dp=%d ans=%d\n",at+1,dleaf[at],dp[at],ret);
	return ret;
}

int solve() {
	REP(i,n) if(par[i]!=-1) ch[par[i]].PB(i);
	dfsinit(0);
	return dfsans(0);
}

void run() {
	scanf("%d%d",&n,&lim);
	par[0]=-1; FOR(i,1,n) scanf("%d",&par[i]),--par[i];
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}