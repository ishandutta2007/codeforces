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

const int MAXK=200;
const int MOD=1000000007;

typedef struct F { int a,b; F(int a,int b):a(a),b(b) {} } F; // a+b*sqrt(5)
F operator+(const F &p,const F &q) { int a=p.a+q.a,b=p.b+q.b; if(a>=MOD) a-=MOD; if(b>=MOD) b-=MOD; return F(a,b); }
F operator*(const F &p,const F &q) { return F(((ll)p.a*q.a+(ll)p.b*q.b*5)%MOD,((ll)p.a*q.b+(ll)p.b*q.a)%MOD); }
F mypow(F p,ll n) { F ret(1,0); while(true) { if(n&1) ret=ret*p; if((n>>=1)==0) return ret; p=p*p; } }
F mysumpow(F p,ll n) {
	//printf("mysumpow(%d+%d*sqrt(5),%lld)\n",p.a,p.b,n);
	F ret(0,0),q(1,0),pp=p; int nn=n; ++n;
	while(true) {
		if(n&1) ret=ret*p+q;
		if((n>>=1)==0) break;
		q=q+p*q; p=p*p;
	}
	//printf("=(%d+%d*sqrt(5))\n",ret.a,ret.b);
	//F chk(0,0); REPE(i,nn) chk=chk+mypow(pp,i); if(chk.a!=ret.a||chk.b!=ret.b) printf("!!! chk=(%d+%d*sqrt(5))\n",chk.a,chk.b);
	return ret;
}

int k; ll l,r;
int a[MAXK+1];
int fact[MAXK+1];
int inv[MAXK+1];
int ifact[MAXK+1];
int C[MAXK+1][MAXK+1];

// fib[x]=fib[x-2]+fib[x-1], fib[0]=0, fib[1]=1
// fib[x]=p^x -> 1+p-p^2=0 -> p/q=1/2+-1/2*sqrt(5), fib[x]=a*p^x+b*q^x -> fib[0]=0=a+b->b=-a, fib[1]=1=a*sqrt(5)->a=1/sqrt(5) -> fib[x]=1/sqrt(5)*(p^x-q^x)
// sum(x=l..r,C[fib[x+2],k]) = sum(x=0..r,C[fib[x+2],k]) - sum(x=0..l-1,C[fib[x+2],k])
// sum(x=0..r,C[fib[x+2],k]) = sum(x=0..r,sum(i=0..k,a[i]*fib[x+2]^i)) = sum(i=0..k,a[i]*(sum(x=0..r+2,fib[x]^i)-1))
// sum(x=0..n,fib[x]^i) = sum(x=0..n,(1/sqrt(5)*(p^x-q^x))^i) = (sqrt(5)/5)^i*sum(x=0..n,sum(j=0..i,C[i,j]*(p^x)^j*(-1)^(i-j)*(q^x)^(i-j)))
// = (sqrt(5)/5)^i*sum(j=0..i,C[i,j]*(-1)^(i-j)*sum(x=0..n,(p^j*q^(i-j))^x))

int sumfibpow(ll n,int i) {
	F ret(0,0);
	F p(inv[2],inv[2]),q(inv[2],MOD-inv[2]);
	REPE(j,i) {
		int coeff=C[i][j]; if((i-j)%2!=0) coeff=coeff==0?0:MOD-coeff;
		F r(mypow(p,j)*mypow(q,i-j));
		F s=mysumpow(r,n);
		F cur=F(coeff,0)*s;
		ret=ret+cur;
	}
	ret=ret*mypow(F(0,inv[5]),i);
	assert(ret.b==0);
	//printf("sumfibpow(%lld,%d)=%d\n",n,i,ret.a);
	return ret.a;
}

int calc(ll r) {
	int ret=0;
	REPE(i,k) {
		int cur=sumfibpow(r+2,i)-1;
		ret=(ret+(ll)cur*a[i])%MOD;
	}
	//printf("calc(%lld)=%d\n",r,ret);
	return ret;
}

void run() {
	scanf("%d%lld%lld",&k,&l,&r);
	fact[0]=1; FORE(i,1,MAXK) fact[i]=(ll)fact[i-1]*i%MOD;
	inv[1]=1; FORE(i,2,MAXK) inv[i]=(ll)(MOD-(MOD/i))*inv[MOD%i]%MOD;
	ifact[0]=1; FORE(i,1,MAXK) ifact[i]=(ll)ifact[i-1]*inv[i]%MOD;
	REPE(i,MAXK) { C[i][0]=C[i][i]=1; FOR(j,1,i) if((C[i][j]=C[i-1][j-1]+C[i-1][j])>=MOD) C[i][j]-=MOD; }

	// C[x,k] = a[0]+a[1]*x+...+a[k]*x^k
	// C[x,k] = x!/k!/(x-k)! = x*(x-1)*...*(x-k+1)/k!
	a[0]=ifact[k];
	REP(i,k) { int t=i==0?0:MOD-i; a[i+1]=0; for(int j=i+1;j>0;--j) a[j]=(a[j-1]+(ll)t*a[j])%MOD; a[0]=(ll)t*a[0]%MOD; }
	//REPE(i,k) printf("%d*x^%d ",a[i],i); puts("");
	//FORE(x,2,20) { int cur=0; REPE(i,k) { int tmp=1; REP(j,i) tmp=(ll)tmp*x%MOD; cur=(cur+(ll)tmp*a[i])%MOD; } printf("%d = %d\n",x,cur); }


	int ret=calc(r)-calc(l-1); if(ret<0) ret+=MOD; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}