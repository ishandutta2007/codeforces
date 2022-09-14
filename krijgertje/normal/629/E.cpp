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
const int MAXLGN=16;

int n,nq;
int head[MAXN],nxt[2*MAXM],to[2*MAXM];
int d[MAXN],anc[MAXN][1+MAXLGN];
int csz[MAXN]; ll csum[MAXN];
int psz[MAXN]; ll psum[MAXN];

void dfs(int at,int par) {
	d[at]=par==-1?0:d[par]+1,anc[at][0]=par==-1?at:par; csz[at]=1; csum[at]=0;
	for(int x=head[at];x!=-1;x=nxt[x]) {
		if(to[x]==par) continue;
		dfs(to[x],at);
		csz[at]+=csz[to[x]]; csum[at]+=csz[to[x]]+csum[to[x]];
	}
}
void dfs2(int at,int par) {
	for(int x=head[at];x!=-1;x=nxt[x]) {
		if(to[x]==par) continue;
		psz[to[x]]=psz[at]+csz[at]-csz[to[x]];
		psum[to[x]]=psum[at]+csum[at]-csum[to[x]]-csz[to[x]]+psz[to[x]];
		dfs2(to[x],at);
	}
}

int lca(int a,int b) {
	if(d[a]>d[b]) swap(a,b);
	for(int k=MAXLGN;k>=0;--k) if(d[b]-(1<<k)>=d[a]) b=anc[b][k];
	if(a==b) return a;
	for(int k=MAXLGN;k>=0;--k) if(anc[a][k]!=anc[b][k]) a=anc[a][k],b=anc[b][k];
	return anc[a][0];
}
int getanc(int a,int m) { for(int k=MAXLGN;k>=0;--k) if((1<<k)<=m) a=anc[a][k],m-=1<<k; return a; }

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) head[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a;
	}
	dfs(0,-1);
	psz[0]=0; psum[0]=0; dfs2(0,-1);
	REP(k,MAXLGN) REP(i,n) anc[i][k+1]=anc[anc[i][k]][k];
	//REP(i,n) printf("%d: %d / %d %lld / %d %lld\n",i,d[i],csz[i],csum[i],psz[i],psum[i]);
	REP(qi,nq) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		int c=lca(a,b);
		//printf("\t%d %d -> %d\n",a,b,c);
		if(c==b) swap(a,b);
		double ret;
		if(c==a) {
			int x=getanc(b,d[b]-d[a]-1);
			//printf(" \tx=%d\n",x);
			ret=1+d[b]-d[a]+1.0*(csum[a]+psum[a]-csz[x]-csum[x])/(csz[a]+psz[a]-csz[x])+1.0*csum[b]/csz[b];
		} else {
			ret=1+d[a]-d[c]+d[b]-d[c]+1.0*csum[a]/csz[a]+1.0*csum[b]/csz[b];
		}
		printf("%.9lf\n",ret);
	}
}

int main() {
	run();
	return 0;
}