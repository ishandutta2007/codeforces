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
#include <random>
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
const int MAXQ=300000;
const int MAXVAL=1000000000;


int n,nq;
int qt[MAXQ],ql[MAXQ],qr[MAXQ],qx[MAXQ];
int mx[MAXN],ret[MAXN];

typedef struct S1 {
	int sval[4*MAXN];
	void sinit(int x,int l,int r) {
		sval[x]=INT_MAX;
		if(l==r) return;
		int m=l+(r-l)/2; sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
	}
	void smod(int x,int l,int r,int L,int R,int VAL) {
		//printf("smod(%d,%d..%d,%d..%d,%d)\n",x,l,r,L,R,VAL);
		if(L<=l&&r<=R) { sval[x]=min(sval[x],VAL); return; }
		int m=l+(r-l)/2; if(L<=m) smod(2*x+1,l,m,L,R,VAL); if(m+1<=R) smod(2*x+2,m+1,r,L,R,VAL);
	}
	int sget(int x,int l,int r,int IDX) {
		if(l==r) return sval[x];
		int m=l+(r-l)/2; if(IDX<=m) return min(sval[x],sget(2*x+1,l,m,IDX)); else return min(sval[x],sget(2*x+2,m+1,r,IDX));
	}
} S1;
S1 s1;

typedef struct S2 {
	int sval[4*MAXN];
	void sinit(int x,int l,int r,int *VAL) {
		if(l==r) { sval[x]=VAL[l]; return; }
		int m=l+(r-l)/2; sinit(2*x+1,l,m,VAL); sinit(2*x+2,m+1,r,VAL);
		sval[x]=max(sval[2*x+1],sval[2*x+2]);
	}
	void sset(int x,int l,int r,int IDX,int VAL) {
		if(l==r) { sval[x]=VAL; return; }
		int m=l+(r-l)/2; if(IDX<=m) sset(2*x+1,l,m,IDX,VAL); else sset(2*x+2,m+1,r,IDX,VAL);
		sval[x]=max(sval[2*x+1],sval[2*x+2]);
	}
	int sget(int x,int l,int r,int L,int R) {
		if(L<=l&&r<=R) return sval[x];
		int m=l+(r-l)/2,ret=INT_MIN; if(L<=m) ret=max(ret,sget(2*x+1,l,m,L,R)); if(m+1<=R) ret=max(ret,sget(2*x+2,m+1,r,L,R)); return ret;
	}
} S2;
S2 s2;

int greedy(int lim,int have) { if(lim==0) return 0; int k=0; while(lim>=(2<<k)) ++k; int ret=0; for(int i=k;i>=0;--i) if((have&(1<<i))==0&&ret+(1<<i)<=lim) ret+=1<<i; return ret; }
void run() {
	scanf("%d%d",&n,&nq);
	REP(i,nq) {
		scanf("%d",&qt[i]);
		if(qt[i]==1) scanf("%d%d%d",&ql[i],&qr[i],&qx[i]),--ql[i],--qr[i];
		if(qt[i]==2) scanf("%d%d",&ql[i],&qx[i]),--ql[i];
	}

	REP(i,n) mx[i]=-1;
	s1.sinit(0,0,n-1);
	REP(i,nq) {
		if(qt[i]==1) s1.smod(0,0,n-1,ql[i],qr[i],qx[i]);
		if(qt[i]==2&&mx[ql[i]]==-1) mx[ql[i]]=s1.sget(0,0,n-1,ql[i]);
	}
	REP(i,n) if(mx[i]==-1) mx[i]=s1.sget(0,0,n-1,i);
	//printf("mx:"); REP(i,min(50,n)) printf(" %d",mx[i]); puts("");

	s2.sinit(0,0,n-1,mx);
	REP(i,nq) {
		if(qt[i]==1) { int cur=s2.sget(0,0,n-1,ql[i],qr[i]); if(cur!=qx[i]) { printf("NO\n"); return; } }
		if(qt[i]==2) s2.sset(0,0,n-1,ql[i],qx[i]);
	}

	set<int> seen; int res=0,a=-1,b=-1;
	REP(i,n) {
		if(mx[i]==INT_MAX) { if(a==-1) a=i; else if(b==-1) b=i; else ret[i]=0; }
		else if(!seen.count(mx[i])) { ret[i]=mx[i]; res|=ret[i]; seen.insert(mx[i]); }
		else { ret[i]=greedy(mx[i],res); res|=ret[i]; }
	}
	if(a!=-1&&b!=-1) ret[a]=MAXVAL,res|=ret[a],ret[b]=greedy(MAXVAL,res),res|=ret[b];
	else if(a!=-1) ret[a]=greedy(MAXVAL,res),res|=ret[a];

	//for(int tmp=MAXVAL;tmp!=0;tmp/=2) printf("%d",tmp%2); puts("");
	//for(int tmp=res;tmp!=0;tmp/=2) printf("%d",tmp%2); puts("");

	printf("YES\n");
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}