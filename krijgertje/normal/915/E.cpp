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

const int MAXQ=300000;
const int MAXZ=2*MAXQ+2;
const int MAXS=4*MAXZ;

int len,nq;
int qkind[MAXQ],ql[MAXQ],qr[MAXQ];

int z[MAXZ],nz;

int sval[MAXS],slazy[MAXS];
void sapply(int x,int val,int l,int r) {
	//printf("sapply(%d,%d,%d..%d)\n",x,val,l,r);
	slazy[x]=val;
	sval[x]=val==0?0:z[r+1]-z[l];
	//printf("->%d\n",sval[x]);
}
void spush(int x,int l,int m,int r) {
	if(slazy[x]!=-1) sapply(2*x+1,slazy[x],l,m),sapply(2*x+2,slazy[x],m+1,r),slazy[x]=-1;
}
void spull(int x) {
	sval[x]=sval[2*x+1]+sval[2*x+2];
}
void sinit(int x,int l,int r) {
	if(l==r) {
		sapply(x,1,l,l);
	} else {
		slazy[x]=-1;
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
		spull(x);
	}
}
void sset(int x,int l,int r,int L,int R,int VAL) {
	//printf("sset(%d,%d..%d,%d..%d,%d)\n",x,l,r,L,R,VAL);
	if(L<=l&&r<=R) {
		sapply(x,VAL,l,r);
		slazy[x]=VAL;
	} else {
		int m=l+(r-l)/2;
		spush(x,l,m,r);
		if(L<=m) sset(2*x+1,l,m,L,R,VAL);
		if(m+1<=R) sset(2*x+2,m+1,r,L,R,VAL);
		spull(x);
	}
	//printf("sset(%d,%d..%d,%d..%d,%d)->%d\n",x,l,r,L,R,VAL,sval[x]);
}


void run() {
	scanf("%d%d",&len,&nq);
	REP(i,nq) scanf("%d%d%d",&ql[i],&qr[i],&qkind[i]),--ql[i];

	nz=0; z[nz++]=0; z[nz++]=len; REP(i,nq) z[nz++]=ql[i],z[nz++]=qr[i]; sort(z,z+nz); nz=unique(z,z+nz)-z; REP(i,nq) ql[i]=lower_bound(z,z+nz,ql[i])-z,qr[i]=lower_bound(z,z+nz,qr[i])-z;
	//printf("z:"); REP(i,nz) printf(" %d",z[i]); puts(""); REP(i,nq) printf("%d [%d..%d)\n",qkind[i],ql[i],qr[i]);

	sinit(0,0,nz-2);
	REP(i,nq) {
		sset(0,0,nz-2,ql[i],qr[i]-1,qkind[i]==1?0:1);
		printf("%d\n",sval[0]);
	}
}

int main() {
	run();
	return 0;
}