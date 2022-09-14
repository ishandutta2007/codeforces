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

const int MAXN=400000;
const int MAXM=MAXN-1;

int n;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];
int par[MAXN],sz[MAXN],mxcval[MAXN],mxcid[MAXN],mxcval2[MAXN],mxpval[MAXN],ret[MAXN];

void update(int at,int val,int id) { if(val>mxcval[at]) mxcval2[at]=mxcval[at],mxcval[at]=val,mxcid[at]=id; else if(val>mxcval2[at]) mxcval2[at]=val; }
void dfs1(int at) {
	sz[at]=1,mxcval[at]=mxcval2[at]=0,mxcid[at]=-1;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x];
		if(to==par[at]) continue;
		par[to]=at; dfs1(to);
		sz[at]+=sz[to];
		update(at,sz[to]<=n/2?sz[to]:mxcval[to],to);
	}
}
void dfs2(int at) {
	mxpval[at]=0,ret[at]=1;
	if(par[at]!=-1) {
		mxpval[at]=n-sz[at]<=n/2?n-sz[at]:max(mxpval[par[at]],mxcid[par[at]]!=at?mxcval[par[at]]:mxcval2[par[at]]);
		if(n-sz[at]-mxpval[at]>n/2) ret[at]=0;
	}
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par[at]) continue;
		int cur=sz[to]<=n/2?n/2:mxcval[to]; if(sz[to]-cur>n/2) ret[at]=0;
		dfs2(to);
	}
}


void run() {
	scanf("%d",&n);
	REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}

	par[0]=-1; dfs1(0); dfs2(0);
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}