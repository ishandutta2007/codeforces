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
const int MAXQ=200000;
typedef struct Q { int lx,ly,hx,hy; } Q;
typedef struct Z { int x,y,i,j; } Z;
bool operator<(const Z &a,const Z &b) { return a.x<b.x; }

int n,nq;
int y[MAXN];
Q q[MAXQ];

Z z[4*MAXQ]; int nz;
int ans[MAXQ][4];

int bt[MAXN+1];
void bmod(int idx,int by) { ++idx; while(idx<=n) { bt[idx]+=by; idx+=idx&-idx; } }
int bget(int idx) { int ret=0; ++idx; while(idx>0) { ret+=bt[idx]; idx-=idx&-idx; } return ret; }

ll calc(int n) { return (ll)n*(n-1)/2; }
void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&y[i]),--y[i];
	REP(i,nq) { scanf("%d%d%d%d",&q[i].lx,&q[i].ly,&q[i].hx,&q[i].hy),--q[i].lx,--q[i].hx,--q[i].ly,--q[i].hy; if(q[i].lx>q[i].hx) swap(q[i].lx,q[i].hx); if(q[i].ly>q[i].hy) swap(q[i].ly,q[i].hy); }

	nz=0;
	REP(i,nq) {
		int lx=q[i].lx,hx=q[i].hx,ly=q[i].ly,hy=q[i].hy;
		//printf("%d: x=[%d..%d] y=[%d..%d]\n",i,lx,hx,ly,hy);
		z[nz].x=lx-1,z[nz].y=ly-1,z[nz].i=i,z[nz].j=0,++nz;
		z[nz].x=hx,z[nz].y=ly-1,z[nz].i=i,z[nz].j=1,++nz;
		z[nz].x=lx-1,z[nz].y=hy,z[nz].i=i,z[nz].j=2,++nz;
		z[nz].x=hx,z[nz].y=hy,z[nz].i=i,z[nz].j=3,++nz;
	}
	sort(z,z+nz);
	//REP(i,nz) printf("ans[%d][%d]=q(%d,%d)\n",z[i].i,z[i].j,z[i].x,z[i].y);

	int atz=0; memset(bt,0,sizeof(bt));
	while(atz<nz&&z[atz].x==-1) ans[z[atz].i][z[atz].j]=0,++atz;
	REP(x,n) {
		bmod(y[x],+1);
		while(atz<nz&&z[atz].x==x) ans[z[atz].i][z[atz].j]=bget(z[atz].y),++atz;
	}
	assert(atz==nz);

	REP(i,nq) {
		int lx=q[i].lx,hx=q[i].hx,ly=q[i].ly,hy=q[i].hy;
		int a=ans[i][0],b=ans[i][1],c=ans[i][2],d=ans[i][3];
		//printf("%d: %d %d %d %d\n",i,a,b,c,d);
		ll ret=calc(n)-calc(lx)-calc(ly)-calc(n-hx-1)-calc(n-hy-1)+calc(a)+calc(lx-c)+calc(ly-b)+calc(n-(hx+1)-(hy+1)+d);
		printf("%lld\n",ret);
	}
}

int main() {
	run();
	return 0;
}