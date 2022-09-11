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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

/*
A^M*p

A*x=lambda*x
for all i: sum(j=i..n,xj/(j+1))=lambda*xi
sum(j=k..n,xj/(j+1))-sum(j=k+1..n,xj/(j+1))=lambda*xk-lambda*x{k+1}
x{k+1}=xk*(1-1/(k+1)/lambda)
x{k+1}=xk*(k+1-ilambda)/(k+1)
x{k}=x0*prod(i=1..k,(i-ilambda)/i)
x{k}=0 voor k>=ilambda, anders:
x{k}=x0*(-1)^k*prod(i=1..k,(ilambda-i)/i)
x{k}=x0*(-1)^k*(ilambda-1)!/(ilambda-1-k)!/k!
x{k}=x0*(-1)^k*C(ilambda-1,k)


y*A=lambda*y
for all i: 1/(i+1)*sum(j=0..i,yj)=lambda*yi
1/(k+1)*sum(j=0..k,yj)-k/(k+1)*1/(k-1+1)*sum(j=0..k-1,yj)=lambda*yk-k/(k+1)*lambda*y{k-1}
1/(k+1)*yk=lambda*(yk-k/(k+1)*y{k-1})
1/(k+2)*y{k+1}=lambda*(y{k+1)-(k+1)/(k+2)*yk)
y{k+1}*(lambda-1/(k+2))=lambda*(k+1)/(k+2)*yk
y{k+1}=yk*lambda*(k+1)/((k+2)*lambda-1)
y{k+1}=yk*(k+1)/(k+2-ilambda)
y{ilambda-1}=1
y{k}=prod(i=ilambda-1..k-1,(i+1)/(i+2-ilambda))
y{k}=prod(i=1..k-(ilambda-1),(i+ilambda-1)/i)
y{k}=C(k,ilambda-1)

[y0 y1 ... yn]' * D^M * [x0 x1 .. xn] * p

conv(a,b){i}=sum(j=0..i,a(i)*b(i-j))
ai=sum(j=0..n,xj{i}*pj)=sum(j=0..n,(-1)^i*C(j,i)*pj)=(-1)^i/i!*sum(j=i..n,pj*j!*1/(j-i)!)
=(-1)^i/i!*sum(j=0..n-i,p{n-j}*(n-j)!*1/(n-i-j)!)=(-1)^i/i!*conv(p{n-k}*(n-k)!,1/k!){n-i}
bi=sum(j=0..n,yi{j}*dj)=sum(j=0..n,(-1)^i*C(j,i)*dj)=(-1)^i/i!*sum(j=i..n,dj*j!*1/(j-i)!)=(-1)^i/i!*conv(d{n-k}*(n-k)!,1/k!){n-i}
*/

const int MAXN=100000;
const int MOD=998244353;
int pw(int x,ll n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int fact[MAXN+1];
int inv[MAXN+2];
int ifact[MAXN+1];

const int MAXFFT=1<<18;
const int PRIMROOT=3;
int rootpw[MAXFFT];
void fft(int *to,int *from,int step,int n) {
	if(n==1) { to[0]=from[0]; return; }
	int h=n/2;
	fft(to,from,step+1,h);
	fft(to+h,from+(1<<step),step+1,h);
	REP(i,h) {
		int e=to[i],o=(ll)to[i+h]*rootpw[i<<step]%MOD;
		to[i]=e+o; if(to[i]>=MOD) to[i]-=MOD;
		to[i+h]=e-o; if(to[i+h]<0) to[i+h]+=MOD;
	}
}
int A[MAXFFT],B[MAXFFT],C[MAXFFT],AA[MAXFFT],BB[MAXFFT],CC[MAXFFT];
void conv(int *a,int na,int *b,int nb,int *c,int nc) {
	//REP(i,nc) c[i]=0; REP(i,na) REP(j,nb) if(i+j<nc) c[i+j]=(c[i+j]+(ll)a[i]*b[j])%MOD;
	int n=1; while(n<na+nb) n*=2;
	REP(i,n) A[i]=i<na?a[i]:0,B[i]=i<nb?b[i]:0;
	int root=pw(PRIMROOT,(MOD-1)/n);
	rootpw[0]=1; FOR(i,1,n) rootpw[i]=(ll)rootpw[i-1]*root%MOD;
	fft(AA,A,0,n);
	fft(BB,B,0,n);
	REP(i,n) CC[i]=(ll)AA[i]*BB[i]%MOD;
	reverse(rootpw+1,rootpw+n);
	fft(C,CC,0,n);
	int mlt=pw(n,MOD-2); REP(i,n) C[i]=(ll)C[i]*mlt%MOD;
	REP(i,nc) c[i]=i<n?C[i]:0;
}

int n; ll nsteps;
int p[MAXN+1];

int u[MAXN+1],v[MAXN+1],w[2*MAXN+1];

int a[MAXN+1];
int d[MAXN+1];
int b[MAXN+1];

void solve() {
	fact[0]=1; FORE(i,1,MAXN) fact[i]=(ll)fact[i-1]*i%MOD;
	inv[1]=1; FORE(i,2,MAXN+1) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	ifact[0]=1; FORE(i,1,MAXN) ifact[i]=(ll)ifact[i-1]*inv[i]%MOD;

	REPE(i,n) u[i]=(ll)p[n-i]*fact[n-i]%MOD,v[i]=ifact[i];
	conv(u,n+1,v,n+1,w,2*n+1);
	REPE(i,n) a[i]=(ll)(i%2==0?1:MOD-1)*ifact[i]%MOD*w[n-i]%MOD;
	//printf("a:"); REPE(i,n) printf(" %d",a[i]); puts("");
	
	REPE(i,n) d[i]=(ll)a[i]*pw(inv[i+1],nsteps)%MOD;
	//printf("d:"); REPE(i,n) printf(" %d",d[i]); puts("");

	REPE(i,n) u[i]=(ll)d[n-i]*fact[n-i]%MOD,v[i]=ifact[i];
	conv(u,n+1,v,n+1,w,2*n+1);
	REPE(i,n) b[i]=(ll)(i%2==0?1:MOD-1)*ifact[i]%MOD*w[n-i]%MOD;
	//printf("b:"); REPE(i,n) printf(" %d",b[i]); puts("");

}

void run() {
	scanf("%d%lld",&n,&nsteps); REPE(i,n) scanf("%d",&p[i]);
	solve();
	REPE(i,n) { if(i!=0) printf(" "); printf("%d",b[i]); } puts("");
}

void stress() {
	n=MAXN; nsteps=(ll)1000000000*1000000000; REPE(i,n) p[i]=rand();
	solve();
}

int main() {
	run();
	//stress();
	return 0;
}