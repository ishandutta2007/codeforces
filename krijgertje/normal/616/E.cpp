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
const int INV2=(MOD+1)/2;

ll n,m;

void run() {
	scanf("%I64d %I64d",&n,&m);

	ll ret=0;
	for(ll at=m,c=0;at>0;) {
		ll x=n/(c+1)+1; // n/m=c -> m>=x
		if(x>at) { c=n/at; continue; }
		//ret+= n%x+n%(x+1)+...+n%at
		//ret+= n-c*x+n-c*(x+1)+...+n-c*at
		//ret+= n*(at-x+1)-c*(x+at)*(at-x+1)/2
		//printf("\t%lld: %lld..%lld\n",c,x,at);
		int cnt=(at-x+1)%MOD,sum=(x+at)%MOD;
		ret+=n%MOD*cnt%MOD-c%MOD*sum%MOD*cnt%MOD*INV2%MOD;
		at=x-1,++c;
	}
	ret%=MOD; if(ret<0) ret+=MOD;
	printf("%d\n",(int)ret);
}

int main() {
	run();
	return 0;
}