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

const int MAXN=200000;
const int MAXM=MAXN-1;

int n,npair;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];
bool hasteam[MAXN];

int sz[MAXN],par[MAXN];
int ret[MAXN],nret;

void dfs(int at) {
	sz[at]=hasteam[at]?1:0;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x];
		if(to==par[at]) continue;
		par[to]=at; dfs(to);
		sz[at]+=sz[to];
	}
}
void dfs2(int at,int p) {
	if(hasteam[at]) ret[nret++]=at;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x];
		if(to==p) continue;
		dfs2(to,at);
	}
}

void run() {
	scanf("%d%d",&n,&npair);
	REP(i,n) ghead[i]=-1,hasteam[i]=false;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}
	REP(i,2*npair) { int a; scanf("%d",&a); --a; hasteam[a]=true; }

	par[0]=-1; dfs(0);
	int c=-1;
	REP(at,n) {
		int mxsz=2*npair-sz[at]; for(int x=ghead[at];x!=-1;x=gnxt[x]) if(gto[x]!=par[at]&&sz[gto[x]]>mxsz) mxsz=sz[gto[x]];
		if(mxsz<=npair) { c=at; break; }
	}
	assert(c!=-1); //printf("%d\n",c);

	nret=0; dfs2(c,-1); assert(nret==2*npair);
	printf("%d\n",1); printf("%d\n",c+1); REP(i,npair) printf("%d %d %d\n",ret[i]+1,ret[i+npair]+1,c+1);
}

int main() {
	run();
	return 0;
}