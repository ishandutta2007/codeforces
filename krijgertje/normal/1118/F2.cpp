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
int colcnt[MAXCOL];
pair<int,int> o[MAXN];


void dfsinit(int at) {
	dep[at]=par[at]==-1?0:dep[par[at]]+1;
	REPSZ(i,adj[at]) { int to=adj[at][i]; if(to==par[at]) continue; par[to]=at; dfsinit(to); }
}

pair<int,int> dfscalc(int at) { // (with some color at root, without a color at root)
	pair<int,int> ret=MP(0,0); if(col[at]!=-1) ++ret.first; else ++ret.second;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]) continue;
		pair<int,int> sub=dfscalc(to);
		if(col[to]!=-1&&col[to]==col[at]) {
			ret.first=(ll)ret.first*sub.first%MOD;
		} else {
			ret.first=((ll)ret.first*(sub.first+sub.second)+(ll)ret.second*sub.first)%MOD;
			ret.second=(ll)ret.second*(sub.first+sub.second)%MOD;
		}
	}
	//printf("%d: (%d,%d)\n",at+1,ret.first,ret.second);
	return ret;
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
	return dfscalc(root).first;
}

void run() {
	scanf("%d%d",&n,&ncol);
	REP(i,n) scanf("%d",&col[i]),--col[i];
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}