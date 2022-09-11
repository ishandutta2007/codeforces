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

const int MAXN=100000;
const int MAXQ=1000000;
const int MAXLG=16;
const int MAXS=4*MAXN+MAXN*(MAXLG+2);
typedef struct S { int l,r,val; } S;

S s[MAXS]; int ns;
int screate(int val) { int ret=ns++; s[ret].l=s[ret].r=-1,s[ret].val=val; return ret; }
int screate(int l,int r) { int ret=ns++; s[ret].l=l,s[ret].r=r,s[ret].val=min(s[l].val,s[r].val); return ret; }

int sinit(int l,int r) {
	if(l==r) {
		return screate(INT_MAX);
	} else {
		int m=l+(r-l)/2;
		return screate(sinit(l,m),sinit(m+1,r));
	}
}
int supd(int x,int l,int r,int IDX,int VAL) {
	if(l==r) {
		return screate(VAL);
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) return screate(supd(s[x].l,l,m,IDX,VAL),s[x].r);
		else return screate(s[x].l,supd(s[x].r,m+1,r,IDX,VAL));
	}
}
int sget(int x,int l,int r,int L,int R) {
	//printf("sget(%d,%d..%d,%d..%d)\n",x,l,r,L,R); if(x==-1) exit(1);
	if(L<=l&&r<=R) {
		return s[x].val;
	} else {
		int m=l+(r-l)/2,ret=INT_MAX;
		if(L<=m) ret=min(ret,sget(s[x].l,l,m,L,R));
		if(m+1<=R) ret=min(ret,sget(s[x].r,m+1,r,L,R));
		return ret;
	}
}

int n,rt,nq;
int a[MAXN];
vector<int> adj[MAXN];
int qp[MAXQ],qq[MAXQ];

int par[MAXN];
int d[MAXN];
int lid[MAXN],rid[MAXN];
int pre[MAXN],npre;

int dmx;
pair<int,int> o[MAXN];
int srt[MAXN];

void dfs(int at) {
	d[at]=par[at]==-1?0:d[par[at]]+1; lid[at]=npre; pre[npre++]=at;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]) continue;
		par[to]=at; dfs(to);
	}
	rid[at]=npre-1;
}

void run() {
	scanf("%d%d",&n,&rt); --rt; REP(i,n) scanf("%d",&a[i]); REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	scanf("%d",&nq); REP(qi,nq) scanf("%d%d",&qp[qi],&qq[qi]);

	//n=1000,rt=rand()%n; REP(i,n) a[i]=rand()%1000+1; REP(i,n) adj[i].clear(); REP(i,n-1) adj[i].PB(i+1),adj[i+1].PB(i);
	//nq=1000; REP(i,nq) qp[i]=rand()%n+1,qq[i]=rand()%n+1;

	par[rt]=-1; npre=0; dfs(rt);
	dmx=0; REP(i,n) dmx=max(dmx,d[i]);

	ns=0; srt[0]=sinit(0,npre);
	REP(i,n) o[i]=MP(d[i],i); sort(o,o+n);
	REP(i,n) {
		int prt=i==0||o[i].first==o[i-1].first?srt[o[i].first]:srt[o[i].first-1];
		//printf("%d: updating %d with %d\n",o[i].first,lid[o[i].second],a[o[i].second]);
		srt[o[i].first]=supd(prt,0,npre,lid[o[i].second],a[o[i].second]);
	}
	
	int last=0;
	REP(qi,nq) {
		int p=qp[qi],q=qq[qi]; int x=(p+last)%n,k=(q+last)%n;
		int dd=min(dmx,d[x]+k);
		//printf("x=%d k=%d dd=%d lid=%d rid=%d\n",x+1,k,dd,lid[x],rid[x]);
		int ans=sget(srt[dd],0,npre,lid[x],rid[x]);
		printf("%d\n",ans);
		last=ans;
	}
}

int main() {
	run();
	return 0;
}