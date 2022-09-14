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

const int MAXN=300000;
const int MAXEQ=20;
const int MAXHAVESUM=300000;
const int MAXLEN=10000;
const int MOD=1000000007;
const int BASE=1000000000;
const int BASELG10=9;
typedef struct C { int l,r,sum,rat,need; } C;

int n;
int rat[MAXN];
int have[MAXN];
char s[MAXLEN+1]; int slen;
int need[(MAXLEN+BASELG10-1)/BASELG10],needlen;
C c[MAXN]; int nc;
int dp[MAXHAVESUM+1],dpmx;
int dpsum[MAXHAVESUM+2];


int dv(int by) {
	ll rem=0;
	for(int i=needlen-1;i>=0;--i) {
		rem=rem*BASE+need[i]; need[i]=rem/by; rem%=by;
	}
	while(needlen>0&&need[needlen-1]==0) --needlen;
	return rem;
}

int solve() {
	{ needlen=1; need[0]=0; int t=1; REP(i,slen) { if(t==BASE) need[needlen++]=0,t=1; need[needlen-1]+=t*(s[slen-i-1]-'0'); t*=10; } }
	//REP(i,needlen) printf("%09d ",need[i]); puts("");

	nc=1; c[0].l=c[0].r=0,c[0].sum=have[0],c[0].rat=0;
	FOR(i,1,n) {
		if(rat[i]==1) { c[nc-1].r=i,c[nc-1].sum+=have[i]; continue; }
		c[nc].l=c[nc].r=i,c[nc].sum=have[i],c[nc].rat=rat[i],++nc;
	}
	REP(i,nc-1) c[i].need=dv(c[i+1].rat);
	if(needlen>1) return 0; else c[nc-1].need=needlen==0?0:need[0];
	//REP(i,nc) printf("%d..%d rat=%d sum=%d need=%d\n",c[i].l,c[i].r,c[i].rat,c[i].sum,c[i].need);

	dpmx=0; dp[0]=1;
	REP(i,nc) {
		//printf("starting %d:",i); REPE(k,dpmx) printf(" %d",dp[k]); puts("");
		FORE(j,c[i].l,c[i].r) {
			REP(k,have[j]) dp[++dpmx]=0;
			dpsum[0]=0; REPE(k,dpmx) if((dpsum[k+1]=dpsum[k]+dp[k])>=MOD) dpsum[k+1]-=MOD;
			for(int k=dpmx;k>=0;--k) if((dp[k]=dpsum[k+1]-dpsum[max(0,k-have[j])])<0) dp[k]+=MOD;
			//printf("\tafter %d:",j); REPE(k,dpmx) printf(" %d",dp[k]); puts("");
		}
		if(dpmx<c[i].need) return 0;
		if(i+1<nc) {
			dpmx=(dpmx-c[i].need)/c[i+1].rat;
			REPE(k,dpmx) dp[k]=dp[c[i].need+k*c[i+1].rat];
		}
	}
	return dp[c[nc-1].need];
}

void run() {
	scanf("%d",&n);
	rat[0]=0; FOR(i,1,n) scanf("%d",&rat[i]);
	REP(i,n) scanf("%d",&have[i]);
	scanf("%s",s); slen=strlen(s);

	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}