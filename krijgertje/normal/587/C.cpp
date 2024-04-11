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
const int MAXM=MAXN-1;
const int MAXP=100000;
const int MAXLOGN=16;
const int MAXLIM=10;

typedef struct X { int v[MAXLIM],nv; } X;
X merge(const X &a,const X &b) {
	X ret; ret.nv=0; int i=0,j=0;
	while((i<a.nv||j<b.nv)&&ret.nv<MAXLIM) if(i<a.nv&&(j>=b.nv||a.v[i]<=b.v[j])) ret.v[ret.nv++]=a.v[i++]; else ret.v[ret.nv++]=b.v[j++];
	return ret;
}

int n,np,nq;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];
int phead[MAXN],pnxt[MAXP];

int d[MAXN];
int par[MAXN][MAXLOGN+1];
X x[MAXN][MAXLOGN+1];

int tmp[MAXP],ntmp;

void dfs(int at) {
	d[at]=par[at][0]==at?0:d[par[at][0]]+1;
	for(int z=ghead[at];z!=-1;z=gnxt[z]) {
		if(gto[z]==par[at][0]) continue;
		par[gto[z]][0]=at;
		dfs(gto[z]);
	}
	ntmp=0; for(int z=phead[at];z!=-1;z=pnxt[z]) tmp[ntmp++]=z+1; sort(tmp,tmp+ntmp);
	x[at][0].nv=0; REP(i,min(MAXLIM,ntmp)) x[at][0].v[x[at][0].nv++]=tmp[i];
}

void run() {
	scanf("%d%d%d",&n,&np,&nq);
	REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}
	REP(i,n) phead[i]=-1;
	REP(i,np) {
		int a; scanf("%d",&a); --a;
		pnxt[i]=phead[a]; phead[a]=i;
	}
	REP(i,n) par[i][0]=-1;
	par[0][0]=0; dfs(0);
	REP(k,MAXLOGN) REP(i,n) par[i][k+1]=par[par[i][k]][k],x[i][k+1]=merge(x[i][k],x[par[i][k]][k]);
	REP(qi,nq) {
		int a,b,lim; scanf("%d%d%d",&a,&b,&lim); --a,--b;
		X cur; cur.nv=0;
		if(d[a]>d[b]) swap(a,b);
		for(int k=MAXLOGN;k>=0;--k) if(d[b]-(1<<k)>=d[a]) { cur=merge(cur,x[b][k]); b=par[b][k]; }
		if(a!=b) {
			for(int k=MAXLOGN;k>=0;--k) if(par[a][k]!=par[b][k]) { cur=merge(cur,x[a][k]); cur=merge(cur,x[b][k]); a=par[a][k]; b=par[b][k]; }
			cur=merge(cur,x[a][0]); cur=merge(cur,x[b][0]); a=par[a][0]; b=par[b][0];
		}
		cur=merge(cur,x[a][0]);
		printf("%d",min(cur.nv,lim)); REP(i,min(cur.nv,lim)) printf(" %d",cur.v[i]); puts("");
	}

}

int main() {
	run();
	return 0;
}