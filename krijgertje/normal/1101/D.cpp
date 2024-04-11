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
const int MAXVAL=200000;

int n;
int val[MAXN];
vector<int> adj[MAXN];

int pmn[MAXVAL+1];
vector<int> who[MAXVAL+1];

int mark[MAXN];
int q[MAXN],qhead,qtail;
int d[MAXN];

pair<int,int> farthest(int p,int s) {
	qhead=qtail=0; d[s]=0,q[qhead++]=s;
	while(qtail<qhead) { int at=q[qtail++]; REPSZ(i,adj[at]) { int to=adj[at][i]; if(mark[to]!=p||d[to]!=-1) continue; d[to]=d[at]+1,q[qhead++]=to; } }
	int u=q[qhead-1];
	pair<int,int> ret=MP(u,d[u]);
	REP(i,qhead) { int at=q[i]; d[at]=-1; }
	return ret;
}

int calc(int p,int s) {
	//printf("calc(%d,%d)\n",p,s+1);
	qhead=qtail=0; q[qhead++]=s,mark[s]=p; while(qtail<qhead) { int at=q[qtail++]; REPSZ(i,adj[at]) { int to=adj[at][i]; if(val[to]%p!=0||mark[to]==p) continue; q[qhead++]=to,mark[to]=p; } }
	int u=farthest(p,s).first;
	return farthest(p,u).second+1;
}

int solve() {
	memset(pmn,-1,sizeof(pmn)); FORE(i,2,MAXVAL) if(pmn[i]==-1) for(int j=i;j<=MAXVAL;j+=i) if(pmn[j]==-1) pmn[j]=i;
	REPE(i,MAXVAL) who[i].clear();
	REP(i,n) { int x=val[i]; while(x!=1) { int p=pmn[x]; while(x%p==0) x/=p; who[p].PB(i); } }

	int ret=0;
	REP(i,n) mark[i]=-1,d[i]=-1;
	REPE(p,MAXVAL) if(SZ(who[p])>0) {
		//printf("%d:",p); REPSZ(i,who[p]) printf(" %d",who[p][i]+1); puts("");
		REPSZ(i,who[p]) {
			int at=who[p][i]; if(mark[at]==p) continue;
			int cur=calc(p,at);
			ret=max(ret,cur);
		}
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&val[i]);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}