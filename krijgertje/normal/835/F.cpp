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

const int MAXN=200000;

int n;
vector<pair<int,int> > adj[MAXN];

bool been[MAXN];

int cyc[2*MAXN],cyclen[2*MAXN],ncyc;
ll tmx[2*MAXN];
ll dsum[2*MAXN];

set<pair<ll,int> > lt,rt;

int dfscyc(int at,int par) {
	been[at]=true;
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first; if(to==par) continue;
		int cur=been[to]?to:dfscyc(to,at);
		if(cur>=0) cyc[ncyc]=at,cyclen[ncyc]=adj[at][i].second,++ncyc;
		if(cur==at) cur=-2;
		if(cur!=-1) return cur;
	}
	return -1;
}

pair<ll,ll> dfslen(int at,int par) {
	//printf("dfslen(%d,%d)\n",at,par);
	pair<ll,ll> ret=MP(0,0);
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first; if(to==par) continue;
		pair<ll,ll> cur=dfslen(to,at); cur.first+=adj[at][i].second;
		ret.second=max(ret.second,max(cur.second,ret.first+cur.first));
		ret.first=max(ret.first,cur.first);
	}
	return ret;
}

ll calc() {
	auto ait=lt.end(); --ait; pair<ll,int> a1=*ait; --ait; pair<ll,int> a2=*ait;
	auto bit=rt.end(); --bit; pair<ll,int> b1=*bit; --bit; pair<ll,int> b2=*bit;
	ll ret=0;
	if(a1.second!=b1.second) ret=max(ret,a1.first+b1.first);
	if(a1.second!=b2.second) ret=max(ret,a1.first+b2.first);
	if(a2.second!=b1.second) ret=max(ret,a2.first+b1.first);
	if(a2.second!=b2.second) ret=max(ret,a2.first+b2.first);
	return ret;
}

ll solve() {
	REP(i,n) been[i]=false; ncyc=0;
	assert(dfscyc(0,-1)==-2);
	//printf("cyc:"); REP(i,ncyc) printf(" (%d) %d",cyclen[i],cyc[i]+1); puts("");

	ll bound=0;
	REP(i,ncyc) {
		int at=cyc[i]; tmx[i]=0;
		REPSZ(j,adj[at]) {
			int to=adj[at][j].first; if(to==cyc[(i+1)%ncyc]||to==cyc[(i+ncyc-1)%ncyc]) continue; 
			pair<ll,ll> cur=dfslen(to,at); cur.first+=adj[at][j].second;
			bound=max(bound,max(cur.second,tmx[i]+cur.first));
			tmx[i]=max(tmx[i],cur.first);
		}
	}
	//printf("cyc:"); REP(i,ncyc) printf(" (%d) %d=%lld",cyclen[i],cyc[i]+1,tmx[i]); puts("");

	REP(i,ncyc) cyc[ncyc+i]=cyc[i],cyclen[ncyc+i]=cyclen[i],tmx[ncyc+i]=tmx[i];
	dsum[0]=0; REP(i,2*ncyc-1) dsum[i+1]=dsum[i]+cyclen[i+1];
	//printf("dsum:"); REP(i,2*ncyc) printf(" %lld",dsum[i]); puts("");

	ll ret=LLONG_MAX; lt.clear(); rt.clear();
	REP(i,ncyc) lt.insert(MP(tmx[i]-dsum[i],i)),rt.insert(MP(tmx[i]+dsum[i],i));
	REP(i,ncyc) {
		ll cur=calc();
		if(cur<ret) ret=cur;
		lt.erase(MP(tmx[i]-dsum[i],i)),rt.erase(MP(tmx[i]+dsum[i],i));
		lt.insert(MP(tmx[ncyc+i]-dsum[ncyc+i],ncyc+i)),rt.insert(MP(tmx[ncyc+i]+dsum[ncyc+i],ncyc+i));
	}
	return max(ret,bound);
}


void run() {
	scanf("%d",&n);
	REP(i,n) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; adj[a].PB(MP(b,c)); adj[b].PB(MP(a,c)); }
	printf("%lld\n",solve());
}

int find(vector<int> &par,int x) { if(par[x]<0) return x; return par[x]=find(par,par[x]); }
void unite(vector<int> &par,int a,int b) { a=find(par,a); b=find(par,b); if(a==b) return; if(-par[a]<-par[b]) swap(a,b); par[a]+=par[b]; par[b]=a; }

ll bfcalc(int a,int b) {
	vector<vector<int> > d(n,vector<int>(n,INT_MAX)); REP(i,n) d[i][i]=0;
	REP(at,n) REPSZ(i,adj[at]) {
		int to=adj[at][i].first; if(at==a&&to==b||at==b&&to==a) continue;
		d[at][to]=min(d[at][to],adj[at][i].second);
	}
	REP(k,n) REP(i,n) REP(j,n) if(d[i][k]!=INT_MAX&&d[k][j]!=INT_MAX) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	int ret=0; REP(i,n) REP(j,n) ret=max(ret,d[i][j]); return ret;
}

ll bf() {
	ll ret=LLONG_MAX;
	REP(i,n) REPSZ(j,adj[i]) {
		int k=adj[i][j].first; if(i>k) continue;
		ll cur=bfcalc(i,k); if(cur<ret) ret=cur;
	}
	return ret;
}

void stress() {
	REP(rep,1000) {
		n=10;
		REP(i,n) adj[i].clear();
		vector<int> par(n); REP(i,n) par[i]=-1; set<pair<int,int> > have;
		REP(i,n-1) {
			while(true) {
				int a=rand()%n,b=rand()%n;
				if(find(par,a)==find(par,b)) continue;
				int c=rand()%10+1;
				adj[a].PB(MP(b,c)); adj[b].PB(MP(a,c));
				unite(par,a,b); have.insert(MP(a,b)); have.insert(MP(b,a)); break;
			}
		}
		while(true) { int a=rand()%n,b=rand()%n; if(a==b||have.count(MP(a,b))) continue; int c=rand()%10+1; adj[a].PB(MP(b,c)); adj[b].PB(MP(a,c)); break; }
		ll ans=solve();
		ll chk=bf();
		if(ans!=chk) {
			printf("rep%d: have=%lld want=%lld\n",rep,ans,chk);
			printf("%d\n",n);
			REP(at,n) REPSZ(i,adj[at]) { int to=adj[at][i].first; if(at>to) continue; printf("%d %d %d\n",at+1,to+1,adj[at][i].second); }
			break;
		} else printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}