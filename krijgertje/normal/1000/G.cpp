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

const int MAXN=300000;
const int MAXLG=18;

int n,nq;
int nodegain[MAXN];
vector<pair<int,int> > e[MAXN];

int dep[MAXN];
int par[MAXN],parcost[MAXN];
vector<int> ch[MAXN];
int up[MAXN][MAXLG+1];

ll downgain[MAXN];
ll downsum[MAXN]; // excluding gain from root
ll upgain[MAXN];
ll upval[MAXN][MAXLG+1];



void dfsinit(int at) {
	dep[at]=par[at]==-1?0:dep[par[at]]+1;
	up[at][0]=par[at]==-1?at:par[at]; REP(k,MAXLG) up[at][k+1]=up[up[at][k]][k];
	REPSZ(i,e[at]) {
		int to=e[at][i].first; if(to==par[at]) continue;
		ch[at].PB(to);
		par[to]=at,parcost[to]=e[at][i].second;
		dfsinit(to);
	}
}

void dfsdown(int at) {
	downsum[at]=0;
	REPSZ(i,ch[at]) {
		int to=ch[at][i];
		dfsdown(to);
		downsum[at]+=downgain[to]; 
	}
	downgain[at]=max(0LL,downsum[at]+nodegain[at]-2*parcost[at]);
}

void dfsup(int at) {
	upgain[at]=par[at]==-1?0LL:max(0LL,upgain[par[at]]+downsum[par[at]]-downgain[at]+nodegain[par[at]]-2*parcost[at]);
	REPSZ(i,ch[at]) {
		int to=ch[at][i];
		dfsup(to);
	}
}

int lca(int a,int b) {
	if(dep[a]<dep[b]) swap(a,b);
	for(int k=MAXLG;k>=0;--k) if(dep[a]-(1<<k)>=dep[b]) a=up[a][k];
	for(int k=MAXLG;k>=0;--k) if(up[a][k]!=up[b][k]) a=up[a][k],b=up[b][k];
	return a==b?a:up[a][0];
}

ll calcsteps(int &a,int nsteps) {
	ll ret=0;
	for(int k=MAXLG;k>=0;--k) if(nsteps&(1<<k)) { ret+=upval[a][k]; a=up[a][k]; }
	return ret;
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&nodegain[i]);
	REP(i,n-1) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; e[a].PB(MP(b,c)); e[b].PB(MP(a,c)); }

	par[0]=-1,parcost[0]=0; dfsinit(0);
	dfsdown(0);
	dfsup(0);
	REP(i,n) upval[i][0]=par[i]==-1?0:downsum[par[i]]-downgain[i]+nodegain[par[i]]-parcost[i];
	REP(k,MAXLG) REP(i,n) upval[i][k+1]=upval[i][k]+upval[up[i][k]][k];

	//REP(i,n) printf("%d: downgain=%lld downsum=%lld upgain=%lld\n",i,downgain[i],downsum[i],upgain[i]);

	REP(i,nq) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		int c=lca(a,b);
		//printf("%d->%d->%d\n",a,c,b);
		ll ans=0;
		if(a!=c) ans+=nodegain[a]+downsum[a]+calcsteps(a,dep[a]-dep[c]-1);
		if(b!=c) ans+=nodegain[b]+downsum[b]+calcsteps(b,dep[b]-dep[c]-1);
		assert(a==c||par[a]==c); assert(b==c||par[b]==c);
		ans+=nodegain[c]+upgain[c]+downsum[c]-(a==c?0:downgain[a]+parcost[a])-(b==c?0:downgain[b]+parcost[b]);
		printf("%lld\n",ans);
	}
}

int main() {
	run();
	return 0;
}