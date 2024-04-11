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
#include <complex>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MOD=7340033; // 7*(2^20)+1;
const int PRIMROOT=3;
const int SZ=3500;

int mypow(int a,int k) {
	int ret=1,b=a;
	while(k>0) {
		if(k&1) ret=(ll)ret*b%MOD;
		k>>=1; b=(ll)b*b%MOD;
	}
	return ret;
}

const int N=1<<18;
const int NINV=mypow(N,MOD-2);
const int W=mypow(PRIMROOT,(MOD-1)/N);
const int WINV=mypow(W,MOD-2);
const int INV2=mypow(2,MOD-2);

int rev[N];
int w[N];
int winv[N];


void preFFT() {
	for(int i=1,j=0;i<N;++i) { int bit=N>>1; for(;j>=bit;bit>>=1) j-=bit; j+=bit; rev[i]=j; }
	w[0]=1; FOR(i,1,N) w[i]=(ll)w[i-1]*W%MOD;
	winv[0]=1; FOR(i,1,N) winv[i]=(ll)winv[i-1]*WINV%MOD;
}

void FFT(int a[N],bool invert) {
	REP(i,N) if(i<rev[i]) swap(a[i],a[rev[i]]);
	
	for(int hlen=1,len=2;len<=N;len<<=1,hlen<<=1) {
		int wstep=1; for(int i=len;i<N;i<<=1) wstep*=2;
		for(int i=0;i<N;i+=len) {
			int* cu=a+i,*cv=a+i+hlen,*cw=invert?winv:w,t;
			REP(j,hlen) {
				t=(ll)(*cv)*(*cw)%MOD;
				*cv=*cu-t; //if(*cv<0) *cv+=MOD;
				*cu+=t; //if(*cu>=MOD) *cu-=MOD;
				cu++,cv++,cw+=wstep;
			}
		}
		REP(i,N) if(a[i]<0) a[i]+=MOD; else if(a[i]>=MOD) a[i]-=MOD;
	}
	if(invert) REP(i,N) a[i]=(ll)a[i]*NINV%MOD;
}

char a[200001]; int alen;
char b[200001]; int blen;


int A[N],B[N];
int f(char c) { return c=='0'?MOD-1:+1; }


//precalc[i][j]=sum(k=0..SZ-1,a[i*SZ+k]!=b[j+k])	j=0..blen-SZ
//precalc[i][j]=(SZ-sum(k=0..SZ-1,f(a[i*SZ+k])*f(b[j+k])))/2
int precalc[100][200000];

// (alen/SZ)*2Nlg(N)+nq*(2*SZ+alen/SZ)
// alen*(nq+2Nlg(N))/SZ+2*nq*SZ
// -alen*(nq+2Nlg(N))/(SZ*SZ)+2*nq=0
// SZ=sqrt(alen)*sqrt(1/2+(Nlg(N))/nq)

typedef struct Q { int ai,bi,qlen,idx; } Q;
bool operator<(const Q &u,const Q &v) {
	if(u.ai!=v.ai) return u.ai<v.ai;
	if(u.bi!=v.bi) return u.bi<v.bi;
	return u.qlen<v.qlen;
}
Q q[400000]; int nq;
int ret[400000];

void run() {
	scanf("%s%s",a,b); alen=strlen(a),blen=strlen(b);
	clock_t begin = clock();
	preFFT();

	REP(i,blen) B[blen-i-1]=f(b[i]); FOR(i,blen,N) B[i]=0;
	FFT(B,false);
	fprintf(stderr,"inited %lf\n",double(clock() - begin) / CLOCKS_PER_SEC);

	int nblock=alen/SZ;
	REP(i,nblock) {
		REP(j,SZ) A[j]=f(a[i*SZ+j]); FOR(j,SZ,N) A[j]=0;
		FFT(A,false);
		REP(j,N) A[j]=(ll)A[j]*B[j]%MOD;
		FFT(A,true);
		REPE(j,blen-SZ) {
			int val=SZ-A[blen-j-1]; if(val<0) val+=MOD; val=(ll)val*INV2%MOD;
			precalc[i][j]=val;
		}
		//printf("A:");REP(j,SZ) printf(" %d",A[j]); puts("");
		//printf("p:");REPE(j,blen-SZ) printf(" %d",precalc[i][j]); puts("");
	}
	fprintf(stderr,"precalced %lf\n",double(clock() - begin) / CLOCKS_PER_SEC);

	scanf("%d",&nq);
	REP(qi,nq) { int ai,bi,qlen; scanf("%d%d%d",&q[qi].ai,&q[qi].bi,&q[qi].qlen); q[qi].idx=qi; }
	//sort(q,q+nq);
	REP(qi,nq) {
		int cur=0;
		if(qi!=0&&q[qi].ai==q[qi-1].ai&&q[qi].bi==q[qi-1].bi&&q[qi].qlen==q[qi-1].qlen) { ret[q[qi].idx]=ret[q[qi-1].idx]; continue; }
		int ai=q[qi].ai,bi=q[qi].bi,qlen=q[qi].qlen,idx=q[qi].idx;
		int nai=ai/SZ*SZ; if(nai<ai) nai+=SZ; int dai=min(qlen,nai-ai);
		REP(i,dai) if(a[ai+i]!=b[bi+i]) ++cur; ai+=dai; bi+=dai; qlen-=dai;
		int nqlen=qlen/SZ*SZ,dqlen=qlen-nqlen;
		REP(i,dqlen) if(a[ai+nqlen+i]!=b[bi+nqlen+i]) ++cur; qlen-=dqlen;
		int sblock=ai/SZ,cntblock=qlen/SZ;
		//printf("\t%d %d %d (%d) -> %d,%d\n",ai,bi,qlen,ret,sblock,cntblock);
		REP(i,cntblock) cur+=precalc[sblock+i][bi+i*SZ];
		ret[idx]=cur;
	}
	REP(qi,nq) printf("%d\n",ret[qi]);
	fprintf(stderr,"done %lf\n",double(clock() - begin) / CLOCKS_PER_SEC);
}

int myrand() { int ret=rand()*RAND_MAX+rand(); if(ret<0) ret=-ret; return ret; }

void gen() {
	alen=200,blen=200;
	int nq=400;
	REP(i,alen) a[i]='0'+rand()%2; REP(i,blen) b[i]='0'+rand()%2;
	a[alen]=b[blen]='\0';
	printf("%s\n%s\n",a,b);
	printf("%d\n",nq);
	REP(i,nq) {
		int qlen=1+myrand()%min(alen,blen);
		int ai=myrand()%(alen-qlen+1),bi=myrand()%(blen-qlen+1);
		printf("%d %d %d\n",ai,bi,qlen);
	}
}

int main() {
	//gen(); exit(0);
	run();
	return 0;
}