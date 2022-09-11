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
const int MAXBUS=200000;
const int MAXLG=17;
const int MAXS=4*MAXN;

int n;
int par[MAXN];
int nbus;
int bus[MAXBUS][2];

int dep[MAXN];
int up[MAXN][MAXLG+1];
int bustop[MAXBUS];
int one[MAXN];
int many[MAXN][MAXLG+1];

vector<int> ch[MAXN];
int id[MAXN],lid[MAXN],rid[MAXN],nid;

int lca(int a,int b) {
	if(dep[a]<dep[b]) swap(a,b);
	for(int k=MAXLG;k>=0;--k) if(dep[a]-(1<<k)>=dep[b]) a=up[a][k];
	for(int k=MAXLG;k>=0;--k) if(up[a][k]!=up[b][k]) a=up[a][k],b=up[b][k];
	return a==b?a:up[a][0];
}
void depupd(int &a,int b) { if(dep[b]<dep[a]) a=b; }

void dfsid(int at) {
	id[at]=lid[at]=nid++;
	REPSZ(i,ch[at]) { int to=ch[at][i]; dfsid(to); }
	rid[at]=nid-1;
}

vector<int> sval[MAXS];

void sinit(int z,int l,int r,const vector<pair<int,int> > &p) {
	REPSZ(i,p) sval[z].PB(p[i].second); sort(sval[z].begin(),sval[z].end());
	if(l!=r) {
		int m=l+(r-l)/2;
		vector<pair<int,int> > p1,p2; REPSZ(i,p) if(p[i].first<=m) p1.PB(p[i]); else p2.PB(p[i]);
		sinit(2*z+1,l,m,p1); sinit(2*z+2,m+1,r,p2);
	}
}

bool sget(int z,int l,int r,int LX,int RX,int LY,int RY) {
	if(LX<=l&&r<=RX) {
		int idx=lower_bound(sval[z].begin(),sval[z].end(),LY)-sval[z].begin();
		return idx<SZ(sval[z])&&sval[z][idx]<=RY;
	} else {
		int m=l+(r-l)/2;
		if(LX<=m&&sget(2*z+1,l,m,LX,RX,LY,RY)) return true;
		if(m+1<=RX&&sget(2*z+2,m+1,r,LX,RX,LY,RY)) return true;
		return false;
	}
}

int solve(int a,int b) {
	int c=lca(a,b),ret=0;
	for(int k=MAXLG;k>=0;--k) if(dep[many[a][k]]>dep[c]) ret+=1<<k,a=many[a][k];
	for(int k=MAXLG;k>=0;--k) if(dep[many[b][k]]>dep[c]) ret+=1<<k,b=many[b][k];
	if(dep[one[a]]>dep[c]||dep[one[b]]>dep[c]) return -1;
	if(id[a]>id[b]) swap(a,b);
	int extra=a==c||b==c||sget(0,0,nid-1,lid[a],rid[a],lid[b],rid[b])?1:2;
	//printf("either one or two buses to get from %d to %d -> %d [%d..%d] [%d..%d]\n",a+1,b+1,extra,lid[a],rid[a],lid[b],rid[b]);
	return ret+extra;
}




void run() {
	scanf("%d",&n); par[0]=-1; FOR(i,1,n) scanf("%d",&par[i]),--par[i]; scanf("%d",&nbus); REP(i,nbus) REP(j,2) scanf("%d",&bus[i][j]),--bus[i][j];

	REP(i,n) up[i][0]=par[i]==-1?i:par[i],dep[i]=par[i]==-1?0:dep[par[i]]+1;
	REP(k,MAXLG) REP(i,n) up[i][k+1]=up[up[i][k]][k];
	REP(i,nbus) bustop[i]=lca(bus[i][0],bus[i][1]);

	REP(i,n) one[i]=i;
	REP(i,nbus) REP(j,2) depupd(one[bus[i][j]],bustop[i]);
	for(int i=n-1;i>=0;--i) if(par[i]!=-1) depupd(one[par[i]],one[i]);
	REP(i,n) many[i][0]=one[i];
	REP(k,MAXLG) REP(i,n) many[i][k+1]=many[many[i][k]][k];

	REP(i,n) if(par[i]!=-1) ch[par[i]].PB(i);
	dfsid(0);
	//printf("id:"); REP(i,n) printf(" %d",id[i]); puts("");

	vector<pair<int,int> > p;
	REP(i,nbus) { int a=id[bus[i][0]],b=id[bus[i][1]]; if(a>b) swap(a,b); p.PB(MP(a,b)); }
	//printf("p:"); REPSZ(i,p) printf(" (%d,%d)",p[i].first,p[i].second); puts("");
	sinit(0,0,nid-1,p);

	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		printf("%d\n",solve(a,b));
	}
}

int main() {
	run();
	return 0;
}