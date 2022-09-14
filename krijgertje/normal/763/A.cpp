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

int n;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];
int col[MAXN];
int tcol[MAXN]; // entire tree same color
int t1col[MAXN],t1idx[MAXN]; // entire tree same color except one adjacent subtree


void dfs1(int at,int par) {
	tcol[at]=col[at],t1col[at]=col[at],t1idx[at]=-1;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		dfs1(to,at);
		if(tcol[to]!=tcol[at]) tcol[at]=0;
		if(tcol[to]!=t1col[at]) if(t1idx[at]==-1) t1idx[at]=to; else t1col[at]=0,t1idx[at]=-1;
	}
}
void dfs2(int at,int par) {
	if(par!=-1) {
		int parcol=t1idx[par]==at?t1col[par]:tcol[par];
		if(parcol!=tcol[at]) tcol[at]=0;
		if(parcol!=t1col[at]) if(t1idx[at]==-1) t1idx[at]=par; else t1col[at]=0,t1idx[at]=par;
	}
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		dfs2(to,at);
	}
}

void run() {
	scanf("%d",&n); REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}
	REP(i,n) scanf("%d",&col[i]);
	dfs1(0,-1);
	dfs2(0,-1);
	int ret=-1;
	REP(at,n) {
		bool ok=true;
		for(int x=ghead[at];x!=-1;x=gnxt[x]) {
			int to=gto[x];
			int tocol=t1idx[to]==at?t1col[to]:tcol[to];
			if(tocol==0) ok=false;
		}
		if(ok) { ret=at; break; }
	}
	if(ret==-1) printf("NO\n"); else printf("YES\n%d\n",ret+1);
}

int main() {
	run();
	return 0;
}