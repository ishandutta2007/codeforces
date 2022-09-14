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


// F(x)=sum(k*x^i) -> there are k good rooted binary trees with weight i (including empty tree)

// F(x)=A(x)*F(x)*F(x)+1
// -> A(x)*F(x)*F(x)-F(x)+1=0 -> F(x)=(1+sign*sqrt(1-4A(x)))/(2A(x)) ->F(x)=1/(1/2*(1-sign*sqrt(1-4A(x))))
// B=1-4*A
// C=sqrt(B)
// Cni2m=2*Cnim-Cnim*Cnim*Cn
// C2n=1/2*(Cn+B*Cni2n)
// D=1/2*(1-sign*C)
// E=1/D
// E2n=2*En-En*En*D

// En*A=1 (mod x^n)
// (En*A-1)^2=0 (mod x^2n)
// En*En*A*A-2*En*A+1=0 (mod x^2n)
// (2*En-En*En*A)*A=1 (mod x^2n)

// Cn*Cn=B (mod x^n)
// (Cn*Cn-B)^2=0 (mod x^2n)
// Cn*Cn*Cn*Cn-2*B*Cn*Cn+B*B=0 (mod x^2n)
// (1/2*(Cn+B*Cni2n))^2=B (mod x^2n)

const int MOD=998244353;
const int SZ=(1<<17);
const int PRIMROOT=3;

typedef struct modint {
	int val;
	modint() { val=0; }
	modint(int _val) { val=_val%MOD; if(val<0) val+=MOD; }
	modint(ll _val) { val=_val%MOD; if(val<0) val+=MOD; }
} modint;
modint operator-(const modint &a) { return modint(-a.val); }
modint operator+(const modint &a,const modint &b) { return modint(a.val+b.val); }
modint operator*(const modint &a,const modint &b) { return modint((ll)a.val*b.val); }
modint mpow(const modint &a,const int &n) {
	modint ret=modint(1),cur=a;
	for(int i=n;i>0;i/=2) { if(i&1) ret=ret*cur; cur=cur*cur; }
	return ret;
}
modint inv(const modint &a) { return mpow(a,MOD-2); }

modint rootpow[2*SZ];
void fft(modint *to,modint *from,int step,int n) {
	if(n==1) { to[0]=from[0]; return; }
	int h=n/2;
	fft(to,from,step+1,h);
	fft(to+h,from+(1<<step),step+1,h);
	REP(i,h) {
		modint e=to[i],o=to[i+h]*rootpow[i<<step];
		to[i]=e+o;
		to[i+h]=e+(-o);
	}
}

void pprint(modint *f,int sz) {
	bool first=true;
	REP(i,sz) if(f[i].val!=0) {
		if(f[i].val<MOD/2) {
			if(first) first=false; else printf("+");
			if(f[i].val!=1||i==0) printf("%d",f[i].val);
		} else {
			if(first) first=false; printf("-");
			if(MOD-f[i].val!=1||i==0) printf("%d",MOD-f[i].val);
		}
		if(i>0) printf("x");
		if(i>1) printf("^%d",i);
	}
	if(first) printf("0");
}

void pmult(modint *f,modint *g,int sz) {
/*	static modint h[2*SZ];
	REP(i,2*sz) h[i]=modint(0);
	REP(i,sz) REP(j,sz) h[i+j]=h[i+j]+f[i]*g[j];
	REP(i,2*sz) f[i]=h[i]; */
	static modint tf[2*SZ],tg[2*SZ];
	REP(i,sz) tf[i]=f[i]; FOR(i,sz,2*sz) tf[i]=modint(0);
	REP(i,sz) tg[i]=g[i]; FOR(i,sz,2*sz) tg[i]=modint(0);
	modint root=mpow(PRIMROOT,(MOD-1)/(2*sz));
	rootpow[0]=1; FOR(i,1,2*SZ) rootpow[i]=rootpow[i-1]*root;
	static modint dftf[2*SZ],dftg[2*SZ];
	fft(dftf,tf,0,2*sz);
	fft(dftg,tg,0,2*sz);
	REP(i,2*sz) dftf[i]=dftf[i]*dftg[i];
	reverse(rootpow+1,rootpow+2*SZ);
	fft(tf,dftf,0,2*sz);
	reverse(rootpow+1,rootpow+2*SZ);
	modint mult=inv(2*sz);
	REP(i,2*sz) f[i]=tf[i]*mult;
}

void pcopy(modint *f,modint *g,int sz) {
	REP(i,sz) f[i]=g[i];
}

void pneg(modint *f,int sz) {
	REP(i,sz) f[i]=-f[i];
}

void padd(modint *f,modint *g,int sz) {
	REP(i,sz) f[i]=f[i]+g[i];
}

void padd2(modint *f,modint *g,int sz) {
	REP(i,sz) f[i]=f[i]+modint(2)*g[i];
}

void pclear(modint *f,int sz1,int sz2) {
	FOR(i,sz1,sz2) f[i]=modint(0);
}

void pdiv2(modint *f,int sz) {
	REP(i,sz) f[i]=f[i]*modint((MOD+1)/2);
}

int n,m;
modint A[SZ];
modint B[SZ];
modint C[SZ];
modint Ci[SZ];
modint Ci2[2*SZ];
modint D[SZ];
modint E[2*SZ];
modint TMP[2*SZ];

void run() {
	memset(A,0,sizeof(A));
	scanf("%d%d",&n,&m);
	REP(i,n) { int x; scanf("%d",&x); A[x]=A[x]+modint(1); }

	int msz=2; while(msz<=m) msz*=2;
	REP(i,msz) B[i]=modint(i==0?1:0)+modint(-4)*A[i];
	C[0]=1; if(B[1].val!=0) C[1]=modint(-2);
	Ci[0]=1;
	Ci2[0]=1;
	for(int sz=4;sz<=msz;sz*=2) { // Ci==C{sz/4}i{sz/4} C=C{sz/2}
		pmult(Ci,Ci,sz/4); pmult(Ci,C,sz/2); pneg(Ci,sz/2); padd2(Ci,Ci2,sz/4);
		pcopy(Ci2,Ci,sz/2); pmult(Ci2,Ci2,sz/2); pmult(Ci2,C,sz);  pneg(Ci2,sz); padd2(Ci2,Ci,sz/2);
		pcopy(TMP,Ci2,sz); pmult(TMP,B,sz); pclear(C,sz/2,sz); padd(C,TMP,sz); pdiv2(C,sz);
//		printf("C%di%d=",sz/2,sz/2); pprint(Ci,sz/2); puts("");
//		printf("C%di%d=",sz/2,sz); pprint(Ci2,sz); puts("");
//		printf("C%d=",sz); pprint(C,sz); puts("");
	}
	pcopy(D,C,msz); D[0]=D[0]+modint(1); pdiv2(D,msz);
//	printf("D="); pprint(D,msz); puts("");
	E[0]=1;
	for(int sz=2;sz<=msz;sz*=2) { // E=E{sz/2}
		pcopy(TMP,E,sz/2); pmult(E,E,sz/2); pmult(E,D,sz); pneg(E,sz); padd2(E,TMP,sz/2);
//		printf("E%d=",sz); pprint(E,sz); puts("");
	}
	FORE(i,1,m) printf("%d\n",E[i].val);
}

int main() {
	run();
	return 0;
}