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

const int MAXN=250000;

int n,m,k;
vector<int> adj[MAXN];

vector<int> path;
vector<vector<int>> cycs;

bool done[MAXN];
int dep[MAXN];
int par[MAXN];
bool isleaf[MAXN];

void dfs(int at) {
	done[at]=isleaf[at]=true; dep[at]=par[at]==-1?0:dep[par[at]]+1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(done[to]) continue;
		isleaf[at]=false; par[to]=at; dfs(to);
	}
}

void solve() {
	path.clear(); cycs.clear();

	REP(i,n) done[i]=false;
	REP(i,n) if(!done[i]) { par[i]=-1; dfs(i); }
	int need=(n+k-1)/k;
	REP(i,n) if(dep[i]+1>=need) {
		//printf("found path\n");
		for(int x=i;x!=-1;x=par[x]) path.PB(x);
		return;
	}
	REP(a,n) if(isleaf[a]&&SZ(cycs)<k) {
		int b=-1,c=-1; REPSZ(i,adj[a]) { int to=adj[a][i]; assert(dep[to]<dep[a]); if(dep[to]==dep[a]-1) continue; if(b==-1) b=to; else if(c==-1) c=to; } assert(b!=-1&&c!=-1&&b!=c&&dep[b]!=dep[c]); if(dep[b]<dep[c]) swap(b,c);
		int ablen=dep[a]-dep[b]+1,aclen=dep[a]-dep[c]+1,abclen=dep[b]-dep[c]+2;
		if(ablen%3!=0) {
			vector<int> cyc; for(int x=a;x!=b;x=par[x]) cyc.PB(x); cyc.PB(b);
			cycs.PB(cyc);
			continue;
		}
		if(aclen%3!=0) {
			vector<int> cyc; for(int x=a;x!=c;x=par[x]) cyc.PB(x); cyc.PB(c);
			cycs.PB(cyc);
			continue;
		}
		if(abclen%3!=0) {
			vector<int> cyc; cyc.PB(a); for(int x=b;x!=c;x=par[x]) cyc.PB(x); cyc.PB(c);
			cycs.PB(cyc);
			continue;
		}
		assert(false);
	}
	assert(SZ(cycs)==k);
}

void run() {
	scanf("%d%d%d",&n,&m,&k);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	solve();
	if(SZ(path)!=0) { printf("PATH\n"); printf("%d\n",SZ(path)); REPSZ(i,path) { if(i!=0) printf(" "); printf("%d",path[i]+1); } puts(""); }
	if(SZ(cycs)!=0) { printf("CYCLES\n"); REPSZ(i,cycs) { printf("%d\n",SZ(cycs[i])); REPSZ(j,cycs[i]) { if(j!=0) printf(" "); printf("%d",cycs[i][j]+1); } puts(""); } }
}

int main() {
	run();
	return 0;
}