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

const int MAXSTN=50;
const int MAXTRN=100;
const int MAXT=20000;
const int MAXFFT=1<<15;

typedef struct C { 
	double x,y; C() { x=y=0; } C(double x,double y):x(x),y(y) {}
	const inline C operator+(const C &b) const { return C(x+b.x,y+b.y); }
	const inline C operator-(const C &b) const { return C(x-b.x,y-b.y); }
	const inline C operator*(const C &b) const { return C(x*b.x-y*b.y,x*b.y+y*b.x); }
	const inline void operator-=(const C &b) { x-=b.x; y-=b.y; }
	const inline void operator+=(const C &b) { x+=b.x; y+=b.y; }
} C;

C wpos[MAXFFT],wneg[MAXFFT]; // r=acos(-1)/MAXFFT punit=(cos(r),sin(r)),wpos[i]=punit^i,wneg[i]=punit^(-i)
void initFFT() {
	double r=acos(-1)/MAXFFT;
	C punit(cos(r),sin(r));
	wpos[0]=C(1,0); FOR(i,1,MAXFFT) wpos[i]=wpos[i-1]*punit;
	wneg[0]=C(1,0); FOR(i,1,MAXFFT) wneg[i]=C(0,0)-wpos[MAXFFT-i];
}
void FFT(C *x,int n,int type) {
	for(int i=1,j=0;i<n-1;++i) {
		for(int s=n;j^=s>>=1,~j&s;);	
		if(i<j) swap(x[i],x[j]);
	}
	for(int d=0;(1<<d)<n;++d) {
		int m=1<<d,m2=m*2,step=MAXFFT/m;
		for(int i=0;i<n;i+=m2) {
			C *l=x+i,*r=x+i+m,*w=type==+1?wpos:wneg;
			for(int j=0;j<m;++j,++l,++r,w+=step) {
				C s=*l,t=*r**w;
				*l=s+t,*r=s-t;
			}
		}
	}
}

C A[2*MAXT+1],B[2*MAXT+1];
int memstart[100*MAXTRN];
C mem[MAXTRN*2*MAXFFT]; int nmem;
double res[2*MAXT+1];
void conv(double *a,double *b,int sz,int memid) {
	if(sz<=128) {
		REP(i,2*sz) res[i]=0;
		REP(i,sz) REP(j,sz) res[i+j]+=a[i]*b[j];
	} else {
		REP(i,2*sz) A[i]=C(i<sz?a[i]:0,0);
		FFT(A,2*sz,+1);
		if(memid!=-1&&memstart[memid]!=-1) {
			REP(i,2*sz) B[i]=mem[memstart[memid]+i];
		} else {
			REP(i,2*sz) B[i]=C(i<sz?b[i]:0,0);
			FFT(B,2*sz,+1);
			if(memid!=-1) { memstart[memid]=nmem; REP(i,2*sz) mem[nmem++]=B[i]; }
		}
		REP(i,2*sz) A[i]=A[i]*B[i];
		FFT(A,2*sz,-1);
		REP(i,2*sz) res[i]=A[i].x/(2*sz);
	}
}


int nstn,ntrn,tmax,fine;
int head[MAXSTN],nxt[MAXTRN],from[MAXTRN],to[MAXTRN],cost[MAXTRN];
double p[MAXTRN][2*MAXT+1];
double psum[MAXTRN][MAXT+1];

int d[MAXSTN][MAXSTN];
double Estn[MAXSTN][MAXT+1];
double Etrn[MAXTRN][MAXT+1];


/*
Etrn(j,t) = expected cost if we take train i with t units left
Estn(i,t) = expected cost if we are at station i with t units left

Estn(dest,t) = 0
Estn(i,t) = min(Etrn(j,t) | train j starts at station i)
Etrn(j,t) = cj+sum(Estn(toj,t-k)*pj[k] | k=1..t)+pj[>t]*(fine+dmin[toj][dest])
*/
void run() {
	scanf("%d%d%d%d",&nstn,&ntrn,&tmax,&fine);
	REP(i,nstn) head[i]=-1;
	REP(i,ntrn) {
		int a,b; scanf("%d%d%d",&a,&b,&cost[i]); --a,--b;
		nxt[i]=head[a]; head[a]=i; from[i]=a; to[i]=b;
		p[i][0]=0; FORE(t,1,tmax) { int x; scanf("%d",&x); p[i][t]=0.00001*x; }
		FORE(t,tmax+1,2*tmax) p[i][t]=0;
		psum[i][0]=p[i][0]; FORE(t,1,tmax) psum[i][t]=psum[i][t-1]+p[i][t];
	}
	//REP(i,nstn) { printf("%d:",i); for(int x=head[i];x!=-1;x=nxt[x]) printf(" %d",to[x]); puts(""); }


	REP(i,nstn) REP(j,nstn) d[i][j]=i==j?0:INT_MAX;
	REP(i,ntrn) if(cost[i]<d[from[i]][to[i]]) d[from[i]][to[i]]=cost[i];
	REP(k,nstn) REP(i,nstn) REP(j,nstn) if(d[i][k]!=INT_MAX&&d[k][j]!=INT_MAX&&d[i][k]+d[k][j]<d[i][j]) d[i][j]=d[i][k]+d[k][j];
	//REP(i,nstn) { REP(j,nstn) printf("%d ",d[i][j]); puts(""); }

	initFFT(); memset(memstart,-1,sizeof(memstart)); nmem=0;
	REP(i,nstn) REPE(t,tmax) Estn[i][t]=i==nstn-1?0:fine+d[i][nstn-1];
	REP(i,ntrn) REPE(t,tmax) Etrn[i][t]=cost[i]+(1-psum[i][t])*(fine+d[to[i]][nstn-1]);
	REPE(t,tmax) {
		REP(i,nstn) for(int x=head[i];x!=-1;x=nxt[x]) if(Etrn[x][t]<Estn[i][t]) Estn[i][t]=Etrn[x][t];
		//printf("T%d:",t); REP(i,ntrn) printf(" %.2lf",Etrn[i][t]); puts("");
		//printf("S%d:",t); REP(i,nstn) printf(" %.2lf",Estn[i][t]); puts("");
		REP(i,ntrn) {
			for(int sz=1,szp=0;(t+1)%sz==0;sz*=2,++szp) {
				int csz=sz; while(csz>1&&t+1+csz/2>tmax) csz/=2;
				conv(Estn[to[i]]+t-sz+1,p[i]+sz,csz,csz==sz?i*100+szp:-1);
				//printf("\t%d (%d..%d)*(%d..%d)->(%d..%d):",t,t-sz+1,t,sz,sz+sz-1,t+1,t+1+2*sz-2); REP(j,2*sz-1) printf(" %.2lf",res[j]); puts("");
				REP(j,2*csz-1) if(t+1+j<=tmax) Etrn[i][t+1+j]+=res[j];
			}
		}
	}
	printf("%.9lf\n",Estn[0][tmax]);
}

int main() {
	run();
	return 0;
}