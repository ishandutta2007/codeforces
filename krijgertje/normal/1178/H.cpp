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

typedef struct MCMF {
	int n,m;
	vector<int> ghead,gnxt,gto,gcap; vector<int> gcost;
 
	vector<int> d; vector<int> bck; vector<int> pot; vector<int> flow;
 
	void init(int _n) { n=_n,m=0; ghead=vector<int>(n,-1); gnxt.clear(),gto.clear(),gcap.clear(),gcost.clear(); d=vector<int>(n); bck=vector<int>(n); pot=vector<int>(n,0); flow=vector<int>(n); }
	void addedge(int a,int b,int c,int d) {
		gnxt.PB(ghead[a]); ghead[a]=m; gto.PB(b); gcap.PB(c); gcost.PB(+d); ++m;
		gnxt.PB(ghead[b]); ghead[b]=m; gto.PB(a); gcap.PB(0); gcost.PB(-d); ++m;
		//printf("adding edge %d-%d with cap %d and cost %d\n",a,b,c,d);
	}
	// Assumes all initial edges with positive capacity have nonnegative cost
	// Assumes cost of edges is relatively small, so a list of queues is used instead of a priority queue
	pair<int,int> solve(int s,int t) {
		REP(i,n) pot[i]=0;
		pair<int,int> ret=MP(0,0);
		while(true) {
			
			REP(i,n) d[i]=INT_MAX,bck[i]=-1,flow[i]=0; d[s]=0,bck[s]=-2,flow[s]=INT_MAX;
			vector<vector<int>> q(1); q[0].PB(s);
			REPSZ(i,q) REPSZ(j,q[i]) {
				int cost=i,at=q[i][j];
				for(int x=ghead[at];x!=-1;x=gnxt[x]) if(gcap[x]>0) {
					int to=gto[x]; int rcost=gcost[x]+pot[at]-pot[to]; if(d[at]+rcost>=d[to]) continue;
					d[to]=d[at]+rcost; bck[to]=x^1; flow[to]=min(flow[at],gcap[x]); if(d[to]>=SZ(q)) q.resize(d[to]+1); q[d[to]].PB(to);
				}
			}
			if(d[t]==INT_MAX) break;
			assert(flow[t]>0);
			REP(i,n) if(d[i]!=INT_MAX) pot[i]+=d[i];
			ret.first+=flow[t],ret.second+=pot[t]*flow[t];
 
			//vector<int> path;
			for(int at=t;at!=s;at=gto[bck[at]]) {
				//path.PB(at);
				gcap[bck[at]]+=flow[t]; gcap[bck[at]^1]-=flow[t];
			}
			//path.PB(s); reverse(path.begin(),path.end());
			//printf("flow=%d each=%d path=",flow[t],pot[t]); REPSZ(i,path) printf(" %d",path[i]+1); puts("");
		}
		return ret;
	}
} MCMF;

const int MAXN=2*2200;
const int MAXVAL=1000000000;
struct Stock { int a,b; ll eval(int t) { return (ll)a*t+b; } };

int n;
Stock stock[MAXN];

pair<ll,int> opt[MAXN]; int nopt;
ll have[MAXN/2],need[MAXN/2];

int nid,sid,tid,lid[MAXN],zcid[MAXN],rid[MAXN],tcid[MAXN];
int zval[MAXN]; ll tval[MAXN]; int nzval,ntval;

MCMF g;

bool can(int t) {
	REP(i,n) opt[i]=MP(-stock[i].eval(t),stock[i].b);
	sort(opt,opt+n);
	REP(i,n) opt[i].first=-opt[i].first;
	nopt=0; REP(i,n) if(i==0||opt[i].second<opt[nopt-1].second) opt[nopt++]=opt[i];
	//printf("opt:"); REP(i,nopt) printf(" (%lld,%d)",opt[i].first,opt[i].second); puts("");
	REP(i,n/2) { int l=-1,h=nopt-1; assert(stock[i].b>=opt[h].second); while(l+1<h) { int m=l+(h-l)/2; if(stock[i].b>=opt[m].second) h=m; else l=m; } have[i]=opt[h].first; }
	REP(i,n/2) need[i]=stock[n/2+i].eval(t);
	sort(have,have+n/2); sort(need,need+n/2); REP(i,n/2) if(have[i]<need[i]) return false;
	return true;
}

pair<int,int> solve() {
	int l=-1,h=MAXVAL;
	if(!can(h)) return MP(-1,-1);
	while(l+1<h) { int m=l+(h-l)/2;	if(can(m)) h=m; else l=m; }
	int t=h;

	nzval=0; REP(i,n) zval[nzval++]=stock[i].b; sort(zval,zval+nzval); nzval=unique(zval,zval+nzval)-zval;
	ntval=0; REP(i,n) tval[ntval++]=stock[i].eval(t); sort(tval,tval+ntval); ntval=unique(tval,tval+ntval)-tval;
	nid=0; sid=nid++; tid=nid++; REP(i,n) lid[i]=nid++; REP(i,nzval) zcid[i]=nid++; REP(i,n) rid[i]=nid++; REP(i,ntval) tcid[i]=nid++;
	g.init(nid);
	REP(i,n/2) g.addedge(sid,lid[i],1,0);
	REP(i,n) { int zidx=lower_bound(zval,zval+nzval,stock[i].b)-zval; g.addedge(lid[i],zcid[zidx],n,1); g.addedge(zcid[zidx],lid[i],n,0); }
	REP(i,nzval-1) g.addedge(zcid[i+1],zcid[i],n,0);
	REP(i,n) g.addedge(lid[i],rid[i],n,0);
	REP(i,n) { int tidx=lower_bound(tval,tval+ntval,stock[i].eval(t))-tval; g.addedge(rid[i],tcid[tidx],n,1); g.addedge(tcid[tidx],rid[i],n,0); }
	REP(i,ntval-1) g.addedge(tcid[i+1],tcid[i],n,0);
	REP(i,n/2) g.addedge(rid[n/2+i],tid,1,0);
	pair<int,ll> res=g.solve(sid,tid);
	assert(res.first==n/2);

	return MP(t,(int)res.second);
}

void run() {
	scanf("%d",&n); n*=2;
	REP(i,n) scanf("%d%d",&stock[i].a,&stock[i].b);
	pair<int,int> ans=solve();
	if(ans.first==-1) printf("%d\n",-1); else printf("%d %d\n",ans.first,ans.second);
}

int main() {
	run();
	return 0;
}