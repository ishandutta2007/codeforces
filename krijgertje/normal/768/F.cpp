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

const int MOD=1000000007;
const int MAXN=100000;

int na,nb,want;

int fac[2*MAXN+1];
int inv[2*MAXN+1];
int ifac[2*MAXN+1];

int mypow(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
int calc(int n,int k) {
	if(n==0) return 1;
	int ret=(ll)fac[n+k-1]*ifac[n]%MOD*ifac[k-1]%MOD;
	return ret;
}

void run() {
	fac[0]=1; FORE(i,1,2*MAXN) fac[i]=(ll)fac[i-1]*i%MOD;
	inv[1]=1; FORE(i,2,2*MAXN) inv[i]=(MOD-(ll)MOD/i*inv[MOD%i]%MOD)%MOD;
	ifac[0]=1; FORE(i,1,2*MAXN) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;

	scanf("%d%d%d",&na,&nb,&want); ++want;

	int num=0,den=0;
	REP(fst,2) for(int len=1;;++len) {
		int pa=fst==0?(len+1)/2:len/2;
		int pb=fst==0?len/2:(len+1)/2;
		if(pa>na||pb>nb) break;
		if(pa==0&&na>0||pb==0&&nb>0) continue;
		int xa=calc(na-pa,pa),xb=calc(nb-pb,pb),xc=nb>=(ll)want*pb?calc(nb-want*pb,pb):0;
		//printf("%d %d: %d %d %d\n",fst,len,xa,xb,xc);
		num=(num+(ll)xa*xc)%MOD;
		den=(den+(ll)xa*xb)%MOD;
	}
	//printf("\t%d %d\n",num,den);
	int ret=(ll)num*mypow(den,MOD-2)%MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}