#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <unordered_map>
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

const int MAXLEN=40;
const int MAXN=500000;
const int MOD=1000000007;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
const ull m1  = 0x5555555555555555;
const ull m2  = 0x3333333333333333;
const ull m4  = 0x0f0f0f0f0f0f0f0f;
const ull h01 = 0x0101010101010101;
int popcount64c(ull x) {
    x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
    x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits 
    x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits 
    return (x * h01) >> 56;  //returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ... 
}

char s[MAXLEN+1]; int len;

int np;
int p[MAXN],pp[MAXN];

ll zero,one; int nzero,none=0;
ll pmask[MAXN];

int bc[1<<11];
int dp29[1<<11][1<<11][18+1]; // dp29[a][b][c] = ways when only considering primes >= 29 when the first at most len-29 bits are a, the last len-29 bits are b, and there are c zeroes left in the middle
int dp31[1<< 9][1<< 9][22+1];
int dp37[1<< 3][1<< 3][34+1];
int dp[MAXLEN+1]; // dp[c] = ways when only considering primes >= len

int tmp[(1<<18)*(22+1)];


int calc(int j) { return dp[j]; }
bool have37;
int calc37(int a,int b,int j) {
	if(dp37[a][b][j]!=-1) return dp37[a][b][j];
	int nout=max(0,len-37),nmid=len-2*nout;
	int midzero=0,midone=0; FOR(i,nout,len-nout) if(s[i]=='0') ++midzero; else ++midone;
	int dj=bc[a]+bc[b];
	ll now=(ll)calc(j+dj)*(!have37?1:nmid-midone-j);
	if(j!=0&&have37) now+=(ll)calc(j+dj-1)*j;
	if(have37) REP(k,nout) {
		if(one&(1LL<<k)) continue; if(one&(1LL<<(k+37))) continue;
		int cdj=dj; cdj-=((a>>k)&1); cdj-=((b>>k)&1);
		now+=calc(j+cdj);
	}
	//if(now!=0) printf("dp37[%d][%d][%d]=%lld\n",a,b,j,now);
	return dp37[a][b][j]=now%MOD;
}
bool have31;
int calc31(int a,int b,int j) {
	if(dp31[a][b][j]!=-1) return dp31[a][b][j];
	int pout=max(0,len-37),nout=max(0,len-31),nmid=len-2*nout;
	int midzero=0,midone=0; FOR(i,nout,len-nout) if(s[i]=='0') ++midzero; else ++midone;
	int dj=bc[a>>pout]+bc[b&((1<<(nout-pout))-1)],aa=a&((1<<pout)-1),bb=b>>(nout-pout);
	ll now=(ll)calc37(aa,bb,j+dj)*(!have31?1:nmid-midone-j);
	if(j!=0&&have31) now+=(ll)calc37(aa,bb,j+dj-1)*j;
	if(have31) REP(k,nout) {
		if(one&(1LL<<k)) continue; if(one&(1LL<<(k+31))) continue;
		int cdj=dj,caa=aa,cbb=bb; if(k<pout) caa&=~(1<<k); else cdj-=((a>>k)&1); if(k<nout-pout) cdj-=((b>>k)&1); else cbb&=~(1<<(k-(nout-pout)));
		now+=calc37(caa,cbb,j+cdj);
	}
	//if(now!=0) printf("dp31[%d][%d][%d]=%lld\n",a,b,j,now);
	return dp31[a][b][j]=now%MOD;
}
bool have29;
int calc29(int a,int b,int j) {
	if(dp29[a][b][j]!=-1) return dp29[a][b][j];
	int pout=max(0,len-31),nout=max(0,len-29),nmid=len-2*nout;
	int midzero=0,midone=0; FOR(i,nout,len-nout) if(s[i]=='0') ++midzero; else ++midone;
	int dj=bc[a>>pout]+bc[b&((1<<(nout-pout))-1)],aa=a&((1<<pout)-1),bb=b>>(nout-pout);
	ll now=(ll)calc31(aa,bb,j+dj)*(!have29?1:nmid-midone-j);
	if(j!=0&&have29) now+=(ll)calc31(aa,bb,j+dj-1)*j;
	if(have29) REP(k,nout) {
		if(one&(1LL<<k)) continue; if(one&(1LL<<(k+29))) continue;
		int cdj=dj,caa=aa,cbb=bb; if(k<pout) caa&=~(1<<k); else cdj-=((a>>k)&1); if(k<nout-pout) cdj-=((b>>k)&1); else cbb&=~(1<<(k-(nout-pout)));
		now+=calc31(caa,cbb,j+cdj);
	}
	//if(now!=0) printf("dp29[%d][%d][%d]=%lld\n",a,b,j,now);
	return dp29[a][b][j]=now%MOD;
}

