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

const int MAXN=300001;
const int MAXS=4*MAXN;
const int MAXBIT=18;

int n;
int par[MAXN];
vector<int> childs[MAXN];

int d[MAXN];
int up[MAXN][MAXBIT+1];
int lid[MAXN],rid[MAXN];
int id[MAXN],nid;

void dfs(int at) {
	lid[at]=nid; id[nid++]=at; d[at]=par[at]==-1?0:d[par[at]]+1;
	up[at][0]=par[at]==-1?at:par[at]; REP(k,MAXBIT) up[at][k+1]=up[up[at][k]][k];
	REPSZ(i,childs[at]) {
		int to=childs[at][i];
		dfs(to);
	}
	rid[at]=nid-1;
}
int calcup(int at,int steps) {
	assert(d[at]>=steps);
	for(int k=MAXBIT;k>=0;--k) if(steps>=(1<<k)) steps-=1<<k,at=up[at][k];
	return at;
}

int smx[MAXS],smxcnt[MAXS],slazy[MAXS];

void sapply(int x,int val) {
	if(smx[x]!=INT_MIN) smx[x]+=val;
	slazy[x]+=val;
}
void spush(int x) {
	if(slazy[x]==0) return;
	sapply(2*x+1,slazy[x]); sapply(2*x+2,slazy[x]); slazy[x]=0;
}
void spull(int x) {
	smx[x]=max(smx[2*x+1],smx[2*x+2]);
	smxcnt[x]=(smx[2*x+1]==smx[x]?smxcnt[2*x+1]:0)+(smx[2*x+2]==smx[x]?smxcnt[2*x+2]:0);
}
void sinit(int x,int l,int r) {
	if(l==r) {
		smx[x]=INT_MIN,smxcnt[x]=0,slazy[x]=2*d[id[l]];
	} else {
		slazy[x]=0;
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		spull(x);
	}
	//printf("sinit(%d,%d..%d) -> smx=%d smxcnt=%d\n",x,l,r,smx[x],smxcnt[x]);
}
void salive(int x,int l,int r,int IDX) {
	if(l==r) {
		smx[x]=slazy[x]; smxcnt[x]=1;
	} else {
		spush(x);
		int m=l+(r-l)/2;
		if(IDX<=m) salive(2*x+1,l,m,IDX); else salive(2*x+2,m+1,r,IDX);
		spull(x);
	}
	//printf("salive(%d,%d..%d,%d) -> smx=%d smxcnt=%d\n",x,l,r,IDX,smx[x],smxcnt[x]);
}
void smod(int x,int l,int r,int L,int R,int BY) {
	if(L<=l&&r<=R) {
		sapply(x,BY);
	} else {
		spush(x);
		int m=l+(r-l)/2;
		if(L<=m) smod(2*x+1,l,m,L,R,BY);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
		spull(x);
	}
	//printf("smod(%d,%d..%d,%d..%d,%d) -> smx=%d smxcnt=%d\n",x,l,r,L,R,BY,smx[x],smxcnt[x]);
}

void run() {
	scanf("%d",&n); ++n;
	par[0]=-1; FOR(i,1,n) scanf("%d",&par[i]),--par[i];
	REP(i,n) if(par[i]!=-1) childs[par[i]].PB(i);
	
	nid=0; dfs(0);
	sinit(0,0,n-1);
	salive(0,0,n-1,lid[0]);
	//REP(i,n) printf("%d: d=%d lid=%d rid=%d\n",i,d[i],lid[i],rid[i]);

	int center=0; bool onparentpath=false; int diam=0;
	FOR(i,1,n) {
		salive(0,0,n-1,lid[i]);
		int cur=smx[0];
		//printf("%d: %d\n",i,cur);
		if(cur>diam) {
			int a=-1;
			if(d[i]>d[center]) a=calcup(i,d[i]-d[center]-1);
			if(a!=-1&&par[a]==center) {
				if(onparentpath) {
					smod(0,0,n-1,0,n-1,1);
					smod(0,0,n-1,lid[center],rid[center],-2);
					onparentpath=false;
				} else {
					smod(0,0,n-1,0,n-1,1);
					smod(0,0,n-1,lid[a],rid[a],-2);
					center=a; onparentpath=true;
				}
			} else {
				if(onparentpath) {
					smod(0,0,n-1,0,n-1,-1);
					smod(0,0,n-1,lid[center],rid[center],+2);
					center=par[center]; onparentpath=false;
				} else {
					smod(0,0,n-1,0,n-1,-1);
					smod(0,0,n-1,lid[center],rid[center],+2);
					onparentpath=true;
				}
			}
			diam=smx[0];
			//printf("->center=%d onparentpath=%d diam=%d\n",center,onparentpath?1:0,diam);
		}
		printf("%d\n",smxcnt[0]);
	}
}

int main() {
	run();
	return 0;
}