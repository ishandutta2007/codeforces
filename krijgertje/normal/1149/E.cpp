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

const int MAXN=200000;

int n,m;
int val[MAXN];
vector<int> adj[MAXN];
int ans[MAXN];

vector<int> radj[MAXN];
int rem[MAXN];
int q[MAXN],qhead,qtail;
int col[MAXN];
bool seen[MAXN];
int sum[MAXN];

bool solve() {
	REP(i,n) radj[i].clear();
	REP(i,n) REPSZ(j,adj[i]) { int k=adj[i][j]; radj[k].PB(i); }
	REP(i,n) rem[i]=SZ(adj[i]);
	REP(i,n) col[i]=-1;
	qhead=qtail=0; REP(i,n) if(rem[i]==0) q[qhead++]=i;
	REP(i,n) seen[i]=false;
	while(qtail<qhead) {
		int at=q[qtail++];
		REPSZ(i,adj[at]) { int to=adj[at][i]; assert(col[to]!=-1); seen[col[to]]=true; }
		col[at]=0; while(seen[col[at]]) ++col[at];
		REPSZ(i,adj[at]) { int to=adj[at][i]; assert(col[to]!=-1); seen[col[to]]=false; }
		REPSZ(i,radj[at]) { int to=radj[at][i]; if(--rem[to]==0) q[qhead++]=to; }
	}
	REP(i,n) assert(col[i]!=-1);
	REP(i,n) sum[i]=0; REP(i,n) sum[col[i]]^=val[i];
	int mxnonzero=-1; REP(i,n) if(sum[i]!=0) mxnonzero=i; if(mxnonzero==-1) return false;
	//printf("mxnonzero=%d\n",mxnonzero);
	//printf("col:"); REP(i,n) printf(" %d",col[i]); puts("");
	//printf("sum:"); REP(i,n) printf(" %d",sum[i]); puts("");
	int who=-1; REP(i,n) if(col[i]==mxnonzero&&val[i]>=(sum[col[i]]^val[i])) { who=i; break; } assert(who!=-1);
	REP(i,n) ans[i]=val[i];
	ans[who]^=sum[col[who]]; sum[col[who]]^=val[who]^ans[who];
	REPSZ(i,adj[who]) { int to=adj[who][i]; ans[to]^=sum[col[to]]; sum[col[to]]^=val[to]^ans[to]; }
	REP(i,n) assert(sum[i]==0);
	return true;
}


void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%d",&val[i]);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); }
	if(!solve()) { printf("LOSE\n"); return; }
	printf("WIN\n");
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");

}

int main() {
	run();
	return 0;
}