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

const int MAXN=300000;
const int MAXCOL=MAXN;
const int MOD=998244353;

int n,ncol;
int col[MAXN];
vector<int> adj[MAXN];

int root;
int par[MAXN],dep[MAXN];
int colcnt[MAXN];
pair<int,int> o[MAXN];


void dfsinit(int at) {
	dep[at]=par[at]==-1?0:dep[par[at]]+1;
	REPSZ(i,adj[at]) { int to=adj[at][i]; if(to==par[at]) continue; par[to]=at; dfsinit(to); }
}

int solve() {
	root=-1; REP(i,n) if(col[i]!=-1) { root=i; break; } assert(root!=-1);
	par[root]=-1; dfsinit(root);
	REP(i,ncol) colcnt[i]=0; REP(i,n) if(col[i]!=-1) ++colcnt[col[i]];
	REP(i,n) o[i]=MP(-dep[i],i); sort(o,o+n);
	REP(i,n) {
		int at=o[i].second; if(col[at]==-1||colcnt[col[at]]==1) continue;
		--colcnt[col[at]];
		assert(par[at]!=-1);
		if(col[par[at]]==-1) col[par[at]]=col[at],++colcnt[col[at]];
		if(col[par[at]]!=col[at]) return 0;
	}
	//printf("col:"); REP(i,n) printf(" %d",col[i]); puts("");
	int ret=1;
	REP(i,n) if(col[i]!=-1&&par[i]!=-1&&col[par[i]]!=col[i]) {
		int at=par[i],cnt=1; while(par[at]!=-1&&col[at]==-1) ++cnt,at=par[at];
		//printf("%d: %d\n",i+1,cnt);
		ret=(ll)ret*cnt%MOD;
	}
	return ret;
}

void run() {
	scanf("%d",&n); ncol=2;
	REP(i,n) scanf("%d",&col[i]),--col[i];
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}