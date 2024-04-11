#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
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

const int MOD=7340033;

ll f[31][1024];
ll g[5][31][1024];

ll tmp[6*1024];

void basic(ll *a,ll *b,ll *ret,int n) {
	REP(i,2*n) ret[i]=0;
	REP(i,n) REP(j,n) ret[i+j]=(ret[i+j]+a[i]*b[j])%MOD;
}

void convolute(ll *a,ll *b,ll *ret,int n) {
	int nn=n/2;
	ll *a1=&a[0],*a2=&a[nn],*b1=&b[0],*b2=&b[nn];
	ll *asum=&ret[5*n],*bsum=&ret[5*n+nn];
	ll *x1=&ret[0],*x2=&ret[n],*x3=&ret[2*n];
	
	if(n<=4) { basic(a,b,ret,n); return; }
	REP(i,nn) {
		asum[i]=a1[i]+a2[i]; if(asum[i]>=MOD) asum[i]-=MOD;
		bsum[i]=b1[i]+b2[i]; if(bsum[i]>=MOD) bsum[i]-=MOD;
	}
	convolute(a1,b1,x1,nn);
	convolute(a2,b2,x2,nn);
	convolute(asum,bsum,x3,nn);
	REP(i,n) { x3[i]-=x1[i]+x2[i]; if(x3[i]<0) x3[i]+=MOD; if(x3[i]<0) x3[i]+=MOD; }
	REP(i,n) { ret[i+nn]+=x3[i]; if(ret[i+nn]>=MOD) ret[i+nn]-=MOD; }
}

void precalc() {
	f[0][0]=g[4][0][0]=1; FOR(j,1,1024) f[0][j]=g[4][0][j]=0;
	FORE(i,1,30) {
		f[i][0]=1; FOR(j,1,1024) f[i][j]=g[4][i-1][j-1];
		g[0][i][0]=1; FOR(j,1,1024) g[0][i][j]=0;
		convolute(f[i],g[0][i],tmp,1024); REP(j,1024) g[1][i][j]=tmp[j];
		convolute(f[i],g[1][i],tmp,1024); REP(j,1024) g[2][i][j]=tmp[j];
		convolute(f[i],g[2][i],tmp,1024); REP(j,1024) g[3][i][j]=tmp[j];
		convolute(f[i],g[3][i],tmp,1024); REP(j,1024) g[4][i][j]=tmp[j];
	}
}

void run(int casenr) {
	int n,k; scanf("%d%d",&n,&k);
	int m=0; while(n%2==1&&n>=3) { ++m; n=(n-1)/2; }
	printf("%d\n",(int)f[m][k]);
}

int main() {
	precalc();
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}