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
const int MAXDIST=5;
typedef struct R { int id[2*MAXDIST],len,nid; } R;

int n,mxd,m,nq;
bool frnd[MAXN][MAXDIST+1];
R sval[4*MAXN];

int tmp[4*MAXDIST],ntmp;
int mp[4*MAXDIST],nmp;
void print(const R &a) {
	printf("[%d|%d",a.len,a.nid); REP(i,min(a.len,2*mxd)) printf("%c%d",i==0?'|':',',a.id[i]); printf("]");
}
R combine(const R &a,const R &b,int mid) {
	R c;
	c.len=a.len+b.len,c.nid=a.nid+b.nid;
	ntmp=0; REP(i,min(a.len,2*mxd)) tmp[ntmp++]=a.id[i]; REP(i,min(b.len,2*mxd)) tmp[ntmp++]=2*mxd+b.id[i];
	REP(i,min(a.len,mxd)) REP(j,min(b.len,mxd-i)) {
		int aa=mid-1-i,bb=mid+j;
		if(!frnd[aa][bb-aa]) continue;
		int ai=min(a.len,2*mxd)-1-i,bi=min(a.len,2*mxd)+j;
		if(tmp[ai]==tmp[bi]) continue;
		--c.nid;
		int x=tmp[ai],y=tmp[bi];
		REP(k,ntmp) if(tmp[k]==y) tmp[k]=x;
	}
	memset(mp,-1,sizeof(mp)); nmp=0;
	REP(i,ntmp) if(i>=mxd&&i<ntmp-mxd) tmp[i]=-2; else { if(mp[tmp[i]]==-1) mp[tmp[i]]=nmp++; tmp[i]=mp[tmp[i]]; }
	if(ntmp<=2*mxd) REP(i,ntmp) c.id[i]=tmp[i]; else REP(i,mxd) c.id[i]=tmp[i],c.id[mxd+i]=tmp[ntmp-mxd+i];
	//printf("[%d..%d]: ",mid-a.len,mid+b.len-1); print(a); printf(" + "); print(b); printf(" -> "); print(c); puts("");
	return c;
}

void sinit(int x,int l,int r) {
	if(l==r) {
		sval[x].len=1,sval[x].nid=1,sval[x].id[0]=0;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		sval[x]=combine(sval[2*x+1],sval[2*x+2],m+1);
	}
}

R sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) return sval[x];
	int m=l+(r-l)/2;
	if(m+1>R) return sget(2*x+1,l,m,L,R);
	if(L>m) return sget(2*x+2,m+1,r,L,R);
	return combine(sget(2*x+1,l,m,L,R),sget(2*x+2,m+1,r,L,R),m+1);
}


void run() {
	scanf("%d%d%d",&n,&mxd,&m);
	memset(frnd,false,sizeof(frnd));
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		if(a>b) swap(a,b); assert(b-a<=mxd);
		frnd[a][b-a]=true;
	}
	sinit(0,0,n-1);
	scanf("%d",&nq);
	REP(i,nq) {
		int l,r; scanf("%d%d",&l,&r); --l,--r;
		R res=sget(0,0,n-1,l,r);
		printf("%d\n",res.nid);
	}
}

int main() {
	run();
	return 0;
}