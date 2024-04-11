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

int n,nq;
int par[MAXN];
int initval[MAXN];
vector<int> ch[MAXN];

int lid[MAXN],rid[MAXN],rev[MAXN],nid;
void dfsid(int at) {
	lid[at]=nid++; rev[lid[at]]=at;
	REPSZ(i,ch[at]) { int to=ch[at][i]; dfsid(to); }
	rid[at]=nid-1;
}

int ssum[4*MAXN],slazy[4*MAXN];
void sapply(int x,int len) {
	ssum[x]=len-ssum[x];
	slazy[x]=1-slazy[x];
}
void sinit(int x,int l,int r) {
	slazy[x]=0;
	if(l==r) {
		ssum[x]=initval[rev[l]];
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		ssum[x]=ssum[2*x+1]+ssum[2*x+2];
	}
	//printf("init [%d..%d] = %d\n",l,r,ssum[x]);
}
void smod(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		sapply(x,r-l+1);
	} else {
		int m=l+(r-l)/2;
		if(slazy[x]) sapply(2*x+1,m-l+1),sapply(2*x+2,r-(m+1)+1),slazy[x]=0;
		if(L<=m) smod(2*x+1,l,m,L,R);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R);
		ssum[x]=ssum[2*x+1]+ssum[2*x+2];
	}
}
int sget(int x,int l,int r,int L,int R) {
	//printf("sget(%d..%d %d..%d) [%d]\n",l,r,L,R,ssum[x]);
	if(L<=l&&r<=R) {
		return ssum[x];
	} else {
		int m=l+(r-l)/2;
		if(slazy[x]) sapply(2*x+1,m-l+1),sapply(2*x+2,r-(m+1)+1),slazy[x]=0;
		int ret=0;
		if(L<=m) ret+=sget(2*x+1,l,m,L,R);
		if(m+1<=R) ret+=sget(2*x+2,m+1,r,L,R);
		ssum[x]=ssum[2*x+1]+ssum[2*x+2];
		return ret;
	}
}


void run() {
	scanf("%d",&n);
	par[0]=-1; FOR(i,1,n) scanf("%d",&par[i]),--par[i];
	REP(i,n) scanf("%d",&initval[i]);
	REP(i,n) if(par[i]!=-1) ch[par[i]].PB(i);
	nid=0; dfsid(0);
	sinit(0,0,nid-1);

	scanf("%d",&nq);
	REP(i,nq) {
		char kind[4]; int x; scanf("%s%d",kind,&x); --x;
		if(strcmp(kind,"get")==0) printf("%d\n",sget(0,0,nid-1,lid[x],rid[x]));
		if(strcmp(kind,"pow")==0) smod(0,0,nid-1,lid[x],rid[x]);
	}

}

int main() {
	run();
	return 0;
}