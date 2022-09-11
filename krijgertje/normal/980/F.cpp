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

const int MAXN=500000;

int n,m;
vector<int> adj[MAXN];

int par[MAXN];
int state[MAXN];
int comp[MAXN];
vector<int> cyc[MAXN];

void dfsinit(int at) {
	//printf("dfsinit(%d)\n",at+1);
	state[at]=1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]) continue;
		//printf("\t%d->%d\n",at+1,to+1);
		if(state[to]==0) {
			par[to]=at; dfsinit(to);
		} else if(state[to]==1) {
			for(int x=at;x!=to;x=par[x]) cyc[to].PB(x); cyc[to].PB(to); reverse(cyc[to].begin(),cyc[to].end());
			REPSZ(j,cyc[to]) assert(comp[cyc[to][j]]==-1); REPSZ(j,cyc[to]) comp[cyc[to][j]]=to;
		} else {
			assert(state[to]==2&&comp[to]==comp[at]);
		}
	}
	state[at]=2;
}

int dpdown[MAXN],downvia[MAXN],dpdown2[MAXN]; // dpdown[i] = maximum distance 'down' from i (choosing which edges in cycles to remove optimally). this includes the cycle only for the rootnode
int dpup[MAXN]; // dpup[i] = maximum distance 'up' from i (choosing which edges in cycles to remove optimally). this includes the cycle except for the rootnode

int tmp[2*MAXN];

void upddown(int at,int val,int via) { if(val>dpdown[at]) dpdown2[at]=dpdown[at],dpdown[at]=val,downvia[at]=via; else if(val>dpdown2[at]) dpdown2[at]=val; }
void dfsdown(int at) {
	dpdown[at]=0,downvia[at]=-1,dpdown2[at]=0;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]||(comp[at]!=-1&&comp[at]==comp[to])) continue;
		dfsdown(to);
		upddown(at,dpdown[to]+1,to);
	}
	if(comp[at]!=-1&&at==comp[at]) {
		assert(comp[at]==at&&SZ(cyc[at])>0&&cyc[at][0]==at);
		FORSZ(i,1,cyc[at]) { int to=cyc[at][i]; dfsdown(to); }
		FORSZ(i,1,cyc[at]) { int to=cyc[at][i]; tmp[i]=dpdown[to]; }
		int cycdown=0; FORSZ(i,1,cyc[at]) cycdown=max(cycdown,tmp[i]+min(i,SZ(cyc[at])-i)); upddown(at,cycdown,-2);
	}
	//printf("dpdown[%d]=%d via %d (2nd = %d)\n",at+1,dpdown[at],downvia[at]+1,dpdown2[at]);
}

struct MxQ {
	int lidx,ridx; char id;
	pair<int,int> q[2*MAXN]; int qtail,qhead;

	void clear() { lidx=ridx=qtail=qhead=0; }
	void push(int val) { /*printf("%c: pushing %d\n",id,val);*/ while(qtail<qhead&&q[qhead-1].second<val) --qhead; q[qhead++]=MP(ridx,val); ++ridx; }
	void pop() { /*printf("%c: popping\n",id);*/ ++lidx; while(qtail<qhead&&q[qtail].first<lidx) ++qtail; }
	int get(int off) { return qtail<qhead?q[qtail].second+off:INT_MIN; }
};

MxQ qa,qb;

void dfsup(int at) { // not called for non-root nodes of cycles
	dpup[at]=0;
	if(par[at]!=-1) {
		dpup[at]=max(dpup[at],1+dpup[par[at]]);
		dpup[at]=max(dpup[at],1+(downvia[par[at]]!=at?dpdown[par[at]]:dpdown2[par[at]]));
	}
	//printf("dpup[%d]=%d\n",at+1,dpup[at]);
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]||(comp[at]!=-1&&comp[at]==comp[to])) continue;
		dfsup(to);
	}
	if(comp[at]!=-1) {
		assert(comp[at]==at&&SZ(cyc[at])>0&&cyc[at][0]==at);
		REPSZ(i,cyc[at]) { tmp[i]=0; int u=cyc[at][i]; REPSZ(j,adj[u]) { int to=adj[u][j]; if(to==par[at]) tmp[i]=max(tmp[i],dpup[at]); else if(comp[to]!=at) tmp[i]=max(tmp[i],1+dpdown[to]); } }
		REPSZ(i,cyc[at]) tmp[i+SZ(cyc[at])]=tmp[i];
		//printf("cycup%d:",at+1); REPSZ(i,cyc[at]) printf(" %d",tmp[i]); puts("");
		qa.id='A'; qb.id='B'; qa.clear(); qb.clear(); int lsa=0,hsa=0,lsb=0,hsb=0;
		FORSZ(i,1,cyc[at]) {
			int u=cyc[at][i];
			//dpup[u]=0; FORSZ(j,1,cyc[at]) dpup[u]=max(dpup[u],tmp[i+j]+min(j,SZ(cyc[at])-j));
			// j<=SZ(cyc[at])-j -> j<=SZ(cyc[at])/2
			while(i+SZ(cyc[at])/2>=hsa) qa.push(tmp[hsa]+hsa),++hsa;
			while(lsa<=i) qa.pop(),++lsa;
			while(i+SZ(cyc[at])-1>=hsb) qb.push(tmp[hsb]+SZ(cyc[at])-hsb),++hsb;
			while(lsb<=i+SZ(cyc[at])/2) qb.pop(),++lsb;
			dpup[u]=max(qa.get(-i),qb.get(+i));
			//printf("dpup[%d]=%d [%d,%d]\n",u+1,dpup[u],qa.get(-i),qb.get(+i));
		}
		FORSZ(i,1,cyc[at]) { int u=cyc[at][i]; REPSZ(j,adj[u]) { int to=adj[u][j]; if(to!=par[at]&&comp[to]!=at) dfsup(to); } }
	}
}

int ans[MAXN];



void run() {
	scanf("%d%d",&n,&m); REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	
	REP(i,n) par[i]=-1,comp[i]=-1,state[i]=0;
	dfsinit(0);

	dfsdown(0);
	dfsup(0);
	REP(at,n) {
		ans[at]=0;
		ans[at]=max(ans[at],dpup[at]);
		if(comp[at]!=-1&&at==comp[at]) ans[at]=max(ans[at],dpdown[at]);
		REPSZ(i,adj[at]) {
			int to=adj[at][i];
			if(to!=par[at]&&(comp[at]==-1||comp[to]!=comp[at])) ans[at]=max(ans[at],1+dpdown[to]);
		}
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}