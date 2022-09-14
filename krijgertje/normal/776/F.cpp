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

const int MAXVERT=100000;
const int MAXDIAG=MAXVERT-3;
const int MAXREG=MAXVERT-2;
const int MAXM=MAXREG-1;

int nvert,ndiag;

int dhead[MAXVERT],dnxt[MAXDIAG],dto[MAXDIAG],dcnt[MAXVERT],doff[MAXVERT+1];
int dlst[MAXDIAG];

int nreg;
int mxvert[MAXREG][2];
int rhead[MAXREG],rnxt[2*MAXM],rto[2*MAXM]; int m;
int col[MAXREG];

void addedge(int a,int b) {
	rnxt[m]=rhead[a],rhead[a]=m,rto[m]=b,++m;
	rnxt[m]=rhead[b],rhead[b]=m,rto[m]=a,++m;
}
int createreg(int a,int b,int c) {
	int ret=nreg++; rhead[ret]=-1;
	while(true) {
		int prv=-1;
		REP(i,dcnt[b]) {
			int d=i==0?b+1:dlst[doff[b]+i-1],e=dlst[doff[b]+i]; assert(b<=d&&d<e&&e<=c);
			int cur=createreg(b,d,e);
			if(prv!=-1) addedge(prv,cur);
			prv=cur;
		}
		if(prv!=-1) addedge(ret,prv);
		int nb=dcnt[b]==0?b+1:dlst[doff[b]+dcnt[b]-1]; assert(b<nb);
		if(nb==c) {
			mxvert[ret][0]=c,mxvert[ret][1]=b;
			break;
		}
		b=nb;
	}
	return ret;
}

int mark[MAXREG],par[MAXREG],curmark;
int q[MAXREG],qhead,qtail;
int sz[MAXREG],mxcsz[MAXREG];
int centroid(int at) {
	++curmark; qhead=qtail=0; q[qhead++]=at; par[at]=-1; sz[at]=1,mxcsz[at]=0; mark[at]=curmark;
	while(qtail<qhead) {
		int at=q[qtail++];
		for(int x=rhead[at];x!=-1;x=rnxt[x]) {
			int to=rto[x]; if(col[to]!=-1||mark[to]==curmark) continue;
			q[qhead++]=to; mark[to]=curmark; par[to]=at; sz[to]=1,mxcsz[to]=0;
		}
	}
	int n=qhead;
	for(int i=n-1;i>=0;--i) {
		int at=q[i];
		if(2*mxcsz[at]<=n&&2*(n-sz[at])<=n) return at;
		if(par[at]!=-1) { sz[par[at]]+=sz[at]; if(sz[at]>mxcsz[par[at]]) mxcsz[par[at]]=sz[at]; }
	}
	assert(false);
}
void colorrec(int at,int c) {
	at=centroid(at);
	col[at]=c;
	for(int x=rhead[at];x!=-1;x=rnxt[x]) {
		int to=rto[x]; if(col[to]!=-1) continue;
		colorrec(to,c+1);
	}
}

int p[MAXREG];
bool pcmp(const int &a,const int &b) { REP(i,2) if(mxvert[a][i]!=mxvert[b][i]) return mxvert[a][i]<mxvert[b][i]; return false; }

void run() {
	scanf("%d%d",&nvert,&ndiag);
	REP(i,nvert) dhead[i]=-1,dcnt[i]=0;
	REP(i,ndiag) { int a,b; scanf("%d%d",&a,&b); --a,--b; if(a>b) swap(a,b); dnxt[i]=dhead[a]; dhead[a]=i; dto[i]=b; ++dcnt[a]; }
	doff[0]=0; REP(i,nvert) doff[i+1]=doff[i]+dcnt[i];
	REP(i,nvert) for(int j=doff[i],x=dhead[i];x!=-1;x=dnxt[x]) dlst[j++]=dto[x];
	REP(i,nvert) sort(dlst+doff[i],dlst+doff[i+1]);
	//REP(i,nvert) { printf("%d:",i+1); FOR(j,doff[i],doff[i+1]) printf(" %d",dlst[j]+1); puts(""); }

	int prv=-1; nreg=m=0;
	REPE(i,dcnt[0]) {
		int a=i==0?1:dlst[doff[0]+i-1],b=i==dcnt[0]?nvert-1:dlst[doff[0]+i];
		int cur=createreg(i,a,b);
		if(prv!=-1) addedge(prv,cur);
		prv=cur;
	}
	//REP(i,nreg) { printf("reg %d: last=(%d,%d)",i,mxvert[i][0]+1,mxvert[i][1]+1); for(int x=rhead[i];x!=-1;x=rnxt[x]) printf(" %d",rto[x]); puts(""); }

	REP(i,nreg) col[i]=-1; curmark=-1; memset(mark,-1,sizeof(mark));
	colorrec(0,1);
	//REP(i,nreg) printf("reg %d = %d\n",i,col[i]);

	REP(i,nreg) p[i]=i; sort(p,p+nreg,pcmp);
	REP(i,nreg) { if(i!=0) printf(" "); printf("%d",col[p[i]]); } puts("");
}

int main() {
	run();
	return 0;
}