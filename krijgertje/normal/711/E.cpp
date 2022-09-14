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

const int MOD=1000003;
const int PMOD=MOD-1;
const int DIV2=(MOD+1)/2;


// pdiff=((2^n)-1)*((2^n)-2)*...*((2^n)-(k-1)) / 2^(n*(k-1))
// ret = 1-pdiff

ll n,k;

ll calcfacdiv(ll x,ll dv) {
	ll ret=0;
	for(ll y=x;dv<=y;y/=dv) ret+=y/dv;
	return ret;
}
int mypow(int x,ll n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

pair<int,int> solve() {
	if(n<60&&k>(1LL<<n)) return MP(1,1);
	ll a2=calcfacdiv(k-1,2);
	int b2=(((n%PMOD)*((k-1)%PMOD)-a2)%PMOD+PMOD)%PMOD;
	int b=mypow(2,b2);
	if(k-1>=MOD) return MP(b,b);
	int nn=mypow(2,n);
	int a=1; FORE(i,1,k-1) a=(ll)a*(MOD+nn-i)%MOD; a=(ll)a*mypow(DIV2,a2)%MOD; a=(MOD+b-a)%MOD;
	return MP(a,b);
}

void run() {
	scanf("%lld%lld",&n,&k);
	pair<int,int> ret=solve();
	printf("%d %d\n",ret.first,ret.second);
}

int main() {
	run();
	return 0;
}