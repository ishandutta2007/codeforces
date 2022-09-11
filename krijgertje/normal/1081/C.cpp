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

int nbrick,ncol,ngroup;

int choose(int n,int k) {
	if(k<0||k>n) return 0;
	vector<int> inv(n+1); inv[1]=1; FORE(i,2,n) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	vector<int> fac(n+1); fac[0]=1; FORE(i,1,n) fac[i]=(ll)fac[i-1]*i%MOD;
	vector<int> ifac(n+1); ifac[0]=1; FORE(i,1,n) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;
	return (ll)fac[n]*ifac[k]%MOD*ifac[n-k]%MOD;
}

int solve() {
	if(ngroup>nbrick||ngroup<1) return 0;
	int ret=ncol; REP(i,ngroup-1) ret=(ll)ret*(ncol-1)%MOD;
	ret=(ll)ret*choose(nbrick-ngroup+ngroup-1,ngroup-1)%MOD;
	return ret;
}

void run() {
	scanf("%d%d%d",&nbrick,&ncol,&ngroup); ++ngroup;
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}