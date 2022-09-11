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

const int MAXN=1000000;
const int MOD=1000000007;

int n,k;
int fac[MAXN+1];
int inv[MAXN+1];
int ifac[MAXN+1];
int C(int n,int k) { if(k<0||k>n) return 0; return (ll)fac[n]*ifac[k]%MOD*ifac[n-k]%MOD; }

int dp[MAXN+1]; // dp[i]=number errors for length i where the largest element is on the last position
int dp2[MAXN+1]; // dp2[i]=number errors for length 1 where the largest element is on one of the last k positions
int dpsum[MAXN+2];

void run() {
	fac[0]=1; FORE(i,1,MAXN) fac[i]=(ll)fac[i-1]*i%MOD;
	inv[1]=1; FORE(i,2,MAXN) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	ifac[0]=1; FORE(i,1,MAXN) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;
	
	scanf("%d%d",&n,&k);
	REPE(i,n) {
		if(i<k+2) { dp[i]=dp2[i]=0; continue; }
		dp[i]=(ll)(i-k-1)*fac[i-2]%MOD;
		dp[i]=(dp[i]+dp2[i-1])%MOD;
		dp2[i]=dp[i];
		dp2[i]=(dp2[i]+(ll)dp2[i-1]*(i-1))%MOD;
		dp2[i]=(dp2[i]+MOD-(ll)dp[i-k]*C(i-1,k)%MOD*fac[k]%MOD)%MOD;
		//printf("%d: dp=%d dp2=%d\n",i,dp[i],dp2[i]);
	}
	int ret=0; FORE(i,1,n) ret=(ret+(ll)dp[i]*C(n-1,n-i)%MOD*fac[n-i])%MOD;
	printf("%d\n",ret);

	//vector<int> p(n); REP(i,n) p[i]=i; int chk=0; do { bool ok=true; int mxi=0; FOR(i,1,n) if(p[i]>p[mxi]) { if(i-mxi>k) ok=false; mxi=i; } if(!ok) ++chk;  } while(next_permutation(p.begin(),p.end())); printf("chk=%d\n",chk);
}

int main() {
	run();
	return 0;
}