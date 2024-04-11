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
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],deg[MAXN];

bool been[MAXN];
int path[MAXN],npath; bool donepath;
int ret[MAXN];

bool findcycle(int at,int par) {
	been[at]=true;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		if(been[to]) { npath=0; donepath=false; path[npath++]=to; path[npath++]=at; return true; }
		if(findcycle(to,at)) { if(!donepath) { path[npath++]=at; if(path[0]==at) donepath=true; } return true; }
	}
	return false;
}

bool findpath(int at,int par) {
	if(par!=-1&&deg[at]>=3) { npath=0; path[npath++]=at; return true; }
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		if(findpath(to,at)) { path[npath++]=at; return true; }
	}
	return false;
}

void getpath(int at,int par) {
	path[npath++]=at;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		getpath(to,at);
	}
}

bool solve() {
	REP(j,n) ret[j]=0;
	REP(i,n) been[i]=false;
	REP(i,n) if(!been[i]&&findcycle(i,-1)) {
		REP(j,npath) ret[path[j]]=1; return true;
	}
	REP(i,n) if(deg[i]>=4) {
		ret[i]=2; for(int x=ghead[i];x!=-1;x=gnxt[x]) ret[gto[x]]=1; return true;
	}
	REP(i,n) if(deg[i]==3&&findpath(i,-1)) {
		int a=path[0],b=path[npath-1]; REP(j,npath) ret[path[j]]=2;
		for(int x=ghead[a];x!=-1;x=gnxt[x]) { int to=gto[x]; if(ret[to]==0) ret[to]=1; }
		for(int x=ghead[b];x!=-1;x=gnxt[x]) { int to=gto[x]; if(ret[to]==0) ret[to]=1; }
		return true;
	}
	REP(i,n) if(deg[i]==3) {
		npath=0; 
		for(int x=ghead[i];x!=-1;x=gnxt[x]) {
			int to=gto[x]; if(deg[to]==1) continue;
			path[npath++]=to;
		}
		if(npath>=3) {
			ret[i]=3; REP(j,npath) { int a=path[j]; ret[a]=2; for(int x=ghead[a];x!=-1;x=gnxt[x]) { int to=gto[x]; if(ret[to]==0) ret[to]=1; } } return true;
		}
	}
	REP(i,n) if(deg[i]==3) {
		int cnt=0;
		for(int x=ghead[i];x!=-1;x=gnxt[x]) {
			int to=gto[x]; npath=0; getpath(to,i); if(npath>=3) ++cnt;
		}
		if(cnt>=2) {
			ret[i]=4;
			for(int x=ghead[i];x!=-1;x=gnxt[x]) {
				int to=gto[x]; npath=0; getpath(to,i); if(npath>=3) REP(j,3) ret[path[j]]=3-j; else REP(j,npath) ret[path[j]]=2;
			}
			return true;
		}
	}
	REP(i,n) if(deg[i]==3) {
		bool lng=false,oth=false;
		for(int x=ghead[i];x!=-1;x=gnxt[x]) {
			int to=gto[x]; npath=0; getpath(to,i); if(npath>=5) lng=true; else if(npath==2) oth=true;
		}
		if(lng&&oth) {
			ret[i]=6;
			for(int x=ghead[i];x!=-1;x=gnxt[x]) {
				int to=gto[x]; npath=0; getpath(to,i); if(npath>=5) REP(j,5) ret[path[j]]=5-j; else if(npath==2) REP(j,npath) ret[path[j]]=4-2*j; else REP(j,npath) ret[path[j]]=3;
			}
			return true;
		}
	}
	return false;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) ghead[i]=-1,deg[i]=0;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b,++deg[a];
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a,++deg[b];
	}
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}