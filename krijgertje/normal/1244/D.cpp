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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;

int n;
int cost[MAXN][3];
vector<int> adj[MAXN];
ll anscost;
int ans[MAXN];

int path[MAXN],npath;

bool solve() {
	REP(i,n) if(SZ(adj[i])>=3) return false;
	int leaf=-1; REP(i,n) if(SZ(adj[i])<2) { leaf=i; break; } if(leaf==-1) return false;
	{ npath=0; int at=leaf; while(true) { path[npath++]=at; int to=-1; REPSZ(i,adj[at]) { int cur=adj[at][i]; if(npath>=2&&path[npath-2]==cur) continue; assert(to==-1); to=cur; } if(to==-1) break; else at=to; } assert(npath==n); }
	anscost=LLONG_MAX;
	REP(x,3) REP(y,3) if(y!=x) {
		int z=3-x-y;
		int w[3]; w[0]=x,w[1]=y,w[2]=z;
		ll curcost=0; REP(i,n) curcost+=cost[path[i]][w[i%3]];
		if(curcost<anscost) { anscost=curcost; REP(i,n) ans[path[i]]=w[i%3]; }
	}
	return true;
}

void run() {
	scanf("%d",&n);
	REP(j,3) REP(i,n) scanf("%d",&cost[i][j]);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b),adj[b].PB(a); }
	if(!solve()) { printf("-1\n"); return; }
	printf("%lld\n",anscost);
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");

}

int main() {
	run();
	return 0;
}