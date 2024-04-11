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

const int MAXN=500;

int n,npath;
vector<int> adj[MAXN];

bool isalive[MAXN];
vector<int> alivenodes;
bool stayalive[MAXN];

int state[MAXN],par[MAXN];
bool paredgeisoncycle[MAXN];
int cycleidx[MAXN]; // not for root
vector<int> rootofcycles[MAXN];
vector<vector<int>> cycles;

int cyccnt[MAXN],cycdist[MAXN]; // do not count root
int downcnt[MAXN],downdist[MAXN]; // down along tree-edges and cycles for which we are the root
int upcnt[MAXN],updist[MAXN]; // up along tree-edges and cycles for which we are not the root

void dfsinit(int at) {
	state[at]=1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(!isalive[to]||to==par[at]||state[to]==2) continue;
		if(state[to]==0) {
			par[to]=at; paredgeisoncycle[to]=false; dfsinit(to);
		} else {
			vector<int> cycle; int cur=at; while(true) { cycle.PB(cur); if(cur==to) break; assert(!paredgeisoncycle[cur]); paredgeisoncycle[cur]=true; cycleidx[cur]=SZ(cycles); cur=par[cur]; } reverse(cycle.begin(),cycle.end());
			cycles.PB(cycle); rootofcycles[to].PB(SZ(cycles)-1);
		}
	}
	state[at]=2;
}

void dfscalcdown(int at) {
	downdist[at]=0; downcnt[at]=1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(!isalive[to]||par[to]!=at||paredgeisoncycle[to]) continue;
		dfscalcdown(to);
		downcnt[at]+=downcnt[to]; downdist[at]+=downdist[to]+downcnt[to];
	}
	REPSZ(i,rootofcycles[at]) {
		int idx=rootofcycles[at][i],cyclen=SZ(cycles[idx]); cyccnt[idx]=0,cycdist[idx]=0;
		FOR(j,1,cyclen) {
			int to=cycles[idx][j];
			dfscalcdown(to);
			cyccnt[idx]+=downcnt[to]; cycdist[idx]+=downdist[to]+min(j,cyclen-j)*downcnt[to];
		}
		downcnt[at]+=cyccnt[idx],downdist[at]+=cycdist[idx];
	}
}
int calcrange(const vector<int> &sum,int l,int r) { int n=SZ(sum)-1; if(l>=n) return calcrange(sum,l-n,r-n); if(r>=n) return calcrange(sum,l,n-1)+calcrange(sum,0,r-n); return sum[r+1]-sum[l]; }
void dfscalcup(int at) {
	if(par[at]==-1||!paredgeisoncycle[at]) { updist[at]=0; upcnt[at]=1; }
	if(par[at]!=-1&&!paredgeisoncycle[at]) { int to=par[at]; upcnt[at]+=upcnt[to]+downcnt[to]-downcnt[at]-1; updist[at]+=updist[to]+upcnt[to]+downdist[to]-downdist[at]-downcnt[at]+downcnt[to]-downcnt[at]-1; }
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(!isalive[to]||par[to]!=at||paredgeisoncycle[to]) continue;
		dfscalcup(to);
	}
	REPSZ(i,rootofcycles[at]) {
		int idx=rootofcycles[at][i],cyclen=SZ(cycles[idx]);
		int sumdist=updist[at]+downdist[at]-cycdist[idx]; FOR(j,1,cyclen) { int to=cycles[idx][j]; sumdist+=downdist[to]; }
		vector<int> cnt(cyclen); cnt[0]=upcnt[at]+downcnt[at]-cyccnt[idx]-1; FOR(j,1,cyclen) { int to=cycles[idx][j]; cnt[j]=downcnt[to]; }
		vector<int> sum(cyclen+1); sum[0]=0; REP(j,cyclen) sum[j+1]=sum[j]+cnt[j];
		int cur=sumdist; FOR(j,1,cyclen) cur+=min(j,cyclen-j)*cnt[j];
		FOR(j,1,cyclen) {
			cur+=calcrange(sum,j+(cyclen+1)/2,j+cyclen-1)-calcrange(sum,j,j+cyclen/2-1);
			int to=cycles[idx][j]; updist[to]=cur-downdist[to]; upcnt[to]=sum[cyclen]-downcnt[to]+1; dfscalcup(to);
		}
	}
}
void dfsalive(int at,int skip) {
	stayalive[at]=true;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(!isalive[to]||par[to]!=at||paredgeisoncycle[to]) continue;
		if(to!=skip) dfsalive(to,skip);
	}
	REPSZ(i,rootofcycles[at]) {
		int idx=rootofcycles[at][i],cyclen=SZ(cycles[idx]); if(cycles[idx][1]==skip) continue;
		FOR(j,1,cyclen) { int to=cycles[idx][j]; dfsalive(to,skip); }
	}
}

