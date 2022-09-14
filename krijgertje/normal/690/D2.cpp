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

const int MAXN=500000;
const int MAXC=200000;
const int MAXV=MAXN+MAXC;
const int MOD=1000003;

int n,c;
int fac[MAXV+1];
int inv[MAXV+1];
int ifac[MAXV+1];

void run() {
	fac[0]=1; FORE(i,1,MAXV) fac[i]=(ll)fac[i-1]*i%MOD;
	inv[1]=1; FORE(i,2,MAXV) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	ifac[0]=1; FORE(i,1,MAXV) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;
	FORE(i,1,MAXV) assert((ll)fac[i]*ifac[i]%MOD==1);

	scanf("%d%d",&n,&c);
	int ret=(ll)fac[n+c]*ifac[c]%MOD*ifac[n]%MOD;
	if((--ret)<0) ret+=MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}