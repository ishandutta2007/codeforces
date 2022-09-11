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

const int MAXQ=400;
const int MAXN=400;

int nq,MOD;
int q[MAXQ];

int fac[MAXN+1];
int ans[MAXN+1];
int dp[MAXN+1][MAXN+1];
int dppref[MAXN+1];

void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { if((a-=b)<0) a+=MOD; }

ll solve() {
	fac[0]=1; FORE(i,1,MAXN) fac[i]=(ll)fac[i-1]*i%MOD;
	memset(dp,0,sizeof(dp)); dp[0][0]=1; FORE(i,1,MAXN) FORE(j,1,i) FORE(k,1,i-j+1) inc(dp[i][j],(ll)dp[i-k][j-1]*fac[k]%MOD);
	//REPE(i,10) { printf("dp%d:",i); REPE(j,i) printf(" %d",dp[i][j]); puts(""); }
	FORE(i,1,MAXN) { dppref[i]=fac[i]; FORE(j,1,i-1) dec(dppref[i],(ll)dppref[j]*fac[i-j]%MOD); }
	//printf("dppref:"); FORE(i,1,10) printf(" %d",dppref[i]); puts("");
	FORE(i,1,MAXN) {
		ans[i]=fac[i];
		if(i!=2) FORE(a,1,i-1) FORE(b,1,i-a) dec(ans[i],(ll)2*dppref[a]*dppref[b]%MOD*fac[i-a-b]%MOD);
		FORE(j,3,i-1) dec(ans[i],(ll)ans[j]*dp[i][j]%MOD);
		//if(i<10) printf("ans[%d]=%d\n",i,ans[i]);
	}
}

void run() {
	scanf("%d%d",&nq,&MOD);
	REP(i,nq) scanf("%d",&q[i]);
	solve();
	REP(i,nq) printf("%d\n",ans[q[i]]);
}

int main() {
	run();
	return 0;
}