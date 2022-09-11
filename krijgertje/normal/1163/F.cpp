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
const int MAXM=200000;
const int MAXQ=200000;
struct E { int a,b,len,id; E() {} E(int a,int b,int len,int id):a(a),b(b),len(len),id(id) {} };

int n,m,nq;
E e[MAXM];
vector<int> adj[MAXN];
int qid[MAXQ],qc[MAXQ]; ll qans[MAXQ];

int pos[MAXM];
pair<ll,int> cost[MAXN];
priority_queue<pair<pair<ll,int>,int>> pq;
int prv[MAXN],prvedge[MAXN];

vector<int> path;
pair<ll,int> lcost[MAXN];
pair<ll,int> rcost[MAXN];

vector<pair<ll,pair<int,int>>> opt;
ll bestwithout[MAXM];

void dijkstra(int s) {
	REP(i,n) cost[i]=MP(LLONG_MAX,INT_MAX),prv[i]=-2,prvedge[i]=-2;
	pq=priority_queue<pair<pair<ll,int>,int>>();
	cost[s]=MP(0LL,-1),prv[s]=-1,prvedge[s]=-1; pq.push(MP(MP(-cost[s].first,-cost[s].second),-s));
	while(!pq.empty()) {
		ll dist=-pq.top().first.first; int mxused=-pq.top().first.second,at=-pq.top().second; pq.pop();
		if(cost[at]!=MP(dist,mxused)) continue;
		REPSZ(i,adj[at]) {
			int edgeid=adj[at][i]; int to=e[edgeid].a+e[edgeid].b-at; ll ndist=dist+e[edgeid].len; int nmxused=max(mxused,pos[edgeid]);
			if(ndist<cost[to].first||ndist==cost[to].first&&nmxused<cost[to].second) cost[to]=MP(ndist,nmxused),prv[to]=at,prvedge[to]=edgeid,pq.push(MP(MP(-cost[to].first,-cost[to].second),-to));
		}
	}
}

void solve() {
	REP(i,m) pos[i]=-1;
	dijkstra(0);
	assert(cost[n-1].first!=LLONG_MAX);
	path.clear(); for(int at=n-1;at>=0;at=prv[at]) path.PB(prvedge[at]); path.pop_back(); reverse(path.begin(),path.end());
	//printf("path:"); REPSZ(i,path) printf(" %d",path[i]+1); puts("");

	REP(i,m) pos[i]=-1; REPSZ(i,path) pos[path[i]]=i;
	dijkstra(0);
	REP(i,n) lcost[i]=cost[i];
	REP(i,m) pos[i]=-1; REPSZ(i,path) pos[path[i]]=SZ(path)-1-i;
	dijkstra(n-1);
	REP(i,n) rcost[i]=cost[i];
	REP(i,n) rcost[i].second=SZ(path)-1-rcost[i].second;
	//REP(i,n) printf("%d: lcost=(%lld,%d) rcost=(%lld,%d)\n",i+1,lcost[i].first,lcost[i].second+1,rcost[i].first,rcost[i].second+1);

	opt.clear();
	REP(i,m) pos[i]=-1; REPSZ(i,path) pos[path[i]]=i;
	REP(i,m) if(pos[i]==-1) {
		int a=e[i].a,b=e[i].b,c=e[i].len;
		REP(rep,2) {
			if(lcost[a].first!=LLONG_MAX&&rcost[b].first!=LLONG_MAX&&lcost[a].second+1<=rcost[b].second-1) opt.PB(MP(lcost[a].first+c+rcost[b].first,MP(lcost[a].second+1,rcost[b].second-1)));
			swap(a,b);
		}
	}
	sort(opt.begin(),opt.end());
	//printf("opt:"); REPSZ(i,opt) printf(" %d..%d=%lld",opt[i].second.first+1,opt[i].second.second+1,opt[i].first); puts("");
	REPSZ(i,path) bestwithout[i]=LLONG_MAX;
	set<int> rem; REPSZ(i,path) rem.insert(i);
	REPSZ(i,opt) {
		int l=opt[i].second.first,r=opt[i].second.second; ll val=opt[i].first;
		auto it=rem.lower_bound(l);
		while(it!=rem.end()&&*it<=r) {
			bestwithout[*it]=val;
			auto nit=next(it); rem.erase(it); it=nit;
		}
	}
	//printf("bestwithout:"); REPSZ(i,path) printf(" %lld",bestwithout[i]); puts("");

	REP(i,m) pos[i]=-1; REPSZ(i,path) pos[path[i]]=i;
	REP(i,nq) {
		qans[i]=LLONG_MAX;
		int edgeid=qid[i],edgecost=qc[i];
		if(pos[edgeid]==-1) {
			int a=e[edgeid].a,b=e[edgeid].b,c=edgecost;
			qans[i]=min(qans[i],lcost[n-1].first);
			if(lcost[a].first!=LLONG_MAX&&rcost[b].first!=LLONG_MAX) qans[i]=min(qans[i],lcost[a].first+c+rcost[b].first);
			if(lcost[b].first!=LLONG_MAX&&rcost[a].first!=LLONG_MAX) qans[i]=min(qans[i],lcost[b].first+c+rcost[a].first);
		} else {
			if(lcost[n-1].first!=LLONG_MAX) qans[i]=min(qans[i],lcost[n-1].first+edgecost-e[edgeid].len);
			if(bestwithout[pos[edgeid]]!=LLONG_MAX) qans[i]=min(qans[i],bestwithout[pos[edgeid]]);
		}
	}
}

void run() {
	scanf("%d%d%d",&n,&m,&nq);
	REP(i,m) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; e[i]=E(a,b,c,i); adj[a].PB(i); adj[b].PB(i); }
	REP(i,nq) scanf("%d%d",&qid[i],&qc[i]),--qid[i];
	solve();
	REP(i,nq) printf("%lld\n",qans[i]);
}

int main() {
	run();
	return 0;
}