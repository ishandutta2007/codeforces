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

const int MAXN=1000;

int n,m;
vector<int> adj[MAXN];
vector<pair<int,int>> ans;

int comp[MAXN],ncomp;
int diag[MAXN],rad[MAXN],leader[MAXN];

int d[MAXN],prv[MAXN];
int q[MAXN],qhead,qtail;
int path[MAXN],npath;

int calcfurthest(int s) {
	qhead=qtail=0; REP(i,n) d[i]=INT_MAX,prv[i]=-2;
	d[s]=0,prv[s]=-1,q[qhead++]=s;
	while(qtail<qhead) {
		int at=q[qtail++];
		REPSZ(i,adj[at]) { int to=adj[at][i]; if(d[to]!=INT_MAX) continue; d[to]=d[at]+1,prv[to]=at,q[qhead++]=to; }
	}
	int ret=q[qhead-1];
	npath=0; for(int i=ret;i!=-1;i=prv[i]) path[npath++]=i; reverse(path,path+npath);
	return ret;
}

void calccomp(int id,int s) {
	int u=calcfurthest(s);
	int v=calcfurthest(u);
	REP(i,qhead) comp[q[i]]=id;
	diag[id]=npath-1; rad[id]=(diag[id]+1)/2; leader[id]=path[rad[id]];
}

int solve() {
	REP(i,n) comp[i]=-1;
	REP(i,n) if(comp[i]==-1) {
		int id=ncomp++;
		calccomp(id,i);
	}
	int rootcomp=0; REP(i,ncomp) if(rad[i]>rad[rootcomp]) rootcomp=i;
	ans.clear(); REP(i,ncomp) if(i!=rootcomp) ans.PB(MP(leader[i],leader[rootcomp]));
	int ret=0; REP(i,ncomp) ret=max(ret,diag[i]); REP(i,ncomp) if(i!=rootcomp) ret=max(ret,rad[i]+rad[rootcomp]+1); REP(i,ncomp) FOR(j,i+1,ncomp) if(i!=rootcomp&&j!=rootcomp) ret=max(ret,rad[i]+rad[j]+2); return ret;

}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n",solve());
	REPSZ(i,ans) printf("%d %d\n",ans[i].first+1,ans[i].second+1);
}

int main() {
	run();
	return 0;
}