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

const int MOD=1000000007;
const int MAXVAL=1000001;

int n,m;
int inv[MAXVAL+1];

int mypow(int x,int n) {
	int ret=1;
	while(true) {
		if(n&1) ret=(ll)ret*x%MOD;
		if((n>>=1)==0) return ret;
		x=(ll)x*x%MOD;
	}
}

void run() {
	scanf("%d%d",&n,&m);
	if(m==1) { printf("%d\n",(int)((ll)mypow(m,n)*(n+1)%MOD)); return; }
	inv[1]=1; FORE(i,2,MAXVAL) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;

	// ret=sum(sum(#(subsequences of length n containing x),x|x is a sequence of length k),k=0..n)
	// [k>0] #(subsequences of length n containing x)=#((m-1)^a0*(m-1)^a1*...*(m-1)^a{k-1}*m^ak,sum(ai)==n-k)=sum((m-1)^(n-k-ak)*m^ak*C(n-ak-1,k-1),ak=0..n-k)
	// ret=m^n+sum(sum((m-1)^(n-k-ak)*m^ak*C(n-ak-1,k-1),ak=0..n-k)*m^k,k=1..n)
	// s=k+ak: ret=m^n+sum(sum((m-1)^(n-s)*m^s*C(n-s+k-1,k-1),s=k..n),k=1..n)
	// ret=m^n+sum(sum((m-1)^(n-s)*m^s*C(n-s+k-1,k-1),k=1..s),s=1..n)
	// k'=k-1: ret=m^n+sum((m-1)^(n-s)*m^s*sum(C(n-s+k,n-s),k=0..s-1),s=1..n)
	// ret=m^n+sum((m-1)^(n-s)*m^s*sum(C(n-s+k,n-s),k=0..s-1),s=1..n)
	// ret=m^n+sum((m-1)^(n-s)*m^s*C(n,s-1),s=1..n) [diagonal sum of pascals triangle]

	//x=m/(m-1)*(n-s+1)/s
	int ret=mypow(m,n);
	ll cur=(ll)mypow(m-1,n-1)*m%MOD;
	FORE(s,1,n) {
		if((ret+=cur)>=MOD) ret-=MOD;
		cur=(ll)cur*m%MOD*inv[m-1]%MOD*(n-s+1)%MOD*inv[s]%MOD;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}