unordered_map<ll,int> mem;
int go(ll mask,int at) {
	ll key=mask|((ll)at<<len); if(mem.count(key)) return mem[key];
	if(at>=np||p[at]>=len) return calc(popcount64c(mask));
	if(p[at]==37) { int nout=max(0,len-37),nmid=len-2*nout; return calc37(mask&((1<<nout)-1),mask>>(len-nout),popcount64c(mask&(((1LL<<nmid)-1)<<nout))); }
	if(p[at]==31) { int nout=max(0,len-31),nmid=len-2*nout; return calc31(mask&((1<<nout)-1),mask>>(len-nout),popcount64c(mask&(((1LL<<nmid)-1)<<nout))); }
	if(p[at]==29) { int nout=max(0,len-29),nmid=len-2*nout; return calc29(mask&((1<<nout)-1),mask>>(len-nout),popcount64c(mask&(((1LL<<nmid)-1)<<nout))); }
	ll ret=0;
	REP(i,p[at]) {
		ll cur=(pmask[at]&((1LL<<(len-i))-1))<<i;
		if(cur&one) continue;
		ret+=go(mask&~cur,at+1);
	}
	//printf("%llx %d=%lld\n",mask,at,ret);
	return mem[key]=ret%MOD;
}


void run() {
	memset(bc,0,sizeof(bc)); FOR(i,1,1<<11) bc[i]=bc[i>>1]+(i&1);
	scanf("%s",s); len=strlen(s);
	scanf("%d",&np); REP(i,np) scanf("%d%d",&p[i],&pp[i]); 
	int mlt=1; REP(i,np) mlt=(ll)mlt*pw(p[i],pp[i]-1)%MOD;
	//printf("mlt=%d\n",mlt);

	sort(p,p+np);
	REP(i,np) { pmask[i]=1LL<<0; REP(j,(len-1)/p[i]) pmask[i]=(pmask[i]<<p[i])|(1LL<<0); }
	//REP(i,np) { printf("%2d: ",p[i]); REP(j,len) printf("%d",(pmask[i]>>j)&1); puts(""); }
	zero=one=nzero=none=0; REP(i,len) if(s[i]=='0') zero|=1LL<<i,++nzero; else one|=1LL<<i,++none;

	dp[0]=1; FORE(j,1,len) dp[j]=0; 
	REP(i,np) if(p[i]>=len) {
		for(int j=nzero;j>=0;--j) {
			dp[j]=(ll)dp[j]*(p[i]-none-j)%MOD;
			if(j!=0) dp[j]=(dp[j]+(ll)dp[j-1]*j)%MOD;
		}
	}
	//REPE(j,nzero) if(dp[j]!=0) printf("dp[%d]=%d\n",j,dp[j]);
	memset(dp37,-1,sizeof(dp37)); have37=false;
	memset(dp31,-1,sizeof(dp31)); have31=false;
	memset(dp29,-1,sizeof(dp29)); have29=false;
	REP(i,np) if(p[i]==37) have37=37<len; else if(p[i]==31) have31=31<len; else if(p[i]==29) have29=29<len;
	int times=go(zero,0);
	int ret=(ll)mlt*times%MOD;
	printf("%d\n",ret);
	//printf("times=%d\n",times);
}

int main() {
	run();
	return 0;
}