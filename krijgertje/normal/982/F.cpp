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

int n,m;
vector<int> adj[MAXN];
vector<int> radj[MAXN];

int indeg[MAXN],outdeg[MAXN];
bool alive[MAXN];
int q[MAXN],qhead,qtail;

int path[MAXN],npath; bool onpath[MAXN];
int cyc[MAXN],ncyc;
int cycidx[MAXN];
int state[MAXN];

int mxreachidx[MAXN],mnreachidx[MAXN],mxreachedbyidx[MAXN];

vector<pair<int,int> > ranges;
int sum[MAXN+1];

bool findcyc(int at) {
	if(onpath[at]) { int idx=0; while(path[idx]!=at) ++idx; ncyc=0; while(idx<npath) cyc[ncyc++]=path[idx++]; return true; }
	path[npath++]=at; onpath[at]=true;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(!alive[to]) continue;
		if(findcyc(to)) return true;
	}
	--npath; onpath[at]=false;
	return false;
}

bool istop(int at) {
	if(state[at]!=0) return state[at]==2;
	state[at]=1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(cycidx[to]!=-1) continue;
		if(!istop(to)) return false;
	}
	state[at]=2;
	return true;
}

int solve() {
	REP(i,n) indeg[i]=outdeg[i]=0,alive[i]=true; REP(i,n) REPSZ(j,adj[i]) { int k=adj[i][j]; ++outdeg[i]; ++indeg[k]; } qhead=qtail=0;
	REP(i,n) if(indeg[i]==0||outdeg[i]==0) { alive[i]=false; q[qhead++]=i; }
	while(qtail<qhead) {
		int at=q[qtail++];
		REPSZ(i,adj[at]) {
			int to=adj[at][i];
			if(--indeg[to]==0&&alive[to]) { alive[to]=false; q[qhead++]=to; }
		}
		REPSZ(i,radj[at]) {
			int fr=radj[at][i];
			if(--outdeg[fr]==0&&alive[fr]) { alive[fr]=false; q[qhead++]=fr; }
		}
	}

	int rt=-1; REP(i,n) if(alive[i]) { rt=i; break; } assert(rt!=-1);
	npath=0; REP(i,n) onpath[i]=false;
	assert(findcyc(rt));
	REP(i,n) cycidx[i]=-1; REP(i,ncyc) cycidx[cyc[i]]=i;
	//printf("cyc:"); REP(i,ncyc) printf(" %d",cyc[i]+1); puts("");

	REP(i,n) state[i]=0;
	REP(i,n) if(alive[i]&&cycidx[i]==-1&&state[i]==0&&!istop(i)) return -1;

	REP(i,n) mxreachidx[i]=-1;
	for(int j=ncyc-1;j>=0;--j) {
		qhead=qtail=0; q[qhead++]=cyc[j];
		while(qtail<qhead) {
			int at=q[qtail++];
			REPSZ(i,radj[at]) {
				int fr=radj[at][i]; if(!alive[fr]||mxreachidx[fr]!=-1||cycidx[fr]!=-1&&cycidx[at]!=-1&&(cycidx[fr]+1)%ncyc==cycidx[at]) continue;
				mxreachidx[fr]=j; if(cycidx[fr]==-1) q[qhead++]=fr;
			}
		}
	}
	REP(i,n) mnreachidx[i]=-1;
	REP(j,ncyc) {
		qhead=qtail=0; q[qhead++]=cyc[j];
		while(qtail<qhead) {
			int at=q[qtail++];
			REPSZ(i,radj[at]) {
				int fr=radj[at][i]; if(!alive[fr]||mnreachidx[fr]!=-1||cycidx[fr]!=-1&&cycidx[at]!=-1&&(cycidx[fr]+1)%ncyc==cycidx[at]) continue;
				mnreachidx[fr]=j; if(cycidx[fr]==-1) q[qhead++]=fr;
			}
		}
	}
	REP(i,n) mxreachedbyidx[i]=-1;
	for(int j=ncyc-1;j>=0;--j) {
		qhead=qtail=0; q[qhead++]=cyc[j];
		while(qtail<qhead) {
			int at=q[qtail++];
			REPSZ(i,adj[at]) {
				int to=adj[at][i]; if(!alive[to]||mxreachedbyidx[to]!=-1||cycidx[to]!=-1&&cycidx[at]!=-1&&(cycidx[at]+1)%ncyc==cycidx[to]) continue;
				mxreachedbyidx[to]=j; if(cycidx[to]==-1) q[qhead++]=to;
			}
		}
	}
	//REP(i,n) printf("%d: mnreachidx=%d mxreachidx=%d mxreachedbyidx=%d\n",i+1,mnreachidx[i],mxreachidx[i],mxreachedbyidx[i]);

	int l=0,r=ncyc-1;
	REP(i,ncyc) { int at=cyc[i]; if(mxreachedbyidx[at]!=-1&&mxreachedbyidx[at]>=i) l=max(l,i); if(mnreachidx[at]!=-1&&mnreachidx[at]<=i) r=min(r,i); }
	if(l>r) return -1;

	ranges.clear();
	REP(i,ncyc) { int at=cyc[i]; if(mxreachidx[at]!=-1&&mxreachidx[at]>=i) ranges.PB(MP(at,cyc[mxreachidx[at]])); }
	//printf("ranges:"); REPSZ(i,ranges) printf(" %d-%d",ranges[i].first,ranges[i].second); puts("");

	REPE(i,ncyc) sum[i]=0;
	REPSZ(i,ranges) { int l=cycidx[ranges[i].first],r=cycidx[ranges[i].second]; swap(l,r); if(l<=r) ++sum[l],--sum[r+1]; else ++sum[0],--sum[r+1],++sum[l],--sum[ncyc]; }
	REP(i,ncyc) sum[i+1]+=sum[i];
	//printf("sum:"); REPE(i,ncyc) printf(" %d",sum[i]); puts("");
	REP(i,ncyc) if(l<=i&&i<=r&&sum[i]==SZ(ranges)) return cyc[i]+1;
	return -1;
}

void run() {
	scanf("%d%d",&n,&m); REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); radj[b].PB(a); }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}