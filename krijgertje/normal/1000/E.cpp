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

int n,m;
vector<int> adj[MAXN];

int id[MAXN],mnid[MAXN],nid;
int comp[MAXN],ncomp;
int stck[MAXN],nstck;

void tarjan(int at,int par) {
	id[at]=mnid[at]=nid++; stck[nstck++]=at;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		if(id[to]==-1) {
			tarjan(to,at);
			mnid[at]=min(mnid[at],mnid[to]);
		} else {
			mnid[at]=min(mnid[at],id[to]);
		}
	}
	if(id[at]==mnid[at]) {
		while(comp[at]==-1) comp[stck[--nstck]]=ncomp; ++ncomp;
	}
}

vector<int> cadj[MAXN];
int d[MAXN];
int q[MAXN],qhead,qtail;

int farthest(int s) {
	REP(i,ncomp) d[i]=INT_MAX; qhead=qtail=0;
	d[s]=0; q[qhead++]=s;
	while(qtail<qhead) {
		int at=q[qtail++];
		REPSZ(i,cadj[at]) {
			int to=cadj[at][i];
			if(d[to]==INT_MAX) d[to]=d[at]+1,q[qhead++]=to;
		}
	}
	return q[qhead-1];
}

void run() {
	scanf("%d%d",&n,&m); REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }

	nid=ncomp=nstck=0; REP(i,n) id[i]=comp[i]=-1;
	tarjan(0,-1);
	REP(i,n) assert(id[i]!=-1);

	REP(i,n) REPSZ(j,adj[i]) { int a=comp[i],b=comp[adj[i][j]]; if(a!=b) cadj[a].PB(b),cadj[b].PB(a); }
	REP(i,ncomp) { sort(cadj[i].begin(),cadj[i].end()); cadj[i].erase(unique(cadj[i].begin(),cadj[i].end()),cadj[i].end()); }

	int u=farthest(0);
	int v=farthest(u);
	printf("%d\n",d[v]);
}

int main() {
	run();
	return 0;
}