int query(int at) {
	printf("%d\n",at+1); fflush(stdout);
	char buff[100]; scanf("%s",buff); if(strcmp(buff,"FOUND")==0) return -1; assert(strcmp(buff,"GO")==0); int ret; scanf("%d",&ret); --ret; return ret;
}

void solve() {
	//REP(i,n) { printf("adj%d:",i); REPSZ(j,adj[i]) printf(" %d",adj[i][j]+1); puts(""); }
	REP(i,n) isalive[i]=true;
	alivenodes.clear(); REP(i,n) alivenodes.PB(i);
	while(true) {
		assert(SZ(alivenodes)>=1); int root=alivenodes[0];
		cycles.clear(); REPSZ(i,alivenodes) { int at=alivenodes[i]; state[at]=0; rootofcycles[at].clear(); }
		par[root]=-1; paredgeisoncycle[root]=false; dfsinit(root);
		dfscalcdown(root);
		dfscalcup(root);
		//REPSZ(i,alivenodes) { int at=alivenodes[i]; printf("%d: par=%d%s(%d) down=%d,%d up=%d,%d",at+1,par[at]+1,paredgeisoncycle[at]?"c":"",cycleidx[at],downcnt[at],downdist[at],upcnt[at],updist[at]);  REPSZ(j,rootofcycles[at]) printf("%s%d",j==0?" root=":",",rootofcycles[at][j]); puts(""); }
		//REPSZ(i,cycles) { printf("cyc%d=%d,%d nodes:",i,cyccnt[i],cycdist[i]); REPSZ(j,cycles[i]) printf(" %d",cycles[i][j]+1); puts(""); }
		int best=-1; REPSZ(i,alivenodes) { int at=alivenodes[i]; if(best==-1||updist[at]+downdist[at]<updist[best]+downdist[best]) best=at; } assert(best!=-1);
		int nxt=query(best);
		if(nxt==-1) break;
		REPSZ(i,alivenodes) { int at=alivenodes[i]; stayalive[at]=false; }
		if(nxt==par[best]&&!paredgeisoncycle[best]) dfsalive(root,best);
		REPSZ(i,adj[best]) { int to=adj[best][i]; if(!isalive[to]||par[to]!=best||paredgeisoncycle[to]) continue; if(to==nxt) dfsalive(to,-1); }
		REP(rep,2) {
			int tmp=best,offset=0; if(rep==1) { if(!paredgeisoncycle[tmp]) continue; while(paredgeisoncycle[par[tmp]]&&cycleidx[par[tmp]]==cycleidx[tmp]) tmp=par[tmp],++offset; tmp=par[tmp],++offset; }
			REPSZ(i,rootofcycles[tmp]) {
				int idx=rootofcycles[tmp][i],cyclen=SZ(cycles[idx]); if(offset>=cyclen||cycles[idx][offset]!=best) continue;
				if(nxt==cycles[idx][(offset+1)%cyclen]) REP(j,cyclen) if(j!=offset&&(j-offset+cyclen)%cyclen<=(offset-j+cyclen)%cyclen) if(j==0) dfsalive(root,cycles[idx][1]); else dfsalive(cycles[idx][j],-1);
				if(nxt==cycles[idx][(offset+cyclen-1)%cyclen]) REP(j,cyclen) if(j!=offset&&(offset-j+cyclen)%cyclen<=(j-offset+cyclen)%cyclen) if(j==0) dfsalive(root,cycles[idx][1]); else dfsalive(cycles[idx][j],-1);
			}
		}
		vector<int> stayalivenodes; REPSZ(i,alivenodes) { int at=alivenodes[i]; isalive[at]=stayalive[at]; if(isalive[at]) stayalivenodes.PB(at); } assert(2*SZ(stayalivenodes)<=SZ(alivenodes)); alivenodes=stayalivenodes;
	}
}

void run() {
	scanf("%d%d",&n,&npath);
	REP(i,npath) { int len; scanf("%d",&len); vector<int> path(len); REP(j,len) scanf("%d",&path[j]); REP(j,len-1) { int a=path[j],b=path[j+1]; --a,--b; adj[a].PB(b); adj[b].PB(a); } }
	REP(i,n) solve();
}

int main() {
	run();
	return 0;
}