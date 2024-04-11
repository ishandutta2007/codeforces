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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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

const int MAXN=1000000;
const int MOD=1000000007;

int n,lim,a,b;

int inv[MAXN+1];
int fac[MAXN+1];
int ifac[MAXN+1];

int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
int C(int n,int k) { if(k<0||k>n) return 0; return (ll)fac[n]*ifac[k]%MOD*ifac[n-k]%MOD; }

int solve() {
	inv[1]=1; FORE(i,2,MAXN) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1; FORE(i,1,MAXN) fac[i]=(ll)fac[i-1]*i%MOD;
	ifac[0]=1; FORE(i,1,MAXN) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;

	int ret=0;
	FORE(pathlen,1,n-1) {
		if(pathlen>lim) continue;
		int waysedgesonpath=C(lim-1,pathlen-1);
		int waysnodesonpath=(ll)C(n-2,pathlen-1)*fac[pathlen-1]%MOD;
		int waysotheredges=pw(lim,n-pathlen-1);
		int waysothernodes=pathlen==n-1?1:(ll)(pathlen+1)*pw(n,n-pathlen-2)%MOD;
		//printf("%d: %d %d %d %d\n",pathlen,waysedgesonpath,waysnodesonpath,waysotheredges,waysothernodes);
		int cur=(ll)waysedgesonpath*waysnodesonpath%MOD*waysotheredges%MOD*waysothernodes%MOD;
		ret=(ret+cur)%MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d%d%d",&n,&lim,&a,&b);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}