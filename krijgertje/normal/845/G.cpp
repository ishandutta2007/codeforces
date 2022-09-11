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

const int MAXN=100000;
const int MAXM=100000;

int n,m;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],gval[MAXM];

int pval[MAXN]; int state[MAXN];
int cyc[2*MAXM],ncyc;
void dfs(int at,int xup) {
	pval[at]=xup==-1?0:(pval[gto[xup]]^gval[xup>>1]); state[at]=1;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		if(x==xup) continue; int to=gto[x];
		if(state[to]==0) dfs(to,x^1);
		else if(state[to]==1&&(at!=to||(x&1)==0)) cyc[ncyc++]=pval[at]^pval[to]^gval[x>>1];
	}
	state[at]=2;
}

void gaussjord() {
	int r=0,c=26;
	while(r<ncyc&&c>=0) {
		{ int rr=r; while(rr<ncyc&&((cyc[rr]>>c)&1)==0) ++rr; if(rr==ncyc) { --c; continue; } else swap(cyc[rr],cyc[r]); }
		FOR(rr,r+1,ncyc) if((cyc[rr]>>c)&1) cyc[rr]^=cyc[r];
		++r,--c;
	}
}


void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) ghead[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d%d",&a,&b,&gval[i]); --a,--b;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a;
	}

	REP(i,n) state[i]=0; ncyc=0;
	dfs(0,-1);
	//REP(i,n) printf("%d: %x\n",i+1,pval[i]);
	//printf("cyc:"); REP(i,ncyc) printf(" %x",cyc[i]); puts("");

	gaussjord();
	int ret=pval[n-1];
	REP(i,ncyc) if((ret^cyc[i])<ret) ret^=cyc[i];
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}