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

const int MAXK=1000000;
const int MOD=1000000007;

int mypow(int x,int n) {
	int ret=1;
	for(;n>0;n>>=1) {
		if(n&1) ret=(ll)ret*x%MOD;
		x=(ll)x*x%MOD;
	}
	return ret;
}
int neg(int x) { return x==0?0:MOD-x; }
int myinv(int x) { return mypow(x,MOD-2); }


int n,k;

// f(x)=sum(ai*x^i,i=0..k)=sum(bi*prod(x-j,j=0..i-1),i=0..k)=sum(f(i)*prod(x-xj,j!=i)/prod(xi-xj,j!=i))
// f(0)..f(k) are known

int f[MAXK+2];



void run() {
	scanf("%d%d",&n,&k);

	f[0]=0;
	FORE(i,1,k+1) f[i]=(f[i-1]+mypow(i,k))%MOD;
	//REPE(i,k+1) printf("f[%d]=%d\n",i,f[i]);

	int ret=0;
	if(n<=k+1) {
		ret=f[n];
	} else {
		int mlt=1; FORE(j,1,k+1) mlt=(ll)mlt*(n-j)%MOD; FORE(j,1,k+1) mlt=(ll)mlt*neg(myinv(j))%MOD;
		REPE(i,k+1) {
			//printf("%d: %d\n",i,mlt);
			ret=(ret+(ll)f[i]*mlt)%MOD;
			if(i==k+1) break;
			//printf("\t%d %d %d %d [%d]\n",n-i,myinv(n-i-1),myinv(i+1),neg(k+1-i),n-i-1);
			mlt=(ll)mlt*(n-i)%MOD*myinv(n-i-1)%MOD;
			mlt=(ll)mlt*myinv(i+1)%MOD*neg(k+1-i)%MOD;
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}