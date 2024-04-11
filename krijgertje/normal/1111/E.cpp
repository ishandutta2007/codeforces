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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN=100000;
const int MAXQ=100000;
const int MOD=1000000007;
const int MAXLIM=300;

struct T {
	int n;
	vector<int> adj[MAXN];
	T() { n=0; }
	void reset() { REP(i,n) adj[i].clear(); n=0; }
	int addnode() { int ret=n++; adj[ret].clear(); return ret; }
	void addedge(int a,int b) { adj[a].PB(b),adj[b].PB(a); }
};

struct LCA {
	int lgn;
	vector<int> dep;
	vector<vector<int>> up;
	
	void dfsinit(const T &t,int at,int par) {
		dep[at]=par==-1?0:dep[par]+1; up[at][0]=par==-1?at:par; REP(k,lgn) up[at][k+1]=up[up[at][k]][k];
		REPSZ(i,t.adj[at]) { int to=t.adj[at][i]; if(to==par) continue; dfsinit(t,to,at); }
	}
	
	void init(const T &t) {
		lgn=0; while((2<<lgn)<=t.n-1) ++lgn;
		dep=vector<int>(t.n,-1);
		up=vector<vector<int>>(t.n,vector<int>(lgn+1,-1));
		dfsinit(t,0,-1);
	}
	int calc(int a,int b) {
		if(dep[a]<dep[b]) swap(a,b);
		for(int k=lgn;k>=0;--k) if(dep[a]-(1<<k)>=dep[b]) a=up[a][k];
		for(int k=lgn;k>=0;--k) if(up[a][k]!=up[b][k]) a=up[a][k],b=up[b][k];
		return a==b?a:up[a][0];
	}
};

struct TreeCompressor {
	vector<int> preidx,dep;
	LCA lca;
	
	void dfsinit(const T &t,int at,int par,int &npre) {
		preidx[at]=npre++; dep[at]=par==-1?0:dep[par]+1;
		REPSZ(i,t.adj[at]) { int to=t.adj[at][i]; if(to==par) continue; dfsinit(t,to,at,npre); }
	}
	
	void init(const T &t) {
		preidx=dep=vector<int>(t.n,-1);
		int npre=0; dfsinit(t,0,-1,npre);
		lca.init(t);
	}
	
	vector<int> build(const vector<int> &nodes,T &result) {
		vector<pair<int,int>> o; REPSZ(i,nodes) o.PB(MP(preidx[nodes[i]],i)); sort(o.begin(),o.end());
		vector<int> ret(SZ(nodes),-1); result.reset(); vector<pair<int,int>> path;
		int root=0,rootid=result.addnode(); path.PB(MP(root,rootid));
		REPSZ(i,o) {
			int idx=o[i].second,at=nodes[idx];
			int x=lca.calc(at,path[SZ(path)-1].first);
			while(SZ(path)>=2&&dep[x]<=dep[path[SZ(path)-2].first]) { result.addedge(path[SZ(path)-2].second,path[SZ(path)-1].second); path.pop_back(); }
			if(dep[x]<dep[path[SZ(path)-1].first]) { int xid=result.addnode(); result.addedge(xid,path[SZ(path)-1].second); path.pop_back(); path.PB(MP(x,xid)); }
			if(dep[at]>dep[x]) { int atid=result.addnode(); path.PB(MP(at,atid)); }
			ret[idx]=path[SZ(path)-1].second;
		}
		while(SZ(path)>=2) { result.addedge(path[SZ(path)-2].second,path[SZ(path)-1].second); path.pop_back(); }
		return ret;
	}
};

T t;
int nq;
vector<int> qmarked[MAXQ]; int qlim[MAXQ],qroot[MAXQ]; int qans[MAXQ];

TreeCompressor compressor;
T tcompressed;

void dfscompressed(int at,int par,const vector<bool> &marked,vector<int> &pre,vector<int> &cnt,int &npre) {
	pre[npre++]=at; cnt[at]=par==-1?0:cnt[par]+(marked[par]?1:0);
	REPSZ(i,tcompressed.adj[at]) { int to=tcompressed.adj[at][i]; if(to==par) continue; dfscompressed(to,at,marked,pre,cnt,npre); }
}


void solve() {
	compressor.init(t);
	REP(i,nq) {
		vector<int> special; special.PB(qroot[i]); REPSZ(j,qmarked[i]) special.PB(qmarked[i][j]);
		vector<int> mapping=compressor.build(special,tcompressed);
		vector<bool> marked(tcompressed.n,false); FORSZ(i,1,special) marked[mapping[i]]=true;
		vector<int> pre(tcompressed.n,-1),cnt(tcompressed.n,-1); int npre=0; dfscompressed(mapping[0],-1,marked,pre,cnt,npre); assert(npre==SZ(pre));
		vector<int> ways(qlim[i]+1,0); ways[0]=1; REPSZ(j,pre) { int at=pre[j]; if(!marked[at]) continue; for(int k=qlim[i];k>=0;--k) ways[k]=((k==0?0:ways[k-1])+(ll)max(0,k-cnt[at])*ways[k])%MOD; }
		qans[i]=0; REPSZ(k,ways) qans[i]=(qans[i]+ways[k])%MOD;
	}
}

void run() {
	scanf("%d%d",&t.n,&nq);
	REP(i,t.n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; t.adj[a].PB(b),t.adj[b].PB(a); }
	REP(i,nq) { int qcnt; scanf("%d%d%d",&qcnt,&qlim[i],&qroot[i]),--qroot[i]; qmarked[i]=vector<int>(qcnt); REP(j,qcnt) scanf("%d",&qmarked[i][j]),--qmarked[i][j]; }
	solve();
	REP(i,nq) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}