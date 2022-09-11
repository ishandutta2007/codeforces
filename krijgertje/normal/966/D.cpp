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

const int MAXN=300000;
const int MAXM=300000;
const int MAXK=1000000;

int n,m;
vector<int> adj[MAXN];

int ret[MAXK],nret;

bool onestep[MAXN];
int twostep[MAXN];
int prv[MAXN],d[MAXN];
int cur[MAXN],ncur;
int q[MAXN],qhead,qtail;
int path1[MAXN],npath1,path2[MAXN],npath2,path[MAXN],npath;

bool exists(int a,int b) { int idx=lower_bound(adj[a].begin(),adj[a].end(),b)-adj[a].begin(); return idx<SZ(adj[a])&&adj[a][idx]==b; }


bool solve() {
	REP(i,n) sort(adj[i].begin(),adj[i].end());

	int s=0,t=n-1;
	REP(i,n) onestep[i]=false,twostep[i]=-1; REPSZ(j,adj[s]) onestep[adj[s][j]]=true;
	REP(i,n) if(onestep[i]) REPSZ(j,adj[i]) { int to=adj[i][j]; if(to!=s&&!onestep[to]&&twostep[to]==-1) twostep[to]=i; }

	REPSZ(j,adj[t]) { int to=adj[t][j]; if(to==s) { nret=2; ret[0]=s,ret[1]=t; return true; } }
	REPSZ(j,adj[t]) { int to=adj[t][j]; if(onestep[to]) { nret=3; ret[0]=s,ret[1]=to,ret[2]=t; return true; } }
	REPSZ(j,adj[t]) { int to=adj[t][j]; if(twostep[to]!=-1) { nret=4; ret[0]=s,ret[1]=twostep[to],ret[2]=to,ret[3]=t; return true; } }
	REP(i,n) if(onestep[i]) REPSZ(j,adj[i]) { int to=adj[i][j]; if(to!=s&&!onestep[to]) { nret=5; ret[0]=s,ret[1]=i,ret[2]=to,ret[3]=s,ret[4]=t; return true; } }

	REP(i,n) prv[i]=d[i]=-2;
	REP(i,n) if(onestep[i]&&prv[i]==-2) {
		qhead=qtail=ncur=0; prv[i]=-1,d[i]=0,cur[ncur++]=i,q[qhead++]=i;
		while(qtail<qhead) {
			int at=q[qtail++];
			REPSZ(j,adj[at]) {
				int to=adj[at][j]; if(to==s||prv[to]!=-2) continue; assert(onestep[to]);
				prv[to]=at,d[to]=d[at]+1,cur[ncur++]=to,q[qhead++]=to;
			}
		}
		REP(ai,ncur) FOR(bi,ai+1,ncur) if(!exists(cur[ai],cur[bi])) {
			npath1=npath2=npath=0;
			int a=cur[ai],b=cur[bi];
			while(a!=b) { if(d[a]>=d[b]) path1[npath1++]=a,a=prv[a]; else path2[npath2++]=b,b=prv[b]; }
			REP(j,npath1) path[npath++]=path1[j]; path[npath++]=a; for(int j=npath2-1;j>=0;--j) path[npath++]=path2[j];
			assert(npath>=3&&path[0]==cur[ai]&&path[npath-1]==cur[bi]);
			int idx=0; while(!exists(path[idx+1],path[npath-1])) ++idx;
			nret=6; ret[0]=s,ret[1]=path[idx],ret[2]=path[idx+1],ret[3]=path[npath-1],ret[4]=path[idx],ret[5]=t; return true;
		}
	}
	return false;
}

void run() {
	scanf("%d%d",&n,&m); REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	if(!solve()) { printf("-1\n"); return; }
	printf("%d\n",nret-1); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}