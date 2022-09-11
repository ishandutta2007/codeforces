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

struct SegTree {
	int n;
	vector<ll> lazy;
	vector<pair<ll,int>> val;

	void _apply(int x,ll by) { lazy[x]+=by; val[x].first+=by; }
	void _push(int x) { if(lazy[x]!=0) _apply(2*x+1,lazy[x]),_apply(2*x+2,lazy[x]),lazy[x]=0; }
	void _pull(int x) { val[x]=max(val[2*x+1],val[2*x+2]); }
	void init(int _n) { n=_n; assert(n>=1); lazy=vector<ll>(4*n,0LL); val=vector<pair<ll,int>>(4*n,MP(0LL,0)); }
	void _update(int x,int l,int r,int L,int R,pair<ll,int> BY) {
		//printf("_update(%d,%d..%d,%d..%d,%lld)\n",x,l,r,L,R,BY);
		if(L<=l&&r<=R) {
			_apply(x,BY.first); if(BY.second!=-1) { assert(l==r); val[x].second=BY.second; }
		} else {
			int m=l+(r-l)/2; _push(x);
			if(L<=m) _update(2*x+1,l,m,L,R,BY);
			if(m+1<=R) _update(2*x+2,m+1,r,L,R,BY);
			_pull(x);
		}
		//printf("_updated(%d,%d..%d,%d..%d,%lld)\n",x,l,r,L,R,BY);
	}
	void update(int l,int r,pair<ll,int> by) { assert(n>=1); _update(0,0,n-1,l,r,by); }
	void update(int l,int r,ll by) { assert(n>=1); _update(0,0,n-1,l,r,MP(by,-1)); }
	pair<ll,int> _get(int x,int l,int r,int L,int R) {
		if(L<=l&&r<=R) {
			return val[x];
		} else {
			int m=l+(r-l)/2; _push(x);
			if(m+1>R) return _get(2*x+1,l,m,L,R);
			if(L>m) return _get(2*x+2,m+1,r,L,R);
			return max(_get(2*x+1,l,m,L,R),_get(2*x+2,m+1,r,L,R));
		}
	}
	pair<ll,int> get(int l,int r) { assert(n>=1); return _get(0,0,n-1,l,r); }
	pair<ll,int> best() { assert(n>=1); return val[0]; }
};

const int MAXN=100000;
const int MAXLG=16;
const int MAXM=MAXN-1;
const int MAXQ=100000;

int n,nq; ll wlim;
int e[MAXM][2];
vector<int> adj[MAXN];
int exor[MAXM];
ll winit[MAXM];
int qidx[MAXQ]; ll qw[MAXQ]; ll qans[MAXQ];


ll wcur[MAXM];

int root[MAXN][MAXLG+1],subtree[MAXN][MAXLG+1],par[MAXN][MAXLG+1]; ll dist[MAXN][MAXLG+1]; int lpre[MAXN][MAXLG+1],rpre[MAXN][MAXLG+1];
int npre[MAXN][MAXLG+1]; SegTree subtreedist[MAXN][MAXLG+1];
set<pair<ll,int>> bestdist[MAXN][MAXLG+1];

bool alive[MAXN]; int sz[MAXN];
void dfssz(int at,int p) { sz[at]=1; REPSZ(i,adj[at]) { int id=adj[at][i],to=at^exor[id]; if(to==p||!alive[to]) continue; dfssz(to,at); sz[at]+=sz[to]; } }
int dfscentroid(int at,int p,int rootsz) { REPSZ(i,adj[at]) { int id=adj[at][i],to=at^exor[id]; if(to==p||!alive[to]) continue; if(2*sz[to]>rootsz) return dfscentroid(to,at,rootsz); } return at; }
int centroid(int at) { dfssz(at,-1); return dfscentroid(at,-1,sz[at]); }
void dfsinit(int at,int rt,int st,int k) {
	root[at][k]=rt,subtree[at][k]=st; lpre[at][k]=npre[st][k]++; subtreedist[st][k].update(lpre[at][k],lpre[at][k],MP(dist[at][k],at));
	//printf("\t\tdist %d=%lld\n",at,dist[at][k]);
	REPSZ(i,adj[at]) {
		int id=adj[at][i],to=at^exor[id]; if(to==par[at][k]||!alive[to]) continue;
		par[to][k]=at,dist[to][k]=dist[at][k]+wcur[id]; dfsinit(to,rt,st,k);
	}
	rpre[at][k]=npre[st][k]-1;
}
void decompose(int at,int k) {
	at=centroid(at);
	dfssz(at,-1);
	//printf("centroid at level %d = %d\n",k,at+1);
	
	root[at][k]=at,subtree[at][k]=at,par[at][k]=-1,dist[at][k]=0,lpre[at][k]=rpre[at][k]=0;
	bestdist[at][k].clear(); npre[at][k]=1; subtreedist[at][k].init(1); subtreedist[at][k].update(lpre[at][k],rpre[at][k],MP(dist[at][k],at)); bestdist[at][k].insert(subtreedist[at][k].best());
	REPSZ(i,adj[at]) {
		int id=adj[at][i],to=at^exor[id]; if(!alive[to]) continue;
		npre[to][k]=0; subtreedist[to][k].init(sz[to]); par[to][k]=at; dist[to][k]=wcur[id]; dfsinit(to,at,to,k); assert(npre[to][k]==sz[to]);
		bestdist[at][k].insert(subtreedist[to][k].best());
	}
	//printf("\tbestdist:"); for(auto it=bestdist[at][k].begin();it!=bestdist[at][k].end();++it) printf(" %d=%lld",it->second+1,it->first); puts("");
	alive[at]=false;
	REPSZ(i,adj[at]) { int id=adj[at][i],to=at^exor[id]; if(!alive[to]) continue; decompose(to,k+1); }
}

