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
const int MAXM=1000000;
const int MAXNM=MAXN>MAXM?MAXN:MAXM;

int n,m,s,t;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];
int par[MAXN],parx[MAXN];

int lst[MAXN],nlst;
int id[MAXN],nid;
int path[MAXN],npath;
int ehead[MAXN],enxt[2*MAXM],pnxt[2*MAXM],etail[2*MAXM];
bool visit[MAXN];
int stck[MAXN],nstck;
int val[MAXN],nval;
int thead[MAXN];

void dfs(int at) {
	lst[nlst++]=at,id[at]=nid++;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(par[to]!=-2) continue;
		par[to]=at,parx[to]=x^1; dfs(to);
	}
}

bool solve() {
	REP(i,n) if(i!=s&&i!=t&&(ghead[i]==-1||gnxt[ghead[i]]==-1)) return false;
	REP(i,n) par[i]=-2; par[s]=-1; nlst=nid=0; dfs(s);
	REP(i,n) visit[i]=false,ehead[i]=-1;
	for(int cur=t;cur!=-1;cur=par[cur]) visit[cur]=true;
	//printf("main:"); for(int cur=t;cur!=-1;cur=par[cur]) printf(" %d",cur); puts("");
	//REP(i,n) printf("%d: par=%d\n",i,par[i]);
	REP(i,n) {
		int at=lst[i];
		for(int x=ghead[at];x!=-1;x=gnxt[x]) {
			int to=gto[x]; if(par[to]==at||to==par[at]||id[to]<=id[at]) continue;
			npath=0; path[npath++]=x; visit[at]=true; for(int cur=to;!visit[cur];visit[cur]=true,cur=par[cur]) path[npath++]=parx[cur];
			//REP(j,npath) printf("%d-%d ",gto[path[j]^1],gto[path[j]]); puts("");
			if(gto[path[npath-1]]==at) return false;
			enxt[path[0]]=ehead[at]; ehead[at]=path[0]; etail[path[0]]=gto[path[npath-1]]; REP(j,npath) pnxt[path[j]]=j+1<npath?path[j+1]:-1;
			enxt[path[npath-1]^1]=ehead[gto[path[npath-1]]]; ehead[gto[path[npath-1]]]=path[npath-1]^1; etail[path[npath-1]^1]=at; REP(j,npath) pnxt[path[j]^1]=j-1>=0?(path[j-1]^1):-1;
		}
	}
	//REP(i,n) for(int x=ehead[i];x!=-1;x=enxt[x]) { printf("%d",i); for(int y=x;y!=-1;y=pnxt[y]) printf("-%d",gto[y]); puts(""); }
	nstck=0; for(int cur=t;cur!=-1;cur=par[cur]) stck[nstck++]=cur;
	REP(i,n) val[i]=-1,thead[i]=ehead[i]; nval=0;
	while(nstck>0) {
		int at=stck[nstck-1];
		//printf("stck:"); REP(i,nstck) printf(" %d",stck[i]); puts(""); if(nstck>10) exit(0);
		if(val[at]==-1) {
			val[at]=nval++;
			//printf("%d = %d\n",at,val[at]);
		}
		bool found=false;
		for(int x=thead[at];!found&&x!=-1;x=thead[at]=enxt[x]) {
			if(val[etail[x]]!=-1) continue;
			npath=0; for(int y=x;y!=-1;y=pnxt[y]) path[npath++]=gto[y];
			for(int i=npath-2;i>=0;--i) stck[nstck++]=path[i];
			found=true;
		}
		if(!found) --nstck;
	}
	return true;
}

int ncases;
void run(int casenr) {
	scanf("%d%d%d%d",&n,&m,&s,&t); --s,--t;
	REP(i,n) ghead[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}
	//if(ncases==50000&&casenr==875) { printf("input: %d %d %d %d\n",n,m,s+1,t+1); REP(i,m) printf("%d %d\n",gto[2*i+1]+1,gto[2*i+0]+1); }
	if(!solve()) { printf("No\n"); return; }
	printf("Yes\n");
	REP(i,m) { int a=gto[2*i+1],b=gto[2*i+0]; if(val[a]>val[b]) swap(a,b); printf("%d %d\n",a+1,b+1); }
}

int main() {
	scanf("%d",&ncases); FORE(i,1,ncases) run(i);
	return 0;
}