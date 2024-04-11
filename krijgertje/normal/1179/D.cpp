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

const int MAXN=500000;

int n;
vector<int> adj[MAXN];

int par[MAXN];
int sz[MAXN];
ll mem[MAXN];

void dfsinit(int at) {
	sz[at]=1;
	REPSZ(i,adj[at]) { int to=adj[at][i]; if(to==par[at]) continue; par[to]=at; dfsinit(to); sz[at]+=sz[to]; }
}

pair<ll,ll> q[MAXN]; int qhead,qtail;
pair<int,ll> opt[MAXN]; int nopt;

ll eval(const pair<ll,ll> &z,int x) { return z.first*x+z.second; }
ll overtake(const pair<ll,ll> &a,const pair<ll,ll> &b) { 
	assert(a.first>b.first); assert(a.second<b.second);
	return (b.second-a.second+a.first-b.first-1)/(a.first-b.first);
}

pair<ll,ll> dfscalc(int at) { // first is partial path, second is full path
	pair<ll,ll> ret=MP((ll)sz[at]*sz[at],(ll)n*n);
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]) continue;
		pair<ll,ll> sub=dfscalc(to);
		ret.first=min(ret.first,(ll)(sz[at]-sz[to])*(sz[at]-sz[to])+sub.first);
		ret.second=min(ret.second,sub.second);
		ret.second=min(ret.second,(ll)(n-sz[to])*(n-sz[to])+sub.first);
		mem[to]=sub.first;
	}
	nopt=0; REPSZ(i,adj[at]) { int to=adj[at][i]; if(to==par[at]) continue; opt[nopt++]=MP(sz[to],mem[to]); }
	//REPSZ(i,opt) FORSZ(j,i+1,opt) { ll cur=opt[i].second+opt[j].second+(ll)(n-opt[i].first-opt[j].first)*(n-opt[i].first-opt[j].first); ret.second=min(ret.second,cur); }
	REP(i,nopt) { int x=opt[i].first; ll y=opt[i].second; opt[i].second=y+(ll)x*x-(ll)2*n*x; } sort(opt,opt+nopt);
	qhead=qtail=0;
	REP(i,nopt) {
		int x=opt[i].first; ll y=opt[i].second;
		while(qhead-2>=qtail&&eval(q[qhead-2],x)<=eval(q[qhead-1],x)) --qhead;
		if(qhead-1>=qtail) {
			ll cur=eval(q[qhead-1],x)+y+(ll)n*n; 
			//printf("evalating (%d,%lld) -> cur=%lld\n",x,y,cur); 
			ret.second=min(ret.second,cur); 
		}
		pair<ll,ll> z=MP(2LL*x,y);
		//printf("pushing (%lld,%lld)\n",z.first,z.second);
		bool ok=true;
		while(true) {
			if(qhead-1>=qtail&&z.second>=q[qhead-1].second) { ok=false; break; }
			if(qhead-2>=qtail&&overtake(z,q[qhead-1])>=overtake(q[qhead-1],q[qhead-2])) { --qhead; continue; }
			break;
		}
		if(ok) q[qhead++]=z;
	}
	
	//if(par[at]==-1) { printf("%d: ret: (%lld,%lld) opt:",at+1,ret.first,ret.second); REP(i,nopt) printf(" (%d,%lld)",opt[i].first,opt[i].second); puts(""); }
	return ret;
}

ll solve() {
	if(n==2) return 2;
	int root=-1; REP(at,n) if(SZ(adj[at])>=2) { root=at; break; } assert(root!=-1);
	par[root]=-1; dfsinit(root);
	ll ret=0;
	REP(at,n) {
		ret+=(ll)sz[at]*sz[at]-1;
		REPSZ(i,adj[at]) { int to=adj[at][i]; if(to==par[at]) continue; ret-=(ll)sz[to]*sz[to]; }
	}
	ret+=(ll)n*n-dfscalc(root).second;
	assert(ret%2==0); ret/=2;
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	printf("%lld\n",solve());
}

void stress() {
	n=MAXN;
	REP(i,n-1) { int a=i,b=i+1; adj[a].PB(b); adj[b].PB(a); }
	ll have=solve();
	printf("have=%lld\n",have);
}

int main() {
	run();
	//stress();
	return 0;
}