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
#include <chrono>
#include <random>
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

const int MAXN=250000;
struct Res {
	vector<ll> cost; // cost[i] = cost to make degree of each node in subtree at most i, taking the parent edge into account as well
	vector<ll> extracost; // extracost[i] = extra cost to make the degree of each node in the subtree at most i, when the parent edge must be removed
};

struct Z {
	multiset<ll> small,large; ll sumsmall;

	void init() { small.clear(); large.clear(); sumsmall=0; }
	void add(ll val) { if(SZ(small)>0&&val<=*prev(small.end())) { small.insert(val); sumsmall+=val; } else { large.insert(val); } }
	void remove(ll val) { auto it=small.find(val); if(it!=small.end()) { sumsmall-=val; small.erase(it); return; } it=large.find(val); if(it!=large.end()) { large.erase(it); return; } assert(false); }
	void rebalance(int nsmall) {
		while(SZ(small)>nsmall) { auto it=prev(small.end()); large.insert(*it); sumsmall-=*it; small.erase(it); }
		while(SZ(small)<nsmall&&SZ(large)>0) { auto it=large.begin(); small.insert(*it); sumsmall+=*it; large.erase(it); }
	}
};

int n;
vector<pair<int,int>> adj[MAXN];
ll ans[MAXN];

Res res[MAXN];
Z z;

int dfs(int at,int par,int parcost) {
	vector<pair<int,int>> subs;
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first,edgecost=adj[at][i].second; if(to==par) continue;
		int sub=dfs(to,at,edgecost);
		subs.PB(MP(sub,edgecost));
	}

	int ret=-1;
	REPSZ(i,subs) { int sub=subs[i].first; if(ret==-1||SZ(res[sub].cost)>SZ(res[ret].cost)) ret=sub; }
	if(ret==-1) ret=at;

	REPSZ(i,subs) {
		int sub=subs[i].first; if(sub==ret) continue;
		REPSZ(j,res[sub].cost) { assert(j<SZ(res[ret].cost)); res[ret].cost[j]+=res[sub].cost[j]; }
	}
	int deg=SZ(adj[at])+(par==-1?1:0);
	vector<ll> myextracost(deg,0);
	vector<vector<pair<ll,ll>>> changes(deg);
	z.init();
	REPSZ(i,subs) {
		int sub=subs[i].first,edgecost=subs[i].second;
		ll prv=-1;
		REP(j,deg) {
			ll cur=j<SZ(res[sub].extracost)?res[sub].extracost[j]:edgecost;
			if(j!=0&&prv!=cur) changes[j-1].PB(MP(cur,prv));
			prv=cur; if(j>=SZ(res[sub].extracost)) break;
		}
		z.add(prv);
		//if(at+1==4) printf("\tinitcost=%lld\n",prv);
	}
	while(SZ(res[ret].cost)<deg) res[ret].cost.PB(0);
	for(int i=deg-1;i>=0;--i) {
		REPSZ(j,changes[i]) { ll a=changes[i][j].first,b=changes[i][j].second; z.remove(a); z.add(b); }
		z.rebalance(deg-i-1);
		ll with=SZ(z.small)==deg-i-1?z.sumsmall+parcost:LLONG_MAX; assert(with!=LLONG_MAX);
		z.rebalance(deg-i);
		ll without=SZ(z.small)==deg-i?z.sumsmall:LLONG_MAX;
		ll best=min(with,without);
		res[ret].cost[i]+=best;
		myextracost[i]=with-best;
		if(at+1==4) {
			//printf("at=%d i=%d: with=%lld without=%lld\n",at+1,i,with,without);
			//REPSZ(j,changes[i]) printf("\t%lld->%lld\n",changes[i][j].first,changes[i][j].second);
		}
	}

	res[ret].extracost=myextracost;
	//printf("%d:",at+1); REPSZ(i,res[ret].cost) printf(" %lld",res[ret].cost[i]); printf(" |"); REPSZ(i,res[ret].extracost) printf(" %lld",res[ret].extracost[i]); puts("");
	return ret;
}

void solve() {
	REP(i,n) res[i].cost.clear(),res[i].extracost.clear();
	int idx=dfs(0,-1,0);
	REP(i,n) { ans[i]=0; if(i<SZ(res[idx].cost)) ans[i]+=res[idx].cost[i]; }
}

void run() {
	scanf("%d",&n);
	REP(i,n-1) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; adj[a].PB(MP(b,c)); adj[b].PB(MP(a,c)); }
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%lld",ans[i]); } puts("");
}

ll bfans[MAXN];

pair<ll,ll> dfsstupid(int at,int par,int parcost,int lim) { // (removed,exists)
	vector<ll> dp(lim+1,0);
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first,edgecost=adj[at][i].second; if(to==par) continue;
		pair<ll,ll> sub=dfsstupid(to,at,edgecost,lim);
		vector<ll> ndp(lim+1,LLONG_MAX);
		REPE(k,lim) {
			ndp[k]=min(ndp[k],dp[k]+edgecost+sub.first);
			if(sub.second!=LLONG_MAX&&k+1<=lim) ndp[k+1]=min(ndp[k+1],dp[k]+sub.second);
		}
		dp=ndp;
	}
	return MP(dp[lim],lim==0?LLONG_MAX:dp[lim-1]);
}

void solvestupid() {
	REP(i,n) bfans[i]=dfsstupid(0,-1,0,i).first;
}

void stress() {
	int mxn=20,mxc=10;
	std::mt19937 rnd(1321);
	REP(rep,100000) {
		n=rnd()%mxn+1;
		vector<int> comp(n); REP(i,n) comp[i]=i; REP(i,n) adj[i].clear();
		REP(i,n-1) while(true) { int a=rnd()%n,b=rnd()%n,c=rnd()%mxc+1; if(comp[a]==comp[b]) continue; int old=comp[b]; REP(j,n) if(comp[j]==old) comp[j]=comp[a]; adj[a].PB(MP(b,c)); adj[b].PB(MP(a,c)); break; }
		solve();
		solvestupid();
		bool ok=true; REP(i,n) if(ans[i]!=bfans[i]) ok=false;
		if(ok) { if(rep%100==99) printf("."); continue; }
		printf("err rep=%d\n",rep);
		printf("have:"); REP(i,n) printf(" %lld",ans[i]); puts("");
		printf("want:"); REP(i,n) printf(" %lld",bfans[i]); puts("");
		printf("%d\n",n);
		REP(at,n) REPSZ(i,adj[at]) { int to=adj[at][i].first,edgecost=adj[at][i].second; if(at<to) printf("%d %d %d\n",at+1,to+1,edgecost); }
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}