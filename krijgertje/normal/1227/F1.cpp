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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXQUEST=200000;
const int MOD=998244353;
const int INV2=(MOD+1)/2;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { inc(a,MOD-b); }

int nquest,nkind;
int ans[MAXQUEST];

int inv[MAXQUEST+1];
int fac[MAXQUEST+1];
int ifac[MAXQUEST+1];
int p2[MAXQUEST+1];
int pkind[MAXQUEST+1];
int pkindsub[MAXQUEST+1];
int choose(int n,int k) { if(k<0||k>n) return 0; return (ll)fac[n]*ifac[k]%MOD*ifac[n-k]%MOD; }

int solve() {
	if(nkind==1) return 0;
	inv[1]=1; FORE(i,2,nquest) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1; FORE(i,1,nquest) fac[i]=(ll)fac[i-1]*i%MOD;
	ifac[0]=1; FORE(i,1,nquest) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;
	p2[0]=1; FORE(i,1,nquest) p2[i]=(ll)p2[i-1]*2%MOD;
	pkind[0]=1; FORE(i,1,nquest) pkind[i]=(ll)pkind[i-1]*nkind%MOD;
	pkindsub[0]=1; FORE(i,1,nquest) pkindsub[i]=(ll)pkindsub[i-1]*(nkind-2)%MOD;

	int nsame=0,ndiff=0;
	REP(i,nquest) {
		int j=(i+1)%nquest;
		if(ans[i]==ans[j]) ++nsame; else ++ndiff;
	}

	int ret=0;
	REPE(nval,ndiff) {
		int ways=p2[nval];
		if(nval%2==0) dec(ways,choose(nval,nval/2));
		ways=(ll)ways*INV2%MOD;
		int cur=(ll)choose(ndiff,nval)*ways%MOD*pkindsub[ndiff-nval]%MOD;
		//printf("nval=%d -> ways=%d cur=%d\n",nval,ways,cur);
		inc(ret,cur);
	}
	ret=(ll)ret*pkind[nsame]%MOD;
	return ret;
}

void run() {
	scanf("%d%d",&nquest,&nkind);
	REP(i,nquest) scanf("%d",&ans[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}