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

const int MAXN=1000;
const int MAXM=30000;

int n,m,s,t;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],gcost[MAXM];
bool dead[MAXM];

int calcidx;
int d[MAXN],mind[MAXN],par[MAXN]; bool been[MAXN],hast[MAXN];
void dfs(int at) {
	been[at]=true,hast[at]=at==t; mind[at]=d[at]=par[at]==-1?0:d[gto[par[at]]]+1;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) if(!dead[x>>1]) {
		int to=gto[x];
		if(!been[to]) {
			par[to]=x^1;
			dfs(to);
			if(hast[to]) hast[at]=true;
			mind[at]=min(mind[at],mind[to]);
			//printf("\t%d->%d (%d) %d vs %d (%d)\n",at,to,x>>1,mind[to],d[at],hast[to]?1:0);
			if(mind[to]>d[at]&&hast[to]) {
				if(calcidx==-1||gcost[x>>1]<gcost[calcidx]) calcidx=x>>1;
			}
		} else if(x!=par[at]) {
			mind[at]=min(mind[at],d[to]);
		}
	}
}

int calc() {
	REP(i,n) been[i]=hast[i]=false,par[i]=-1;
	calcidx=-1; dfs(s);
	if(!hast[s]) return -1; if(calcidx==-1) return -2; return calcidx;
}

int retcost,ret[2],nret;

int q[MAXN],back[MAXN],qhead,qtail;
bool onpath[MAXM];
void findpath() {
	REP(i,n) back[i]=-1; qhead=qtail=0; back[s]=-2,q[qhead++]=s;
	while(qtail<qhead) { int at=q[qtail++]; for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(back[to]==-1) back[to]=x^1,q[qhead++]=to; } }
	REP(i,m) onpath[i]=false;
	if(back[t]==-1) return; for(int x=t;x!=s;x=gto[back[x]]) onpath[back[x]>>1]=true;
}

void run() {
	scanf("%d%d%d%d",&n,&m,&s,&t); --s,--t;
	REP(i,n) ghead[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d%d",&a,&b,&gcost[i]); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}
	//REP(i,n) { printf("%d:",i); for(int x=ghead[i];x!=-1;x=gnxt[x]) printf(" %d",gto[x]); puts(""); }

	nret=-1;
	REP(i,m) dead[i]=false;
	findpath();

	FOR(i,-1,m) {
		if(i!=-1&&!onpath[i]) continue;
		if(i!=-1) dead[i]=true;
		int cur=calc();
		//printf("calc(%d)=%d\n",i,cur);
		if(cur!=-2) {
			int curcost=0; if(cur!=-1) curcost+=gcost[cur]; if(i!=-1) curcost+=gcost[i];
			if(nret==-1||curcost<retcost) { retcost=curcost,nret=0; if(i!=-1) ret[nret++]=i; if(cur!=-1) ret[nret++]=cur; }
		}
		if(i!=-1) dead[i]=false;
	}
	if(nret==-1) { printf("-1\n"); return; }
	printf("%d\n%d\n",retcost,nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}