void update(int id,ll nval) {
	//printf("update (%d-%d) %lld\n",e[id][0]+1,e[id][1]+1,nval);
	ll delta=nval-wcur[id]; wcur[id]=nval;
	REP(side,2) { 
		int at=e[id][side];
		REPE(k,MAXLG) if(root[at][k]!=-1&&par[at][k]==e[id][1-side]) {
			int rt=root[at][k],st=subtree[at][k];
			pair<ll,int> oldbest=subtreedist[st][k].best();
			subtreedist[st][k].update(lpre[at][k],rpre[at][k],delta);
			pair<ll,int> newbest=subtreedist[st][k].best();
			if(newbest!=oldbest) { auto bestit=bestdist[rt][k].find(oldbest); assert(bestit!=bestdist[rt][k].end()); bestdist[rt][k].erase(bestit); bestdist[rt][k].insert(newbest); }
			//printf("updated %d on level %d: oldbest=(%lld,%d) newbest=(%lld,%d)\n",at+1,k,oldbest.first,oldbest.second+1,newbest.first,newbest.second+1);
		}
	}
}
pair<ll,int> farthest(int at) {
	pair<ll,int> ret=MP(0LL,at);
	REPE(k,MAXLG) if(root[at][k]!=-1) {
		int rt=root[at][k],st=subtree[at][k];
		pair<ll,int> skip=subtreedist[st][k].best();
		auto bestit=bestdist[rt][k].rbegin(); assert(bestit!=bestdist[rt][k].rend()); if(*bestit==skip) ++bestit; if(bestit==bestdist[rt][k].rend()) continue;
		//printf("farthest(%d) on level %d: skip=(%lld,%d) best=(%lld,%d)\n",at+1,k,skip.first,skip.second+1,bestit->first,bestit->second+1);
		assert(subtree[bestit->second][k]!=st); ll cdist=subtreedist[st][k].get(lpre[at][k],lpre[at][k]).first+bestit->first; if(cdist>ret.first) ret=MP(cdist,bestit->second);
	}
	return ret;
}


void solve() {
	REP(i,n) alive[i]=true;
	REP(i,n-1) wcur[i]=winit[i];
	memset(root,-1,sizeof(root)); decompose(0,0);
	ll last=0;
	REP(i,nq) {
		int id=(qidx[i]+last)%(n-1); ll w=(qw[i]+last)%wlim;
		update(id,w);
		pair<ll,int> a=farthest(0);
		pair<ll,int> b=farthest(a.second);
		last=qans[i]=b.first;
		//printf("farthest=(%d..%d)\n",a.second+1,b.second+1);
	}
}

void run() {
	scanf("%d%d%lld",&n,&nq,&wlim);
	REP(i,n-1) { int a,b; scanf("%d%d%lld",&a,&b,&winit[i]); --a,--b; e[i][0]=a,e[i][1]=b,exor[i]=a^b; adj[a].PB(i),adj[b].PB(i); }
	REP(i,nq) scanf("%d%lld",&qidx[i],&qw[i]);
	solve();
	REP(i,nq) printf("%lld\n",qans[i]);
}

int main() {
	run();
	return 0;
}