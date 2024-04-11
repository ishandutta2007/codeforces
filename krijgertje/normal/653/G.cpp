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
const int MAXVAL=300000;
const int MAXD=6;
const int MAXDTOT=MAXVAL*MAXD;
const int MAXPOW=18;
const int MOD=1000000007;


int fac[MAXN+1];
int inv[MAXN+1];
int ifac[MAXN+1];
int csum[MAXN+1];

int C(int n,int k) { return (ll)fac[n]*ifac[k]%MOD*ifac[n-k]%MOD; }
int cntdiff(int L,int R,int k) {
	if(k>R) return 0;
	// number ways to choose j items from L and j+k from R
	// == number ways to choose j items from L and (R-j-k) from R
	// == number of ways to choose R-k items from L+R
	return (ll)fac[L+R]*ifac[R-k]%MOD*ifac[L+k]%MOD;
}

int n;
int dv[MAXVAL+1];
int cnt[MAXN];
inline void inc(int &a,const int &b) { if((a+=b)>=MOD) a-=MOD; }
inline void dec(int &a,const int &b) { if((a-=b)<0) a+=MOD; }
void precalc() {
	memset(dv,-1,sizeof(dv)); FORE(i,2,MAXVAL) if(dv[i]==-1) for(int j=i;j<=MAXVAL;j+=i) dv[j]=i;
	fac[0]=1; FORE(i,1,MAXN) fac[i]=(ll)fac[i-1]*i%MOD;
	inv[1]=1; FORE(i,2,MAXN) inv[i]=(ll)(MOD-inv[MOD%i])*(MOD/i)%MOD;
	ifac[0]=1; FORE(i,1,MAXN) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;
	memset(cnt,0,sizeof(cnt));
	csum[0]=0; REP(i,n) if((csum[i+1]=csum[i]+C(n-2,i))>=MOD) csum[i+1]-=MOD;
	REP(k,n) {
		dec(cnt[k],csum[n]); inc(cnt[k],csum[k]);
		dec(cnt[k],csum[n]); inc(cnt[k],csum[k+1]);
		if(k>=1) inc(cnt[k],csum[k-1]);
		inc(cnt[k],csum[k]);
	}
	//REP(i,n) printf("%d: %d\n",i,cnt[i]>=MOD-10000?cnt[i]-MOD:cnt[i]);
}

int x[MAXN];
int dhead[MAXVAL+1],dnxt[MAXDTOT],dcnt[MAXDTOT],nd;

int a[MAXN],na;
int b[MAXPOW],bcnt[MAXPOW],nb;

int solve() {
	int ret=0;
	for(int i=nb-1,j=n-1;i>=0&&b[i]>0;--i) {
		REP(k,bcnt[i]) inc(ret,(ll)b[i]*cnt[j--]%MOD);
	}
	return ret;
}


void run() {
	scanf("%d",&n);
	precalc();
	REP(i,n) scanf("%d",&x[i]);
	memset(dhead,-1,sizeof(dhead)); nd=0;
	REP(i,n) { int cur=x[i]; while(cur!=1) { int d=dv[cur],cnt=0; while(cur%d==0) cur/=d,++cnt; dnxt[nd]=dhead[d],dhead[d]=nd,dcnt[nd]=cnt,++nd; } }
	int ret=0;
	FORE(i,2,MAXVAL) if(dhead[i]!=-1) {
		na=0; for(int j=dhead[i];j!=-1;j=dnxt[j]) a[na++]=dcnt[j]; sort(a,a+na);
		nb=0; if(na!=n) b[nb]=0,bcnt[nb]=n-na,++nb; REP(j,na) if(nb!=0&&a[j]==b[nb-1]) ++bcnt[nb-1]; else b[nb]=a[j],bcnt[nb]=1,++nb;
		//printf("%d:",i); REP(j,nb) printf(" %d=%d",b[j],bcnt[j]); puts("");
		ret+=solve(); if(ret>=MOD) ret-=MOD;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}