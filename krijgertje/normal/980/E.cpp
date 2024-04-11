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

const int MAXN=1000000;
const int MAXLG=19;

int n,nremove;
vector<int> adj[MAXN];

int dep[MAXN];
int par[MAXN];
int up[MAXN][MAXLG+1];

bool marked[MAXN]; int nmarked;

void dfsinit(int at) {
	dep[at]=par[at]==-1?0:dep[par[at]]+1;
	up[at][0]=par[at]==-1?at:par[at]; REP(k,MAXLG) up[at][k+1]=up[up[at][k]][k];
	REPSZ(i,adj[at]) { int to=adj[at][i]; if(to==par[at]) continue; par[to]=at; dfsinit(to); }
}

int calcstepstillmarked(int at) {
	int ret=0;
	for(int k=MAXLG;k>=0;--k) if(!marked[up[at][k]]) ret+=1<<k,at=up[at][k];
	assert(marked[up[at][0]]); return ret+1;
}

void run() {
	scanf("%d%d",&n,&nremove);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }

	par[n-1]=-1; dfsinit(n-1);
	REP(i,n) marked[i]=false; marked[n-1]=true; nmarked=1;
	for(int i=n-2;i>=0;--i) {
		if(marked[i]) continue;
		int cnt=calcstepstillmarked(i);
		if(nmarked+cnt>n-nremove) continue;
		for(int at=i;!marked[at];at=par[at]) marked[at]=true,++nmarked;
	}
	bool fst=true; REP(i,n) if(!marked[i]) { if(fst) fst=false; else printf(" "); printf("%d",i+1); } puts("");
}

int main() {
	run();
	return 0;
}