

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

const int MAXVAL=1000000;
const int MAXCNT=200000;
const int MOD=1000000007;

int n,want,nq;
int cnt[MAXVAL+1]; // cnt[i] = #values that are divisble by i
int dv[MAXVAL+1];
int tot[MAXVAL+1];
int fac[MAXCNT+1];
int inv[MAXCNT+1];
int ifac[MAXCNT+1];
int ans; // sum(tot[y]*C(cnt[y],want))

int C(int n,int k) { if(k>n) return 0; return (ll)fac[n]*ifac[k]%MOD*ifac[n-k]%MOD; }

void inc(int x,int y) {
	if(x==1) {
		ans-=(ll)tot[y]*C(cnt[y],want)%MOD; if(ans<0) ans+=MOD;
		++cnt[y];
		ans+=(ll)tot[y]*C(cnt[y],want)%MOD; if(ans>=MOD) ans-=MOD;
	} else {
		int t=0,z=dv[x]; while(dv[x]==z) x/=dv[x],++t;
		REPE(i,t) { inc(x,y); y*=z; }
	}
}

void run() {
	memset(dv,-1,sizeof(dv));
	FORE(i,2,MAXVAL) if(dv[i]==-1) for(int j=i;j<=MAXVAL;j+=i) dv[j]=i;
	tot[1]=1; FORE(i,2,MAXVAL) { int j=i/dv[i]; tot[i]=tot[j]*(dv[i]-(dv[j]!=dv[i]?1:0)); }
	fac[0]=1; FORE(i,1,MAXCNT) fac[i]=(ll)fac[i-1]*i%MOD;
	inv[1]=1; FORE(i,2,MAXCNT) inv[i]=(MOD-(ll)(MOD/i)*inv[MOD%i]%MOD)%MOD;
	ifac[0]=1; FORE(i,1,MAXCNT) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;
	scanf("%d%d%d",&n,&want,&nq);
	ans=0;
	REP(i,n) { int x; scanf("%d",&x); inc(x,1); }
	REP(i,nq) { int x; scanf("%d",&x); inc(x,1); printf("%d\n",ans); }
}

int main() {
	run();
	return 0;
}