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

const int MAXN=200000;
const int MOD=1000000007;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { inc(a,MOD-b); }

int n; ll totaltime;
int t[MAXN];

int inv[MAXN+1];
int fac[MAXN+1];
int ifac[MAXN+1];
int invp2[MAXN+1];
int choose(int n,int k) { assert(0<=n&&n<=::n); if(k<0||k>n) return 0; return (ll)fac[n]*ifac[k]%MOD*ifac[n-k]%MOD; }

int solve() {
	inv[1]=1; FORE(i,2,MAXN) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1; FORE(i,1,MAXN) fac[i]=(ll)fac[i-1]*i%MOD;
	ifac[0]=1; FORE(i,1,MAXN) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;
	invp2[0]=1; FORE(i,1,MAXN) invp2[i]=(ll)invp2[i-1]*inv[2]%MOD;

	int ret=0; ll trem=totaltime;
	int p=-1;
	REP(i,n) {
		trem-=t[i];
		if(trem<0) break;
		if(trem>=i+1) { inc(ret,1); continue; }
		//printf("%d: prob at most %lld out of %d\n",i+1,trem,i+1);
		if(p==-1) {
			p=0; REPE(j,trem) inc(p,(ll)choose(i+1,j)*invp2[i+1]%MOD);
		} else {
			//printf("\twas %lld out of %d (prob=%d)\n",trem+t[i],i,p);
			for(int j=trem+t[i];j>trem;--j) dec(p,(ll)choose(i,j)*invp2[i]%MOD);
			dec(p,(ll)choose(i,trem)*invp2[i+1]%MOD);
			//int pchk=0; REPE(j,trem) inc(pchk,(ll)choose(i+1,j)*invp2[i+1]%MOD); printf("\tpchk=%d diff=%d\n",pchk,abs(p-pchk));
		}
		//printf("\tp=%d\n",p);
		inc(ret,p);
	}
	return ret;
}

void run() {
	scanf("%d%lld",&n,&totaltime);
	REP(i,n) scanf("%d",&t[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}