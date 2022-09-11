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
const int MAXQ=100000;

int n,nq;
int par[MAXN]; vector<int> ch[MAXN];
int slim[MAXN];
int q[MAXN];
int ans[MAXQ];

int top[MAXN],ntop;
void dfstop(int at) {
	top[ntop++]=at;
	REPSZ(i,ch[at]) { int to=ch[at][i]; dfstop(to); }
}

int cdispl;
int clim[MAXN];
bool away[MAXN];
int delta[MAXN];

bool marked[MAXN];
int cmarked[MAXN];
int path[MAXN],parpath[MAXN];


vector<pair<int,int> > freq[MAXN]; int off[MAXN],freqidx[MAXN]; // freq[i][freqidx[i]].first+off[i]>=0

vector<int> byclim[2*MAXN+1];

void process(int l,int r) {
	//printf("processing %d..%d\n",l,r);
	//printf("state:"); REP(i,n) if(away[i]) printf(" [%d]",clim[i]); else printf(" %d",clim[i]); printf(" -> %d\n",cdispl);
	REP(i,n) marked[i]=false,cmarked[i]=0;
	FOR(i,l,r) { int id=abs(q[i])-1; marked[id]=true; }
	for(int i=ntop-1;i>=0;--i) { int at=top[i]; if(par[at]==-1) continue; if(marked[at]||cmarked[at]>0) ++cmarked[par[at]]; }
	REP(i,n) if(cmarked[i]>=2) marked[i]=true;
	REP(i,n) path[i]=marked[i]?i:-1,parpath[i]=-1;
	for(int i=ntop-1;i>=0;--i) { int at=top[i]; if(par[at]==-1||path[at]==-1) continue; if(marked[par[at]]) parpath[path[at]]=path[par[at]]; else path[par[at]]=path[at]; }

	REP(i,n) if(!marked[i]&&path[i]!=-1&&!away[i]) byclim[clim[i]+n].PB(i);
	FORE(i,-n,+n) REPSZ(j,byclim[n+i]) {
		int at=byclim[n+i][j],p=path[at];
		if(SZ(freq[p])==0||freq[p][SZ(freq[p])-1].first!=clim[at]) freq[p].PB(MP(clim[at],1)); else ++freq[p][SZ(freq[p])-1].second;
	}
	REPE(i,2*n) byclim[i].clear();
	REP(i,n) if(marked[i]) {
		off[i]=0;
		freqidx[i]=0; while(freqidx[i]<SZ(freq[i])&&freq[i][freqidx[i]].first<0) ++freqidx[i];
	}
	//REP(i,n) if(marked[i]) { printf("%d:",i); REPSZ(j,freq[i]) printf(" %d*%d",freq[i][j].second,freq[i][j].first); puts(""); }

	REP(i,n) delta[i]=0;
	FOR(i,l,r) {
		int id=abs(q[i])-1,by=away[id]?+1:-1;
		assert(marked[id]&&id==path[id]);
		for(int p=path[id];p!=-1;p=parpath[p]) {
			if(by==-1&&freqidx[p]<SZ(freq[p])&&freq[p][freqidx[p]].first+off[p]==0) { cdispl+=freq[p][freqidx[p]].second; ++freqidx[p]; }
			if(by==-1&&!away[p]&&clim[p]+off[p]==0) ++cdispl;
			off[p]+=by;
			if(by==+1&&freqidx[p]-1>=0&&freq[p][freqidx[p]-1].first+off[p]==0) { cdispl-=freq[p][freqidx[p]-1].second; --freqidx[p]; }
			if(by==+1&&!away[p]&&clim[p]+off[p]==0) --cdispl;
		}
		if(by==-1&&clim[id]+off[id]<0) --cdispl;
		if(by==+1&&clim[id]+off[id]<0) ++cdispl;
		ans[i]=cdispl;
		delta[id]+=by; away[id]=!away[id];
	}
	REP(i,n) freq[i].clear();

	// update clim+away
	for(int i=ntop-1;i>=0;--i) { int at=top[i]; if(par[at]!=-1) delta[par[at]]+=delta[at]; }
	REP(i,n) clim[i]+=delta[i];
}

void run() {
	scanf("%d%d",&n,&nq);
	par[0]=-1; FOR(i,1,n) { scanf("%d",&par[i]); --par[i]; }
	REP(i,n) scanf("%d",&slim[i]);
	REP(i,nq) scanf("%d",&q[i]);

	REP(i,n) if(par[i]!=-1) ch[par[i]].PB(i);
	ntop=0; dfstop(0);
	REP(i,n) clim[i]=slim[i],away[i]=false; cdispl=0;

	int bsz=(int)sqrt(1.0*nq);
	for(int i=0;i<nq;i+=bsz) process(i,min(i+bsz,nq));
	REP(i,nq) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}