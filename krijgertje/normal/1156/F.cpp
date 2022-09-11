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

const int MAXN=5000;
const int MOD=998244353;

int n;
int a[MAXN];

int inv[MAXN+1];
int fac[MAXN+1];
int ifac[MAXN+1];
int C(int n,int k) { if(k<0||k>n) return 0; return (ll)fac[n]*ifac[k]%MOD*ifac[n-k]%MOD; }

int ways[MAXN+1];

int solve() {
	inv[1]=1; FORE(i,2,n) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1; FORE(i,1,n) fac[i]=(ll)fac[i-1]*i%MOD;
	ifac[0]=1; FORE(i,1,n) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;

	sort(a,a+n);
	int cntdiff=0; ways[0]=1;
	int num=0;
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&a[r]==a[l]) ++r;
		int cnteq=r-l;
		if(cnteq>=2) {
			int cur=0;
			REPE(i,cntdiff) cur=(cur+(ll)ways[i]*fac[n-i-2])%MOD;
			num=(num+(ll)cur*2*C(cnteq,2))%MOD;
		}
		++cntdiff; ways[cntdiff]=0;
		for(int i=cntdiff-1;i>=0;--i) ways[i+1]=(ways[i+1]+(ll)ways[i]*cnteq)%MOD;
	}
	//printf("num=%d\n",num);
	return (ll)num*ifac[n]%MOD;
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