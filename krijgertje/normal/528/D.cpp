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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MOD=7340033; // 7*(2^20)+1;
const int PRIMROOT=3;


int mypow(int a,int k) {
	int ret=1,b=a;
	while(k>0) {
		if(k&1) ret=(ll)ret*b%MOD;
		k>>=1; b=(ll)b*b%MOD;
	}
	return ret;
}

const int N=1<<19;
const int NINV=mypow(N,MOD-2);
const int W=mypow(PRIMROOT,(MOD-1)/N);
const int WINV=mypow(W,MOD-2);


void fft(int a[N],bool invert) {
	for(int i=1,j=0;i<N;++i) { int bit=N>>1; for(;j>=bit;bit>>=1) j-=bit; j+=bit; if(i<j) swap(a[i],a[j]); }
	for(int len=2;len<=N;len<<=1) {
		int wstep=invert?WINV:W; for(int i=len;i<N;i<<=1) wstep=(ll)wstep*wstep%MOD;
		for(int i=0;i<N;i+=len) {
			int w=1;
			REP(j,len/2) {
				int u=a[i+j],v=(ll)a[i+j+len/2]*w%MOD;
				a[i+j]=u+v<MOD?u+v:u+v-MOD; a[i+j+len/2]=u-v>=0?u-v:u-v+MOD;
				w=(ll)w*wstep%MOD;
			}
		}
	}
	if(invert) REP(i,N) a[i]=(ll)a[i]*NINV%MOD;
}


int A[N];
int B[N];
int C[N];

const char c[4]={'A','C','G','T'};

int slen,tlen,maxdist;
char s[200001],t[200001];
bool ret[200000];



void run() {
	scanf("%d%d%d%s%s",&slen,&tlen,&maxdist,s,t);
	REPE(j,slen-tlen) ret[j]=true;
	REP(i,4) {
		memset(A,0,sizeof(A)); memset(B,0,sizeof(B));
		REP(j,slen) if(s[j]==c[i]) { int fst=max(0,j-maxdist),lst=min(slen-1,j+maxdist); A[fst]++; if(lst+1<slen) A[lst+1]--; }
		FOR(j,1,slen) A[j]+=A[j-1];
		REP(j,slen) if(A[j]>1) A[j]=1;
		int bcnt=0; REP(j,tlen) if(t[j]==c[i]) B[tlen-j-1]=1,++bcnt;
		//printf("%c A:",c[i]); REP(j,slen) printf(" %d",A[j]); puts("");
		//printf("%c B:",c[i]); REP(j,tlen) printf(" %d",B[j]); puts("");
		fft(A,false); fft(B,false); REP(j,N) C[j]=(ll)A[j]*B[j]%MOD; fft(C,true);
		//printf("%c C:",c[i]); REP(j,slen+tlen-1) printf(" %d",C[j]); puts("");
		REPE(j,slen-tlen) if(C[j+tlen-1]!=bcnt) ret[j]=false;
	}
	int nret=0; REPE(j,slen-tlen) if(ret[j]) ++nret; printf("%d\n",nret);
}

int main() {
	run();
	return 0;
}