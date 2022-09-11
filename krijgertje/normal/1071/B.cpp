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

const int MAXN=2000;

int n,mxchanges;
char g[MAXN][MAXN+1];

int dp[MAXN][MAXN];

bool can[MAXN][MAXN];
char ans[2*MAXN];

vector<pair<int,int>> bydiag[2*MAXN-1];

void solve() {
	REP(i,2*n-1) ans[i]='?'; ans[2*n]='\0';
	REP(x,n) REP(y,n) {
		dp[x][y]=0;
		if(x-1>=0) dp[x][y]=max(dp[x][y],dp[x-1][y]);
		if(y-1>=0) dp[x][y]=max(dp[x][y],dp[x][y-1]);
		if(g[x][y]=='a') ++dp[x][y];
	}
	int mxa=0; REP(x,n) REP(y,n) if(dp[x][y]+mxchanges>=x+y+1) mxa=max(mxa,x+y+1);
	REP(i,mxa) ans[i]='a';
	
	REP(i,2*n-1) bydiag[i].clear(); REP(x,n) REP(y,n) bydiag[x+y].PB(MP(x,y));
	REP(x,n) REP(y,n) can[x][y]=false;
	int at;
	if(mxa==0) {
		at=1;
		can[0][0]=true; ans[0]=g[0][0];
	} else {
		at=mxa;
		REPSZ(i,bydiag[mxa-1]) { int x=bydiag[mxa-1][i].first,y=bydiag[mxa-1][i].second; if(dp[x][y]+mxchanges>=x+y+1) can[x][y]=true; }
	}
	FOR(d,at,2*n-1) {
		char best='z'+1;
		REPSZ(i,bydiag[d]) {
			int x=bydiag[d][i].first,y=bydiag[d][i].second;
			bool ok=false; if(x-1>=0&&can[x-1][y]) ok=true; if(y-1>=0&&can[x][y-1]) ok=true; if(!ok) continue;
			best=min(best,g[x][y]);
		}
		ans[d]=best;
		REPSZ(i,bydiag[d]) {
			int x=bydiag[d][i].first,y=bydiag[d][i].second;
			bool ok=false; if(x-1>=0&&can[x-1][y]) ok=true; if(y-1>=0&&can[x][y-1]) ok=true; if(!ok) continue;
			if(g[x][y]==best) can[x][y]=true;
		}
	}
}

void run() {
	scanf("%d%d",&n,&mxchanges);
	REP(x,n) scanf("%s",g[x]);
	solve();
	printf("%s\n",ans);

}

int main() {
	run();
	return 0;
}