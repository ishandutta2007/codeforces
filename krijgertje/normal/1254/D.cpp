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
#include <chrono>
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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=150000;
const int MAXLEVELS=18;
const int MAXQ=150000;
const int MOD=998244353;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { inc(a,MOD-b); }

int n,nq;
vector<int> adj[MAXN];
int qkind[MAXQ],qx[MAXQ],qv[MAXQ],qans[MAXQ];

bool alive[MAXN];
int sz[MAXN];

int centlevel[MAXN];
int centroid[MAXN][MAXLEVELS];
int subtree[MAXN][MAXLEVELS];
int allsz[MAXN][MAXLEVELS];

int centcontrib[MAXN];
int stcontrib[MAXN][MAXLEVELS];
int centsum[MAXN];

void dfssz(int at,int par) {
	sz[at]=1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(!alive[to]||to==par) continue;
		dfssz(to,at);
		sz[at]+=sz[to];
	}
}
int dfscentroid(int at,int par,int rootsz) {
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(!alive[to]||to==par) continue;
		if(2*sz[to]>rootsz) return dfscentroid(to,at,rootsz);
	}
	return at;
}
int calccentroid(int at) {
	dfssz(at,-1);
	return dfscentroid(at,-1,sz[at]);
}

void dfsinit(int at,int par,int level,int cent,int st) {
	centroid[at][level]=cent,subtree[at][level]=st,allsz[at][level]=1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		if(!alive[to]) { 
			int othlevel=centlevel[to];
			assert(othlevel<level&&centroid[at][othlevel]==to); 
			allsz[at][level]+=allsz[to][othlevel]-allsz[subtree[at][othlevel]][othlevel];
		} else {
			dfsinit(to,at,level,cent,st);
			allsz[at][level]+=allsz[to][level];
		}
	}
}

void decompose(int at,int level) {
	at=calccentroid(at);
	centlevel[at]=level,centroid[at][level]=at,subtree[at][level]=-1,allsz[at][level]=1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i];
		if(!alive[to]) {
			int othlevel=centlevel[to];
			assert(othlevel<level&&centroid[at][othlevel]==to); 
			allsz[at][level]+=allsz[to][othlevel]-allsz[subtree[at][othlevel]][othlevel];
		} else {
			dfsinit(to,at,level,at,to);
			allsz[at][level]+=allsz[to][level];
		}
	}
	assert(allsz[at][level]==n);
	alive[at]=false;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(!alive[to]) continue;
		decompose(to,level+1);
	}
}

int inv[MAXN+1];

void solve() {
	inv[1]=1; FORE(i,2,n) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	REP(i,n) alive[i]=true,centlevel[i]=-1;
	decompose(0,0);
	memset(centcontrib,0,sizeof(centcontrib));
	memset(stcontrib,0,sizeof(stcontrib));
	memset(centsum,0,sizeof(centsum));
	REP(i,nq) {
		if(qkind[i]==1) {
			int at=qx[i],val=qv[i];
			for(int level=0;;++level) {
				int cent=centroid[at][level],st=subtree[at][level];
				if(cent!=at) {
					int cur=(ll)val*allsz[at][level]%MOD*inv[n]%MOD;
					inc(centcontrib[cent],cur);
					dec(stcontrib[st][level],cur);
				} else {
					inc(centsum[cent],val);
					break;
				}
			}
		}
		if(qkind[i]==2) {
			int at=qx[i]; qans[i]=0;
			for(int level=0;;++level) {
				int cent=centroid[at][level],st=subtree[at][level];
				if(cent!=at) {
					inc(qans[i],centcontrib[cent]);
					inc(qans[i],stcontrib[st][level]);
					int cur=(ll)centsum[cent]*(allsz[cent][level]-allsz[st][level])%MOD*inv[n]%MOD;
					inc(qans[i],cur);
				} else {
					inc(qans[i],centcontrib[cent]);
					inc(qans[i],centsum[cent]);
					break;
				}
			}

		}
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	REP(i,nq) {
		scanf("%d",&qkind[i]);
		if(qkind[i]==1) scanf("%d%d",&qx[i],&qv[i]),--qx[i];
		if(qkind[i]==2) scanf("%d",&qx[i]),--qx[i];
	}
	solve();
	REP(i,nq) if(qkind[i]==2) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}