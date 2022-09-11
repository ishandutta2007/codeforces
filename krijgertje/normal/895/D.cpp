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

char a[MAXN+1],b[MAXN+1]; int n;

int fac[MAXN+1];
int inv[MAXN+1];
int ifac[MAXN+1];

int cnt[26];
int cursum,curcalc;
void precalc() {
	cursum=0; REP(i,26) cursum+=cnt[i];
	curcalc=fac[cursum]; REP(i,26) curcalc=(ll)curcalc*ifac[cnt[i]]%MOD;
}
void dec(int x) { assert(cnt[x]>0&&cursum>0); curcalc=(ll)curcalc*inv[cursum]%MOD*cnt[x]%MOD; --cnt[x],--cursum; }
void inc(int x) { ++cnt[x],++cursum; curcalc=(ll)curcalc*cursum%MOD*inv[cnt[x]]%MOD; }

void run() {
	scanf("%s%s",a,b); n=strlen(a);
	fac[0]=1; FORE(i,1,n) fac[i]=(ll)fac[i-1]*i%MOD;
	inv[1]=1; FORE(i,2,n) inv[i]=(MOD-(ll)(MOD/i)*inv[MOD%i]%MOD)%MOD;
	ifac[0]=1; FORE(i,1,n) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;

	int pref=0; while(pref<n&&a[pref]==b[pref]) ++pref;
	int ret=0;

	// c[pref]<b[pref]
	REP(i,26) cnt[i]=0; FOR(i,pref,n) ++cnt[a[i]-'a']; precalc();
	FOR(i,pref,n) { // a[i]<c[i]
		int cur=a[i]-'a',mn=cur+1,mx=(i==pref?b[i]-'a'-1:25);
		FORE(x,mn,mx) if(cnt[x]>0) { dec(x); ret=(ret+curcalc)%MOD; inc(x); }
		if(cnt[cur]==0) break; else dec(cur);
	}
	
	// c[pref]==b[pref]
	REP(i,26) cnt[i]=0; FOR(i,pref,n) ++cnt[a[i]-'a']; precalc();
	FOR(i,pref,n) {
		int cur=b[i]-'a',mn=(i==pref?cur:0),mx=cur-1;
		FORE(x,mn,mx) if(cnt[x]>0) { dec(x); ret=(ret+curcalc)%MOD; inc(x); }
		if(cnt[cur]==0) break; else dec(cur);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}