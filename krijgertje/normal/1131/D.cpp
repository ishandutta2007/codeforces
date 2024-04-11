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
const int MAXID=2*MAXN;

int na,nb;
char g[MAXN][MAXN+1];
int ansa[MAXN],ansb[MAXN];

int ida[MAXN],idb[MAXN],nid;
int par[MAXID],sz[MAXID];

bool isleader[MAXID];
vector<int> out[MAXID];
int state[MAXID],top[MAXID],topidx[MAXID],ntop;
int ans[MAXID];

int find(int x) { if(par[x]==x) return x; return par[x]=find(par[x]); }
bool unite(int x,int y) { x=find(x),y=find(y); if(x==y) return false; if(sz[x]<sz[y]) swap(x,y); par[y]=x,sz[x]+=sz[y]; return true; }

bool dfstop(int at) {
	state[at]=1; 
	REPSZ(i,out[at]) { int to=out[at][i]; if(state[to]==1) return false; if(state[to]==0&&!dfstop(to)) return false; }
	top[ntop]=at,topidx[at]=ntop,++ntop;
	state[at]=2; return true;
}

bool solve() {
	nid=0; REP(i,na) ida[i]=nid++; REP(i,nb) idb[i]=nid++;
	REP(i,nid) par[i]=i,sz[i]=i;
	REP(i,na) REP(j,nb) if(g[i][j]=='=') unite(ida[i],idb[j]);
	REP(i,nid) isleader[i]=par[i]==i;
	REP(i,na) REP(j,nb) { int aleader=find(ida[i]),bleader=find(idb[j]); if(g[i][j]=='>') out[aleader].PB(bleader); if(g[i][j]=='<') out[bleader].PB(aleader); }
	//REP(i,nid) { printf("%d (%d):",i,find(i)); REPSZ(j,out[i]) printf(" %d",out[i][j]); puts(""); }
	REP(i,nid) state[i]=isleader[i]?0:-1;
	ntop=0; REP(i,nid) if(state[i]==0) if(!dfstop(i)) return false; reverse(top,top+ntop);
	//printf("top:"); REP(i,ntop) printf(" %d",top[i]); puts("");
	for(int i=ntop-1;i>=0;--i) { int at=top[i]; ans[at]=1; REPSZ(j,out[at]) { int to=out[at][j]; ans[at]=max(ans[at],ans[to]+1); } }
	REP(i,na) ansa[i]=ans[find(ida[i])];
	REP(i,nb) ansb[i]=ans[find(idb[i])];
	return true;
}

void run() {
	scanf("%d%d",&na,&nb);
	REP(i,na) scanf("%s",g[i]);
	if(!solve()) { printf("No\n"); return; }
	printf("Yes\n");
	REP(i,na) { if(i!=0) printf(" "); printf("%d",ansa[i]); } puts("");
	REP(i,nb) { if(i!=0) printf(" "); printf("%d",ansb[i]); } puts("");
}

int main() {
	run();
	return 0;
}