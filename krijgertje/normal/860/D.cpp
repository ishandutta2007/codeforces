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

const int MAXN=200000;
const int MAXM=200000;

int n,m;
vector<int> adj[MAXN];

int d[MAXN];
int par[MAXN];
int single[MAXN];

pair<int,pair<int,int> > ret[(MAXM+1)/2]; int nret;

void dfs(int at) {
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]||par[to]!=-2) continue;
		par[to]=at; d[to]=d[at]+1; dfs(to);
	}
	single[at]=-1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]||par[to]!=at&&d[to]>d[at]) continue;
		if(par[to]==at&&single[to]!=-1) { ret[nret++]=MP(single[to],MP(to,at)); single[to]=-1; continue; }
		if(single[at]!=-1) { ret[nret++]=MP(single[at],MP(at,to)); single[at]=-1; continue; }
		single[at]=to;
	}
}


void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }

	nret=0;
	REP(i,n) par[i]=-2;
	REP(i,n) if(par[i]==-2) { par[i]=-1; d[i]=0; dfs(i); }

	printf("%d\n",nret);
	REP(i,nret) printf("%d %d %d\n",ret[i].first+1,ret[i].second.first+1,ret[i].second.second+1);
}

int main() {
	run();
	return 0;
}