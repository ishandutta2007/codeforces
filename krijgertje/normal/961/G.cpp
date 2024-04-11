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

const int MAXN=200000;
const int MOD=1000000007;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int n,want;
int w[MAXN];

int inv[MAXN+1];
int ifac[MAXN+1];

int s2(int n,int k) {
	if(k>n) return 0;
	// sum(j=0..k,(-1)^(k-j)*ifac[j]*ifac[k-j]*j^n)
	int ret=0;
	REPE(j,k) {
		int cur=(ll)ifac[j]*ifac[k-j]%MOD*pw(j,n)%MOD;
		if((k-j)%2==0) ret=(ret+cur)%MOD; else ret=(ret+MOD-cur)%MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&want); REP(i,n) scanf("%d",&w[i]);

	inv[1]=1; FORE(i,2,n) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	ifac[0]=1; FORE(i,1,n) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;

	int a=s2(n,want),b=s2(n-1,want),c=n-1;
	int d=(a+(ll)b*c)%MOD;
	int sum=0; REP(i,n) sum=(sum+w[i])%MOD;
	//printf("a=%d b=%d c=%d sum=%d\n",a,b,c,sum);
	int ans=(ll)d*sum%MOD;
	printf("%d\n",ans);
}

int main() {
	run();
	return 0;
}