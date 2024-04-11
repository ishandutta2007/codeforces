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
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int n;

int inv[MAXN+1];
int fac[MAXN+1];
int ifac[MAXN+1];
int C(int n,int k) { if(k<0||k>n) return 0; return (ll)fac[n]*ifac[k]%MOD*ifac[n-k]%MOD; }

int pmn[MAXN+1];
int len[MAXN+1];
int dp[MAXN+1];

int solve() {
	inv[1]=1; FORE(i,2,MAXN) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1; FORE(i,1,MAXN) fac[i]=(ll)fac[i-1]*i%MOD;
	ifac[0]=1; FORE(i,1,MAXN) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;

	memset(pmn,-1,sizeof(pmn));
	FORE(i,2,MAXN) if(pmn[i]==-1) for(int j=i;j<=MAXN;j+=i) if(pmn[j]==-1) pmn[j]=i;
	len[1]=1; FORE(i,2,n) len[i]=len[i/pmn[i]]+1;
	int mxlen=1; FORE(i,2,n) mxlen=max(mxlen,len[i]);
	//printf("mxlen=%d\n",mxlen);
	dp[1]=1;
	FORE(i,2,n) {
		int x=i; dp[i]=0;
		while(x!=1) {
			int p=pmn[x];
			int j=i/p;
			int cntnow=n/j-n/i;
			int rem=n-n/i;
			//printf("i=%d p=%d j=%d -> cntnow=%d rem=%d\n",i,p,j,cntnow,rem);
			inc(dp[i],(ll)C(rem-1,cntnow-1)*fac[cntnow]%MOD*dp[j]%MOD);
			while(x%p==0) x/=p;
		}
	}
	int ret=0; FORE(i,1,n) if(len[i]==mxlen) inc(ret,dp[i]); return ret;
}

void run() {
	scanf("%d",&n);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}