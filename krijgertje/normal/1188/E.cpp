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

const int MOD=998244353;
const int MAXN=100000;
const int MAXSUM=1000000;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int inv[MAXSUM+1];
int fac[MAXSUM+1];
int ifac[MAXSUM+1];

int choose(int n,int k) {
	return (ll)fac[n]*ifac[k]%MOD*ifac[n-k]%MOD;
}

int calc(int n,int k) { // distribute n items over k slots, with repetitions allowed
	if(k==0) return 0;
	return choose(n+k-1,k-1);
}

int n;
int a[MAXN];

int b[MAXN];

int solve() {
	inv[1]=1; FORE(i,2,MAXSUM) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1; FORE(i,1,MAXSUM) fac[i]=(ll)fac[i-1]*i%MOD;
	ifac[0]=1; FORE(i,1,MAXSUM) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;

	sort(a,a+n);
	int lim=-1; REP(i,n) if(a[i]<i) { lim=i-1; break; }
	//printf("lim=%d\n",lim);
	int ret=0;
	if(lim!=-1) {
		int at=0;
		REPE(i,lim) {
			assert(at<=i);
			inc(ret,calc(i-at,n));
			while(at<n&&a[at]==i) ++at;
		}
	} else {
		REP(i,n) b[i]=a[i]%n;
		sort(b,b+n);
		int at=0;
		int rem=0; REP(i,n) rem+=a[i]/n;
		REP(i,n) {
			inc(ret,calc(rem,n));
			++rem;
			while(at<n&&b[at]==i) ++at,--rem;
		}
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}