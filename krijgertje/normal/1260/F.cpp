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

const int MAXN=100000;
const int MOD=1000000007;
const int MAXLEVEL=16;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { inc(a,MOD-b); }
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
int inv(int x) { return pw(x,MOD-2); }
struct E { int t,at,by; E() {} E(int t,int at,int by):t(t),at(at),by(by) {} };
bool operator<(const E &a,const E &b) { return a.t<b.t; }

int n;
int lcol[MAXN],rcol[MAXN];
vector<int> adj[MAXN];

bool alive[MAXN];
int sz[MAXN];
int cent[MAXN][MAXLEVEL+1];
int subt[MAXN][MAXLEVEL+1];
int dep[MAXN][MAXLEVEL+1];

void dfssz(int at,int par) {
	sz[at]=1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(!alive[to]||to==par) continue;
		dfssz(to,at); sz[at]+=sz[to];
	}
}
int dfscentroid(int at,int par,int rootsz) {
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(!alive[to]||to==par) continue;
		if(2*sz[to]>rootsz) return dfscentroid(to,at,rootsz);
	}
	return at;
}
int centroid(int at) {
	dfssz(at,-1);
	return dfscentroid(at,-1,sz[at]);
}
void dfsdecompose(int at,int par,int lvl,int ct,int st) {
	cent[at][lvl]=ct,subt[at][lvl]=st,dep[at][lvl]=dep[par][lvl]+1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(!alive[to]||to==par) continue;
		dfsdecompose(to,at,lvl,ct,st);
	}
}
void decompose(int at,int lvl) {
	int ct=centroid(at);
	//printf("decomposing (%d,%d) -> ct=%d\n",at+1,lvl,ct+1);
	cent[ct][lvl]=ct,subt[ct][lvl]=-1,dep[ct][lvl]=0;
	REPSZ(i,adj[ct]) {
		int to=adj[ct][i]; if(!alive[to]) continue;
		int st=lvl==0||dep[to][0]>dep[ct][0]?to:ct;
		dfsdecompose(to,ct,lvl,ct,st);
	}
	alive[ct]=false;
	REPSZ(i,adj[ct]) {
		int to=adj[ct][i]; if(!alive[to]) continue;
		decompose(to,lvl+1);
	}
}

int weight[MAXN];

int gsum,gmlt;
int centwsum[MAXN],centwdsum[MAXN];
int subtwsum[MAXN],subtwdsum[MAXN];


void mod(int at,int by) {
	REPE(lvl,MAXLEVEL) {
		int ct=cent[at][lvl],st=subt[at][lvl],d=dep[at][lvl],w=weight[at],wd=(ll)w*d%MOD;
		if(ct==-1) break;
		int wsum=centwsum[ct]; if(st!=-1) wsum+=MOD-subtwsum[st];
		int wdsum=centwdsum[ct]; if(st!=-1) wdsum+=MOD-subtwdsum[st];
		int delta=((ll)wd*wsum+(ll)w*wdsum)%MOD;
		//printf("changing %d at level %d (by=%d) -> delta=%d (%d,%d,%d,%d) [%d]\n",at+1,lvl,by,(int)((ll)delta*gmlt%MOD),wd,wsum%MOD,w,wdsum%MOD,st);
		if(by==+1) {
			inc(gsum,delta);
			inc(centwsum[ct],w); if(st!=-1) inc(subtwsum[st],w);
			inc(centwdsum[ct],wd); if(st!=-1) inc(subtwdsum[st],wd);
		} else {
			dec(gsum,delta);
			dec(centwsum[ct],w); if(st!=-1) dec(subtwsum[st],w);
			dec(centwdsum[ct],wd); if(st!=-1) dec(subtwdsum[st],wd);
		}
	}
}

vector<E> e;

int solve() {
	REP(i,n) alive[i]=true;
	REP(i,n) REPE(lvl,MAXLEVEL) cent[i][lvl]=-1;
	decompose(0,0);
	
	gsum=0,gmlt=1;
	REP(i,n) centwsum[i]=centwdsum[i]=subtwsum[i]=subtwdsum[i]=0;
	REP(i,n) { int ncol=rcol[i]-lcol[i]+1; gmlt=(ll)gmlt*ncol%MOD; weight[i]=inv(ncol); }
	
	e.clear();
	REP(i,n) e.PB(E(lcol[i],i,+1)),e.PB(E(rcol[i]+1,i,-1));
	sort(e.begin(),e.end());
	int pt=-1,ret=0;
	for(int l=0,r=l;l<SZ(e);l=r) {
		int t=e[l].t;
		if(gsum!=0) {
			int cur=(ll)gmlt*gsum%MOD;
			//printf("t=[%d..%d] -> %d\n",pt,t-1,cur);
			ret=(ret+(ll)(t-pt)*cur)%MOD;
		}
		while(r<SZ(e)&&e[r].t==t) ++r;
		FOR(i,l,r) mod(e[i].at,e[i].by);
		pt=t;
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&lcol[i],&rcol[i]);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}