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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

struct {
	int n,m;
	int fst[2000];
	int to[4000000];
	int nxt[4000000];

	int nid;
	int id[2000];
	int id2node[2000];
	int par[2000];
	int paredge[2000];

	bool been[2000];
	bool isbridge[2000000];

	int ncomp;
	int comp[2000];
	
	void init(int n) { this->n=n; m=0; REP(i,n) fst[i]=-1; }
	void addedge(int a,int b) {
		to[2*m+0]=b; nxt[2*m+0]=fst[a]; fst[a]=2*m+0;
		to[2*m+1]=a; nxt[2*m+1]=fst[b]; fst[b]=2*m+1;
		++m;
	}
	void iddfs(int at) {
		id[at]=nid; id2node[nid]=at; ++nid;
		for(int x=fst[at];x!=-1;x=nxt[x]) if(id[to[x]]==-1) { par[to[x]]=at; paredge[to[x]]=x^1; iddfs(to[x]); }
	}
	void calcbridges() {
		nid=0; REP(i,n) par[i]=paredge[i]=-1,id[i]=-1; iddfs(0);
		REP(i,m) isbridge[i]=true;
		REP(i,n) been[i]=false;
		REP(i,n) {
			int at=id2node[i]; been[at]=true;
			for(int x=fst[at];x!=-1;x=nxt[x]) {
				if(to[x]==par[at]||par[to[x]]==at) continue;
				if(id[to[x]]<id[at]) continue;
				isbridge[x>>1]=false;
				for(int y=to[x];!been[y]&&y!=at;y=par[y]) been[y]=true,isbridge[paredge[y]>>1]=false;
			}
		}
		//REP(i,m) if(isbridge[i]) printf("(%d,%d)\n",to[2*i+1],to[2*i+0]);
	}
	void compdfs(int at,int c) {
		comp[at]=c;
		for(int x=fst[at];x!=-1;x=nxt[x]) if(!isbridge[x>>1]&&comp[to[x]]==-1) compdfs(to[x],c);
	}
	void calccomponents() {
		ncomp=0; REP(i,n) comp[i]=-1;
		REP(i,n) if(comp[i]==-1) compdfs(i,ncomp++);
		//REP(i,n) printf("%d = %d\n",i,comp[i]);
	}
} graph;

struct {
	int n,m;
	int w[2000],wsum;
	int fst[2000];
	int to[4000];
	int nxt[4000];
	int sz[4000];
	int res[4000];
	bool can[2001];

	void addedge(int a,int b) {
		to[2*m+0]=b; nxt[2*m+0]=fst[a]; fst[a]=2*m+0;
		to[2*m+1]=a; nxt[2*m+1]=fst[b]; fst[b]=2*m+1;
		++m;
	}
	void createfromgraph() {
		n=graph.ncomp; m=0;
		REP(i,n) w[i]=0,fst[i]=-1; wsum=0;
		REP(i,graph.n) ++w[graph.comp[i]],++wsum;
		REP(i,graph.m) if(graph.isbridge[i]) addedge(graph.comp[graph.to[2*i+1]],graph.comp[graph.to[2*i+0]]);
		//REP(i,n) { printf("%d (%d):",i,w[i]); for(int x=fst[i];x!=-1;x=nxt[x]) printf(" %d",to[x]); puts(""); }
	}
	void calcsubtree(int x) {
		if(sz[x]!=-1||res[x]!=-1) return;
		int at=to[x];
		sz[x]=w[at]; res[x]=w[at]*w[at];
		for(int y=fst[at];y!=-1;y=nxt[y]) if(y!=(x^1)) {
			calcsubtree(y);
			sz[x]+=sz[y];
			res[x]+=res[y]+sz[y]*w[at];
		}
	}
	void calcsubtrees() {
		REP(i,2*m) sz[i]=res[i]=-1;
		REP(i,2*m) calcsubtree(i);
		//REP(i,2*m) printf("%d to %d: %d/%d\n",to[i^1],to[i],sz[i],res[i]);
	}
	int calc(int at) {
		memset(can,false,sizeof(can));
		can[0]=true;
		int ret=w[at]*wsum;
		for(int x=fst[at];x!=-1;x=nxt[x]) {
			ret+=res[x];
			for(int i=wsum-w[at];i>=0;--i) if(can[i]) can[i+sz[x]]=true;
		}
		int extra=0; REPE(i,wsum) if(can[i]&&i*(wsum-w[at]-i)>extra) extra=i*(wsum-w[at]-i);
		//printf("%d: %d+%d\n",at,ret,extra);
		return ret+extra;
	}
	int calcbest() {
		int ret=0;
		REP(i,n) { int cur=calc(i); if(cur>ret) ret=cur; }
		return ret;
	}
} tree;

void input() {
	int n,m; scanf("%d%d",&n,&m);
	graph.init(n);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; graph.addedge(a,b); }
	graph.calcbridges();
	graph.calccomponents();
	tree.createfromgraph();
	tree.calcsubtrees();
	int ret=tree.calcbest();
	printf("%d\n",ret);
}


void run() {
	input();

}

int main() {
	run();
	return 0;
}