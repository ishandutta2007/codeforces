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

const int MAXN=150000;
const int MAXQ=150000;
const int MAXLEAF=MAXN;
const int MAXS=4*MAXLEAF;

int n,nq;
int par[MAXN]; char initparedge[MAXN];
int qidx[MAXQ]; char qc[MAXQ]; ll qans[MAXQ];

int root;
vector<int> ch[MAXN];
bool isleaf[MAXN];
int dep[MAXN];
int specialpar[MAXN],specialside[MAXN];

void dfsinit(int at) {
	dep[at]=par[at]==-1?0:dep[par[at]]+1;
	REPSZ(i,ch[at]) {
		int to=ch[at][i];
		if(SZ(ch[at])==2||par[at]==-1) {
			specialpar[to]=at,specialside[to]=i;
		} else {
			specialpar[to]=specialpar[at],specialside[to]=specialside[at];
		}
		dfsinit(to);
	}
}

char curparedge[MAXN];

// the following is only used for the root and nodes with two childs
int numnegativeslack;
int slack[MAXN]; 
int mymx[MAXN][26];
int chmx[MAXN][2][26];

void mod(int at,int x,int by) {
	while(true) {
		int to=specialpar[at],side=specialside[at];
		chmx[to][side][x]+=by;
		int old=mymx[to][x];
		if(slack[to]<0) --numnegativeslack;
		slack[to]+=mymx[to][x];
		mymx[to][x]=max(chmx[to][0][x],chmx[to][1][x]);
		slack[to]-=mymx[to][x];
		if(slack[to]<0) ++numnegativeslack;
		if(mymx[to][x]==old||to==root) break;
		at=to;
	}
}


void solve() {
	root=0;
	REP(i,n) ch[i].clear();
	REP(i,n) if(par[i]!=-1) ch[par[i]].PB(i);
	REP(i,n) isleaf[i]=SZ(ch[i])==0;
	dfsinit(root);
	
	vector<int> leafdists; REP(i,n) if(isleaf[i]) leafdists.PB(dep[i]);
	sort(leafdists.begin(),leafdists.end()); leafdists.erase(unique(leafdists.begin(),leafdists.end()),leafdists.end());
	assert(SZ(leafdists)>=1);
	if(SZ(leafdists)>=2) { REP(i,nq) qans[i]=0; return; }
	int leafdist=leafdists[0];
	numnegativeslack=0;
	REP(i,n) slack[i]=leafdist-dep[i];
	REP(i,n) REP(x,26) mymx[i][x]=chmx[i][0][x]=chmx[i][1][x]=0;

	REP(i,n) curparedge[i]=initparedge[i];
	REP(i,n) if(par[i]!=-1&&curparedge[i]!='?') mod(i,curparedge[i]-'a',+1);
	REP(i,nq) {
		int idx=qidx[i]; char c=qc[i];
		if(curparedge[idx]!='?') mod(idx,curparedge[idx]-'a',-1);
		curparedge[idx]=c;
		if(curparedge[idx]!='?') mod(idx,curparedge[idx]-'a',+1);
		int sum=0; REP(k,26) sum+=mymx[root][k];
		qans[i]=0; if(sum<=leafdist&&numnegativeslack==0) REP(k,26) qans[i]+=(ll)(k+1)*(mymx[root][k]+leafdist-sum);
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	par[0]=-1,initparedge[0]='-'; FOR(i,1,n) scanf("%d %c",&par[i],&initparedge[i]),--par[i];
	REP(i,nq) scanf("%d %c",&qidx[i],&qc[i]),--qidx[i];
	solve();
	REP(i,nq) if(qans[i]==0) printf("Fou\n"); else printf("Shi %lld\n",qans[i]);
}

int main() {
	run();
	return 0;
}