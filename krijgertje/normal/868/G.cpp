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

const int MOD=1000000007;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
int inv(int x) { x%=MOD; assert(x!=0); return pw(x,MOD-2); }

struct LinTrans { int a,b; LinTrans():a(1),b(0) {} LinTrans(int a,int b):a(a),b(b) {} int eval(int x) { return ((ll)a*x+b)%MOD; } }; // a*x+b
LinTrans add(const LinTrans &u,const LinTrans &v) { return LinTrans((u.a+v.a)%MOD,(u.b+v.b)%MOD); }
LinTrans mlt(const LinTrans &u,const LinTrans &v) { return LinTrans((ll)u.a*v.a%MOD,((ll)u.a*v.b+u.b)%MOD); }
LinTrans pw(LinTrans x,int n) { LinTrans ret(1,0); while(true) { if(n&1) ret=mlt(ret,x); if((n>>=1)==0) return ret; x=mlt(x,x); } }
LinTrans inv(const LinTrans &u) { int tmp=inv(u.a); return LinTrans(tmp,(MOD-(ll)tmp*u.b%MOD)%MOD); }
LinTrans sum(LinTrans x,int n) { // sum(i=0..n-1,A^i)
	if(x.a==1) return LinTrans((ll)x.a*n%MOD,(ll)n*(n-1)/2%MOD*x.b%MOD);
	int den=inv(x.a+MOD-1);
	return LinTrans((ll)(pw(x.a,n)+MOD-1)*den%MOD,(((ll)pw(x.a,n)+MOD-1)*den+MOD-n)%MOD*den%MOD*x.b%MOD);
}
	
// x[i]=A(x[i+n-k]) for i<k, x[i]=B(x[i-k]) for i>=k
// Inverted: x[i]=B^{-1}(x[i+k]) for i+k<n, x[i]=A^{-1}(x[i-n+k]) for i>=n-k
// x[i]=B^{-(n/k)}(A^{-1}(x[i+k-n%k]))	for i<n%k
// x[i]=B^{-(n/k-1)}(A^{-1}(x[i-n%k]))	for i>=n%k
// sum(i<k,SA(x[i]))+sum(i>=k,SB(x[i])) becomes sum(i<n%k,SA(x[i])+sum(j=1..n/k,SB(B^j(x[i])))+sum(i>=n%k,SA(x[i])+sum(j=1..n/k-1,SB(B^j(x[i]))) 

int calc(int n,int k,LinTrans A,LinTrans B,LinTrans SA,LinTrans SB) {
	//printf("calc(%d,%d,%dx+%d,%dx+%d,%dx+%d,%dx+%d)\n",n,k,A.a,A.b,B.a,B.b,SA.a,SA.b,SB.a,SB.b);
	if(k==0) {
		// x[i]=B(x[i]) -> x[i]=B.a*x[i]+B.b -> x[i]=B.b/(1-B.a)
		int x=(ll)B.b*inv(1+MOD-B.a)%MOD;
		//printf("x=%d\n",x);
		return (ll)n*SB.eval(x)%MOD;
	} else {
		LinTrans Ainv=inv(A),Binv=inv(B);
		//printf("Ainv=%dx+%d Binv=%dx+%d [%dx+%d,%dx+%d,%dx+%d,%dx+%d]\n",Ainv.a,Ainv.b,Binv.a,Binv.b,mlt(A,Ainv).a,mlt(A,Ainv).b,mlt(Ainv,A).a,mlt(Ainv,A).b,mlt(B,Binv).a,mlt(B,Binv).b,mlt(Binv,B).a,mlt(Binv,B).b);
		LinTrans tmp1=pw(Binv,n/k-1);
		//printf("tmp1=%dx+%d\n",tmp1.a,tmp1.b);
		LinTrans nA=mlt(mlt(tmp1,Binv),Ainv),nB=mlt(tmp1,Ainv);
		//printf("nA=%dx+%d nB=%dx+%d\n",nA.a,nA.b,nB.a,nB.b);
		LinTrans tmp2=sum(B,n/k);
		LinTrans tmp3=LinTrans((ll)SB.a*mlt(tmp2,B).a%MOD,((ll)SB.a*mlt(tmp2,B).b+(ll)SB.b*(n/k))%MOD),tmp4=LinTrans((ll)SB.a*(tmp2.a+MOD-1)%MOD,((ll)SB.a*tmp2.b+(ll)SB.b*(n/k-1))%MOD);
		//printf("tmp2=%dx+%d tmp3=%dx+%dx tmp4=%dx+%d\n",tmp2.a,tmp2.b,tmp3.a,tmp3.b,tmp4.a,tmp4.b);
		LinTrans nSA=add(SA,tmp3),nSB=add(SA,tmp4);
		//printf("nSA=%dx+%d nSB=%dx+%d\n",nSA.a,nSA.b,nSB.a,nSB.b);
		return calc(k,n%k,nA,nB,nSA,nSB);
	}

	// SB.a*(A^0.a*x+A^0.b)+SB.b+SB.a*(A^1.a*x+A^1.b)+SB.b+SB.a*(A^2.a*x+A^2.b)+SB.b+SB.a*(A^3.a*x+A^3.b)+SB.b
	// SB.a*(A^0.a+A^1.a+A^2.a+A^3.a)*x+(SB.a*(A^0.b+A^1.b+A^2.b+A^3.b)+4*SB.b)
}

void run() {
	int n,k; scanf("%d%d",&n,&k);
	int sum=calc(n,k,LinTrans((MOD+1)/2,1),LinTrans(1,1),LinTrans(1,0),LinTrans(1,0));
	int ans=(ll)sum*inv(n)%MOD;
	printf("%d\n",ans);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}